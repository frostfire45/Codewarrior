/*****************************************************

     CString.cpp - ANSI-C++ library: Strings
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

/* 
Copyright (C) 1988 Free Software Foundation
    written by Doug Lea (dl@rocky.oswego.edu)

This file is part of the GNU C++ Library.  This library is free
software; you can redistribute it and/or modify it under the terms of
the GNU Library General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.  This library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the Free Software
Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/* 
  String class implementation
 */

#ifdef __GNUG__
#pragma implementation
#endif
#include "comp.h"
#include <cstring.h>
#include <std.h>
#include <ctype.h>
#include <limits.h>
#include <new.h>
#include <builtin.h>

#undef OK

void String::error(const char*_LIBDEF_FAR_CPP_PTR msg) const
{
#ifdef _LIMITATION_HC05
  exit(1);
#else
  (*lib_error_handler)("String", msg);
#endif
}

String::operator const char*_LIBDEF_FAR_CPP_PTR() const
{ 
  return (const char*_LIBDEF_FAR_CPP_PTR)chars();
}

//  globals

StrRep  _nilStrRep = { 0, 1, { 0 } }; // nil strings point here
String _nilString;               // nil SubStrings point here




/*
 the following inline fcts are specially designed to work
 in support of String classes, and are not meant as generic replacements
 for libc "str" functions.

 inline copy fcts -  I like left-to-right from->to arguments.
 all versions assume that `to' argument is non-null

 These are worth doing inline, rather than through calls because,
 via procedural integration, adjacent copy calls can be smushed
 together by the optimizer.
*/

// copy n bytes
inline static void ncopy(const char*_LIBDEF_FAR_CPP_PTR from, char* to, int n)
{
  if (from != to) while (--n >= 0) *to++ = *from++;
}

// copy n bytes, null-terminate
inline static void ncopy0(const char*_LIBDEF_FAR_CPP_PTR from, char* to, int n)
{
  if (from != to) 
  {
    while (--n >= 0) *to++ = *from++;
    *to = 0;
  }
  else
    to[n] = 0;
}

// copy until null
inline static void scopy(const char*_LIBDEF_FAR_CPP_PTR from, char* to)
{
  if (from != 0) while((*to++ = *from++) != 0);
}

// copy right-to-left
inline static void revcopy(const char*_LIBDEF_FAR_CPP_PTR from, char* to, short n)
{
  if (from != 0) while (--n >= 0) *to-- = *from--;
}


inline static int slen(const char*_LIBDEF_FAR_CPP_PTR t) // inline  strlen
{
  if (t == 0)
    return 0;
  else
  {
    const char*_LIBDEF_FAR_CPP_PTR a = t;
    while (*a++ != 0);
    return a - 1 - t;
  }
}

// minimum & maximum representable rep size

#define MAXStrRep_SIZE   ((1 << (sizeof(short) * CHAR_BIT - 1)) - 1)
#define MINStrRep_SIZE   16

#ifndef MALLOC_MIN_OVERHEAD
#define MALLOC_MIN_OVERHEAD  4
#endif

// The basic allocation primitive:
// Always round request to something close to a power of two.
// This ensures a bit of padding, which often means that
// concatenations don't have to realloc. Plus it tends to
// be faster when lots of Strings are created and discarded,
// since just about any version of malloc (op new()) will
// be faster when it can reuse identically-sized chunks

inline static StrRep* Snew(int newsiz)
{
  unsigned int siz = sizeof(StrRep) + newsiz + MALLOC_MIN_OVERHEAD;
  unsigned int allocsiz = MINStrRep_SIZE;
  while (allocsiz < siz) {
    allocsiz <<= 1;
#ifdef _LIBRARY_WORKAROUND
    if(allocsiz==0) {
      break;
    }
  }
  if(allocsiz==0) {
    allocsiz = 64;
  } else {
    allocsiz -= MALLOC_MIN_OVERHEAD;
  }
#else
  }
  allocsiz -= MALLOC_MIN_OVERHEAD;
#endif
  if (allocsiz >= MAXStrRep_SIZE)
#ifdef _LIMITATION_HC05
  exit(1);
#else
    (*lib_error_handler)("String", "Requested length out of range");
#endif
#ifndef _LIBRARY_WORKAROUND_PLAC    
  StrRep* rep = new (operator new (allocsiz)) StrRep;
#else
  StrRep* rep = (StrRep *)new char[allocsiz];
#endif

  rep->sz = allocsiz - sizeof(StrRep);
  return rep;
}

// Do-something-while-allocating routines.

// We live with two ways to signify empty Sreps: either the
// null pointer (0) or a pointer to the nilStrRep.

// We always signify unknown source lengths (usually when fed a char*)
// via len == -1, in which case it is computed.

// allocate, copying src if nonull

StrRep* Salloc(StrRep* old, const char*_LIBDEF_FAR_CPP_PTR src, int srclen, int newlen)
{
  if (old == &_nilStrRep) old = 0;
  if (srclen < 0) srclen = slen(src);
  if (newlen < srclen) newlen = srclen;
  StrRep* rep;
  if (old == 0 || newlen > old->sz)
    rep = Snew(newlen);
  else
    rep = old;

  rep->len = newlen;
  ncopy0(src, rep->s, srclen);

  if (old != rep && old != 0) delete old;

  return rep;
}

// reallocate: Given the initial allocation scheme, it will
// generally be faster in the long run to get new space & copy
// than to call realloc

static StrRep*
Sresize(StrRep* old, int newlen)
{
  if (old == &_nilStrRep) old = 0;
  StrRep* rep;
  if (old == 0)
    rep = Snew(newlen);
  else if (newlen > old->sz)
  {
    rep = Snew(newlen);
    ncopy0(old->s, rep->s, old->len);
    delete old;
  }
  else
    rep = old;

  rep->len = newlen;

  return rep;
}

void
String::alloc (int newsize)
{
  unsigned short old_len = rep->len;
  rep = Sresize(rep, newsize);
  rep->len = old_len;
}

// like allocate, but we know that src is a StrRep

StrRep* Scopy(StrRep* old, const StrRep* s)
{
  if (old == &_nilStrRep) old = 0;
  if (s == &_nilStrRep) s = 0;
  if (old == s) 
    return (old == 0)? &_nilStrRep : old;
  else if (s == 0)
  {
    old->s[0] = 0;
    old->len = 0;
    return old;
  }
  else 
  {
    StrRep* rep;
#ifdef _LIBRARY_WORKAROUND
    unsigned int newlen = s->len;
#else
    int newlen = s->len;
#endif
    if (old == 0 || newlen > old->sz)
    {
      if (old != 0) delete old;
      rep = Snew(newlen);
    }
    else
      rep = old;
    rep->len = newlen;
    ncopy0(s->s, rep->s, newlen);
    return rep;
  }
}

// allocate & concatenate

StrRep* Scat(StrRep* old, const char*_LIBDEF_FAR_CPP_PTR s, int srclen, const char*_LIBDEF_FAR_CPP_PTR t, int tlen)
{
  if (old == &_nilStrRep) old = 0;
  if (srclen < 0) srclen = slen(s);
  if (tlen < 0) tlen = slen(t);
  int newlen = srclen + tlen;
  StrRep* rep;

  if (old == 0 || newlen > old->sz 
      || (t >= old->s && t < &(old->s[old->len]))
    ) // beware of aliasing
    rep = Snew(newlen);
  else
    rep = old;
  rep->len = newlen;

  ncopy(s, rep->s, srclen);
  ncopy0(t, &(rep->s[srclen]), tlen);

  if (old != rep && old != 0) delete old;

  return rep;
}

// double-concatenate

StrRep* Scat(StrRep* old, const char*_LIBDEF_FAR_CPP_PTR s, int srclen, const char*_LIBDEF_FAR_CPP_PTR t, int tlen,
             const char*_LIBDEF_FAR_CPP_PTR u, int ulen)
{
  if (old == &_nilStrRep) old = 0;
  if (srclen < 0) srclen = slen(s);
  if (tlen < 0) tlen = slen(t);
  if (ulen < 0) ulen = slen(u);
  int newlen = srclen + tlen + ulen;
  StrRep* rep;

  if (old == 0 || newlen > old->sz 
      ||  (t >= old->s && t < &(old->s[old->len]))
      ||  (u >= old->s && u < &(old->s[old->len]))
      )
    rep = Snew(newlen);
  else
    rep = old;

  rep->len = newlen;

  ncopy(s, rep->s, srclen);
  ncopy(t, &(rep->s[srclen]), tlen);
  ncopy0(u, &(rep->s[srclen+tlen]), ulen);

  if (old != rep && old != 0) delete old;

  return rep;
}

// like cat, but we know that new stuff goes in the front of existing rep

StrRep* Sprepend(StrRep* old, const char*_LIBDEF_FAR_CPP_PTR t, int tlen)
{
  char* s;
#ifdef _LIBRARY_WORKAROUND  
  unsigned int srclen;
#else
  int srclen;
#endif
  if (old == &_nilStrRep || old == 0)
  {
    s = 0; old = 0; srclen = 0;
  }
  else
  {
    s = old->s; srclen = old->len;
  }
  if (tlen < 0) tlen = slen(t);
  int newlen = srclen + tlen;
  StrRep* rep;
  if (old == 0 || newlen > old->sz || 
      (t >= old->s && t < &(old->s[old->len])))
    rep = Snew(newlen);
  else
    rep = old;

  rep->len = newlen;

  revcopy(&(s[srclen]), &(rep->s[newlen]), srclen+1);
  ncopy(t, rep->s, tlen);

  if (old != rep && old != 0) delete old;

  return rep;
}


// string compare: first argument is known to be non-null

inline static int scmp(const char*_LIBDEF_FAR_CPP_PTR a, const char*_LIBDEF_FAR_CPP_PTR b)
{
  if (b == 0)
    return *a != 0;
  else
  {
    int diff = 0;
    while ((diff = *a - *b++) == 0 && *a++ != 0);
    return diff;
  }
}


inline static int ncmp(const char*_LIBDEF_FAR_CPP_PTR a, int al, const char*_LIBDEF_FAR_CPP_PTR b, int bl)
{
  int n = (al <= bl)? al : bl;
  int diff;
  while (n-- > 0) if ((diff = *a++ - *b++) != 0) return diff;
  return al - bl;
}

int fcompare(const String& x, const String& y)
{
  const char*_LIBDEF_FAR_CPP_PTR a = x.chars();
  const char*_LIBDEF_FAR_CPP_PTR b = y.chars();
  int al = x.length();
  int bl = y.length();
  int n = (al <= bl)? al : bl;
  int diff = 0;
  while (n-- > 0)
  {
    char ac = *a++;
    char bc = *b++;
    if ((diff = ac - bc) != 0)
    {
      if (ac >= 'a' && ac <= 'z')
        ac = ac - 'a' + 'A';
      if (bc >= 'a' && bc <= 'z')
        bc = bc - 'a' + 'A';
      if ((diff = ac - bc) != 0)
        return diff;
    }
  }
  return al - bl;
}

// these are not inline, but pull in the above inlines, so are 
// pretty fast

int compare(const String& x, const char*_LIBDEF_FAR_CPP_PTR b)
{
  return scmp(x.chars(), b);
}

int compare(const String& x, const String& y)
{
  return scmp(x.chars(), y.chars());
}

int compare(const String& x, const SubString& y)
{
  return ncmp(x.chars(), x.length(), y.chars(), y.length());
}

int compare(const SubString& x, const String& y)
{
  return ncmp(x.chars(), x.length(), y.chars(), y.length());
}

int compare(const SubString& x, const SubString& y)
{
  return ncmp(x.chars(), x.length(), y.chars(), y.length());
}

int compare(const SubString& x, const char*_LIBDEF_FAR_CPP_PTR b)
{
  if (b == 0)
    return x.length();
  else
  {
    const char*_LIBDEF_FAR_CPP_PTR a = x.chars();
    int n = x.length();
    int diff;
    while (n-- > 0) if ((diff = *a++ - *b++) != 0) return diff;
    return (*b == 0) ? 0 : -1;
  }
}

/*
 index fcts
*/

int String::search(int start, int sl, char c) const
{
  const char*_LIBDEF_FAR_CPP_PTR s = chars();
  if (sl > 0)
  {
    if (start >= 0)
    {
      const char*_LIBDEF_FAR_CPP_PTR a = &(s[start]);
      const char*_LIBDEF_FAR_CPP_PTR lasta = &(s[sl]);
      while (a < lasta) if (*a++ == c) return --a - s;
    }
    else
    {
      const char*_LIBDEF_FAR_CPP_PTR a = &(s[sl + start + 1]);
      while (--a >= s) if (*a == c) return a - s;
    }
  }
  return -1;
}

int String::search(int start, int sl, const char*_LIBDEF_FAR_CPP_PTR t, int tl) const
{
  const char*_LIBDEF_FAR_CPP_PTR s = chars();
  if (tl < 0) tl = slen(t);
  if (sl > 0 && tl > 0)
  {
    if (start >= 0)
    {
      const char*_LIBDEF_FAR_CPP_PTR lasts = &(s[sl - tl]);
      const char*_LIBDEF_FAR_CPP_PTR lastt = &(t[tl]);
      const char*_LIBDEF_FAR_CPP_PTR p = &(s[start]);

      while (p <= lasts)
      {
        const char*_LIBDEF_FAR_CPP_PTR x = p++;
        const char*_LIBDEF_FAR_CPP_PTR y = t;
        while (*x++ == *y++) if (y >= lastt) return --p - s;
      }
    }
    else
    {
      const char*_LIBDEF_FAR_CPP_PTR firsts = &(s[tl - 1]);
      const char*_LIBDEF_FAR_CPP_PTR lastt =  &(t[tl - 1]);
      const char*_LIBDEF_FAR_CPP_PTR p = &(s[sl + start + 1]); 

      while (--p >= firsts)
      {
        const char*_LIBDEF_FAR_CPP_PTR x = p;
        const char*_LIBDEF_FAR_CPP_PTR y = lastt;
        while (*x-- == *y--) if (y < t) return ++x - s;
      }
    }
  }
  return -1;
}

int String::match(int start, int sl, int exact, const char*_LIBDEF_FAR_CPP_PTR t, int tl) const
{
  if (tl < 0) tl = slen(t);

  if (start < 0)
  {
    start = sl + start - tl + 1;
    if (start < 0 || (exact && start != 0))
      return -1;
  }
  else if (exact && sl - start != tl)
    return -1;

  if (sl == 0 || tl == 0 || sl - start < tl || start >= sl)
    return -1;

  int n = tl;
  const char*_LIBDEF_FAR_CPP_PTR s = &(rep->s[start]);
  while (--n >= 0) if (*s++ != *t++) return -1;
  return tl;
}

void SubString::assign(const StrRep* ysrc, const char*_LIBDEF_FAR_CPP_PTR ys, int ylen)
{
  if (&S == &_nilString) return;

  if (ylen < 0) ylen = slen(ys);
  StrRep* targ = S.rep;
  int sl = targ->len - len + ylen;

  if (ysrc == targ || sl >= targ->sz) {
    StrRep* oldtarg = targ;
    targ = Sresize(0, sl);
    ncopy(oldtarg->s, targ->s, pos);
    ncopy(ys, &(targ->s[pos]), ylen);
    scopy(&(oldtarg->s[pos + len]), &(targ->s[pos + ylen]));
    delete oldtarg;
  } else if (len == ylen) {
    ncopy(ys, &(targ->s[pos]), len);
  } else if (ylen < len) {
    ncopy(ys, &(targ->s[pos]), ylen);
    scopy(&(targ->s[pos + len]), &(targ->s[pos + ylen]));
  } else {
    revcopy(&(targ->s[targ->len]), &(targ->s[sl]), targ->len-pos-len +1);
    ncopy(ys, &(targ->s[pos]), ylen);
  }
  targ->len = sl;
  S.rep = targ;
}


/*
 * substitution
 */


int String::_gsub(const char*_LIBDEF_FAR_CPP_PTR pat, int pl, const char*_LIBDEF_FAR_CPP_PTR r, int rl)
{
  int nmatches = 0;
  if (pl < 0) pl = slen(pat);
  if (rl < 0) rl = slen(r);
  int sl = length();
  if (sl <= 0 || pl <= 0 || sl < pl)
    return nmatches;
  
  const char*_LIBDEF_FAR_CPP_PTR s = chars();

  // prepare to make new rep
  StrRep* nrep = 0;
  int nsz = 0;
  char* x = 0;

  int si = 0;
  int xi = 0;
  int remaining = sl;

  while (remaining >= pl)
  {
    int pos = search(si, sl, pat, pl);
    if (pos < 0)
      break;
    else
    {
      ++nmatches;
      int mustfit = xi + remaining + rl - pl;
      if (mustfit >= nsz)
      {
        if (nrep != 0) nrep->len = xi;
        nrep = Sresize(nrep, mustfit);
        nsz = nrep->sz;
        x = nrep->s;
      }
      pos -= si;
      ncopy(&(s[si]), &(x[xi]), pos);
      ncopy(r, &(x[xi + pos]), rl);
      si += pos + pl;
      remaining -= pos + pl;
      xi += pos + rl;
    }
  }

  if (nrep == 0)
  {
    if (nmatches == 0)
      return nmatches;
    else
      nrep = Sresize(nrep, xi+remaining);
  }

  ncopy0(&(s[si]), &(x[xi]), remaining);
  nrep->len = xi + remaining;

  if (nrep->len <= rep->sz)   // fit back in if possible
  {
    rep->len = nrep->len;
    ncopy0(nrep->s, rep->s, rep->len);
    delete(nrep);
  }
  else
  {
    delete(rep);
    rep = nrep;
  }
  return nmatches;
}

int String::_gsub(const Regex& pat, const char*_LIBDEF_FAR_CPP_PTR r, int rl)
{
  int nmatches = 0;
  int sl = length();
  if (sl <= 0)
    return nmatches;

  if (rl < 0) rl = slen(r);

  const char*_LIBDEF_FAR_CPP_PTR s = chars();

  StrRep* nrep = 0;
  int nsz = 0;

  char* x = 0;

  int si = 0;
  int xi = 0;
  int remaining = sl;
  int  pos, pl = 0;         // how long is a regular expression?

  while (remaining > 0)
  {
    pos = pat.search(s, sl, pl, si); // unlike string search, the pos returned here is absolute
    if (pos < 0 || pl <= 0)
      break;
    else
    {
      ++nmatches;
      int mustfit = xi + remaining + rl - pl;
      if (mustfit >= nsz)
      {
        if (nrep != 0) nrep->len = xi;
        nrep = Sresize(nrep, mustfit);
        x = nrep->s;
        nsz = nrep->sz;
      }
      pos -= si;
      ncopy(&(s[si]), &(x[xi]), pos);
      ncopy(r, &(x[xi + pos]), rl);
      si += pos + pl;
      remaining -= pos + pl;
      xi += pos + rl;
    }
  }

  if (nrep == 0)
  {
    if (nmatches == 0)
      return nmatches;
    else
      nrep = Sresize(nrep, xi+remaining);
  }

  ncopy0(&(s[si]), &(x[xi]), remaining);
  nrep->len = xi + remaining;

  if (nrep->len <= rep->sz)   // fit back in if possible
  {
    rep->len = nrep->len;
    ncopy0(nrep->s, rep->s, rep->len);
    delete(nrep);
  }
  else
  {
    delete(rep);
    rep = nrep;
  }
  return nmatches;
}


/*
 * deletion
 */

void String::del(int pos, int len)
{
  if (pos < 0 || len <= 0 || (unsigned)(pos + len) > length()) return;
  int nlen = length() - len;
  int first = pos + len;
  ncopy0(&(rep->s[first]), &(rep->s[pos]), length() - first);
  rep->len = nlen;
}

void String::del(const Regex& r, int startpos)
{
  int mlen;
  int first = r.search(chars(), length(), mlen, startpos);
  del(first, mlen);
}

void String::del(const char*_LIBDEF_FAR_CPP_PTR t, int startpos)
{
  int tlen = slen(t);
  int p = search(startpos, length(), t, tlen);
  del(p, tlen);
}

void String::del(const String& y, int startpos)
{
  del(search(startpos, length(), y.chars(), y.length()), y.length());
}

void String::del(const SubString& y, int startpos)
{
  del(search(startpos, length(), y.chars(), y.length()), y.length());
}

void String::del(char c, int startpos)
{
  del(search(startpos, length(), c), 1);
}

/*
 * substring extraction
 */


SubString String::at(int first, int len)
{
  return _substr(first, len);
}

SubString String::operator() (int first, int len)
{
  return _substr(first, len);
}

SubString String::before(int pos)
{
  return _substr(0, pos);
}

SubString String::through(int pos)
{
  return _substr(0, pos+1);
}

SubString String::after(int pos)
{
  return _substr(pos + 1, length() - (pos + 1));
}

SubString String::from(int pos)
{
  return _substr(pos, length() - pos);
}

SubString String::at(const String& y, int startpos)
{
  int first = search(startpos, length(), y.chars(), y.length());
  return _substr(first,  y.length());
}

SubString String::at(const SubString& y, int startpos)
{
  int first = search(startpos, length(), y.chars(), y.length());
  return _substr(first, y.length());
}

SubString String::at(const Regex& r, int startpos)
{
  int mlen;
  int first = r.search(chars(), length(), mlen, startpos);
  return _substr(first, mlen);
}

SubString String::at(const char*_LIBDEF_FAR_CPP_PTR t, int startpos)
{
  int tlen = slen(t);
  int first = search(startpos, length(), t, tlen);
  return _substr(first, tlen);
}

SubString String::at(char c, int startpos)
{
  int first = search(startpos, length(), c);
  return _substr(first, 1);
}

SubString String::before(const String& y, int startpos)
{
  int last = search(startpos, length(), y.chars(), y.length());
  return _substr(0, last);
}

SubString String::before(const SubString& y, int startpos)
{
  int last = search(startpos, length(), y.chars(), y.length());
  return _substr(0, last);
}

SubString String::before(const Regex& r, int startpos)
{
  int mlen;
  int first = r.search(chars(), length(), mlen, startpos);
  return _substr(0, first);
}

SubString String::before(char c, int startpos)
{
  int last = search(startpos, length(), c);
  return _substr(0, last);
}

SubString String::before(const char*_LIBDEF_FAR_CPP_PTR t, int startpos)
{
  int tlen = slen(t);
  int last = search(startpos, length(), t, tlen);
  return _substr(0, last);
}

SubString String::through(const String& y, int startpos)
{
  int last = search(startpos, length(), y.chars(), y.length());
  if (last >= 0) last += y.length();
  return _substr(0, last);
}

SubString String::through(const SubString& y, int startpos)
{
  int last = search(startpos, length(), y.chars(), y.length());
  if (last >= 0) last += y.length();
  return _substr(0, last);
}

SubString String::through(const Regex& r, int startpos)
{
  int mlen;
  int first = r.search(chars(), length(), mlen, startpos);
  if (first >= 0) first += mlen;
  return _substr(0, first);
}

SubString String::through(char c, int startpos)
{
  int last = search(startpos, length(), c);
  if (last >= 0) last += 1;
  return _substr(0, last);
}

SubString String::through(const char*_LIBDEF_FAR_CPP_PTR t, int startpos)
{
  int tlen = slen(t);
  int last = search(startpos, length(), t, tlen);
  if (last >= 0) last += tlen;
  return _substr(0, last);
}

SubString String::after(const String& y, int startpos)
{
  int first = search(startpos, length(), y.chars(), y.length());
  if (first >= 0) first += y.length();
  return _substr(first, length() - first);
}

SubString String::after(const SubString& y, int startpos)
{
  int first = search(startpos, length(), y.chars(), y.length());
  if (first >= 0) first += y.length();
  return _substr(first, length() - first);
}

SubString String::after(char c, int startpos)
{
  int first = search(startpos, length(), c);
  if (first >= 0) first += 1;
  return _substr(first, length() - first);
}

SubString String::after(const Regex& r, int startpos)
{
  int mlen;
  int first = r.search(chars(), length(), mlen, startpos);
  if (first >= 0) first += mlen;
  return _substr(first, length() - first);
}

SubString String::after(const char*_LIBDEF_FAR_CPP_PTR t, int startpos)
{
  int tlen = slen(t);
  int first = search(startpos, length(), t, tlen);
  if (first >= 0) first += tlen;
  return _substr(first, length() - first);
}

SubString String::from(const String& y, int startpos)
{
  int first = search(startpos, length(), y.chars(), y.length());
  return _substr(first, length() - first);
}

SubString String::from(const SubString& y, int startpos)
{
  int first = search(startpos, length(), y.chars(), y.length());
  return _substr(first, length() - first);
}

SubString String::from(const Regex& r, int startpos)
{
  int mlen;
  int first = r.search(chars(), length(), mlen, startpos);
  return _substr(first, length() - first);
}

SubString String::from(char c, int startpos)
{
  int first = search(startpos, length(), c);
  return _substr(first, length() - first);
}

SubString String::from(const char*_LIBDEF_FAR_CPP_PTR t, int startpos)
{
  int tlen = slen(t);
  int first = search(startpos, length(), t, tlen);
  return _substr(first, length() - first);
}



/*
 * split/join
 */


int split(const String& src, String results[], int n, const String& sep)
{
#ifndef _LIBRARY_WORKAROUND
  String x = src;
#else
  String x(src);
#endif
  const char*_LIBDEF_FAR_CPP_PTR s = x.chars();
  int sl = x.length();
  int i = 0;
  int pos = 0;
  while (i < n && pos < sl)
  {
    int p = x.search(pos, sl, sep.chars(), sep.length());
    if (p < 0)
      p = sl;
    results[i].rep = Salloc(results[i].rep, &(s[pos]), p - pos, p - pos);
    i++;
    pos = p + sep.length();
  }
  return i;
}

int split(const String& src, String results[], int n, const Regex& r)
{
#ifndef _LIBRARY_WORKAROUND
  String x = src;
#else
  String x(src);
#endif
  const char*_LIBDEF_FAR_CPP_PTR s = x.chars();
  int sl = x.length();
  int i = 0;
  int pos = 0;
  int p, matchlen;
  while (i < n && pos < sl)
  {
    p = r.search(s, sl, matchlen, pos);
    if (p < 0)
      p = sl;
    results[i].rep = Salloc(results[i].rep, &(s[pos]), p - pos, p - pos);
    i++;
    pos = p + matchlen;
  }
  return i;
}


#if defined(__GNUG__) && !defined(_G_NO_NRV)
#define RETURN(r) return
#define RETURNS(r) return r;
#define RETURN_OBJECT(TYPE, NAME) /* nothing */
#else /* _G_NO_NRV */
#define RETURN(r) return r
#define RETURNS(r) /* nothing */
#define RETURN_OBJECT(TYPE, NAME) TYPE NAME;
#endif

String join(String src[], int n, const String& separator) RETURNS(x)
{
  RETURN_OBJECT(String,x)
#ifndef _LIBRARY_WORKAROUND
  String sep = separator;
#else
  String sep(separator);
#endif
  int xlen = 0;
  int i;
  for (i = 0; i < n; ++i)
    xlen += src[i].length();
  xlen += (n - 1) * sep.length();

  x.rep = Sresize (x.rep, xlen);

  int j = 0;
  
  for (i = 0; i < n - 1; ++i)
  {
    ncopy(src[i].chars(), &(x.rep->s[j]), src[i].length());
    j += src[i].length();
    ncopy(sep.chars(), &(x.rep->s[j]), sep.length());
    j += sep.length();
  }
  ncopy0(src[i].chars(), &(x.rep->s[j]), src[i].length());
  RETURN(x);
}
  
/*
 misc
*/

    
StrRep* Sreverse(const StrRep* src, StrRep* dest)
{
  int n = src->len;
  if (src != dest)
    dest = Salloc(dest, src->s, n, n);
  if (n > 0)
  {
    char* a = dest->s;
    char* b = &(a[n - 1]);
    while (a < b)
    {
      char t = *a;
      *a++ = *b;
      *b-- = t;
    }
  }
  return dest;
}


StrRep* Supcase(const StrRep* src, StrRep* dest)
{
  int n = src->len;
  if (src != dest) dest = Salloc(dest, src->s, n, n);
  char* p = dest->s;
  char* e = &(p[n]);
  for (; p < e; ++p) if (islower(*p)) *p = toupper(*p);
  return dest;
}

StrRep* Sdowncase(const StrRep* src, StrRep* dest)
{
  int n = src->len;
  if (src != dest) dest = Salloc(dest, src->s, n, n);
  char* p = dest->s;
  char* e = &(p[n]);
  for (; p < e; ++p) if (isupper(*p)) *p = tolower(*p);
  return dest;
}

StrRep* Scapitalize(const StrRep* src, StrRep* dest)
{
  int n = src->len;
  if (src != dest) dest = Salloc(dest, src->s, n, n);

  char* p = dest->s;
  char* e = &(p[n]);
  for (; p < e; ++p)
  {
    int at_word;
    if (at_word = islower(*p))
      *p = toupper(*p);
    else 
      at_word = isupper(*p) || isdigit(*p);

    if (at_word)
    {
      while (++p < e)
      {
        if (isupper(*p))
          *p = tolower(*p);
  /* A '\'' does not break a word, so that "Nathan's" stays
     "Nathan's" rather than turning into "Nathan'S". */
        else if (!islower(*p) && !isdigit(*p) && (*p != '\''))
          break;
      }
    }
  }
  return dest;
}

#if defined(__GNUG__) && !defined(_G_NO_NRV)

String replicate(char c, int n) return w;
{
  w.rep = Sresize(w.rep, n);
  char* p = w.rep->s;
  while (n-- > 0) *p++ = c;
  *p = 0;
}

String replicate(const String& y, int n) return w
{
  int len = y.length();
  w.rep = Sresize(w.rep, n * len);
  char* p = w.rep->s;
  while (n-- > 0)
  {
    ncopy(y.chars(), p, len);
    p += len;
  }
  *p = 0;
}

String common_prefix(const String& x, const String& y, int startpos) return r;
{
  const char*_LIBDEF_FAR_CPP_PTR xchars = x.chars();
  const char*_LIBDEF_FAR_CPP_PTR ychars = y.chars();
  const char*_LIBDEF_FAR_CPP_PTR xs = &(xchars[startpos]);
  const char*_LIBDEF_FAR_CPP_PTR ss = xs;
  const char*_LIBDEF_FAR_CPP_PTR topx = &(xchars[x.length()]);
  const char*_LIBDEF_FAR_CPP_PTR ys = &(ychars[startpos]);
  const char*_LIBDEF_FAR_CPP_PTR topy = &(ychars[y.length()]);
  int l;
  for (l = 0; xs < topx && ys < topy && *xs++ == *ys++; ++l);
  r.rep = Salloc(r.rep, ss, l, l);
}

String common_suffix(const String& x, const String& y, int startpos) return r;
{
  const char*_LIBDEF_FAR_CPP_PTR xchars = x.chars();
  const char*_LIBDEF_FAR_CPP_PTR ychars = y.chars();
  const char*_LIBDEF_FAR_CPP_PTR xs = &(xchars[x.length() + startpos]);
  const char*_LIBDEF_FAR_CPP_PTR botx = xchars;
  const char*_LIBDEF_FAR_CPP_PTR ys = &(ychars[y.length() + startpos]);
  const char*_LIBDEF_FAR_CPP_PTR boty = ychars;
  int l;
  for (l = 0; xs >= botx && ys >= boty && *xs == *ys ; --xs, --ys, ++l);
  r.rep = Salloc(r.rep, ++xs, l, l);
}

#else

String replicate(char c, int n)
{
  String w;
  w.rep = Sresize(w.rep, n);
  char* p = w.rep->s;
  while (n-- > 0) *p++ = c;
  *p = 0;
  return w;
}

String replicate(const String& y, int n)
{
  String w;
  int len = y.length();
  w.rep = Sresize(w.rep, n * len);
  char* p = w.rep->s;
  while (n-- > 0)
  {
    ncopy(y.chars(), p, len);
    p += len;
  }
  *p = 0;
  return w;
}

String common_prefix(const String& x, const String& y, int startpos)
{
  String r;
  const char*_LIBDEF_FAR_CPP_PTR xchars = x.chars();
  const char*_LIBDEF_FAR_CPP_PTR ychars = y.chars();
  const char*_LIBDEF_FAR_CPP_PTR xs = &(xchars[startpos]);
  const char*_LIBDEF_FAR_CPP_PTR ss = xs;
  const char*_LIBDEF_FAR_CPP_PTR topx = &(xchars[x.length()]);
  const char*_LIBDEF_FAR_CPP_PTR ys = &(ychars[startpos]);
  const char*_LIBDEF_FAR_CPP_PTR topy = &(ychars[y.length()]);
  int l;
  for (l = 0; xs < topx && ys < topy && *xs++ == *ys++; ++l);
  r.rep = Salloc(r.rep, ss, l, l);
  return r;
}

String common_suffix(const String& x, const String& y, int startpos) 
{
  String r;
  const char*_LIBDEF_FAR_CPP_PTR xchars = x.chars();
  const char*_LIBDEF_FAR_CPP_PTR ychars = y.chars();
  const char*_LIBDEF_FAR_CPP_PTR xs = &(xchars[x.length() + startpos]);
  const char*_LIBDEF_FAR_CPP_PTR botx = xchars;
  const char*_LIBDEF_FAR_CPP_PTR ys = &(ychars[y.length() + startpos]);
  const char*_LIBDEF_FAR_CPP_PTR boty = ychars;
  int l;
  for (l = 0; xs >= botx && ys >= boty && *xs == *ys ; --xs, --ys, ++l);
  r.rep = Salloc(r.rep, ++xs, l, l);
  return r;
}

#endif

// IO

istream& operator>>(istream& s, String& x)
{
#ifndef _LIBRARY_WORKAROUND
  if (!s.ipfx(0) || (!(s.flags() & ios::skipws) && !ws(s)))
#else
  istream* help=&ws(s);
  if (!s.ipfx(0) || (!(s.flags() & ios::skipws) && !help))
#endif
  {
    s.clear(ios::failbit|s.rdstate()); // Redundant if using GNU iostreams.
    return s;
  }
  int ch;
  int i = 0;
  x.rep = Sresize(x.rep, 20);
  register streambuf *sb = s.rdbuf();
  while ((ch = sb->sbumpc()) != EOF)
  {
    if (isspace(ch))
      break;
    if (i >= x.rep->sz - 1)
      x.rep = Sresize(x.rep, i+1);
    x.rep->s[i++] = ch;
  }
  x.rep->s[i] = 0;
  x.rep->len = i;
  int new_state = s.rdstate();
  if (i == 0) new_state |= ios::failbit;
  if (ch == EOF) new_state |= ios::eofbit;
  s.clear(new_state);
  return s;
}

int readline(istream& s, String& x, char terminator, int discard)
{
  if (!s.ipfx(0))
    return 0;
  int ch;
  int i = 0;
  x.rep = Sresize(x.rep, 80);
  register streambuf *sb = s.rdbuf();
  while ((ch = sb->sbumpc()) != EOF)
  {
    if (ch != terminator || !discard)
    {
      if (i >= x.rep->sz - 1)
        x.rep = Sresize(x.rep, i+1);
      x.rep->s[i++] = ch;
    }
    if (ch == terminator)
      break;
  }
  x.rep->s[i] = 0;
  x.rep->len = i;
  if (ch == EOF) s.clear(ios::eofbit|s.rdstate());
  return i;
}


ostream& operator<<(ostream& s, const SubString& x)
{ 
  const char*_LIBDEF_FAR_CPP_PTR a = x.chars();
  const char*_LIBDEF_FAR_CPP_PTR lasta = &(a[x.length()]);
  while (a < lasta)
    s.put(*a++);
  return(s);
}

// from John.Willis@FAS.RI.CMU.EDU

int String::freq(const SubString& y) const
{
  int found = 0;
  for (unsigned int i = 0; i < length(); i++) 
    if (match(i,length(),0,y.chars(), y.length())>= 0) found++;
  return(found);
}

int String::freq(const String& y) const
{
  int found = 0;
  for (unsigned int i = 0; i < length(); i++) 
    if (match(i,length(),0,y.chars(),y.length()) >= 0) found++;
  return(found);
}

int String::freq(const char*_LIBDEF_FAR_CPP_PTR t) const
{
  int found = 0;
  for (unsigned int i = 0; i < length(); i++) 
    if (match(i,length(),0,t) >= 0) found++;
  return(found);
}

int String::freq(char c) const
{
  int found = 0;
  for (unsigned int i = 0; i < length(); i++) 
    if (match(i,length(),0,&c,1) >= 0) found++;
  return(found);
}


int String::OK() const
{
  if (rep == 0             // don't have a rep
    || rep->len > rep->sz     // string oustide bounds
    || rep->s[rep->len] != 0)   // not null-terminated
      error("invariant failure");
  return 1;
}

int SubString::OK() const
{
#ifndef _HICROSS_3
  int v = S != (const char*)0; // have a String;
#else
  int v = ( compare(S, (const char*)0)!=0 ); // have a String;
#endif
  v &= S.OK();                 // that is legal
  v &= pos + len >= S.rep->len;// pos and len within bounds
  if (!v) S.error("SubString invariant failure");
  return v;
}


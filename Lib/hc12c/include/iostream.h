/*****************************************************

     iostream.h - ANSI-C++ library: iostreams
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

/*  This is part of libio/iostream, providing -*- C++ -*- input/output. 
Copyright (C) 1993 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

#include "comp.h"

#ifndef _IOSTREAM_H
#ifdef __GNUG__
#pragma interface
#endif
#define _IOSTREAM_H

#include <streamb.h>

#ifndef _G_HAVE_BOOL
#define _G_HAVE_BOOL 0
#endif

#ifndef _G_CLOG_CONFLICT
#define _G_CLOG_CONFLICT 0
#endif

#pragma push
#pragma MESSAGE DISABLE C2013
#pragma MESSAGE DISABLE C1855

extern "C++" {
class istream; class ostream;
typedef ios& (*__manip)(ios&);
typedef istream& (*__imanip)(istream&);
typedef ostream& (*__omanip)(ostream&);

extern istream& ws(istream& ins);
extern ostream& flush(ostream& outs);
extern ostream& endl(ostream& outs);
extern ostream& ends(ostream& outs);

class ostream : virtual public ios
{
    // NOTE: If fields are changed, you must fix _fake_ostream in stdstreams.C!
    void do_osfx();
  public:
    ostream() { }
#ifdef _VIRTUAL_IMPLEMENTATION
    ostream(_ios_fields *iosf) {
#if 0
      this->init ((streambuf *)iosf, NULL);
#else
      _strbuf=iosf->_strbuf;
      _tie=iosf->_tie;
      _width=iosf->_width;
      _flags=iosf->_flags;
      _fill=iosf->_fill;
      _state=iosf->_state;
      _exceptions=iosf->_exceptions;
      _precision=iosf->_precision;
      _arrays=iosf->_arrays;
#endif
    }
#endif
    ostream(streambuf* sb, ostream* tied=NULL);
    int opfx() {
  if (!good()) return 0; else { if (_tie) _tie->flush(); return 1;} }
    void osfx() {
      if (flags() & (ios::unitbuf|ios::stdio))
        do_osfx();
    }
    ostream& flush();
    ostream& put(char c) { _strbuf->sputc(c); return *this; }
    ostream& write(const char*_LIBDEF_FAR_CPP_PTR s, streamsize n);
#if !defined(_NYI_OVERLOADING)    
    ostream& write(const unsigned char *s, streamsize n)
      { return write((const char*_LIBDEF_FAR_CPP_PTR)s, n);}
#endif      
#if !defined(_NYI_PLAIN_CHAR)
    ostream& write(const signed char *s, streamsize n)
      { return write((const char*_LIBDEF_FAR_CPP_PTR)s, n);}
#endif
#if !defined(_NYI_OVERLOADING)
    ostream& write(const void *s, streamsize n)
      { return write((const char*_LIBDEF_FAR_CPP_PTR)s, n);}
#endif
    ostream& seekp(streampos);
    ostream& seekp(streamoff, _seek_dir);
    streampos tellp();
    ostream& form(const char*_LIBDEF_FAR_CPP_PTR format ...);
    ostream& vform(const char*_LIBDEF_FAR_CPP_PTR format, _IO_va_list args);
#if !defined(_NYI_PLAIN_CHAR)
    ostream& operator<<(char c);
    ostream& operator<<(unsigned char c) { return (*this) << (char)c; }
#else
    ostream& operator<<(signed char c);
    ostream& operator<<(unsigned char c) { return (*this) << (signed char)c; }
#endif    
#if !defined(_NYI_PLAIN_CHAR)
    ostream& operator<<(signed char c) { return (*this) << (char)c; }
#endif
    ostream& operator<<(const char*_LIBDEF_FAR_CPP_PTR s);
#if !defined(_NYI_OVERLOADING)
    ostream& operator<<(const unsigned char *s)
  { return (*this) << (const char*_LIBDEF_FAR_CPP_PTR)s; }
#endif
#if !defined(_NYI_PLAIN_CHAR)  
    ostream& operator<<(const signed char *s)
  { return (*this) << (const char*_LIBDEF_FAR_CPP_PTR)s; }
#endif
#ifndef _LIBRARY_WORKAROUND
    ostream& operator<<(const void *p);
#endif
    ostream& operator<<(int n);
    ostream& operator<<(unsigned int n);
    ostream& operator<<(long n);
    ostream& operator<<(unsigned long n);
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
    ostream& operator<<(long long n);
    ostream& operator<<(unsigned long long n);
#endif
#if !defined(_NYI_EXPL_OP_CALL)
    ostream& operator<<(short n) {return operator<<((int)n);}
    ostream& operator<<(unsigned short n) {return operator<<((unsigned int)n);}
#endif
#if _G_HAVE_BOOL
#if !defined(_NYI_EXPL_OP_CALL)
    ostream& operator<<(bool b) { return operator<<((int)b); }
#endif    
#endif
    ostream& operator<<(double n);
#if !defined(_NYI_EXPL_OP_CALL)    
    ostream& operator<<(float n) { return operator<<((double)n); }
#if !defined(_NYI_LONG_DOUBLE)
    ostream& operator<<(long double n) { return operator<<((double)n); }
#endif
#endif
    ostream& operator<<(__omanip func) { return (*func)(*this); }
    ostream& operator<<(__manip func) {(*func)(*this); return *this;}
    ostream& operator<<(streambuf*);
};

class istream : virtual public ios
{
    // NOTE: If fields are changed, you must fix _fake_istream in stdstreams.C!
protected:
    _IO_size_t _gcount;

    int _skip_ws();
  public:
    istream() { _gcount = 0; }
#ifdef _VIRTUAL_IMPLEMENTATION
    istream(_ios_fields *iosf) {
#if 0
      this->init ((streambuf *)iosf, NULL);
      _gcount = 0;
#else
      _strbuf=iosf->_strbuf;
      _tie=iosf->_tie;
      _width=iosf->_width;
      _flags=iosf->_flags;
      _fill=iosf->_fill;
      _state=iosf->_state;
      _exceptions=iosf->_exceptions;
      _precision=iosf->_precision;
      _arrays=iosf->_arrays;
#endif
    }
#endif
    istream(streambuf* sb, ostream*tied=NULL);
    ~istream();
#if !defined(_NYI_PLAIN_CHAR)
    istream& get(char* ptr, int len, char delim = '\n');
#else
    istream& get(signed char* ptr, int len, char delim = '\n');
#endif
    istream& get(unsigned char* ptr, int len, char delim = '\n')
#if __S12LISA__	
  { return get((signed char*)ptr, len, delim); }
#else
  { return get((char*)ptr, len, delim); }
#endif  
    istream& get(char& c);
#if !defined(_NYI_PLAIN_CHAR)
    istream& get(unsigned char& c) { return get((char&)c); }
#endif    
#if !defined(_NYI_PLAIN_CHAR)
    istream& getline(char* ptr, int len, char delim = '\n');
#else
    istream& getline(signed char* ptr, int len, char delim = '\n');
#endif
    istream& getline(unsigned char* ptr, int len, char delim = '\n')
#if __S12LISA__
  { return getline((signed char*)ptr, len, delim); }
#else
  { return getline((char*)ptr, len, delim); }
#endif  
#if !defined(_NYI_PLAIN_CHAR)    
    istream& get(signed char& c)  { return get((char&)c); }
    istream& get(signed char* ptr, int len, char delim = '\n')
  { return get((char*)ptr, len, delim); }
    istream& getline(signed char* ptr, int len, char delim = '\n')
#if __S12LISA__
  { return getline((signed char*)ptr, len, delim); }
#else
  { return getline((char*)ptr, len, delim); }
#endif  
#endif
#if __S12LISA__
    istream& read(char *ptr, long int n);
#else
    istream& read(char *ptr, streamsize int n);
#endif
#if !defined(_NYI_OVERLOADING)    
    istream& read(unsigned char *ptr, streamsize n)
      { return read((char*)ptr, n); }
#endif
#if !defined(_NYI_PLAIN_CHAR)
    istream& read(signed char *ptr, streamsize n)
      { return read((char*)ptr, n); }
#endif
#if !defined(_NYI_OVERLOADING)
    istream& read(void *ptr, streamsize n)
      { return read((char*)ptr, n); }
#endif      
    istream& get(streambuf& sb, char delim = '\n');
    istream& gets(char **s, char delim = '\n');
    int ipfx(int need = 0) {
  if (!good()) { set(ios::failbit); return 0; }
  else {
    if (_tie && (need == 0 || rdbuf()->in_avail() < need)) _tie->flush();
    if (!need && (flags() & ios::skipws)) return _skip_ws();
    else return 1;
  }
    }
    int ipfx0() { // Optimized version of ipfx(0).
  if (!good()) { set(ios::failbit); return 0; }
  else {
    if (_tie) _tie->flush();
    if (flags() & ios::skipws) return _skip_ws();
    else return 1;
  }
    }
    int ipfx1() { // Optimized version of ipfx(1).
  if (!good()) { set(ios::failbit); return 0; }
  else {
    if (_tie && rdbuf()->in_avail() == 0) _tie->flush();
    return 1;
  }
    }
    void isfx() { }
    int get() { if (!ipfx1()) return EOF;
    else { int ch = _strbuf->sbumpc();
           if (ch == EOF) set(ios::eofbit);
           return ch;
         } }
    int peek();
    _IO_size_t gcount() { return _gcount; }
    istream& ignore(int n=1, int delim = EOF);
    int sync ();
    istream& seekg(streampos);
    istream& seekg(streamoff, _seek_dir);
    streampos tellg();
    istream& putback(char ch) {
  if (good() && _strbuf->sputbackc(ch) == EOF) clear(ios::badbit);
  return *this;}
    istream& unget() {
  if (good() && _strbuf->sungetc() == EOF) clear(ios::badbit);
  return *this;}
#ifndef _NYI_LIB
    istream& scan(const char*_LIBDEF_FAR_CPP_PTR format ...);
#else
    istream& scan(const char*_LIBDEF_FAR_CPP_PTR format ...) {
      exit(1);
      return *this;
    }
#endif
    istream& vscan(const char*_LIBDEF_FAR_CPP_PTR format, _IO_va_list args);


    istream& operator>>(char*);
#if !defined(_NYI_EXPL_OP_CALL)    
    istream& operator>>(unsigned char* p) { return operator>>((char*)p); }
#if !defined(_NYI_PLAIN_CHAR)    
    istream& operator>>(signed char*p) { return operator>>((char*)p); }
#endif    
#endif
    istream& operator>>(char& c);
#if !defined(_NYI_EXPL_OP_CALL)    
    istream& operator>>(unsigned char& c) {return operator>>((char&)c);}
#if !defined(_NYI_PLAIN_CHAR)
    istream& operator>>(signed char& c) {return operator>>((char&)c);}
#endif
#endif
    istream& operator>>(int&);
    istream& operator>>(long&);
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
    istream& operator>>(long long&);
    istream& operator>>(unsigned long long&);
#endif
    istream& operator>>(short&);
    istream& operator>>(unsigned int&);
    istream& operator>>(unsigned long&);
    istream& operator>>(unsigned short&);
#if _G_HAVE_BOOL
    istream& operator>>(bool&);
#endif
    istream& operator>>(float&);
    istream& operator>>(double&);
#if !defined(_NYI_LONG_DOUBLE)    
    istream& operator>>(long double&);
#endif    
    istream& operator>>( __manip func) {(*func)(*this); return *this;}
#if !defined(_NYI_FPTR_UNDEF_CLASS_PARAM)
    istream& operator>>(__imanip func) { return (*func)(*this); }
#endif    
    istream& operator>>(streambuf*);
};

class iostream : public istream, public ostream
{
  public:
    iostream() { }
    iostream(streambuf* sb, ostream*tied=NULL);
};

class _IO_istream_withassign : public istream {
public:
  _IO_istream_withassign& operator=(istream&);
};

class _IO_ostream_withassign : public ostream {
public:
  _IO_ostream_withassign& operator=(ostream&);
};

extern _IO_istream_withassign cin;
// clog->rdbuf() == cerr->rdbuf()
extern _IO_ostream_withassign cout, cerr;

extern _IO_ostream_withassign clog
#if _G_CLOG_CONFLICT
__asm__ ("__IO_clog")
#endif
;

struct Iostream_init { } ;  // required for compatibility to AT&T library.

#if !defined(_NYI_OVERLOADING)
inline ios& dec(ios& i)
{ i.setf(ios::dec, ios::dec|ios::hex|ios::oct); return i; }
inline ios& hex(ios& i)
{ i.setf(ios::hex, ios::dec|ios::hex|ios::oct); return i; }
inline ios& oct(ios& i)
{ i.setf(ios::oct, ios::dec|ios::hex|ios::oct); return i; }
#endif


} // extern "C++"

#pragma pop

#endif /*!_IOSTREAM_H*/

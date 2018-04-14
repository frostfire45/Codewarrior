/*****************************************************
     alloc.c - ANSI-C library: memory management
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#include <stdlib.h>
#include <string.h>
#include <heap.h>
#include <libdefs.h>

typedef struct _header *LIBDEF_HEAP_DPTRQ HeaderPtr;

#ifndef DIS_OPT_0
  #define DIS_OPT_0 0 /* use char/0/1 by default */
#endif

#ifndef DIS_OPT_1
  #define DIS_OPT_1 0
#endif

#ifndef DIS_OPT_2
  #define DIS_OPT_2 0
#endif

#ifndef DIS_OPT_3
  #define DIS_OPT_3 0
#endif

typedef struct _header {
#if DIS_OPT_0
  unsigned int inuse;
#else
  unsigned char inuse;
#endif
  HeaderPtr next;
  size_t    size;
} header;

#ifdef __XGATE__
#define heap_end    _X_heap_end /* XGATE heap */
#define free_ptr    _X_free_ptr /* XGATE heap */
#endif /* __XGATE__ */

static HeaderPtr heap_end  = NULL; /* pointer */
static HeaderPtr free_ptr  = NULL; /* pointer to free list */
#if DIS_OPT_1
static char HeapInitialized; /* initialized to zero */
#endif


#if DIS_OPT_0
#define FREE 0x7067
#define USED 0x5047
#else
#define FREE 0
#define USED 1
#endif

/* the following macros are required for HC08/RS08 compliance with MISRA 10.1 REQ - because size_t is target-dependent */
#if defined (__HC08__) || defined (__RS08__) /* __SIZE_T_IS_UINT__ defined */
#define SIZE_T__1 (size_t)1
#define SIZE_T__LIBDEF_HEAPSIZE (size_t)LIBDEF_HEAPSIZE
#else
#define SIZE_T__1 1
#define SIZE_T__LIBDEF_HEAPSIZE LIBDEF_HEAPSIZE
#endif

/*lint -e946 , MISRA 17.2 REQ & MISRA 17.3 REQ, this file implements the memory management standard library functions; the compiler compares/subtracts the addresses pointed to by the two operands */

/*****************************************************/
void *LIBDEF_HEAP_DPTRQ malloc (size_t nbytes) {
  size_t nunits;
  HeaderPtr p, pl;

  if (nbytes == (size_t)0) {
    return NULL;
  }
#if DIS_OPT_1
  if (!HeapInitialized) { /* first call to malloc, init heap first block */
    _heap_[0] = LIBDEF_HEAPSIZE; /* the free block has the size of the heap */
    HeapInitialized = TRUE;
  }
#endif
  nunits = ( ( (nbytes + sizeof(header)) - SIZE_T__1 ) / sizeof(header) ) + SIZE_T__1; /*lint !e960 , MISRA 10.1 REQ, the result of sizeof() has type size_t */
#if DIS_OPT_1
  if ( (heap_end == NULL) && (free_ptr == NULL) ) {
#else
  if (heap_end == NULL) {
#endif
    /* setup heap */
   free_ptr        = (header *LIBDEF_HEAP_DPTRQ) (void *LIBDEF_HEAP_DPTRQ) &_heap_[0];
#if DIS_OPT_1
    free_ptr->size  = _heap_[0] / sizeof(header);
#else
    free_ptr->size  = SIZE_T__LIBDEF_HEAPSIZE / sizeof(header); /*lint !e960 , MISRA 10.1 REQ, the result of sizeof() has type size_t */
#endif
    free_ptr->next  = NULL;
#if DIS_OPT_0
    free_ptr->inuse = (unsigned int)FREE;
#else
    free_ptr->inuse = (unsigned char)FREE;
#endif    
    heap_end        = (free_ptr + free_ptr->size) - 1;
  }
  if (free_ptr == NULL) {
    return (NULL);     /* free list is empty; no more memory */
  } else {
    pl = NULL;
    p  = free_ptr;
    while (p != NULL) {
      if (p->size >= nunits) {
        if (p->size > nunits) {
          /* block is bigger, so break it */
          p[nunits].next  = p->next;           /* link to next free block */
          p[nunits].size  = p->size - nunits;  /* size of new free block  */
#if DIS_OPT_0
          p[nunits].inuse = (unsigned int)FREE;
#else
          p[nunits].inuse = (unsigned char)FREE;
#endif          
          p->size = nunits;                    /* new size of block       */
          p->next = p + nunits;                /* ptr to next free block  */
        }
        if (pl == NULL) {
          /* we use the first block */
          free_ptr = p->next;
        } else {
          pl->next = p->next;
        }
        
        if (p->inuse != (unsigned int)FREE) {
          _heapcrash_(p, ERR_HEAP_ALLOC);
        }
        p->next  = NULL;
#if DIS_OPT_0
        p->inuse = (unsigned int)USED;
#else
        p->inuse = (unsigned char)USED;
#endif
        return (++p);
      }
      pl = p;
      p  = p->next;    /* next block */
    }
  }
  return (NULL);    /* All free blocks are to small */
} /* end malloc */

/*****************************************************/

void free(void *LIBDEF_HEAP_DPTRQ ap)
{
  HeaderPtr p, pNext, pPrev, pEnd, pPrevEnd;
  
  if (ap == NULL) {
    return;
  }
  p = (HeaderPtr)ap; 
  --p;
  if ( (p < (HeaderPtr) (void *LIBDEF_HEAP_DPTRQ) &_heap_[0]) || (p > heap_end) ) {
    _heapcrash_(p, ERR_HEAP_RANGE);
    return;
  }
  if (p->inuse != (unsigned int)USED) {
    _heapcrash_(p, ERR_HEAP_FREE);
  }

#if DIS_OPT_0
  p->inuse = (unsigned int)FREE;
#else
  p->inuse = (unsigned char)FREE;
#endif  
  p->next  = NULL;

  if ( free_ptr == NULL) {
    /* freelist is empty */
    free_ptr = p;
    return;
  }

  pNext = free_ptr;
  pPrev = NULL;
  while((pNext != NULL) && (pNext < p)) {
    pPrev = pNext;
    pNext = pNext->next;
  } /* end while */
  
  pEnd = p + p->size;
#if DIS_OPT_2
  if (pNext == pEnd && pNext != NULL) {
#else
  if (pNext == pEnd /* && pNext != NULL : pNext cannot be NULL because it is equal to pEnd */) {
#endif
  /* concatenate p and pNext */
    p->size += pNext->size;
    p->next  = pNext->next;
  } else if (pNext == p){
#if DIS_OPT_2
    if (p->size > pNext->size) {
      pNext->size = p->size;
    }
#else /* 'pNext == p' implies that 'p->size == pNext->size' */
    _heapcrash_(p, ERR_HEAP_FREE); /* block to be released was already in free list */
#endif
  } else if ((pNext != NULL) && (pEnd > pNext)) {
#if DIS_OPT_2
    p->size = pNext - p;
    p->next = pNext;
#else
    _heapcrash_(p, ERR_HEAP_FREE); /* block to be released was completely contained in element in free list */
#endif
  } else {
    p->next = pNext;
  }
  if (pPrev == NULL){
  /* p must be the first free block in the list */
    free_ptr = p;
    return;
  }
  pPrevEnd = pPrev + pPrev->size;
  if (p == pPrevEnd) {
  /* concatenate pPrev and p */
    pPrev->size += p->size;
    pPrev->next  = p->next;
    return;
  }
  if (pPrevEnd > p) {
#if DIS_OPT_2
    if (pPrev->next < pEnd) {
      pPrev->next = p->next;
      pPrev->size = p - pPrev + p->size;
    }
#else
    _heapcrash_(p, ERR_HEAP_FREE); /* start of block to be released was contained in element in free list */
#endif
    return;
  }
  pPrev->next = p;
} /* end free */

/*****************************************************/

void *LIBDEF_HEAP_DPTRQ calloc (size_t n, size_t size)
{
  void          *LIBDEF_HEAP_DPTRQ save;

  size = (size_t)(n*size);
  save = malloc(size);
  if (save != NULL) {
#if DIS_OPT_3
    unsigned char *LIBDEF_HEAP_DPTRQ rv;
    rv = save;
    while(size--) {
      *rv++ = 0;
    }
#else
    (void)memset(save, 0, size);
#endif
  }
  return (save);
} /* end calloc */

/*****************************************************/

void *LIBDEF_HEAP_DPTRQ realloc (void *LIBDEF_HEAP_DPTRQ ptr, size_t size)
{
  size_t  nunits;
  HeaderPtr p, p1, p2;
  void     *LIBDEF_HEAP_DPTRQ rv;

  if (ptr == NULL) {
    return ( malloc(size) );
  }
  if (size == (size_t)0) {
    free(ptr);
    return (NULL);
  } else {
    /* calculate size of new block in allocation units */
    nunits = ( ( (size + sizeof(header)) - SIZE_T__1 ) / sizeof(header) ) + SIZE_T__1; /*lint !e960 , MISRA 10.1 REQ, the result of sizeof() has type size_t */

    p = (HeaderPtr)ptr;
    --p;    /* get pointer to internal struct */

    if ( (p < (HeaderPtr) (void *LIBDEF_HEAP_DPTRQ) &_heap_[0]) || (p > heap_end) ) {
      _heapcrash_(p, ERR_HEAP_RANGE);
      return (NULL);
    }

    if (p->size == nunits) {
      return (ptr);    /* if new blocksizze == old; do nothing */
    }
    if (p->size > nunits) { /* if new block will be smaller, so break it */
      p[nunits].size  = p->size - nunits;    /* create new block */
      p[nunits].next  = NULL;
#if DIS_OPT_0
      p[nunits].inuse = (unsigned int)USED;  /* mark it used */
#else                                        
     p[nunits].inuse = (unsigned char)USED;  /* mark it used */
#endif
      p->size = nunits;            /* resize old block */

      /*lint -e{586} accept 'free' */
      /*lint -e{424} deallocation is appropriate */
      free(p + nunits + 1);       /* free the new unused block */
      return (ptr);
    }
      
    if ( (p + p->size) < heap_end ) {
      /* this is not the last block in pool */
      p1 = p + p->size;        /* p1 = pointer to next block */
      if (p1->inuse == (unsigned int)FREE) {
        /* the fallowing block is free !! */
        size = p1->size + p->size;  /* calculate size of cat-blocks */ 

        if  (size > nunits) { 
          /* the superblock will be to big, so break it */ 

          p2 = p + nunits;    /* p2 = pointer to new unused block */

          p2->next  = p1->next;        /* break block and link them */
          p2->size  = size - nunits;    /* together in the free list */
          p1->size -= p2->size;
#if DIS_OPT_0          
          p2->inuse = (unsigned int)FREE;
#else
          p2->inuse = (unsigned char)FREE;
#endif          
          p1->next  = p2;

          size = nunits;
        }

        if (size == nunits) {
          /* unlink the next block from the free list and concatenate */
          if (free_ptr == p1) {
            /* it's the first pointer in free list */
            free_ptr = p1->next;    /* unlink the block */

            p->size += p1->size;    /* adjust size */
            return (++p);
          }
          
          p2 = free_ptr;
          while (p2->next != NULL) {
            /* search the block */
            if (p2->next == p1) {
              /* we found it */
              p2->next = p1->next;    /* unlink the block */
              
              p->size += p1->size;    /* adjust size */
              return (++p);
            }
            p2 = p2->next;
          }
          _heapcrash_(p1, ERR_HEAP_REALL);
        }
      }
    }

    /* There was no way to adjust the block size in place.
       The only chance left is to allocate a new block.
      */
    rv =  malloc(size);
    if (rv != NULL) {
      (void)memcpy(rv, ptr, size);
      free(ptr);
    }
  }
  return (rv);
} /* end realloc */

/*lint +e946 */

/*****************************************************/
/* end alloc.h */

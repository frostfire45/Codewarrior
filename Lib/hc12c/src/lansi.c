/******************************************************************************
  FILE        : lansi.c
  PURPOSE     : C library floating point routines wrapper functions
                  for the large memory model
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
 ******************************************************************************/

/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

#ifdef __LARGE__ /* only needed for large memory model */
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__DOUBLE_IS_IEEE32__)
double NEAR _modf    (double x, double *__near int_part);
#else /* __DOUBLE_IS_IEEE64__ */
void NEAR _frexp   (double* __near structret, double x,int *__near exp);
void NEAR _modf    (double* __near structret, double x, double *__near int_part);
void NEAR _ldexp (double* __near structret, double x, int exp);
double NEAR frexp(double x, int *exp);
double NEAR ldexp(double x, int exp);
#endif
float NEAR _frexpf   (float x,int *__near exp);
float NEAR _modff    (float x, float *__near int_part);
float NEAR frexpf    (float x,int *exp);
double NEAR modf     (double x, double *int_part);
float NEAR modff     (float x, float *int_part);

#if defined(__DOUBLE_IS_IEEE64__)
double NEAR frexp   (double x,int *exp) {
  int rexp;
  double res;
  _frexp(&res, x, &rexp);
  *exp= rexp;
  return res;
}
#endif

float NEAR frexpf   (float x,int *exp) {
  int rexp;
  float res= _frexpf(x, &rexp);
  *exp= rexp;
  return res;
}

#if defined(__DOUBLE_IS_IEEE32__)
double NEAR modf    (double x, double *int_part) {
  double rint_part;
  double res= _modf(x, &rint_part);
  *int_part=rint_part;
  return res;
}
#else
double NEAR modf    (double x, double *int_part) {
  double rint_part;
  double res;
  _modf(&res, x, &rint_part);
  *int_part=rint_part;
  return res;
}
#endif

float NEAR modff    (float x, float *int_part) {
  float rint_part;
  float res= _modff(x, &rint_part);
  *int_part=rint_part;
  return res;
}

#if defined(__DOUBLE_IS_IEEE64__)
double NEAR ldexp(double x, int exp) {
  double res;
  _ldexp(&res, x, exp);
  return res;
}
#endif

#ifdef __cplusplus
}
#endif


#endif
/*lint --e{766} non_bank.sgm is not a regular header file, it contains a conditionally compiled CODE_SEG pragma */

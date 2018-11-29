/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CODEGEN_PREFIX
  #define NAMESPACE_CONCAT(NS, ID) _NAMESPACE_CONCAT(NS, ID)
  #define _NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) phi_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

static const casadi_int casadi_s0[14] = {10, 1, 0, 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
static const casadi_int casadi_s1[6] = {2, 1, 0, 2, 0, 1};
static const casadi_int casadi_s2[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s3[23] = {1, 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

casadi_real casadi_sq(casadi_real x) { return x*x;}

/* phi:(i0[10],i1[2])->(o0,o1[1x10]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a4, a5, a6, a7, a8, a9;
  a0=arg[1] ? arg[1][0] : 0;
  a0=casadi_sq(a0);
  a1=arg[1] ? arg[1][1] : 0;
  a1=casadi_sq(a1);
  a0=(a0+a1);
  a1=arg[0] ? arg[0][0] : 0;
  a2=sin(a1);
  a3=cos(a2);
  a3=(a0*a3);
  a4=(a3*a1);
  a5=arg[0] ? arg[0][1] : 0;
  a6=sin(a5);
  a7=cos(a6);
  a7=(a0*a7);
  a8=(a7*a5);
  a4=(a4+a8);
  a8=arg[0] ? arg[0][2] : 0;
  a9=sin(a8);
  a10=cos(a9);
  a10=(a0*a10);
  a11=(a10*a8);
  a4=(a4+a11);
  a11=arg[0] ? arg[0][3] : 0;
  a12=sin(a11);
  a13=cos(a12);
  a13=(a0*a13);
  a14=(a13*a11);
  a4=(a4+a14);
  a14=arg[0] ? arg[0][4] : 0;
  a15=sin(a14);
  a16=cos(a15);
  a16=(a0*a16);
  a17=(a16*a14);
  a4=(a4+a17);
  a17=arg[0] ? arg[0][5] : 0;
  a18=sin(a17);
  a19=cos(a18);
  a19=(a0*a19);
  a20=(a19*a17);
  a4=(a4+a20);
  a20=arg[0] ? arg[0][6] : 0;
  a21=sin(a20);
  a22=cos(a21);
  a22=(a0*a22);
  a23=(a22*a20);
  a4=(a4+a23);
  a23=arg[0] ? arg[0][7] : 0;
  a24=sin(a23);
  a25=cos(a24);
  a25=(a0*a25);
  a26=(a25*a23);
  a4=(a4+a26);
  a26=arg[0] ? arg[0][8] : 0;
  a27=sin(a26);
  a28=cos(a27);
  a28=(a0*a28);
  a29=(a28*a26);
  a4=(a4+a29);
  a29=arg[0] ? arg[0][9] : 0;
  a30=sin(a29);
  a31=cos(a30);
  a31=(a0*a31);
  a32=(a31*a29);
  a4=(a4+a32);
  if (res[0]!=0) res[0][0]=a4;
  a4=cos(a1);
  a2=sin(a2);
  a1=(a0*a1);
  a2=(a2*a1);
  a4=(a4*a2);
  a3=(a3-a4);
  if (res[1]!=0) res[1][0]=a3;
  a3=cos(a5);
  a6=sin(a6);
  a5=(a0*a5);
  a6=(a6*a5);
  a3=(a3*a6);
  a7=(a7-a3);
  if (res[1]!=0) res[1][1]=a7;
  a7=cos(a8);
  a9=sin(a9);
  a8=(a0*a8);
  a9=(a9*a8);
  a7=(a7*a9);
  a10=(a10-a7);
  if (res[1]!=0) res[1][2]=a10;
  a10=cos(a11);
  a12=sin(a12);
  a11=(a0*a11);
  a12=(a12*a11);
  a10=(a10*a12);
  a13=(a13-a10);
  if (res[1]!=0) res[1][3]=a13;
  a13=cos(a14);
  a15=sin(a15);
  a14=(a0*a14);
  a15=(a15*a14);
  a13=(a13*a15);
  a16=(a16-a13);
  if (res[1]!=0) res[1][4]=a16;
  a16=cos(a17);
  a18=sin(a18);
  a17=(a0*a17);
  a18=(a18*a17);
  a16=(a16*a18);
  a19=(a19-a16);
  if (res[1]!=0) res[1][5]=a19;
  a19=cos(a20);
  a21=sin(a21);
  a20=(a0*a20);
  a21=(a21*a20);
  a19=(a19*a21);
  a22=(a22-a19);
  if (res[1]!=0) res[1][6]=a22;
  a22=cos(a23);
  a24=sin(a24);
  a23=(a0*a23);
  a24=(a24*a23);
  a22=(a22*a24);
  a25=(a25-a22);
  if (res[1]!=0) res[1][7]=a25;
  a25=cos(a26);
  a27=sin(a27);
  a26=(a0*a26);
  a27=(a27*a26);
  a25=(a25*a27);
  a28=(a28-a25);
  if (res[1]!=0) res[1][8]=a28;
  a28=cos(a29);
  a30=sin(a30);
  a0=(a0*a29);
  a30=(a30*a0);
  a28=(a28*a30);
  a31=(a31-a28);
  if (res[1]!=0) res[1][9]=a31;
  return 0;
}

CASADI_SYMBOL_EXPORT int phi(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT void phi_incref(void) {
}

CASADI_SYMBOL_EXPORT void phi_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int phi_n_in(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_int phi_n_out(void) { return 2;}

CASADI_SYMBOL_EXPORT const char* phi_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* phi_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* phi_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* phi_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    case 1: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int phi_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif

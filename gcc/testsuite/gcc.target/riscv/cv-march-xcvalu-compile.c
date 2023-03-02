/* { dg-do compile } */
/* { dg-require-effective-target cv_alu } */
/* { dg-options "-march=rv32i_xcvalu -mabi=ilp32" } */

#include <stdint.h>

extern int d;
extern int e;
extern int f;

void foo0(int a, int b)
{
  d = __builtin_riscv_cv_alu_addN (a, b, 0);
  e = __builtin_riscv_cv_alu_addN (a, b, 7);
  f = __builtin_riscv_cv_alu_addN (a, b, 31);
}

void foo1(int a, int b, int c)
{
  d = __builtin_riscv_cv_alu_addN (a, b, c);
}

void foo2(int a, int b)
{
  d = __builtin_riscv_cv_alu_addRN (a, b, 0);
  e = __builtin_riscv_cv_alu_addRN (a, b, 7);
  f = __builtin_riscv_cv_alu_addRN (a, b, 31);
}

int foo3(int a, int b, int c)
{
  return __builtin_riscv_cv_alu_addRN (a, b, c);
}

void foo4(int a, int b)
{
  d = __builtin_riscv_cv_alu_adduN (a, b, 0);
  e = __builtin_riscv_cv_alu_adduN (a, b, 7);
  f = __builtin_riscv_cv_alu_adduN (a, b, 31);
}

int foo5(int a, int b, int c)
{
  return __builtin_riscv_cv_alu_adduN (a, b, c);
}

void foo6(int a, int b)
{
  d = __builtin_riscv_cv_alu_adduRN (a, b, 0);
  e = __builtin_riscv_cv_alu_adduRN (a, b, 7);
  f = __builtin_riscv_cv_alu_adduRN (a, b, 31);
}

int foo7(int a, int b, int c)
{
  return __builtin_riscv_cv_alu_adduRN (a, b, c);
}

int foo8(int a, int b)
{
  return __builtin_riscv_cv_alu_clip (a, 15);
}

int foo9(int a, int b)
{
  return __builtin_riscv_cv_alu_clip (a, 10);
}

int foo10(int a, int b)
{
  return __builtin_riscv_cv_alu_clipu (a, 15);
}

int foo11(int a, int b)
{
  return __builtin_riscv_cv_alu_clipu (a, 10);
}

int foo12(int a)
{
  return __builtin_riscv_cv_alu_extbs (a);
}

int foo13(int a)
{
  return __builtin_riscv_cv_alu_extbz (a);
}

int foo14(int b)
{
  return __builtin_riscv_cv_alu_exths (b);
}

int foo15(int a)
{
  return __builtin_riscv_cv_alu_exthz (a);
}

int foo16(int a, int b)
{
  return __builtin_riscv_cv_alu_max (a, b);
}

int foo17(int a, int b)
{
  return __builtin_riscv_cv_alu_maxu (a, b);
}

int foo18(int a, int b)
{
  return __builtin_riscv_cv_alu_min (a, b);
}

int foo19(int a, int b)
{
  return __builtin_riscv_cv_alu_minu (a, b);
}

int foo20(int a, int b)
{
  return __builtin_riscv_cv_alu_slet (a, b);
}

int foo21(unsigned int a, unsigned int b)
{
  return __builtin_riscv_cv_alu_sletu (a, b);
}

void foo22(int a, int b)
{
  d = __builtin_riscv_cv_alu_subN (a, b, 0);
  e = __builtin_riscv_cv_alu_subN (a, b, 7);
  f = __builtin_riscv_cv_alu_subN (a, b, 31);
}

int foo23(int a, int b, int c)
{
  return __builtin_riscv_cv_alu_subN (a, b, c);
}

void foo24(int a, int b)
{
  d = __builtin_riscv_cv_alu_subRN (a, b, 0);
  e = __builtin_riscv_cv_alu_subRN (a, b, 7);
  f = __builtin_riscv_cv_alu_subRN (a, b, 31);
}

int foo25(int a, int b, int c)
{
  return __builtin_riscv_cv_alu_subRN (a, b, c);
}

void foo26(int a, int b)
{
  d = __builtin_riscv_cv_alu_subuN (a, b, 0);
  e = __builtin_riscv_cv_alu_subuN (a, b, 7);
  f = __builtin_riscv_cv_alu_subuN (a, b, 31);
}

int foo27(int a, int b, int c)
{
  return __builtin_riscv_cv_alu_subuN (a, b, c);
}

void foo28(int a, int b)
{
  d = __builtin_riscv_cv_alu_subuRN (a, b, 0);
  e = __builtin_riscv_cv_alu_subuRN (a, b, 7);
  f = __builtin_riscv_cv_alu_subuRN (a, b, 31);
}

int foo29(int a, int b, int c)
{
  return __builtin_riscv_cv_alu_subuRN (a, b, c);
}

/* { dg-final { scan-assembler-times "cv\.addN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),0" 1 } } */
/* { dg-final { scan-assembler-times "cv\.addN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),7" 1 } } */
/* { dg-final { scan-assembler-times "cv\.addN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),31" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.addNr" 1 } } */
/* { dg-final { scan-assembler-times "cv\.addRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),0" 1 } } */
/* { dg-final { scan-assembler-times "cv\.addRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),7" 1 } } */
/* { dg-final { scan-assembler-times "cv\.addRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),31" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.addRNr" 1 } } */
/* { dg-final { scan-assembler-times "cv\.adduN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),0" 1 } } */
/* { dg-final { scan-assembler-times "cv\.adduN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),7" 1 } } */
/* { dg-final { scan-assembler-times "cv\.adduN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),31" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.adduNr" 1 } } */
/* { dg-final { scan-assembler-times "cv\.adduRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),0" 1 } } */
/* { dg-final { scan-assembler-times "cv\.adduRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),7" 1 } } */
/* { dg-final { scan-assembler-times "cv\.adduRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),31" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.adduRNr" 1 } } */
/* { dg-final { scan-assembler-times "cv\.clip\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),5" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.clipr" 1 } } */
/* { dg-final { scan-assembler-times "cv\.clipu\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),5" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.clipur" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.extbs" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.extbz" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.exths" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.exthz" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.max" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.maxu" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.min" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.minu" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.slet" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.sletu" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),0" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),7" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),31" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.subNr" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),0" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),7" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),31" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.subRNr" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subuN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),0" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subuN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),7" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subuN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),31" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.subuNr" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subuRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),0" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subuRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),7" 1 } } */
/* { dg-final { scan-assembler-times "cv\.subuRN\t\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),\(\?\:t\[0-6\]\|a\[0-7\]\|s\[1-11\]\),31" 1 } } */
/* { dg-final { scan-assembler-times "cv\\.subuRNr" 1 } } */

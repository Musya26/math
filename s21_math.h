#ifndef S21MATH_S21_MATH_H
#define S21MATH_S21_MATH_H

#define S21_PI 3.141592653589793238462643383279
#define S21_NAN (0.0 / 0.0)
#define S21_INF_POS (1.0 / 0.0)
#define S21_INF_NEG (-1.0 / 0.0)
#define S21_LN2 0.693147180559945309417232
#define S21_E 2.718281828459045235360287471352
#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_NEG || x == S21_INF_POS)
#define S21_SQRT_EPS 1e-20l
#define S21_EPS 1e-12

int compareDoubles(double num1, double num2, int precision);
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_sqrt(double x);
long double s21_log(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_pow(double base, double exp);
#endif  // S21MATH_S21_MATH_H

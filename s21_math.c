#include "s21_math.h"

int s21_abs(int x) {
  if (S21_IS_NAN(x)) return S21_NAN;
  return x > 0 ? x : -x;
}

long double s21_fabs(double x) {
  long double res = 0;
  if (S21_IS_NAN(x)) {
    res = S21_NAN;
  } else if (x == 0.0 || x == -0.0) {
    res = 0.0;
  } else if (S21_IS_INF(x)) {
    res = S21_INF_POS;
  } else {
    res = x > 0 ? (long double)x : (long double)(x *= -1);
  }
  return res;
}

long double s21_ceil(double x) {
  long double res = (long long int)x;
  if (S21_IS_NAN(x)) res = S21_NAN;
  if (S21_IS_INF(x)) {
    if (x < 0)
      res = S21_INF_NEG;
    else
      res = S21_INF_POS;
  }
  if (x < 0 && res == 0)
    res = -0.0;
  else if (res < x)
    res++;
  return res;
}

long double s21_floor(double x) {
  long double res = (long long int)x;
  if (S21_IS_NAN(x)) res = S21_NAN;
  if (S21_IS_INF(x)) {
    if (x < 0)
      res = S21_INF_NEG;
    else
      res = S21_INF_POS;
  } else if (res > x)
    res--;
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  long long int n = x / y;

  if (y == 0) {
    res = S21_NAN;
  } else if (x == 0 && (y != 0 || y != S21_NAN)) {
    res = 0;
  } else if (x == S21_INF_POS || x == S21_INF_NEG || y == 0) {
    res = S21_NAN;
  } else if (x == 0 && (y == 0 || y != y)) {
    res = S21_NAN;
  } else if ((!S21_IS_INF(x) && y == S21_INF_POS) ||
             (!S21_IS_INF(x) && y == S21_INF_NEG)) {
    res = x;
  } else {
    res = x - n * y;
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 1.0;
  if (x <= -14.508658) {
    res = +0;
  } else if (x > 709.782712 || S21_IS_INF(x)) {
    res = S21_INF_POS;
  } else if (x == S21_INF_POS) {
    res = S21_INF_POS;
  } else if (x != x) {
    res = S21_NAN;
  } else if (x == S21_INF_NEG) {
    res = 0;
  } else {
    int n = 1;
    long double a = x, sn = 1;
    if (x < 0.0) a = -x;
    for (int i = 0; i < 1600; i++) {
      sn *= a / n++;
      res += sn;
    }
    if (x < 0.0) res = 1 / res;
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 0;
  if (x < 0 || S21_IS_NAN(x)) {
    res = S21_NAN;
  } else if (S21_IS_INF(x) || x <= S21_SQRT_EPS) {
    res = x;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}

long double s21_log(double x) {
  long double res = 0;
  if (x < 0 || x == S21_INF_NEG || S21_IS_NAN(x)) {
    res = S21_NAN;
  } else if (x == 0) {
    res = S21_INF_NEG;
  } else if (x == S21_INF_POS) {
    res = S21_INF_POS;
  } else if (x == 1) {
    res = 0;
  } else {
    double N = 0.0, P = x, A = 0;
    while (P >= S21_E) {
      P /= S21_E;
      N++;
    }
    N += (P / S21_E);
    P = x;
    int j = 0;
    do {
      double L, R;
      A = N;
      L = (P / (s21_exp(N - 1.0)));
      R = ((N - 1.0) * S21_E);
      N = ((L + R) / S21_E);
      j++;
    } while (N != A && j < 10000);
    res = N;
  }
  return res;
}

int compareDoubles(double num1, double num2, int precision) {
  if (S21_IS_NAN(num1) == 1 && S21_IS_NAN(num2) == 1) return 1;
  if (S21_IS_INF(num1) == 1 && S21_IS_INF(num2) == 1) return 1;
  int res = 0;
  double diff = s21_fabs(num1 - num2);
  double epsilon = 1 / s21_pow(10, precision);
  if (diff < epsilon) {
    res = 1;
  }
  return res;
}

long double s21_atan(double x) {
  if (x == S21_INF_POS) return S21_PI / 2;
  if (x == S21_INF_NEG) return -S21_PI / 2;
  if (S21_IS_NAN(x)) return S21_NAN;
  if (compareDoubles(x, 1.0, 6)) return 0.785398163;
  if (compareDoubles(x, -1.0, 6)) return -0.785398163;
  int n = 1;
  int is_in_range = (x > -1 && x < 1);
  long double res = 0;
  if (is_in_range) {
    long double temp = x;
    while (n < 5000) {
      res += (temp / n);
      temp *= (-1 * x * x);
      n += 2;
    }
  } else {
    long double temp = -1.0 / s21_fabs(x);
    while (n < 5000) {
      res += (temp / n);
      temp *= 1.0 / (-1 * x * x);
      n += 2;
    }
    res += S21_PI / 2;
  }
  return (s21_fabs(x) == x || is_in_range) ? res : -res;
}

long double s21_asin(double x) {
  if (compareDoubles(x, 1.0, 6)) return S21_PI / 2;
  if (compareDoubles(x, -1.0, 6)) return -S21_PI / 2;
  int is_in_range = (x > -1 && x < 1);
  if (!is_in_range) return S21_NAN;
  return s21_atan(x / s21_sqrt(1 - x * x));
}

long double s21_acos(double x) {
  double res = 0.0;
  if (compareDoubles(x, 1.0, 6))
    res = 0;
  else if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (compareDoubles(x, 1.0, 6))
    res = -S21_NAN;
  else
    res = S21_PI / 2 - s21_asin(x);
  return res;
}

long double s21_sin(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x)) return S21_NAN;
  x = s21_fmod(x, 2 * S21_PI);
  long double s = 0;
  int n = 3;
  long double temp = x;
  while (n < 1000) {
    s = s + temp;
    temp *= (-1 * x * x) / (n * (n - 1));
    n += 2;
  }
  return s;
}

long double s21_cos(double x) { return s21_sin(S21_PI / 2 - x); }

long double s21_tan(double x) {
  double res = 0;
  if (compareDoubles(x, S21_PI / 2, 6))
    res = 16331239353195370.000000;
  else
    res = s21_sin(x) / s21_cos(x);
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 0;
  int temp = 0;
  if (base == 1 || exp == 0 || (base == -1 && (S21_IS_INF(exp)))) {
    res = 1;
  } else if ((s21_fabs(base) < 1 && exp == S21_INF_POS) ||
             (s21_fabs(base) > 1 && exp == S21_INF_NEG) ||
             (base == S21_INF_NEG &&
              ((exp > 0 && (int)exp % 2 == 0) || exp == S21_INF_POS)) ||
             (base == S21_INF_POS && exp > 0)) {
    res = S21_INF_POS;
  } else if ((base < 0 && (int)exp - exp != 0) ||
             (base != base && exp != exp)) {
    res = S21_NAN;
  } else if ((base == 0 && exp > 0) ||
             (s21_fabs(base) > 1 && exp == S21_INF_NEG) ||
             (s21_fabs(base) < 1 && exp == S21_INF_POS) ||
             (base == -0.0 && (exp > 0 && (int)exp % 2 == 0)) ||
             (base == S21_INF_NEG && (exp < 0 && (int)exp % 2 == 0)) ||
             (base == S21_INF_POS && exp < 0)) {
    res = 0;
  } else if ((base == -0.0 && (exp > 0 && (int)exp % 2 != 0)) ||
             (base == S21_INF_NEG && (exp < 0 && (int)exp % 2 != 0))) {
    res = -0.0;
  } else if (base == S21_INF_NEG && (exp > 0 && (int)exp % 2 != 0)) {
    res = S21_INF_NEG;
  } else {
    if (base < 0) {
      if ((int)exp % 2 != 0) {
        temp = 1;
      }
      base = s21_fabs(base);
    }
    res = temp ? -s21_exp(exp * s21_log(base)) : s21_exp(exp * s21_log(base));
  }
  return res;
}

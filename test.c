#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), S21_EPS);
  ck_assert_double_nan(s21_acos(-1000));
  ck_assert_double_nan(s21_acos(1000));
  ck_assert_double_nan(s21_acos(10));
  ck_assert_double_nan(s21_acos(S21_INF_POS));
  ck_assert_double_nan(s21_acos(S21_INF_NEG));
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), S21_EPS);
  ck_assert_ldouble_nan(s21_asin(S21_INF_POS));
  ck_assert_ldouble_nan(s21_asin(S21_INF_NEG));
  ck_assert_ldouble_nan(s21_asin(-100));
  ck_assert_ldouble_nan(s21_asin(100));
}
END_TEST

START_TEST(s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF_POS), atan(S21_INF_POS), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF_NEG), atan(S21_INF_NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(100), atan(100), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-100), atan(-100), S21_EPS);
}
END_TEST

START_TEST(s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(0.0), cos(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(20), cos(20), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-2), cos(-2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(2), cos(2), S21_EPS);
  ck_assert_ldouble_nan(s21_cos(S21_INF_POS));
  ck_assert_ldouble_nan(s21_cos(S21_INF_NEG));
}
END_TEST

START_TEST(s21_exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(S21_INF_NEG), exp(S21_INF_NEG), S21_EPS);
  ck_assert_ldouble_eq(s21_exp(S21_INF_POS), exp(S21_INF_POS));
}

START_TEST(s21_sin_test) {
  ck_assert_ldouble_nan(s21_sin(S21_INF_POS));
  ck_assert_ldouble_nan(s21_sin(S21_INF_NEG));
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(0.0), sin(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-3), sin(-3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(3), sin(3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(1000), sin(1000), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-1000), sin(-1000), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(2.5), sqrt(2.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.6), sqrt(0.6), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(34.9), sqrt(34.9), S21_EPS);
  ck_assert_ldouble_eq(s21_sqrt(S21_INF_POS), sqrt(S21_INF_POS));
  ck_assert_ldouble_nan(s21_sqrt(S21_INF_NEG));
  ck_assert_ldouble_nan(s21_sqrt(-2.5));
}
END_TEST

START_TEST(s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(-1.2), tan(-1.2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(1.2), tan(1.2), S21_EPS);
  ck_assert_ldouble_nan(s21_tan(S21_INF_POS));
  ck_assert_ldouble_nan(s21_tan(S21_INF_NEG));
}
END_TEST

START_TEST(s21_log_test) {
  ck_assert_ldouble_eq(s21_log(S21_INF_POS), log(S21_INF_POS));
  ck_assert_ldouble_nan(s21_log(S21_INF_NEG));
  ck_assert_ldouble_eq(s21_log(0), log(0));
  ck_assert_ldouble_eq(s21_log(1), log(1));
  ck_assert_ldouble_nan(s21_log(-2.7));
  ck_assert_ldouble_eq_tol(s21_log(1.43), log(1.43), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_log(2.73), log(2.73), S21_EPS);
}
END_TEST

START_TEST(s21_abs_test) {
  ck_assert_uint_eq(s21_abs(12), abs(12));
  ck_assert_uint_eq(s21_abs(-3), abs(-3));
  ck_assert_uint_eq(s21_abs(10030), abs(10030));
}
END_TEST

START_TEST(s21_ceil_test) {
  ck_assert_ldouble_eq(s21_ceil(S21_INF_POS), ceil(S21_INF_POS));
  ck_assert_ldouble_eq(s21_ceil(S21_INF_NEG), ceil(S21_INF_NEG));
  ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0));
  ck_assert_ldouble_eq(s21_ceil(0.33), ceil(0.33));
  ck_assert_ldouble_eq(s21_ceil(34562), ceil(34562));
}
END_TEST

START_TEST(s21_floor_test) {
  ck_assert_ldouble_eq(s21_floor(S21_INF_POS), floor(S21_INF_POS));
  ck_assert_ldouble_eq(s21_floor(S21_INF_NEG), floor(S21_INF_NEG));
  ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0));
  ck_assert_ldouble_eq(s21_floor(-3.556), floor(-3.556));
  ck_assert_ldouble_eq(s21_floor(1.43), floor(1.43));
}
END_TEST

START_TEST(s21_fmod_test) {
  ck_assert_ldouble_nan(s21_fmod(2.54, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(0.0, 0.0));
  ck_assert_ldouble_eq_tol(s21_fmod(3.345, 5), fmod(3.345, 5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-1.65, S21_INF_POS),
                           fmod(-1.65, S21_INF_POS), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-1.0004, S21_INF_NEG),
                           fmod(-1.0004, S21_INF_NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0, 34.5), fmod(0.0, 34.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(3.345, S21_INF_POS),
                           fmod(3.345, S21_INF_POS), S21_EPS);
  ck_assert_ldouble_nan(s21_fmod(S21_INF_POS, -1.044));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_NEG, 2.44));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_POS, 0.0));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_NEG, 0.0));
  ck_assert_ldouble_nan(s21_fmod(-12.3, 0.0));
}
END_TEST

START_TEST(s21_fabs_test) {
  ck_assert_ldouble_eq(s21_fabs(S21_INF_POS), fabs(S21_INF_POS));
  ck_assert_ldouble_eq(s21_fabs(S21_INF_NEG), fabs(S21_INF_NEG));
  ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0));
  ck_assert_ldouble_eq(s21_fabs(-32.45), fabs(-32.45));
  ck_assert_ldouble_eq(s21_fabs(1.43), fabs(1.43));
}
END_TEST

START_TEST(s21_pow_test) {
  ck_assert_ldouble_eq(s21_pow(0.0, -5.0), pow(0.0, -5.0));
  ck_assert_ldouble_eq(s21_pow(0.0, -1.3), pow(0.0, -1.3));
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), S21_EPS);
  ck_assert_ldouble_eq(s21_pow(0.0, -2.0), pow(0.0, -2.0));
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 3.0), pow(0.0, 3.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 4.0), pow(0.0, 4.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-1.0, S21_INF_POS), pow(-1.0, S21_INF_POS),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-1.0, S21_INF_NEG), pow(-1.0, S21_INF_NEG),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1.0, S21_NAN), pow(1.0, S21_NAN), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1.0, -3.0), pow(1.0, -3.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1.0, -2.0), pow(1.0, -2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_POS, 0.0), pow(S21_INF_POS, 0.0),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_NEG, 0.0), pow(S21_INF_NEG, 0.0),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, 0.0), pow(S21_NAN, 0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(2.75, 0.0), pow(2.75, 0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-1.3, 0.0), pow(-1.3, 0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(2, 2), pow(2, 2), S21_EPS);
  ck_assert_ldouble_nan(s21_pow(-1.3, 1.2));
  ck_assert_ldouble_nan(s21_pow(-1.0, -1.2));
  ck_assert_ldouble_eq(s21_pow(2.0, S21_INF_POS), pow(2.0, S21_INF_POS));
  ck_assert_ldouble_eq(s21_pow(2.2, S21_INF_POS), pow(2.2, S21_INF_POS));
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_NEG, -3.0), pow(S21_INF_NEG, -3.0),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_NEG, -6.0), pow(S21_INF_NEG, -6.0),
                           S21_EPS);
  ck_assert_ldouble_eq(s21_pow(S21_INF_NEG, 5.0), pow(S21_INF_NEG, 5.0));
  ck_assert_ldouble_eq(s21_pow(S21_INF_NEG, 2.0), pow(S21_INF_NEG, 2.0));
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_POS, -1.0), pow(S21_INF_POS, -1.0),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_POS, -4.0), pow(S21_INF_POS, -4.0),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_POS, -2.02), pow(S21_INF_POS, -2.02),
                           S21_EPS);
  ck_assert_ldouble_eq(s21_pow(S21_INF_POS, 3.0), pow(S21_INF_POS, 3.0));
  ck_assert_ldouble_eq(s21_pow(S21_INF_POS, 2.0), pow(S21_INF_POS, 2.0));
  ck_assert_ldouble_eq(s21_pow(S21_INF_POS, 4.456), pow(S21_INF_POS, 4.456));
}
END_TEST

int main() {
  Suite *suite = suite_create("TEST");
  TCase *tCase = tcase_create("TEST");
  SRunner *sRunner = srunner_create(suite);

  double FAILED = 0;
  suite_add_tcase(suite, tCase);
  tcase_add_test(tCase, s21_acos_test);
  tcase_add_test(tCase, s21_asin_test);
  tcase_add_test(tCase, s21_atan_test);
  tcase_add_test(tCase, s21_cos_test);
  tcase_add_test(tCase, s21_exp_test);
  tcase_add_test(tCase, s21_sin_test);
  tcase_add_test(tCase, s21_sqrt_test);
  tcase_add_test(tCase, s21_tan_test);
  tcase_add_test(tCase, s21_log_test);
  tcase_add_test(tCase, s21_abs_test);
  tcase_add_test(tCase, s21_ceil_test);
  tcase_add_test(tCase, s21_floor_test);
  tcase_add_test(tCase, s21_fmod_test);
  tcase_add_test(tCase, s21_fabs_test);
  tcase_add_test(tCase, s21_pow_test);

  srunner_run_all(sRunner, CK_ENV);
  FAILED = srunner_ntests_failed(sRunner);
  srunner_free(sRunner);
  return !FAILED ? EXIT_SUCCESS : EXIT_FAILURE;
}

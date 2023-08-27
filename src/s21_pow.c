#include "s21_math.h"

long double s21_pow(double base, double e) { 
    if (is_nan(base) || is_nan(e)) {
        return S21_NAN;
    }    

    if ((base == 0) && (e < 0)) {
        return S21_INF;
    }
    if ((base == S21_INF) && (e < 0)) {
        return 0;
    }
    if (base == 1) {
        return 1;
    }
    if (s21_fabs(e) < EPS) {
        return 1;
    }
    if ((base < 0) && (e == -S21_INF)) {
        return 1;
    }






    if ((base < 0) && is_finite(e) && ((double)(int)e != e)) {
        return S21_NAN;
    }



    if (base < 0) {
        if (s21_fmod(e, 2) == 0) {
            return s21_pow(-base, e);
        } else {
            return -s21_pow(-base, e);
        }
    }

    long double rezult = 0;
    rezult = s21_exp(e * s21_log(base));
    return rezult;;

}

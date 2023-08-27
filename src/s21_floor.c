#include "s21_math.h"


long double s21_floor(double x) {
    if (is_nan(x)) {
        return S21_NAN;
    }
    if (is_inf(x)) {
        if (x > 0) {
            return +S21_INF;
        } else {
            return -S21_INF;
        }
    }
    long double rezult = (double)(int)x;
    if (x < 0) {
        if (rezult > x) {
            rezult --;
        }

    }
    return rezult;
}

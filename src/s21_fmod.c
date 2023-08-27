#include "s21_math.h"

long double s21_fmod(double x, double y) {
    if (is_nan(x) || is_nan(y)) {
        return S21_NAN;
    }
    long double rezult = 0;
    rezult = (double)(int)(x/y);
    rezult = x -rezult*y;
    return rezult;
}

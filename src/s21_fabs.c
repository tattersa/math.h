#include "s21_math.h"
#include <math.h>


long double s21_fabs(double x) {
    if (is_nan(x) || !is_finite(x))
        return S21_NAN;
    return x = (x > 0) ? x : -x;
}



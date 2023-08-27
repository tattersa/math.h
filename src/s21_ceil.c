#include "s21_math.h"


long double s21_ceil(double x) {
    double res = 0.0;
    if (x > 0) {
        for (int i = 0; i < x; i++) {
            res += 1.0;
        }
    } else if (x < 0) {
        for (int i = 0; i > x; i--) {
            res -= 1.0;
        }
        res += 1;
    } else {
        res = 0.0;
    }
    return res;
}


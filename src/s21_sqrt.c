#include "s21_math.h"

double rough_estimation(double s);
/* Корень вычисляется методом Ньютона. */
/* Начальное значение (первое приближение) вычисляется алгоритмом */
/* из википедии в функции rough_estimation*/


long double s21_sqrt(double x) {
   if (is_nan(x) || (x < 0)) {
        return S21_NAN;
   }
    if (is_inf(x)) {
        if (x > 0) {
            return +S21_INF;
        } else {
            return S21_NAN;
        }
    }
    if (x < EPS) {
        return 0;
    }
    double rezult = rough_estimation(x);
    const double eps = 1e-12;
    while (s21_fabs(x - rezult * rezult) > eps) {
        rezult = 0.5 * (rezult + x / rezult);
    }
    return rezult;
}

double rough_estimation(double s) {
    int d = 0;
    double k = s;
    if (s >= 1) {
        while (k >= 1) {
            k /= 10;
            d ++;
        }
    } else {
        while ((int)(k * 10) == 0) {
            if (s == 0) {
                d = 0;
                break;
            }
            k *= 10;
            d --;
        }
    }
    double n = 0;
    double rezult = 0;
    if ((int)d % 2 == 0) {
        n = (d - 2) / 2;
        rezult = 6;
    } else {
        n = (d - 1) / 2;
        rezult = 2;
    }
    for (int i = 0; i < s21_fabs(n); i ++) {
        if (n > 0) {
            rezult *= 10;
        } else {
            rezult /= 10;
        }
    }
    return rezult;
}

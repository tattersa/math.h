#include "s21_math.h"
#include <math.h>
/* #include <stdlib.h> */
/* double* reduce_argument_1(double *buff, double x); */ 
/* int reduce_argument_2(double x); */
/* long double do_log(double x); */


/* int main() { */
/*     /1* double x = 0.00003; *1/ */
/*     /1* for (int i = 0; i <= 100; i ++) { *1/ */
/*     /1*     s21_log(x); *1/ */
/*     /1*     x *= 13; *1/ */
/*     /1* } *1/ */
/*     /1* double x = 0; *1/ */
/*     /1* for (int i = 0; i < 19; i++) { *1/ */
/*     /1*     if (i % 4 == 0) *1/ */ 
/*     /1*         printf("\n"); *1/ */
/*     /1*     printf("%20.15Lf%s", logl(x), ","); *1/ */
/*     /1*     x += 0.1; *1/ */
/*     /1* } *1/ */

/*     /1* printf("%s%Lf%10s%Lf","s21:   ", do_log(1.978), "orig: ", logl(1.978)); *1/ */    


/*     double x = 1.9; */
/*     for (int i = 0; i < 100; i++) { */
/*         s21_log(x); */
/*         printf("%s%.20Lf%s%.20Lf", "s21:   ", do_log(x), "orig:   ", logl(x)); */
/*         printf("\n"); */
/*         x += 0.01; */
/*     } */
/*     return 0; */
/* } */


/* long double s21_log(double x) { */
/*     double buff[2] = {0}; */
/*     reduce_argument_1(buff, x); */
/*     /1* int max_index = reduce_argument_2(buff[1]); *1/ */
/*     /1* printf("%s%f%s%f%s%f", "x:   ", x, "reduced_1:  ", buff[1], "reduced_2:  ", buff[1] + ln_arguments[max_index]); *1/ */
/*     /1* printf("\n"); *1/ */
/*     /1* printf("%f", reduce_argument_2(buff[1])); *1/ */
/*     return x; */
/* } */

/* double* reduce_argument_1(double *buff, double x) { */
/*     double k = x; */
/*     buff[1] = x; */
/*     int multiplier = 0; */
/*     if (x > 2) { */
/*         while (k >= 2) { */
/*             k /= 2; */
/*             multiplier ++; */
/*          } */
/*     } */
/*     if (x < 0.5) { */
/*         while (k <= 0.5) { */
/*             k *= 2; */
/*             multiplier --; */
/*         } */
        
/*     } */
/*         buff[0] = multiplier; */
/*         for (int i = 0; i < abs(multiplier); i++) { */
/*             if (multiplier > 0) { */
/*                 buff[1] = buff[1] / 2; */
/*             } else { */
/*                 buff[1] = buff[1] * 2; */
/*             } */
/*         } */
/*     return buff; */
/* } */

/* int reduce_argument_2(double x) { */
/*     double max = -10; */
/*     int max_index = -1; */
/*     for (int i = 0; i < 19; i ++) { */
/*         if ((x + ln_arguments[i] > max) && (x + ln_arguments[i] <= 2)) { */
/*             max = ln_arguments[i]; */
/*             max_index = i; */
/*         } */
/*     } */
/*     return max_index; */ 
/* } */

/* long double do_log(double x) { */
/*     return 0.667829 + 0.512821 * (x - 1.95) - 0.131492 * (x - 1.95) * (x - 1.95) + 0.0449547 * (x - 1.95) * (x - 1.95) * (x - 1.95) - 0.0172903 * (x - 1.95) * (x - 1.95) * (x-1.95) * (x - 1.95) + 0.00709344 * (x - 1.95) *(x - 1.95) *(x - 1.95) *(x - 1.95) *(x - 1.95); */
/* } */

long double s21_log(double x) {
    if (is_nan(x) || (x < 0)) {
        return S21_NAN;
    }
    if (x < EPS) {
        return -S21_INF;
    }
    if (is_inf(x)) {
        return S21_INF;
    }
    if (s21_fabs(x - 1) < EPS) {
        return 0;
    }
    long double a = 1;
    long double b = 4 / x / 1125899906842624;
    long double buff_a = 0;
    long double buff_b = 0;
    for (int i = 0; i < 20; i++) {
        buff_a = (a + b) / 2;
        buff_b = sqrt(a * b);
        a = buff_a;
        b = buff_b;
        /* printf("%.10Lf", b); */
        /* printf("\n"); */
    }
    long double rezult = S21_PI / 2 / b - 50 * S21_LN_2;
    return rezult;
    
}






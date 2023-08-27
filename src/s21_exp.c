#include "s21_math.h"



double* reduce_argument_1(double *buff, double x);
int reduce_argument_2(double x);
long double do_exp(double x);

/* Функция reduce_argument_1 разбивает аргумент на две части: */
/* x = multiplier * ln(2) + r */
/* Итого получаем: */
/* e^x = e^(multiplier * ln(2) + r) = (e^ln(2))^multiplier  * e^r = */
/* = 2^multiplier * e^r */

/* Затем функция reduce_argument_2 при помощи заранее рассчитанных значений e^alpha */ 
/* вновь разбивает аргумент: */
/* e^r = e^alpha * e^(x-alpha) */
/* После всех операций получаем: */
/* e^x = 2^multiplier * e^alpha * e^(x-alpha), где e^alpha, alpha - табличные значения. */
/* Почему необходимо так тщательно уменьшать входящий аргумент? */
/* Потому что ряды Тейлора, при помощи которых мы находим значенния нашей функции, */ 
/* хорошо работают лишь в небольшой окрестности заданной точки (в нашем случае x = 0) */

double* reduce_argument_1(double *buff, double x) {
    int multiplier = 0;
    if (s21_fabs(x) > S21_LN_2) {
        multiplier = x / S21_LN_2;
    }
        buff[0] = multiplier;
        buff[1] = x - multiplier * S21_LN_2;
    return buff;
}

long double s21_exp(double x) {
    if (is_nan(x)) {
        return S21_NAN;
    }
    if (is_inf(x)) {
        if (x > 0) {
            return +S21_INF;
        } else {
            return 0;
        }
    }
    double buff[2] = {0};
    reduce_argument_1(buff, x);
    int min_index = reduce_argument_2(buff[1]);
    long double rezult = 1;
    for (int i = 0; i < s21_fabs(buff[0]); i ++) {
        if (buff[0] > 0) {
            rezult *= 2;
        } else {
            rezult /= 2;
        }
    }
    rezult *= exp_values[min_index] * do_exp(buff[1] - exp_arguments[min_index]);
    return rezult;
}
int reduce_argument_2(double x) {
    double min = 1000;
    int min_index = -10;
    for (int i = 0; i <= 201; i++) {
        if ((x - exp_arguments[i] < min) && (x - exp_arguments[i] >= 0)) {
                min = x - exp_arguments[i];
                min_index = i;
        }
    }
    return min_index;
}

long double do_exp(double x) {
    long double rezult;
    rezult = 1 + x + (x * x / 2) + (x * x * x / 6) + (x * x * x * x) / 24 + (x * x * x * x * x / 120) + (x * x * x * x * x * x / 720) + (x * x * x * x * x * x * x / 5040) + (x * x * x * x * x * x * x * x / 40320) + (x * x * x * x * x * x * x * x * x) / 362880 + (x * x * x * x * x * x * x * x * x * x) / 3628800;
    return rezult;
}

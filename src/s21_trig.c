#include "s21_math.h"
double* reduce_trig_argument_1(double x, double *buff);
int reduce_trig_argument_2(double *buff); 
long double do_sin(double x);
long double do_cos(double x);

/* Функция reduce_trig_argument_1 уменьшает значение аргумента путем разбиения его на два слагаемых: */
/* x = multiplier * pi/2 + reduced_argument */
/* Работает плохо при x-> +- inf */
/* Может быть потом поправлю */
double* reduce_trig_argument_1(double x, double *buff) {
    double multiplier  = (int)(x / S21_PI_2);
    double reduced_argument = x - S21_PI_2 * multiplier;
    buff[0] = multiplier;
    buff[1] = reduced_argument;
    /* printf("%s%f%10s%f", "multiplier:   ", buff[0], "reduced:  ", buff[1]); */
   /* printf("\n"); */
    return buff;
}
/* Функция reduce_trig_argument_1 уменьшает значение аргумента путем применения формулы синуса/косинуса суммы углов. */
/* sin(x) = sin(alpha) * cos(x - alpha) + cos(alpha) * sin(x - alpha), аналогично для cos. */
/* Угол alpha, sin(alpha), cos(alpha) вычислены заранее и находятся в хеддере. */ 
/* alpha варьируется от 0 до pi/2 с шагом pi/2 /200. */
/* Двести взял наугад, можно поменять. */
/* Почему нужно так сильно уменьшать аргумент? Потому что разложение в ряд Тейлора работает хорошо только вблизи нуля. */
int reduce_trig_argument_2(double *buff) {
    int min_index = 0;
    double min = buff[1];
    for (int i = 0; i < 200; i ++) {
        if ((buff[1] - trig_angles[i] < min) && (buff[1] - trig_angles[i] > 0)) {
            min_index = i;
        }
    }
    /* printf("%s%.10f", "sin arg:   ", trig_angles[min_index]); */
    /* printf("\n"); */
    return min_index;
}

long double s21_sin(double x) {
    if (is_nan(x) || !is_finite(x))
        return S21_NAN;
    double buff[2] = {0}; 
    int sign = 1;
    if (x < 0) {
        x = -x;
        sign = -1;
    }
    reduce_trig_argument_1(x, buff);
    double rezult = 0;
    int min_index = reduce_trig_argument_2(buff); 
/* В свитчкейсе просто пользуемся правилами симметрии и правилами приведения для тригонометрических функций */
    switch ((int)buff[0] % 4)
    {
        case 0:
            rezult = sin_for_trig_angles[min_index] * do_cos(buff[1] - trig_angles[min_index]) + cos_for_trig_angles[min_index] * do_sin(buff[1] - trig_angles[min_index]);
            break;
        case 1:
            rezult = cos_for_trig_angles[min_index] * do_cos(buff[1] - trig_angles[min_index]) - sin_for_trig_angles[min_index] * do_sin(buff[1] - trig_angles[min_index]);
            break;
        case 2:
            rezult = - (sin_for_trig_angles[min_index] * do_cos(buff[1] - trig_angles[min_index]) + cos_for_trig_angles[min_index] * do_sin(buff[1] - trig_angles[min_index]));
            break;
        case 3:
            rezult = - (cos_for_trig_angles[min_index] * do_cos(buff[1] - trig_angles[min_index]) - sin_for_trig_angles[min_index] * do_sin(buff[1] - trig_angles[min_index]));
            break;
    }
    return sign * rezult;   
}

long double s21_cos(double x) {
    return s21_sin(x + S21_PI_2);
}

long double s21_tan(double x) {
    return s21_sin(x) / s21_cos(x);
}
/* do_sin, do_cos - разложение соответствующих функций в ряд Тейлора вблизи x = 0 */
long double do_sin(double x) {
    return x - x * x * x / 6 + x * x * x * x * x / 120 - x * x * x * x * x * x * x / 5040 + x * x * x * x * x * x * x *x * x / 362880;
}

long double do_cos(double x) {
    if (x < 0) {
        x = -x;
    }
    return 1 - x * x / 2 + x * x * x * x / 24 - x * x * x * x * x * x / 720 + x * x * x * x * x * x * x * x / 40320;
}

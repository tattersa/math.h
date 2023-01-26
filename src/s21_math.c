#include "s21_math.h"
#include <math.h>
int s21_abs(int x) {
    return x = (x > 0) ? x : -x;
}

long double s21_fabs(double x) {
    return x = (x > 0) ? x : -x;
}

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

/* Функция использует итерационный метод Волдера, он же CORDIC. */
/* В начальный момент времени вращемый вектор имеет координаты (1;0); */
/* На каждой итерации алгоритма вектор поворачивается на фиксированный угол (alpha = (pi/2)/2^i, */
/* то есть: 45, 22.5, 11 итд. */
/* После чего происходит сравнение координат вектора с входным значением функции. */
/* (Координата x соответствует значению косинуса, координата y синуса) */
/* В зависимости от результата этого сравнения выбирается дальнейший угол поворота: */
/* против часовой или по часовой стрелке. */
/* Одновременно с этим в переменную buff[2] --> rezult сохраняется итоговый угол поворота. */


long double s21_acos(double x) {
    if (is_nan(x) || !is_finite(x) || (x < -1) || (x > 1))
        return S21_NAN;
    long double rezult = 100;
    if (x < 0) {
        rezult = -do_acos(-x) + S21_PI;
    } else {
        rezult = do_acos(x);
    }

    return rezult;
}


long double s21_asin(double x) {
    if (is_nan(x) || !is_finite(x) || (x < -1) || (x > 1)) {
        return S21_NAN;
    }
    long double rezult = 100;
    if (x < 0) {
        rezult = -do_asin(-x);
    } else {
        rezult = do_asin(x);
    }
    return rezult;
}

long double s21_atan(double x) {
    if (is_nan(x))
        return S21_NAN;
    if (is_inf(x)) {
       if (x > 0) {
           return S21_PI_2;
       } else {
           return -S21_PI_2;
       }
    }

    long double rezult = 100;
    if (x < 0) {
        rezult = -do_atan(-x);
    } else {
        rezult = do_atan(x);
    }
    return rezult;
}




long double do_acos(double(x)) {
    long double buff[3] = {0};
    buff[0] = 1;
    for (int i = 0; i < 100; i++) {
        if (buff[0] > x) {
            rotate_counterclockwise(buff, i);
        } else if (buff[0] < x) {
            rotate_clockwise(buff, i);
        } else {
            break;
        }
    }
    return buff[2];
}



long double do_asin(double(y)) {
    long double buff[3] = {0};
    buff[0] = 1;
    for (int i = 0; i < 100; i++) {
        if (buff[1] < y) {
            rotate_counterclockwise(buff, i);
        } else if (buff[1] > y) {
            rotate_clockwise(buff, i);
        } else {
            break;
        }
    }
    return buff[2];
}



long double do_atan(double(y)) {
    long double buff[3] = {0};
    buff[0] = 1;
    for (int i = 0; i < 100; i++) {
        long double tan = buff[1] / buff[0];
        if (tan < y) {
            rotate_counterclockwise(buff, i);
        } else if (tan > y) {
            rotate_clockwise(buff, i);
        } else {
            break;
        }
    }
    return buff[2];
}

/* Вращение осуществлется функциями rotate_counterclockwise и rotate_clockwise. */
/* А именно умножением вектора на матрицу поворота. */
/* Для (i-того) поворота имеем: */

/* |v_x_i|                 1           |1        -tg(alpha)| |v_x_i-1| */
/* |     |   = ______________________  |                   | |       | */
/* |V_y_i|     sqrt(1 + (tg(alpha))^2) |tg(alpha)      1   | |v_y_i-1| */


/* Где alpha и tg(alpha) заранее рассчитаны и лежат в таблице. */
/* При повороте в противоположную сторону в формуле меняются знаки. */


long double* rotate_counterclockwise(long double *buff, int i) {
    long double buffer = 0;
    buffer = 1 / s21_sqrt(1 + CORDIC_tan_values[i] * CORDIC_tan_values[i]) *
    (buff[0] - CORDIC_tan_values[i] * buff[1]);
    buff[1] = 1 / s21_sqrt(1 + CORDIC_tan_values[i] * CORDIC_tan_values[i]) *
    (CORDIC_tan_values[i] * buff[0] + buff[1]);
    buff[0] = buffer;
    buff[2] += CORDIC_tan_angles[i];
    return buff;
}



long double* rotate_clockwise(long double *buff, int i) {
    long double buffer = 0;
    buffer = 1 / s21_sqrt(1 + CORDIC_tan_values[i] * CORDIC_tan_values[i]) *
    (buff[0]+ CORDIC_tan_values[i] * buff[1]);
    buff[1] = 1 / s21_sqrt(1 + CORDIC_tan_values[i] * CORDIC_tan_values[i]) *
    (-CORDIC_tan_values[i] * buff[0] + buff[1]);
    buff[0] = buffer;
    buff[2] -= CORDIC_tan_angles[i];
    return buff;
}

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
    for (int i = 0; i <= 200; i++) {
        if ((x - exp_arguments[i] < min) && (x - exp_arguments[i] >= 0)) {
                min = x - exp_arguments[i];
                min_index = i;
        }
    }
    return min_index;
}

long double do_exp(double x) {
    long double rezult;
    rezult = 1 + x + (x * x / 2) + (x * x * x / 6) + (x * x * x * x) / 24 +
    (x * x * x * x * x / 120) + (x * x * x * x * x * x / 720) +
    (x * x * x * x * x * x * x / 5040) + (x * x * x * x * x * x * x * x / 40320) +
    (x * x * x * x * x * x * x * x * x) / 362880 + (x * x * x * x * x * x * x * x * x * x) / 3628800;
    return rezult;
}

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
            rezult--;
        }
    }
    return rezult;
}

long double s21_fmod(double x, double y) {
    if (is_nan(x) || is_nan(y)) {
        return S21_NAN;
    }
    long double rezult = 0;
    rezult = (double)(int)(x/y);
    rezult = x -rezult*y;
    return rezult;
}

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
    for (int i = 0; i < 20; i++) {
        long double buff_a = (a + b) / 2;
        long double buff_b = sqrt(a * b);
        a = buff_a;
        b = buff_b;
    }
    long double rezult = S21_PI / 2 / b - 50 * S21_LN_2;
    return rezult;
}

long double s21_pow(double base, double exp) {
    if (is_nan(base) || is_nan(exp)) {
        return S21_NAN;
    }

    if ((base == 0) && (exp < 0)) {
        return S21_INF;
    }
    if ((base == S21_INF) && (exp < 0)) {
        return 0;
    }
    if (base == 1) {
        return 1;
    }
    if (s21_fabs(exp) < EPS) {
        return 1;
    }
    if ((base < 0) && (exp == -S21_INF)) {
        return 1;
    }
    if ((base < 0) && is_finite(exp) && ((double)(int)exp != exp)) {
        return S21_NAN;
    }
    if (base < 0) {
        if (s21_fmod(exp, 2) == 0) {
            return s21_pow(-base, exp);
        } else {
            return -s21_pow(-base, exp);
        }
    }

    long double rezult = 0;
    rezult = s21_exp(exp * s21_log(base));
    return rezult;
}

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
            d++;
        }
    } else {
        while ((int)(k * 10) == 0) {
            if (s == 0) {
                d = 0;
                break;
            }
            k *= 10;
            d--;
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
/* Функция reduce_trig_argument_1 уменьшает значение аргумента путем 
применения формулы синуса/косинуса суммы углов. */
/* sin(x) = sin(alpha) * cos(x - alpha) + cos(alpha) * sin(x - alpha), аналогично для cos. */
/* Угол alpha, sin(alpha), cos(alpha) вычислены заранее и находятся в хеддере. */
/* alpha варьируется от 0 до pi/2 с шагом pi/2 /200. */
/* Двести взял наугад, можно поменять. */
/* Почему нужно так сильно уменьшать аргумент? Потому что разложение в
ряд Тейлора работает хорошо только вблизи нуля. */
int reduce_trig_argument_2(const double *buff) {
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
    switch ((int)buff[0] % 4) {
        case 0:
            rezult = sin_for_trig_angles[min_index] * do_cos(buff[1] - trig_angles[min_index])
            + cos_for_trig_angles[min_index] * do_sin(buff[1] - trig_angles[min_index]);
            break;
        case 1:
            rezult = cos_for_trig_angles[min_index] * do_cos(buff[1] - trig_angles[min_index])
            - sin_for_trig_angles[min_index] * do_sin(buff[1] - trig_angles[min_index]);
            break;
        case 2:
            rezult = - (sin_for_trig_angles[min_index] * do_cos(buff[1] - trig_angles[min_index])
            + cos_for_trig_angles[min_index] * do_sin(buff[1] - trig_angles[min_index]));
            break;
        case 3:
            rezult = - (cos_for_trig_angles[min_index] * do_cos(buff[1] - trig_angles[min_index])
            - sin_for_trig_angles[min_index] * do_sin(buff[1] - trig_angles[min_index]));
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
    return x - x * x * x / 6 + x * x * x * x * x / 120 -
    x * x * x * x * x * x * x / 5040 + x * x * x * x * x * x * x *x * x / 362880;
}

long double do_cos(double x) {
    if (x < 0) {
        x = -x;
    }
    return 1 - x * x / 2 + x * x * x * x / 24 - x * x * x * x * x * x /
    720 + x * x * x * x * x * x * x * x / 40320;
}

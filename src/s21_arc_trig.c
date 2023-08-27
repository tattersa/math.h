#include "s21_math.h"

long double do_acos(double(x)); 
long double do_asin(double(y)); 
long double do_atan(double(y));
long double* rotate_counterclockwise(long double *buff, int i);
long double* rotate_clockwise(long double *buff, int i);

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

long double s21_atan(double y) {
    if (is_nan(y))
        return S21_NAN;
    if (is_inf(y)) {
       if (y > 0) {
           return S21_PI_2;
       } else {
           return -S21_PI_2;
       }
    }

    long double rezult = 100;
    if (y < 0) {
        rezult = -do_atan(-y);
    } else {
        rezult = do_atan(y);
    }
    return rezult;
}




long double do_acos(double(x)) {
    long double buff[3] = {0};
    buff[0] = 1;
    for (int i = 0; i < 100; i++){
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
    for (int i = 0; i < 100; i++){
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
    long double tan = 0;
    long double buff[3] = {0};
    buff[0] = 1;
    for (int i = 0; i < 100; i++){
        tan = buff[1] / buff[0];
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
    buffer = 1 / s21_sqrt(1 + CORDIC_tan_values[i] * CORDIC_tan_values[i]) * (buff[0] - CORDIC_tan_values[i] * buff[1]); 
    buff[1] = 1 / s21_sqrt(1 + CORDIC_tan_values[i] * CORDIC_tan_values[i]) * (CORDIC_tan_values[i] * buff[0] + buff[1]);
    buff[0] = buffer;
    buff[2] += CORDIC_tan_angles[i];
    return buff;
}



long double* rotate_clockwise(long double *buff, int i) {
    long double buffer = 0;
    buffer = 1 / s21_sqrt(1 + CORDIC_tan_values[i] * CORDIC_tan_values[i]) * (buff[0]+ CORDIC_tan_values[i] * buff[1]); 
    buff[1] = 1 / s21_sqrt(1 + CORDIC_tan_values[i] * CORDIC_tan_values[i]) * (-CORDIC_tan_values[i] * buff[0] + buff[1]);
    buff[0] = buffer;
    buff[2] -= CORDIC_tan_angles[i];
    return buff;
}


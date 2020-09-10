//
// Created by kalibri on 09.09.2020.
//

#include "square_solve.h"
#include <math.h>


/*
 * Количество корней квадратного уравнения
 * */
int getSolvesCount(int a, int b, int c) {
    double desc = sqrt((double)(b*b - 4*a*c));
    int solveCount = 0;

    if (desc > 0) {
        solveCount = 2;
    } else if (desc - 0 < EPS) {
        solveCount = 1;
    }
    return solveCount;
}


/*
 * Решение через дескриминант,
 * первым элементом возвращает кол-во ответов, затем сами ответы
 * */
double* solveReal(int a, int b, int c) {
    double desc = sqrt((double)(b*b - 4*a*c));
    int solveCount = getSolvesCount(a, b, c);
    if (solveCount == 2) {
        static double solves[3];
        solves[0] = 2.;
        solves[1] = (double)(-b + desc) / (2 * a);
        solves[2] = (double)(-b - desc) / (2 * a);
        return solves;
    } else if (solveCount == 1) {
        static double solves[2];
        solves[0] = 1.;
        solves[1] = (double)(-b + desc) / (2 * a);
        return solves;
    } else if (!solveCount) {
        static double solves[1] = {0.};
        return solves;
    }
}

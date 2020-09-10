#include <stdio.h>
#include <math.h>
#include "tests.h"
#include "square_solve.h"

#define DEBUG


int main(int argC, const char* argV[]) {
#ifdef DEBUG
    runTests();
#else
//    были ли переданы аргументы
    if (argC != 4) {
        return 0;
    }

//    способ получить число из символа числа
    int aIndex_ = *(argV + 1)[0] - '0';
    int bIndex_ = *(argV + 2)[0] - '0';
    int cIndex_ = *(argV + 3)[0] - '0';

    double* solves = solveReal(aIndex_, bIndex_, cIndex_);

    if (fabs(*solves - 2) < EPS) {
        double to_return[2];
        to_return[0] = *(solves + 1);
        to_return[1] = *(solves + 2);
        printf("%3f %3f", to_return[0], to_return[1]);
    } else if (fabs(*solves - 1) < EPS) {
        printf("%3f", *(solves + 1));
    } else if (fabs(*solves) < EPS) {
        printf("There is no real solutions");
    }
#endif
}

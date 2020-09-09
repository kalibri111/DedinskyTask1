#include <stdio.h>
#include <math.h>
#include "tests.h"
#include "square_solve.h"

#define DEBUG 1


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

    int solveCount = getSolvesCount(aIndex_, bIndex_, cIndex_);
    double* solves =      solveReal(aIndex_, bIndex_, cIndex_);

    if (solveCount == 2) {
        double to_return[2];
        to_return[0] = *solves;
        to_return[1] = *(solves + 1);
        printf("%3f %3f", to_return[0], to_return[1]);
    } else if (solveCount == 1) {
        printf("%3f", *solves);
    } else if (!solveCount) {
        printf("There is no real solutions");
    }
#endif
}

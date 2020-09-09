//
// Created by kalibri on 09.09.2020.
//

#include "tests.h"
#include "square_solve.h"
#include <assert.h>
#include <math.h>


void testGetSolvesCount() {
    assert(getSolvesCount(1, 4, 4) == 1);
    assert(getSolvesCount(1, 5, 1) == 2);
    assert(getSolvesCount(3, 1, 4) == 0);
}

void testSolveReal() {
    double* one_solve    = solveReal(1, 4, 4);  // 2
    double* two_solves   = solveReal(1, 3, 2);  // -1 -2
    double* zero_solves  = solveReal(5, 2, 4);  // none

    assert(*one_solve - 2 < 0.001);
    assert(*two_solves + 1 < 0.001 && *(two_solves + 1) + 2 < 0.001);
    assert(*zero_solves == 0);
}

void runTests() {
    testGetSolvesCount();
    testSolveReal();
}

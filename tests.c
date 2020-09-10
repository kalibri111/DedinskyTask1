//
// Created by kalibri on 09.09.2020.
//

#include "tests.h"
#include "square_solve.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>


void testGetSolvesCount() {
    assert(getSolvesCount(1, 4, 4) == 1);
    assert(getSolvesCount(1, 5, 1) == 2);
    assert(getSolvesCount(3, 1, 4) == 0);
}

void testSolveReal() {
    double* one_solve    = solveReal(1, 4, 4);  // -2
    double* two_solves   = solveReal(1, 3, 2);  // -1 -2
    double* zero_solves  = solveReal(5, 2, 4);  // none

    assert(fabs(*(one_solve + 1) + 2) < EPS);
    assert(fabs(*(two_solves + 1) + 1) < EPS && fabs(*(two_solves + 2) + 2) < EPS);
    assert(*zero_solves < EPS);
}

void runTests() {
    testGetSolvesCount();
    testSolveReal();
    printf("All tests passed");
}

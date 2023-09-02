#ifndef HEAD_H_INCLUDED2
#define HEAD_H_INCLUDED2
#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include "use_me_and_live_without_errors.h"

/**
value, which return #compare_double
*/
enum RETURN_COMP_DOUB
{
    EQUALITY = 0,///<value when double equal
    FIR_BIG_THAN_SEC = 1,///<value when first bigger than second
    FIR_LESS_THAN_SEC = -1,///<value when second bigger than first
    BAD_RETURN_D = 4///<value, when in function was no return
};


int comp_double_for_qsort(const void *first, const void *second);

/** @brief function for compare to double numb
    use next constant #for_compare_double and #EPSILON
    @params[i] first pointer on first double
    @params[i] second pointer on second double
    @params[out] return 0 if numbers equal, 1 if first>second and -1 if first<second
*/
enum RETURN_COMP_DOUB compare_double(const double *first, const double *second);

const double EPSILON = 1e-8;///<Define value of accuracy in #compare_double
const double for_compare_double = 0.0;///<Use when you want to compare double with zero

enum RETURN_COMP_DOUB comp_double_and_zero(const double *first);
#endif

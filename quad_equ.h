#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdlib.h>
#include <TXLib.h>  // � ���, � ���, ������ ���� �� ����, �����������!!!
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <assert.h>
#include "const.h"

/*!
initializes all values in quadratic equ. from #coef init coefficent and other values is default
    @param[in] coef #coef there is value of quadratic equ coefficent
    @param[in] equ. Pointer to quadratic equ which must be fill this function
*/
void gen_struktur(double coef[DEGREE+1], struct quad *equ);
/*!
Verifies the pointer and its continued use
    @param[in] is_bad_ptr pointer to any type
    @param[out] bol returns TRUE if with pointer all right and 0 no
*/
void is_bad_ptr(const void *ptr_for_check);
/*!
Finds solutions for the square equation passed in the structure as an argument
    @param[in] equ pointer to the square equation structure it solves# struct quad
    @param[out] amount numbers of roots of equation
*/
int solve_equ(struct quad *equ);
/*!
    @brief Reads coefficients from standard input flow
Reads the coefficient quantity equal to size_coef. In case of erroneous input, cleans the buffer and
    @param[in] coef #coef
    @param[in] size_coef - the size of the array coef
    @param[out] 1 if all right and -1 if not
*/
int read_numbers(double coef[], size_t size_coef, FILE *stream_in = stdin);

/*!
prints information that the user needs about the program�s work
    @param[in] equ - SQUARE EQUATION IN THE STRUCTURE # struct quad
*/
void print_info_about_roots(const struct quad *equ);

/*!

Structure for Square Equations
*/
struct quad
{
    double a = NAN;/*!<second-degree coaphysicent */
    double b = NAN;/*!<coaphysicent in the first degree */
    double c = NAN;/*!<coaphysicent at zero degree */
    int amount_roots = Poison_value;/*!<number of roots */
    double dis = NAN;/*!<discriminant */
    double roots[DEGREE] = {NAN, NAN};/*!<roots of the equation */
};
#endif // HEAD_H_INCLUDED


#ifndef HEAD_H_INCLUDED

#define HEAD_H_INCLUDED
#include <stdlib.h>
#include <TXLib.h>  // И все, и все, больше ниче не надо, траляляляля!!!
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

#include "use_me_and_live_without_errors.h"

const int AMOUNT_ROOTS_INF = -1;///<Define value which mean that equalations have infinity roots

enum AMOUNT_ROOTS
{
    NO_ROOTS = 0,
    ONE_ROOTS = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = AMOUNT_ROOTS_INF
};


const long int Poison_value = 10000000;///<Define value which variable cant have


const int DEGREE = 2;///<Define degree of equation
/*!
initializes all values in quadratic equ. from #coef init coefficent and other values is default
    @param[in] coef #coef there is value of quadratic equ coefficent
    @param[in] equ. Pointer to quadratic equ which must be fill this function
*/
enum CODE_ERRORS gen_struktur(double coef[DEGREE+1], struct quad *equ);
/*!
Finds solutions for the square equation passed

 in the structure as an argument
    @param[in] equ pointer to the square equation structure it solves# struct quad
    @param[out] amount numbers of roots of equation
*/
enum CODE_ERRORS solve_equations(struct quad *equ);

/*!
prints information that the user needs about the program’s work
    @param[in] equ - SQUARE EQUATION IN THE STRUCTURE # struct quad
*/
enum CODE_ERRORS print_info_about_roots(const struct quad *equ);

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


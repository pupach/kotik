#ifndef TEST_H
#define TEST_H
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <assert.h>


#define create_test(a, b, c, x1, x2, am_roots, amount_of_tes)\
    Test_data test##amount_of_tes = {a, b, c, x1, x2, am_roots};\
    all_data[amount_of_tes] = test##amount_of_tes;\
    amount_of_tests++


/**
    @brief Penetrates through the program tests, monitors the correctness of answers and reports in case of non-conformity
Take units test from file or code
*/
void full_test_for_solve_equ();
/**
structur for test. contains all the necessary information for one test
*/
struct Test_data
{
    double coef[DEGREE+1];///< contains coefficent of the quadratic equ
    double roots[DEGREE+1];///<contains right roots of equ
    int am_roots;///<contains rights count of roots
    char name[10];///<contains name of test
};

/**
take data for test from code and pull in #all_data
 @params[in] all_data.
*/
int fill_test_data_with_code(struct Test_data all_data[]);
/**
take data for test from file and pull in #all_data
 @params[in] all_data.
*/
int fill_test_data_from_file(struct Test_data all_data[]);


FILE * open_file_for_get_test_data();
/*!
Gets generated square equation and its roots.
 Checks whether the program is correct
    @param[in] equ pointer to the square equation to be solved
    @param[in] roots roots of the equation #equ
    @param[out] all good or all bad
*/
bool test_for_one_quad_equ(struct quad *equ, double roots[]);
#endif

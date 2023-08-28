#ifndef CONST_H
#define CONST_H

#include <stdlib.h>
#include <TXLib.h>  // � ���, � ���, ������ ���� �� ����, �����������!!!
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
extern int DEBUG;
#define LOG(mode, args...)                                  \
    do {                                                \
    if(mode) {                                         \
        fprintf(stderr, "%s:%d\t", __FILE__, __LINE__); \
        fprintf(args);}                          \
    } while(0)


#define assert_perror(errnum)						   \
  if(!errnum){								           \
    fprintf(stdout, "%d, %s, %d //-----------------------------------------------------------------------------", (errnum), __FILE__, __LINE__);}
#define SIZE_ARR(arr) sizeof(arr)/sizeof(arr[0])

const int DEGREE = 2;///<Define degree of equation

const int SPLITERS = 4;///<Define Size of #Array_spliter

extern FILE *stream_out;///<����������, � ������� ����������� ���� �������� ������ ������ ������������

const long int Poison_value = 10000000;///<Define value which variable cant have

const double Ep = 1e-8;///<Define value of accuracy in #compare_double

extern const int Array_spliter[SPLITERS];///< Array with #SPLITERS for the #clear_buff_input, which defines the end of the word

extern int TEST_MODE; ///< value 1 means that the program is running in test mode and zero is not

extern char POISON_VALUE_FOR_FILE[100];///<Define value which name of file cant have

extern char OUTPUT_FILE[100];

const int Amount_roots_inf = -1;///<Define value which mean that equalations have infinity roots

const double for_compare_double = 0.0;///<Use when you want to compare double with zero

#endif
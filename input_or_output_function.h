#ifndef INPUT_OR_OUTPUT_FUNCTION
#define INPUT_OR_OUTPUT_FUNCTION

#include<stdlib.h>
#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include "const.h"

/*!
    @brief function for clear input buffer
    delete symbols to next word(define when next word begin by #Array_spliter)
    @params[i] Stream of input, which must be clean
*/
void clear_buff_input(FILE *stream_in=stdin);
/*!
    @brief Define next word (NAN or INFINITY) or not
    @params[i] Stream of input, which must be clean
*/
double check_about_NAN_and_INF(FILE *stream_in=stdin);
#endif

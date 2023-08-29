#ifndef INPUT_OR_OUTPUT_FUNCTION
#define INPUT_OR_OUTPUT_FUNCTION
#include "use_me_and_live_without_errors.h"
#include<stdlib.h>
#include <TXLib.h>
#include <stdio.h>
#include <assert.h>



const char inf[]="INFINITY";

const int SPLITERS = 4;///<Define Size of #ARRAY_SPLITTER


extern const char ARRAY_SPLITTER[SPLITERS];///< Array with #SPLITERS for the #clear_buff_input, which defines the end of the word


/*!
    @brief Reads coefficients from standard input flow
Reads the coefficient quantity equal to size_coef. In case of erroneous input, cleans the buffer and
    @param[in] coef #coef
    @param[in] size_coef - the size of the array coef
    @param[out] 1 if all right and -1 if not
*/
bool read_numbers(double coef[], const size_t size_coef, FILE *stream_in = stdin);

/*!
    @brief function for clear input buffer
    delete symbols to next word(define when next word begin by #ARRAY_SPLITTER)
    @params[i] Stream of input, which must be clean
*/
int clear_buff_input(FILE *stream_in=stdin);
/*!
    @brief Define next word (NAN or INFINITY) or not
    @params[i] Stream of input, which must be clean
*/
bool check_about_NAN_and_INF(double* result, FILE *stream_in=stdin);
#endif

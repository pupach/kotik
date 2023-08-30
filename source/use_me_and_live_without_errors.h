#ifndef use_me_live_without_errors.h
#define hhhhh


#include <stdlib.h>
#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include "debug_and_logs.h"
#define assert_perror(errnum, ERROR_CODE)						                                                  \
  if(!errnum){								                                                                      \
    fprintf(stdout, "%d, %s, %d //-----------------------------------------------------------------------------", \
            (errnum), __FILE__, __LINE__);                                                                        \
     return ERROR_CODE;                                                                                           \
    }
   // do while.

/**
all kinds value, WHICH CAN return function as error
*/
enum CODE_ERRORS
{
    ALL_GOOD = 0,
    VAL_NAN = 1,
    VAL_INF = 2,
    VAL_POISON = 3,
    VAL_ZERO = 4,
    BAD_RETURN = 5
};
/*!
Verifies the pointer and its continued use
    @param[in] is_bad_ptr pointer to any type
    @param[out] bol returns TRUE if with pointer all right and 0 no
*/
void is_bad_ptr(const void *ptr_for_check);



#define SIZE_ARR(arr) sizeof(arr)/sizeof(arr[0])
#endif

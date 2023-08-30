#ifndef DEBUG_AND_LOGS
#define DEBUG_AND_LOGS

#include <stdlib.h>
#include <TXLib.h>  // » все, и все, больше ниче не надо, трал€л€л€л€!!!
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "use_me_and_live_without_errors.h"

#ifdef DEBUG_MODE
#define LOG(mode, args...)                                                       \
    do {                                                                         \
    if(mode) {                                                                   \
        fprintf(stderr, "%s:%d\t %s\t", __FILE__, __LINE__, __PRETTY_FUNCTION__);\
        fprintf(args);}                                                          \
    } while(0)
#endif


/**
all kinds value, WHICH CAN HAVE debug
*/
enum DEBUG_LVL
{
    NO_DEBUG        = 0,
    MIN_DEBUG       = 1,
    HIGH_DEBUG     = 2,
    FILE_DEBUG      = 3

};


extern int DEBUG;


#ifndef DEBUG_MODE
#define LOG(mode, args...){}
#endif


#ifdef DEBUG_MODE
    #define DEBUG_LVL_1 DEBUG>=MIN_DEBUG
#endif

#ifndef DEBUG_MODE
#define DEBUG_LVL_1 0
#endif

#ifdef DEBUG_MODE
    #define DEBUG_LVL_2 DEBUG>=HIGH_DEBUG
#endif


#ifndef DEBUG_MODE
#define DEBUG_LVL_2 0
#endif


/**
MAX SIZE FILE, which user can input
*/
const int MAX_SIZE_FILE = 100;

extern FILE *stream_out;///<Variable that specifies where to output data for the developer



extern int TEST_MODE; ///< value 1 means that the program is running in test mode and zero is not


/**
if #stream_out not equal stdout: close the file, where were writing debug info
*/
void close_file_for_debuf();

/**
    @brief define which stream_out will use programs
if #DEBUG equ 2 when programs will write debug info in file
    @params[out] return stream where must be write debug info
*/
void open_file_for_debug_log();
#endif

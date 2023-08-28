#ifndef DEBUG_AND_LOGS
#define DEBUG_AND_LOGS

#include <stdlib.h>
#include <TXLib.h>  // � ���, � ���, ������ ���� �� ����, �����������!!!
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/**
if #stream_out not equal stdout: close the file, where were writing debug info
*/
void close_file_for_debuf();

/**
    @brief define which stream_out will use programs
if #DEBUG equ 2 when programs will write debug info in file
    @params[out] return stream where must be write debug info
*/
FILE *open_file_for_debug_log();
#endif
#include "debug_and_logs.h"


int DEBUG = 0;
const static char POISON_NAME_FOR_FILE = '_';///<Define value which name of file cant have
static char OUTPUT_FILE[MAX_SIZE_FILE] = {POISON_NAME_FOR_FILE};
FILE *stream_out = stderr;

#ifdef DEBUG_MODE


void open_file_for_debug_log()
{
    if (DEBUG==FILE_DEBUG)
    {
        if (OUTPUT_FILE[0] == POISON_NAME_FOR_FILE)
        {
            printf("Введите имя файла для логирования ");

            scanf("%s", OUTPUT_FILE);

            stream_out = fopen(OUTPUT_FILE, "w");
        }
        else
        {
            stream_out = fopen(OUTPUT_FILE, "a");
        }
    }
    else
    {
        stream_out = stdout;
    }
}

void close_file_for_debug()
{
    if (!((stream_out == stdout) or (stream_out == stderr)))
    {
        fclose(stream_out);
    }
}
#endif
#ifndef DEBUG_MODE
void open_file_for_debug_log(){}
void close_file_for_debug(){}
#endif

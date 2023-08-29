#include "debug_and_logs.h"


int DEBUG = 0;
const static char POISON_NAME_FOR_FILE = '_';///<Define value which name of file cant have
static char OUTPUT_FILE[MAX_SIZE_FILE] = {POISON_NAME_FOR_FILE};
FILE *stream_out = stdout;


FILE *open_file_for_debug_log()
{
    if (DEBUG==FILE_DEBUG)
    {
        printf("%s, %d", OUTPUT_FILE, (OUTPUT_FILE[0] == POISON_NAME_FOR_FILE));

        if (OUTPUT_FILE[0] == POISON_NAME_FOR_FILE)
        {
            printf("Введите имя файла для логирования ");

            scanf("%s", OUTPUT_FILE);

            return fopen(OUTPUT_FILE, "w");
        }
        return fopen(OUTPUT_FILE, "a");
    }
    return stdout;
}

void close_file_for_debuf()
{
    if (!(stream_out == stdout))
    {
        fclose(stream_out);
    }
}


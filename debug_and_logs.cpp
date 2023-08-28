#include "const.h"
#include "debug_and_logs.h"
FILE *open_file_for_debug_log()
{
    if (DEBUG==2)
    {
        printf("%s, %d", OUTPUT_FILE, (OUTPUT_FILE[0] == 'i'));

        if (OUTPUT_FILE[0] == 'i')
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


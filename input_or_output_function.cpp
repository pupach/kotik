#include "const.h"
#include "input_or_output_function.h"
#include "quad_equ.h"

void clear_buff_input(FILE *stream_in)
{
    is_bad_ptr(stream_in);

    int flag = 0;
    do
    {
        int i = 0;
        do
        {
            int symb = getc(stream_in);
            flag = (symb == Array_spliter[i]);
            i++;
        }while(i <= SPLITERS and !flag);
    DEBUG_LOG(stream_out, "end while 1 clear_buff_input\n");

    }while (!flag);
    DEBUG_LOG(stream_out, "end while 2 clear_buff_input\n");
}

double check_about_NAN_and_INF(FILE *stream_in)
{
    is_bad_ptr(stream_in);

    char str[10] = {};
    int res = fscanf(stream_in, "%10s", &str);
    if (res == 0)
    {
        clear_buff_input();
    }
    else if(res == 1)
    {
        if (strcmp(str, "NAN") == 0)
        {
            return NAN;
        }
        else if(strcmp(str, "INFINITY") == 0)
        {
            return INFINITY;
        }
    }
    return Poison_value;
}


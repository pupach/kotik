#include "input_or_output_function.h"
#include "debug_and_logs.h"

const char ARRAY_SPLITTER[SPLITERS] = {'\n', ' ', '\t', ','};

size_t read_number(size_t counter, double * box_for_scanf, FILE *stream_in)
{
        int jesttttt = 0; // from ded

        LOG(DEBUG>=HIGHT_DEBUG, stream_out, "while begin, %d", counter);

        jesttttt = fscanf(stream_in, "%lf", box_for_scanf);
        LOG(DEBUG>=HIGHT_DEBUG, stream_out, "JEEEST %d, %lf", jesttttt, *box_for_scanf);
        int cnt = clear_buff_input();

        LOG(DEBUG>=MIN_DEBUG, stream_out, "fscanf, %d, box_for_scanf %d\n", jesttttt, *box_for_scanf);  //

        if (jesttttt > 0)
        {
            LOG(DEBUG>=MIN_DEBUG, stream_out, " ����� � ������ ��");
            if (cnt == 1)
            {
                return(counter+1);
            }
            else
            {

                return counter;
            }

        }
        else if (jesttttt==-1)
        {
            counter = -1;
            return counter;
        }
        else
        {

            double for_result;
            double cod_ret = check_about_NAN_and_INF(&for_result, stream_in);

            if (cod_ret == false)
            {
                *box_for_scanf = for_result;
                return(counter+1);
            }
        }
        return counter;
}


bool read_numbers(double coef[], const size_t size_coef, FILE *stream_in)
{
    size_t counter = 0;
    double box_for_scanf = NAN;

    if(!TEST_MODE){printf("������� ���������� %d �����\n", size_coef);}

    while(counter < size_coef)
    {
        size_t counter_befor = counter;
        counter = read_number(counter, &box_for_scanf, stream_in);

        if (counter > counter_befor)
        {
            if(!TEST_MODE){printf("����� �������� %d %lf\n", counter, box_for_scanf);}

            coef[counter_befor] = box_for_scanf;
        }
        else if (counter == -1)
        {
            return false;
        }
        else
        {
            if(!TEST_MODE){printf("����� ��������\n");}
        }
    }
    if(!TEST_MODE){printf("����� �������\n");}

    return true;

}


int clear_buff_input(FILE *stream_in)
{
    is_bad_ptr(stream_in);

    int flag = 0;
    int counter = 0;
    do
    {
        int i = 0;
        char symb = getc(stream_in);
        do
        {
            flag = (symb == ARRAY_SPLITTER[i]);
            i++;
        }while(i <= SPLITERS and !flag);
    counter++;

    LOG(DEBUG>=MIN_DEBUG, stream_out, "end while 1\n");

    }while (!flag);

    LOG(DEBUG>=MIN_DEBUG, stream_out, "end while 2\n");
    return counter;
}

bool check_about_NAN_and_INF(double* result, FILE *stream_in)
{
    is_bad_ptr(stream_in);

    char str[SIZE_ARR(inf)] = {};
    int res = fscanf(stream_in, "%10s", &str);
    LOG(DEBUG>=MIN_DEBUG, stream_out, " res %d\n str %s \n", res, str);
    if (res == 0)
    {
        clear_buff_input();
    }
    else if(res == 1)
    {
        if (strcmp(str, "NAN") == 0)
        {
            LOG(DEBUG>=MIN_DEBUG, stream_out, " return %s \n", "NAN");

            (*result) = NAN;
            return false;
        }
        else if(strcmp(str, "INFINITY") == 0)
        {
            LOG(DEBUG>=MIN_DEBUG, stream_out, " return %s \n", "INFINITY");

            (*result) = INFINITY;
            return false;
        }
    }

    return true;
}


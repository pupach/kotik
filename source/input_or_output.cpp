#include "input_or_output.h"
#include "debug_and_logs.h"





const char ARRAY_SPLITTER[SPLITERS_LEN] = {' ', '\t', ','};

size_t read_number(size_t counter, double * box_for_scanf, FILE *stream_in, int *amount_characters)
{
        int jesttttt = 0; // from ded

        LOG(DEBUG_LVL_2, stream_out, "while begin, %d", counter);

        int amount_input = 0;

        fscanf(stream_in, " %n", &amount_input);
        (*amount_characters) += amount_input;

        jesttttt = fscanf(stream_in, "%lf%n", box_for_scanf, &amount_input);

        LOG(DEBUG_LVL_2, stream_out, "JEEEST %d, %lf", jesttttt, *box_for_scanf);
        LOG(DEBUG_LVL_1, stream_out, "fscanf,  box_for_scanf %lf\n", *box_for_scanf);

        if (jesttttt > 0)
        {
            int paniman = (*amount_characters);
            int splitters = clear_buff_input(amount_characters, stream_in);

            LOG(DEBUG_LVL_1, stream_out, " зашли в первый иф");

            if ((splitters == 1))
            {
                if ((*amount_characters) != 0)
                {
                    (*amount_characters) += amount_input;
                }
                return(counter+1);
            }
            else
            {
                if(!(TEST_MODE or DEBUG)) print_panimana(paniman);
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
            double cod_ret = check_about_NAN_and_INF(&for_result, amount_characters , stream_in);

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
    int amount_characters = 0;
    int counter = 0;
    double box_for_scanf = NAN;

    if(!TEST_MODE){printf("¬ведите пожалуйста %d чисел\n", size_coef);}

    while(counter < size_coef)
    {
        size_t counter_befor = counter;
        counter = read_number(counter, &box_for_scanf, stream_in, &amount_characters);
        if (counter > counter_befor)
        {
            if(!TEST_MODE){printf("чисел получено %d %lf\n", counter, box_for_scanf);}

            coef[counter_befor] = box_for_scanf;
        }
        else if (counter == -1)
        {
            return false;
        }
        else
        {
            if(!TEST_MODE){printf("чисел неверный\n");}
            if(!TEST_MODE){printf("повторите ввод\n");}
        }
    }
    if(!TEST_MODE){printf("числа введены\n");}

    return true;

}


int clear_buff_input(int *amount_characters, FILE *stream_in)
{
    LOG(DEBUG_LVL_1, stream_out, "begin while 1\n");

    is_bad_ptr(stream_in);

    int flag = 0;
    int counter = 0;
    do
    {
        (*amount_characters)+=1;

        char symb = getc(stream_in);

        LOG(DEBUG_LVL_2, stream_out, "symb getc, %c", symb);

        counter++;
        if (symb == SYMBOL_ENTER)
        {
            (*amount_characters) = 0;
            break;
        }
        else
        {
            for (int i = 0; i < SPLITERS && !flag; i++)
            {
                flag = (symb == ARRAY_SPLITTER[i]);
            }
        }

        LOG(DEBUG_LVL_1, stream_out, "end while 1\n");

    } while (!flag);

    LOG(DEBUG_LVL_1, stream_out, "end while 2\n");
    return counter;
}

bool check_about_NAN_and_INF(double* result, int *amount_characters, FILE *stream_in)
{
    is_bad_ptr(stream_in);

    int am_input = 0;
    int print_panimana_rem = (*amount_characters);
    char str[SIZE_ARR(inf)] = {};
    int res = fscanf(stream_in, "%10s%n", &str, &am_input);

    (*amount_characters) += am_input;

    LOG(DEBUG>=MIN_DEBUG, stream_out, " res %d\n str %s \n", res, str);

    if (res == 0)
    {
        clear_buff_input(amount_characters, stream_in);
    }
    else if(res == 1)
    {
        if (strcmp(str, "NAN") == 0)
        {
            LOG(DEBUG_LVL_1, stream_out, " return %s \n", "NAN");

            (*result) = NAN;
            return false;
        }
        else if(strcmp(str, "INFINITY") == 0)
        {
            LOG(DEBUG_LVL_1, stream_out, " return %s \n", "INFINITY");

            (*result) = INFINITY;
            return false;
        }
    }
    (*amount_characters) = 0;
    if(!TEST_MODE)print_panimana(print_panimana_rem);
    return true;
}

void print_panimana(int print_panimana_rem)
{
    printf("\n");
    for (int j = 0; j<print_panimana_rem; j++)
    {
        printf(" ");
    }
    printf("!!!!!\n");
}


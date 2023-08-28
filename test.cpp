#include "const.h"
#include "quad_equ.h"
#include "func_numbers.h"
#include "debug_and_logs.h"
#include "input_or_output_function.h"
#include "test.h"


const int MAX_SIZE_ARRAY_OF_TEST = 100;
int INPUT_TEST_MODE = 0;




bool test_for_one_quad_equ(struct quad *equ, double roots[])
{
    is_bad_ptr(equ);

    solve_equ(equ);
    for (int i = 0; i < DEGREE; i++)
    {
        qsort(equ->roots, DEGREE, sizeof(double), compare_double);
        qsort(roots, DEGREE, sizeof(double), compare_double);
        if (compare_double(&(equ->roots[i]), &(roots[i])) != 0)
        {
            printf("���� �� ������ ����������� � ������ �����");
            return 0;
        }
    }
    return 1;
}


int fill_test_data_with_file(struct Test_data all_data[])
{
    DEBUG_LOG(stream_out, "fill_test_data_with_fill begin\n");
    const int MAX_SIZE = 100;
    char file_input[MAX_SIZE];

    printf("������� �������� ����� ");
    int res_scanf = scanf("%s", &file_input);
    FILE *stream_in = fopen(file_input, "r");
    if (stream_in == NULL)
    {
        printf("We cant find this file");
        fill_test_data_with_file(all_data);

    }

    if ((strcmp(file_input, "stdout")==0)||(res_scanf<=0))
    {
        stream_in = stdin;
    }
    else
    {
        stream_in = fopen(file_input, "r");
    }

    int flag_EOF = 1;
    int i =0;
    const int amount_val_in_test_data = 6;
    DEBUG_LOG(stream_out, "stream_in define\n");
    do
    {
        DEBUG_LOG(stream_out, "while step %d begin\n", i);
        double numbers[amount_val_in_test_data];
        flag_EOF = read_numbers(numbers, amount_val_in_test_data, stream_in);

        DEBUG_LOG(stream_out, "test_do_while 1, %d", flag_EOF);

        char name[SIZE_ARR(all_data[0].name1)];
        flag_EOF = fscanf(stream_in, "%s", &name);

        DEBUG_LOG(stream_out, "test_do_while 2, %d, %s", flag_EOF, name);

        if ((int) flag_EOF == -1){break;}

        all_data[i].coef[0]  = numbers[0];
        all_data[i].coef[1]  = numbers[1];
        all_data[i].coef[2]  = numbers[2];
        all_data[i].roots[0] = numbers[3];
        all_data[i].roots[1] = numbers[4];
        all_data[i].am_roots = (int)numbers[5];

        strncpy(all_data[i].name1, name, 10);
        DEBUG_LOG(stream_out, "while step %d end\n", i);
        i++;

    }while(flag_EOF);
    return i;
    DEBUG_LOG(stream_out, "fill_test_data_with_fill end\n");

}


int fill_test_data_with_code(struct Test_data all_data[])
{
    DEBUG_LOG(stream_out, "fill_test_data_with_code begin\n");
    Test_data a1 = {.coef={1, 2, 3}, .roots={NAN, NAN}, .am_roots=0, .name1={'1', 0}};
    all_data[0] = a1;

    Test_data a2 = {.coef={1, 2, 3}, .roots={NAN, NAN}, .am_roots=0, .name1={'1', 0}};
    all_data[1] = a2;

    Test_data a3 = {.coef={1, 5, 4}, .roots={-1, -4}, .am_roots=2, .name1={'1', 0}};
    all_data[2] = a3;
    DEBUG_LOG(stream_out, "fill_test_data_with_code end\n");

    return 3;

}


void full_test_for_solve_equ()
{
    DEBUG_LOG(stream_out, "full_test_for_solve_equ begin\n");

    struct Test_data all_data[MAX_SIZE_ARRAY_OF_TEST];
    unsigned amount_test = 0;

    if(INPUT_TEST_MODE)
    {
        amount_test = fill_test_data_with_code(all_data);
    }
    else
    {
        amount_test = fill_test_data_with_file(all_data);
    }
    DEBUG_LOG(stream_out, "INPUT_TEST_MODE define\n");

    for (unsigned i = 0; i < amount_test; i++)
    {
        struct quad equ_test = {};

        gen_struktur(all_data[i].coef, &equ_test);
        bool test_res = test_for_one_quad_equ(&equ_test, all_data[i].roots);

        if (test_res)
        {
            fprintf(stream_out, "���� %d  �������� �������\n", i+1);
        }
        else
        {

            DEBUG_LOG(stream_out, "%d test complete\n", i);

            fprintf(stream_out, "���� %d �� ������. ����� ��������� %lf"
                            ", %lf\n �������� ���������� %lf, %lf, %lf",
                            i+1, all_data[i].roots[1], all_data[i].roots[0], all_data[i].coef[0],
                             all_data[i].coef[1], all_data[i].coef[2]);

            print_info_about_roots(&equ_test);
        }
    }

    DEBUG_LOG(stream_out, "full_test_for_solve_equ end\n");
}



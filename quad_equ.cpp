#include "const.h"
#include "quad_equ.h"
#include "func_numbers.h"
#include "debug_and_logs.h"
#include "input_or_output_function.h"


static void _find_roots_quad_equ(struct quad *equ);
static void _find_roots_lin_equ(struct quad *equ);
static void _inf_or_not_amount_roots(struct quad *equ);

//-----------------------------------------------------------------------------

int read_numbers(double coef[], size_t size_coef, FILE *stream_in)
{
    int jesttttt = 0; // from ded
    size_t i = 0;
    double box_for_scanf = NAN;

        LOG(!TEST_MODE, stream_out, "������� ���������� %d �����\n", size_coef);

    while(i<size_coef)
    {
        LOG(DEBUG==2, stream_out, "while begin, %d, %d", i, size_coef);

        jesttttt = fscanf(stream_in, "%lf", &box_for_scanf);   // this is krivo!!!

        LOG(DEBUG==2, stream_out, "fscanf, %d, box_for_scanf %d\n", jesttttt, box_for_scanf);  //

        if (jesttttt > 0)
        {
            coef[i] = box_for_scanf;
            i++;

            LOG(!TEST_MODE, stream_out, "����� �������� %d \n", i);

        }
        else if (jesttttt==-1)
        {
            return -1;
        }
        else
        {
            LOG(!TEST_MODE and DEBUG, stream_out, "����� ��������\n");

            double num_from_string = check_about_NAN_and_INF(stream_in);
            LOG(!TEST_MODE, stream_out, "���kj %d \n %d\n", num_from_string, compare_double(&num_from_string, &Poison_value));
            if (compare_double(&num_from_string, &for_compare_double) != 0)
            {
                coef[i] = num_from_string;
                i++;
            }
        }
    }
    LOG(!TEST_MODE, stream_out, "����� �������\n");
    return 1;

}

int solve_equ(struct quad *equ)
{
    is_bad_ptr(equ);
    assert_perror((!isnan(equ->a)) and (!isnan(equ->b)) and (!isnan(equ->c)));

    LOG(DEBUG, stream_out, "���������� ������� ���������\n ewecwce %d, %d \n",
                (compare_double(&(equ->a), &for_compare_double) == 0),
                (compare_double(&(equ->b), &for_compare_double) == 0));


    if ((compare_double(&(equ->a), &for_compare_double) == 0)&&(compare_double(&(equ->b), &for_compare_double) == 0))
    {

        LOG(DEBUG, stream_out, "������� 0\n");

        _inf_or_not_amount_roots(equ); // TODO: do not use _ before the name, they are reserved
    }
    else if (compare_double(&(equ->a), &for_compare_double) == 0)
    {

        LOG(DEBUG, stream_out, "������� 1\n");

        _find_roots_lin_equ(equ);
    }
    else
    {

        LOG(DEBUG, stream_out, "������� 2\n");

        _find_roots_quad_equ(equ);
    }

    LOG(DEBUG, stream_out, "���������� �������\n");

    assert_perror((!isnan(equ->amount_roots)) and (equ->amount_roots != Poison_value));

    return equ->amount_roots;
}

static void _find_roots_lin_equ(struct quad *equ)
{
    is_bad_ptr(equ);
    LOG(DEBUG, stream_out, "_find_roots_lin_equ begin\n");
    assert_perror(((equ->b)!=0) and ((equ->a)==0));

    equ->roots[0] = -(equ->c)/(equ->b);
    equ->amount_roots = 1;

    LOG(DEBUG, stream_out, "_find_roots_lin_equ end\n");
}


static void _inf_or_not_amount_roots(struct quad *equ)
{
    is_bad_ptr(equ);
    assert_perror((compare_double(&(equ->a), &for_compare_double) == 0) and (compare_double(&(equ->b), &for_compare_double) == 0));
    LOG(DEBUG, stream_out, "_inf_or_not_amount_roots begin\n");

    if (compare_double((&(equ->c)), &for_compare_double) == 0)
    {
        equ->amount_roots = Amount_roots_inf;
        equ->roots[0] = INFINITY;
        equ->roots[1] = INFINITY;
    }
    else
    {
        equ->amount_roots = 0;
    }

    LOG(DEBUG, stream_out, "_inf_or_not_amount_roots end\n");
}


static void _find_roots_quad_equ(struct quad *equ)
{

    LOG(DEBUG, stream_out, "_find_roots_quad_equ begin\n");
    is_bad_ptr(equ);

    printf("�������� ����� ������\n");

    equ->dis = (equ->b)*(equ->b) - 4*(equ->a)*(equ->c);
    int dis_and_zero = compare_double(&(equ->dis), &for_compare_double);
    if (dis_and_zero == 0)
    {
        equ->amount_roots = 1;
        equ->roots[0] = (-(equ->b))/2./(equ->a);
    }
    else if (dis_and_zero == 1)
    {
        double dis_sqrt = sqrt(equ->dis);
        equ->roots[0] = (-(equ->b) + dis_sqrt)/(double)2/(equ->a);
        equ->roots[1] = (-(equ->b) - dis_sqrt)/(double)2/(equ->a);
        equ->amount_roots = 2;
    }
    else
    {
        equ->amount_roots = 0;
    }
    printf("����� �������\n");

    LOG(DEBUG, stream_out, "_find_roots_quad_equ begin\n");

}

void print_info_about_roots(const struct quad *equ)
{
    is_bad_ptr(equ);
    LOG(DEBUG, stream_out, "get_and_print_inf_about_roots begin\n");

    switch(equ->amount_roots)
    {
        case 0:
            printf("������ ���\n");
            break;
        case 1:
            printf("%lf - ���e��\n", equ->roots[0]);
            break;
        case 2:
            printf("%lf, %lf - �����\n", equ->roots[0], equ->roots[1]);
            break;
        case Amount_roots_inf:
            printf("���������� ����� ������\n");
            break;
        default:
            printf("����������� ������\n");
            break;
    }

    LOG(DEBUG, stream_out, "get_and_print_inf_about_roots end\n");
    if (TEST_MODE)
    {
        fprintf(stream_out, "���������� %lf, %lf, %lf\n ������������ %lf\n����� %lf, %lf\n ���������� ������ %d",
                equ->a, equ->b, equ->c, equ->dis, equ->roots[0], equ->roots[1], equ->amount_roots);
    }
}


void gen_struktur(double coef[DEGREE+1], struct quad *equ)
{
    is_bad_ptr(equ);
    LOG(DEBUG, stream_out, "gen_struktur begin\n");

    equ->a = coef[0];
    equ->b = coef[1];
    equ->c = coef[2];
    equ->amount_roots = Poison_value;
    equ->dis = NAN;

    for (int i = 0; i < DEGREE; i++)
    {
        equ->roots[i] = NAN;
    }
    LOG(DEBUG, stream_out, "gen_struktur end\n");
}

void is_bad_ptr(const void *ptr_for_check)
{
    assert(ptr_for_check != nullptr);
}


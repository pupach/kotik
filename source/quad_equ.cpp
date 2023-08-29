#include "quad_equ.h"
#include "func_numbers.h"
#include "debug_and_logs.h"
#include "input_or_output_function.h"
#include "use_me_and_live_without_errors.h"


static enum CODE_ERRORS find_roots_quad_equ(struct quad *equ);
static enum CODE_ERRORS find_roots_lin_equ(struct quad *equ);
static enum CODE_ERRORS inf_or_not_amount_roots(struct quad *equ);

//-----------------------------------------------------------------------------


enum CODE_ERRORS solve_equations(struct quad *equ)
{
    is_bad_ptr(equ);
    assert_perror(!isnan(equ->a), VAL_NAN);assert_perror(!isnan(equ->b), VAL_NAN);
    assert_perror(!isnan(equ->c), VAL_NAN);

    LOG(DEBUG>=MIN_DEBUG, stream_out, "���������� ������� ���������\n ewecwce %d, %d \n",
                (compare_double(&(equ->a), &for_compare_double) == 0),
                (compare_double(&(equ->b), &for_compare_double) == 0));


    if ((is_double_zero(&(equ->a)) == 0) &&
        (is_double_zero(&(equ->b)) == 0))
    {

        LOG(DEBUG>=MIN_DEBUG, stream_out, "������� 0\n");

        inf_or_not_amount_roots(equ);
    }
    else if (is_double_zero(&(equ->a)) == 0)
    {

        LOG(DEBUG>=MIN_DEBUG, stream_out, "������� 1\n");

        find_roots_lin_equ(equ);
    }
    else
    {

        LOG(DEBUG>=MIN_DEBUG, stream_out, "������� 2\n");

        find_roots_quad_equ(equ);
    }

    LOG(DEBUG>=MIN_DEBUG, stream_out, "���������� �������\n");
    LOG(DEBUG>=MIN_DEBUG, stream_out, "asserts %d, %d\n", equ->amount_roots, (equ->amount_roots != Poison_value));
    assert_perror(!(isnan(equ->amount_roots)), VAL_NAN);
    assert_perror(((equ->amount_roots) != Poison_value), VAL_POISON);

    return ALL_GOOD;
}

static enum CODE_ERRORS find_roots_lin_equ(struct quad *equ)
{
    is_bad_ptr(equ);
    LOG(DEBUG>=MIN_DEBUG, stream_out, " begin\n");
    assert_perror(is_double_zero(&(equ->b))!=0, VAL_ZERO);
    assert_perror(is_double_zero(&(equ->a))==0, VAL_ZERO);

    equ->roots[0] = -(equ->c)/(equ->b);
    equ->amount_roots = 1;

    LOG(DEBUG>=MIN_DEBUG, stream_out, " end\n");
    return ALL_GOOD;
}


static enum CODE_ERRORS inf_or_not_amount_roots(struct quad *equ)
{
    is_bad_ptr(equ);

    assert_perror(is_double_zero(&(equ->a))==0, VAL_ZERO);
    assert_perror(is_double_zero(&(equ->b))==0, VAL_ZERO);

    LOG(DEBUG>=MIN_DEBUG, stream_out, " begin\n");

    if (is_double_zero((&(equ->c))) == 0)
    {
        equ->amount_roots = AMOUNT_ROOTS_INF;
        equ->roots[0] = INFINITY;
        equ->roots[1] = INFINITY;
    }
    else
    {
        equ->amount_roots = 0;
    }

    LOG(DEBUG>=HIGHT_DEBUG, stream_out, " end\n");
    return ALL_GOOD;
}


static enum CODE_ERRORS find_roots_quad_equ(struct quad *equ)
{

    LOG(DEBUG>=MIN_DEBUG, stream_out, " begin\n");
    is_bad_ptr(equ);

    printf("�������� ����� ������\n");

    equ->dis = (equ->b)*(equ->b) - 4*(equ->a)*(equ->c);
    int dis_and_zero = is_double_zero(&(equ->dis));
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

    LOG(DEBUG>=MIN_DEBUG, stream_out, " begin\n");
    return ALL_GOOD;

}


enum CODE_ERRORS print_info_about_roots(const struct quad *equ)
{
    is_bad_ptr(equ);
    LOG(DEBUG>=MIN_DEBUG, stream_out, " begin\n");

    switch(equ->amount_roots)
    {
        case NO_ROOTS:
            printf("������ ���\n");
            break;
        case ONE_ROOTS:
            printf("%lf - ���e��\n", equ->roots[0]);
            break;
        case TWO_ROOTS:
            printf("%lf, %lf - �����\n", equ->roots[0], equ->roots[1]);
            break;
        case INF_ROOTS:
            printf("���������� ����� ������\n");
            break;
        default:
            printf("����������� ������\n");
            break;
    }

    LOG(DEBUG>=MIN_DEBUG, stream_out, " end\n");
    if (TEST_MODE)
    {
        fprintf(stream_out, "���������� %lf, %lf, %lf\n ������������ %lf\n����� %lf, %lf\n"
                            " ���������� ������ %d",equ->a, equ->b, equ->c, equ->dis,
                             equ->roots[0], equ->roots[1], equ->amount_roots);
    }
    return ALL_GOOD;
}


enum CODE_ERRORS gen_struktur(double coef[DEGREE+1], struct quad *equ)
{
    is_bad_ptr(equ);
    LOG(DEBUG>=MIN_DEBUG, stream_out, " begin\n");

    equ->a = coef[0];
    equ->b = coef[1];
    equ->c = coef[2];
    equ->amount_roots = Poison_value;
    equ->dis = NAN;

    for (int i = 0; i < DEGREE; i++)
    {
        equ->roots[i] = NAN;
    }
    LOG(DEBUG>=MIN_DEBUG, stream_out, " end\n");
    return ALL_GOOD;
}


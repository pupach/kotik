#include "quad_equ.h"
#include "comp_double.h"
#include "debug_and_logs.h"
#include "input_or_output.h"
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
    LOG(DEBUG_LVL_1, stream_out, "Определяем степень уравнения\n ewecwce %d, %d \n",
                (compare_double(&equ->a, &for_compare_double) == 0),
                (compare_double(&equ->b, &for_compare_double) == 0));


    if (is_double_zero(&equ->a) == 0)
    {

        LOG(DEBUG>=MIN_DEBUG, stream_out, "Степень 1\n");

        find_roots_lin_equ(equ);
    }

    else
    {

        LOG(DEBUG_LVL_1, stream_out, "Степень 2\n");

        find_roots_quad_equ(equ);
    }

    qsort(equ->roots, DEGREE, sizeof(double), comp_double_for_qsort);

    LOG(DEBUG_LVL_1, stream_out, "Определили степень\n");
    LOG(DEBUG_LVL_1, stream_out, "asserts %d, %d\n", equ->amount_roots, (equ->amount_roots != Poison_value));
    assert_perror(!(isnan(equ->amount_roots)), VAL_NAN);
    assert_perror((equ->amount_roots != Poison_value), VAL_POISON);

    return ALL_GOOD;
}

static enum CODE_ERRORS find_roots_lin_equ(struct quad *equ)
{
    LOG(DEBUG_LVL_1, stream_out, " begin\n");
    is_bad_ptr(equ);
    assert_perror(is_double_zero(&equ->a)==0, VAL_ZERO);

    if (is_double_zero(&equ->b) != 0)
    {
        assert_perror(is_double_zero(&equ->b)!=0, VAL_ZERO);

        equ->roots[0] = -equ->c/equ->b;
        equ->amount_roots = 1;
    }
    else
    {
        assert_perror(is_double_zero(&equ->b)==0, VAL_ZERO);

        if (is_double_zero((&equ->c)) == 0)
        {
            equ->amount_roots = AMOUNT_ROOTS_INF;
            equ->roots[0] = INFINITY;
            equ->roots[1] = INFINITY;
        }
        else
        {
            equ->amount_roots = 0;
        }
    }

    LOG(DEBUG_LVL_2, stream_out, " end\n");
    return ALL_GOOD;
}


static enum CODE_ERRORS find_roots_quad_equ(struct quad *equ)
{

    LOG(DEBUG_LVL_1, stream_out, " begin\n");
    is_bad_ptr(equ);

    printf("Начинаем поиск корней\n"); //TODO: enum double comp BIGGER, LOWER

    equ->dis = equ->b*equ->b - 4*equ->a*equ->c;
    int dis_comp_res = is_double_zero(&equ->dis);
    if (dis_is_zero == 0)
    {
        equ->amount_roots = 1;
        equ->roots[0] = (-equ->b)/equ->a/2.;
    }
    else if (dis_and_zero == 1)
    {
        double dis_sqrt = sqrt(equ->dis);
        equ->roots[0] = (-equ->b + dis_sqrt)/equ->a/2.;
        equ->roots[1] = (-equ->b - dis_sqrt)/equ->a/2.;
        equ->amount_roots = 2;
    }
    else
    {
        equ->amount_roots = 0;
    }
    printf("Корни найдены\n");

    LOG(DEBUG_LVL_1, stream_out, " begin\n");
    return ALL_GOOD;

}


enum CODE_ERRORS print_info_about_roots(const struct quad *equ)
{
    is_bad_ptr(equ);
    LOG(DEBUG_LVL_1, stream_out, " begin\n");

    switch(equ->amount_roots)
    {
        case NO_ROOTS:
            printf("корней нет\n");
            break;
        case ONE_ROOTS:
            printf("%lf - корeнь\n", equ->roots[0]);
            break;
        case TWO_ROOTS:
            printf("%lf, %lf - корни\n", equ->roots[0], equ->roots[1]);
            break;
        case INF_ROOTS:
            printf("Бесконечно много корней\n");
            break;
        default:
            printf("Неизвестная ошибка\n");
            break;
    }

    LOG(DEBUG_LVL_1, stream_out, " end\n");
    if (TEST_MODE)
    {
        fprintf(stream_out, "Коэфиценты %lf, %lf, %lf\n Дискриминант %lf\nкорни %lf, %lf\n"
                            " количество корней %d",equ->a, equ->b, equ->c, equ->dis,
                             equ->roots[0], equ->roots[1], equ->amount_roots);
    }
    return ALL_GOOD;
}


enum CODE_ERRORS gen_struktur(double coef[DEGREE+1], struct quad *equ)
{
    is_bad_ptr(equ);
    LOG(DEBUG_LVL_1, stream_out, " begin\n");

    equ->a = coef[0];
    equ->b = coef[1];
    equ->c = coef[2];
    equ->amount_roots = Poison_value;
    equ->dis = NAN;

    for (int i = 0; i < DEGREE; i++)
    {
        equ->roots[i] = NAN;
    }
    LOG(DEBUG_LVL_1, stream_out, " end\n");
    return ALL_GOOD;
}


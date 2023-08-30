 #include "comp_double.h"
 #include "quad_equ.h"

 //-----------------------------------------------------------------------------


int comp_double_for_qsort(const void *first, const void *second)
{
    return compare_double((const double *)first, (const double *)second);
}

enum return_comp_doub compare_double(const double *first, const double *second) //TODO без указателей
{
        is_bad_ptr(first);
        is_bad_ptr(second);

        const double first_v  = *first;
        const double second_v = *second;
        int res = Poison_value;

        if ((isinf(first_v) && isinf(second_v)) ||
            (isnan(first_v) && isnan(second_v)) ||
            (fabs((first_v)-(second_v)) < EPSILON))
        {
            return equality;
        }
        else if(first_v>(second_v)+EPSILON)
        {
            return fir_big_than_sec;
        }
        else
        {
            return fir_less_than_sec;
        }
        return BAD_RETURN_D;
}

enum return_comp_doub is_double_zero(const double *first)
{
    return compare_double(first, &for_compare_double);
}

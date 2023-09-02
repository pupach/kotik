 #include "comp_double.h"
 #include "quad_equ.h"

 //-----------------------------------------------------------------------------


int comp_double_for_qsort(const void *first, const void *second)
{
    return compare_double((const double *)first, (const double *)second);
}

enum RETURN_COMP_DOUB compare_double(const double *first, const double *second)
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
            return EQUALITY;
        }
        else if(first_v>(second_v)+EPSILON)
        {
            return FIR_BIG_THAN_SEC;
        }
        else
        {
            return FIR_LESS_THAN_SEC;
        }
        return BAD_RETURN_D;
}

enum RETURN_COMP_DOUB comp_double_and_zero(const double *first)
{
    return compare_double(first, &for_compare_double);
}

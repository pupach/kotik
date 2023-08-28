 #include "const.h"
 #include "func_numbers.h"
 #include "quad_equ.h"

 //-----------------------------------------------------------------------------


int compare_double(const void *first, const void *second)
{
        is_bad_ptr(first);
        is_bad_ptr(second);

        int res = Poison_value;

        if ((isinf(*(double *)first) && isinf(*(double *)second)) ||
         (isnan(*(double *)first) && isnan(*(double *)second))    ||
         (fabs((*(double *)first)-(*(double *)second)) < Ep))

        {
            res = 0;
        }
        else if(*(double *)first>((*(double *)second)+Ep))
        {
            res = 1;
        }
        else
        {
            res = -1;
        }
        return res;

}

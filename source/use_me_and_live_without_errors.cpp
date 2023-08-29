#include "use_me_and_live_without_errors.h"

void is_bad_ptr(const void *ptr_for_check)
{
    if (ptr_for_check == nullptr)
    {
        close_file_for_debuf();
    }
    assert(ptr_for_check != nullptr);


}


#include "use_me_and_live_without_errors.h"


#ifdef DEBUG_MODE
void is_bad_ptr(const void *ptr_for_check)
{
    if (ptr_for_check == nullptr)
    {
        close_file_for_debug();
    }
    assert(ptr_for_check != nullptr);


}
#endif

#ifndef DEBUG_MODE
void is_bad_ptr(const void *ptr_for_check){}
#endif

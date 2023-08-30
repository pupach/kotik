#include "use_me_and_live_without_errors.h"
#include "quad_equ.h"
#include "debug_and_logs.h"
#include "test.h"
#include "input_or_output.h"

static void select_launch_mode(const unsigned argc, const char *argv[]);


/**
Define, in which mode shoube start the program.
*/
static void select_launch_mode(const unsigned argc, const char *argv[])
{
    if (argc > 1)
    {
        for (unsigned i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-t") == 0)
            {
                TEST_MODE = 1;
            }
            else if (strcmp(argv[i], "-d") == 0)
            {
                if ((i + 1) < argc)
                {
                    DEBUG = atoi(argv[i+1]) ;
                }
                else{DEBUG=1;}
            }

        }
    }
}


int main(const int argc, const char* argv[])
{
    select_launch_mode(argc, argv);
    LOG(DEBUG>=MIN_DEBUG, stdout, "DEBUG = %d", DEBUG);
    open_file_for_debug_log();

    if (TEST_MODE)
    {
        full_test_for_solve_equ();
    }
    else
    {
        double coef[DEGREE+1] = {0};
        read_numbers(coef, DEGREE + 1);

        struct quad equ = {};
        gen_struktur(coef, &equ);
        solve_equations(&equ);

        print_info_about_roots(&equ);
    }
    close_file_for_debuf();
}


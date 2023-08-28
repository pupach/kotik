#include "const.h"
#include "quad_equ.h"
#include "debug_and_logs.h"
#include "test.h"


void select_launch_mode(unsigned argc, char *argv[]);

void select_launch_mode(unsigned argc, char *argv[])
{
    if (argc != 1)
    {
        for (unsigned i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "--t1") == 0)
            {
                TEST_MODE = 1;
            }
            else if (strcmp(argv[i], "--d1") == 0)
            {
                DEBUG = 1; // TODO: debugs levels can be described with numbers,
            }              //       but it's also common for them to use names
            //                      for example: TRACE, INFO, DEBUG, ERROR and so on // enum
            else if (strcmp(argv[i], "--d2") == 0)
            {
                DEBUG = 2;
            }
        }
    }
}


int main(int argc, char* argv[])
{
    select_launch_mode(argc, argv);
    stream_out = open_file_for_debug_log();

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
        solve_equ(&equ);

        print_info_about_roots(&equ);
    }
    close_file_for_debuf();
}

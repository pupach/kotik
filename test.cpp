#include <TXLib.h>  // » все, и все, больше ниче не надо, трал€л€л€л€!!!
#include <stdio.h>
#include <math.h>
#include "quad_urav.cpp"

int main()
{
    double a[4]={
    1,2,3, 4
    };
    int h = 0;
    struct quad urav;
    h = get_koaf(a, sizeof(a));
    urav = gen_struktur(a);
    find_korny_quad(&urav);
    get_and_print_inf_about_korn(urav);
}

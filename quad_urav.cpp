#include <TXLib.h>  // И все, и все, больше ниче не надо, траляляляля!!!
#include <stdio.h>
#include <math.h>
#define degree 2
struct quad gen_struktur(double a[]);
int get_koaf(double a[], int size_a);
int find_korny_quad(struct quad *urav);
struct quad{
    double koaf[degree+2] = {0};

    double dis =NAN;
    double korn[degree]=
        {
         NAN,
        NAN,
        };
};
int get_koaf(double a[], int size_a){
    int j = 0, i =0;
    double k = (double)0;


    int len_a = size_a/sizeof(a[0]);
    while(i<len_a)   {
        j = scanf("%lf", &k);
        if (j>0){
            a[i] = k;
            }
        else{
            printf("error");
            break;
            }
        i++;
    }

}

int find_korny_quad(struct quad *urav){
    double a = (*urav).koaf[0];
    double b = (*urav).koaf[1];
    double c = (*urav).koaf[2] - (*urav).koaf[3];
    double dis = NAN;


    (*urav).dis = b*b - 4*a*c;
     dis = (*urav).dis;
    if (dis >= 0){
        (*urav).korn[0] = (-b + sqrt(dis))/(double) 2/a;
        (*urav).korn[1] = (-b - sqrt(dis))/(double) 2/a;
        return 1;
        }
    else{
        return EOF;
    }
}
struct quad gen_struktur(double a[degree+2])
{
    struct quad equ;
    for(int i=0; i<(degree+2); i++){
        equ.koaf[i]=(double)a[i];
    }
    return equ;
}
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
    if (urav.dis >= 0){
        printf("%lf, %lf - корни", urav.korn[0], urav.korn[1]);
        }
    else{
        printf("корней нет");
        }
}

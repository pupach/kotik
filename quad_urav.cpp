#include <TXLib.h>  // И все, и все, больше ниче не надо, траляляляля!!!
#include <stdio.h>
#include <math.h>
#include<windows.h>
#include<stdlib.h>
#define degree 2
static double ep = 1e-8;
struct quad gen_struktur(double a[]);
int get_koaf(double a[], int size_a);
int find_korny_quad(struct quad *urav);
int print_if_about_korn(struct quad urav);
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
    printf("Введите пожалуйста %d коэфицентов ",len_a );
    while(i<len_a)   {
        j = scanf("%lf", &k);
        if (j>0){
            a[i] = k;
            i++;
            }
        else{
            printf("Коэфиценты неверный ");
            fflush(stdin);
            }
    }
    printf("Коэфиценты введены");

}


int find_korny_quad(struct quad *urav){
    printf("Начинаем поиск корней ");
    double a = (*urav).koaf[0];
    double b = (*urav).koaf[1];
    double c = (*urav).koaf[2] - (*urav).koaf[3];
    double dis = NAN;


    (*urav).dis = b*b - 4*a*c;
     dis = (*urav).dis;
    if (dis>(-ep)){
        (*urav).korn[0] = (-b + sqrt(dis))/(double) 2/a;
        (*urav).korn[1] = (-b - sqrt(dis))/(double) 2/a;
        printf("Корни найдены ");

        return 1;
        }
    else{
        return -1;
    }
    printf("Корни найдены ");
}


int get_and_print_inf_about_korn(struct quad urav){
    if (urav.dis<ep){
        printf("корней нет");
        return 1;
    }
    else if(abs(urav.korn[0] - urav.korn[1]) < ep){
        printf("%lf - корeнь", urav.korn[0]);
        return 2;
        }
    else{
        printf("%lf, %lf - корни", urav.korn[0], urav.korn[1]);
        return 0;
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


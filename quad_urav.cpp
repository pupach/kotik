#include <TXLib.h>  // � ���, � ���, ������ ���� �� ����, �����������!!!
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
    printf("������� ���������� %d �����������\n",len_a );
    while(i<len_a)   {
        j = scanf("%lf", &k);
        if (j>0){
            a[i] = k;
            i++;
            printf("����������� �������� %d \n", i);
            }
        else{
            printf("���������� ��������\n");
            fflush(stdin);
            }
    }
    printf("���������� �������\n");

}


int find_korny_quad(struct quad *urav){
    printf("�������� ����� ������\n");
    double a = (*urav).koaf[0];
    double b = (*urav).koaf[1];
    double c = (*urav).koaf[2] - (*urav).koaf[3];
    double dis = NAN;
    int for_return = NAN;


    (*urav).dis = b*b - 4*a*c;
     dis = (*urav).dis;
    if (dis>(-ep)){
        (*urav).korn[0] = (-b + sqrt(dis))/(double) 2/a;
        (*urav).korn[1] = (-b - sqrt(dis))/(double) 2/a;

        for_return = 1;
        }
    else{
        for_return = -1;
    }
    printf("����� �������\n");
    return for_return;
}


int get_and_print_inf_about_korn(struct quad urav){
    if (urav.dis<ep){
        printf("������ ���");
        return 1;
    }
    else if(abs(urav.korn[0] - urav.korn[1]) < ep){
        printf("%lf - ���e��", urav.korn[0]);
        return 2;
        }
    else{
        printf("%lf, %lf - �����", urav.korn[0], urav.korn[1]);
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


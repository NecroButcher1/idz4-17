#ifndef INTEGRAL_H_INCLUDED
#define INTEGRAL_H_INCLUDED
#include <iostream>
#include <cmath>
#include <stdlib.h>

/* ������������ ��������� ������������ �������� ������������� ���������
������� ���������:
a, b � ������ � ������� ������� ��������������;
f � ��� ������������ ��� ��������������� �������;
eps>0 � �������� ��� ������ �����
�������� ��������:
res - ������������ �������� ���������
������� ����������:
0 � ���� ������ ������� �������������� �� ��������� �������,
� eps>0;
1 - �����, � ����� ������ res ��������� ��������������.*/


using namespace std;

typedef double (*ptrFunc)(double x);
int Integral(double a, double b, ptrFunc F, double eps, int iterate, double &res, int steps){
    int i = 0, err_code = 0;
    double F_r = .0, S_r = .0, h;
    double temp_eps = .0;
    while((i < iterate) && (temp_eps < eps)){
        h = fabs((b-a)) / steps;
        for(i = 1; i < steps; i++){
            F_r += 2*(F(a + i * h));
        }
        F_r += F(a) + F(b);
        F_r *= h/2;

        steps *= 3;

        h = (b-a) / steps;
        for(i = 1; i < steps; i++){
            S_r += 2*(F(a + i * h));
        }
        S_r += F(a) + F(b);
        S_r *= h/2;

        i++;
        temp_eps = fabs(F_r - S_r);
        res = S_r;

    }

    if((temp_eps < eps) && (i == iterate)){
       err_code = 1;
    }

    return err_code;

}


#endif // INTEGRAL_H_INCLUDED

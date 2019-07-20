//! @file
//! @authors TieBeTie

#include "TXLib.h"
#include <iostream>
#include <math.h>
#include <vector>

//! @brief ����������� ���������� ������ ����������� ���������
const int INF = -1;
//! @brief �������� ���������� ��� �������
const double epsilon = 0.0000001;

using std::cin;
using std::cout;

/**
 // @brief ����� ����� �� ����?
 // @param num : �������� ������� �����
 // @return ������ ��� ����
 */
bool is_zero (double num)
{
    if (num <= epsilon && num >= - epsilon)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

/**
 // @brief ����� �� ����� ����?
 // @param num : �������� ������� �����
 // @return ������ ��� ����
 */
bool no_zero (double num)
{
    if (num <= epsilon && num >= - epsilon)
    {
        return(false);
    }
    else
    {
        return(true);
    }
}

/**
 // @brief ������ ���������� ���������
 // @param a : ����������� � ����������� ���������
 // @param b : ����������� b ����������� ���������
 // @param c : ����������� c ����������� ���������
 // @param *x1 : ������ ������ ����������� ���������
 // @param *x2 : ������ ������ ����������� ���������
 // @param D : ������������ ����������� ��������
 // @param roots : ������ ������ ����������� ���������
 // @return ���������� ������
 */
int SolveSqareEquation (double a, double b, double c, double* x1, double* x2)
{
         if (no_zero(a) && no_zero(b) && no_zero(c))
         {
             double D = (b*b) - (4*a*c);
             if (D < - epsilon)
             {
                 return(0);
             }
             else if (is_zero(D))
             {
                 *x1 = - b / (2*a);
                 return(1);
             }
             else if (D > epsilon)
             {
                 D = sqrt(D);
                 *x1 = (- b + D) / (2*a);
                 *x2 = (- b - D) / (2*a);
                 assert(x1 != x2);
                 return(2);
             }
         }
    else if (no_zero(a) && no_zero(b) && is_zero(c))
         {
             *x1 = - b/a;
             *x2 = 0;
             return(2);
         }
    else if (no_zero(a) && is_zero(b) && no_zero(c))
         {
             if (a*c < 0)
             {
                 *x1 = sqrt(- c/a);
                 return(1);
             }
             else
             {
                 return(0);
             }
         }
    else if (no_zero(a) && is_zero(b) && is_zero(c))
         {
             *x1 = 0;
             return(1);
         }
    else if (is_zero(a) && no_zero(b) && no_zero(c))
         {
             *x1 = - c/b;
             return(1);
         }
    else if (is_zero(a) && no_zero(b) && is_zero(c))
         {
             *x1 = 0;
             return(1);
         }
    else if (is_zero(a) && is_zero(b) && no_zero(c))
         {
             return(0);
         }
    else if (is_zero(a) && is_zero(b) && is_zero(c))
         {
             return(INF);
         }
}

/**
 // @brief ����� ������� ����������� ���������
 // @param *x1 : ������ ������ ����������� ���������
 // @param *x2 : ������ ������ ����������� ���������
 // @param *roots : ���������� ������ ����������� ���������
 */
void PrintSolveSqareEquation (int *roots, double* x1, double* x2)
{
    if (*roots != INF)
    {
        cout << "Num of roots:" << *roots << "." << "\n";
              if (*roots == 2)
        {
            cout << "x1=" << *x1 << "\n";
            cout << "x2=" << *x2;
        }
        else if (*roots == 1)
        {
            cout << "x1=" << *x1;
        }
    }
    else if (*roots == INF)
    {
        cout << "Num of roots:INFINITY";
    }
    cout << "\n";
}

/**
 // @brief �������� ������ ������� SolveSqareEquation, �� ������ �������� ���� ����, ������ �� �������� ��������� tests
 // @param a : ������� ������������ a ����������� ���������
 // @param b : ������� ������������ b ����������� ���������
 // @param c : ������� ������������ c ����������� ���������
 // @param rootsCheck : ������ ����������� ���������� ������ ����������� ���������
 // @param    x1Check : ������ ���������� ������ ������ ����������� ���������
 // @param    x2Check  :������ ���������� ������ ������ ����������� ���������
 // @param    x1 : ���������� �� ������� ������ ������ ����������� ���������
 // @param    x2 : ���������� �� ������� ������ ������ ����������� ���������
 // @param roots : ���������� �� ������� ���������� ������ ����������� ���������
 // @param tests : ���������� ������
 */
void CheckSolveSqareEquation (double x1 = 0,double x2 = 0, int roots = 0)
{
    const int tests = 7;
    int i = 1;
    std::vector <double> a         {1,0,3,0,1,  epsilon,1, 1};
    std::vector <double> b         {2,0,0,0,3,- epsilon,5, 5};
    std::vector <double> c         {3,0,1,3,2,  epsilon,6, 6};
    std::vector <  int > rootsCheck{4,-1,0,0,2, -1     ,2, 2};
    std::vector <double> x1Check   {5,0,0,0,-1, 0      ,-3,-2};
    std::vector <double> x2Check   {6,0,0,0,-2, 0      ,-2,-3};

    for (i = 1; i <= tests; i++)
    {
        x1 = 0;
        x2 = 0;
        roots = 0;
        roots = SolveSqareEquation(a[i], b[i], c[i], &x1, &x2);
        assert (roots >= -1 && roots <= 2);
        if (rootsCheck[i] == roots && (x1Check[i] == x1 && x2Check[i] == x2 || x1Check[i] == x2 && x2Check[i] == x1))
        {
            cout << "Test" << i << ":OK" << "\n";
        }
        else
        {
            cout << "Test" << i << ":ERROR, expected x1=" << x1Check[i] << ", x2=" << x2Check[i];
            cout << ", roots="<< rootsCheck[i] << ", if a=" << a[i] << ", b=" << b[i];
            cout << ", c=" << c[i] << ", but x1=" << x1 << ", x2=" << x2 << " and roots=" << roots;
        }
        x1 = 0;
        x2 = 0;
        roots = 0;
    }
}

/**
 // @brief ���� ������� ����������� ���������
 // @param *a : ����������� a ����������� ���������
 // @param *b : ����������� b ����������� ���������
 // @param *c : ����������� c ����������� ���������
 */
void initCoeffofSqareEquation (double *a, double *b, double *c)
{
    cout << "������� ������������ ����������� ���������" << "\n";
    cout << "a=";
    cin >> *a;
    cout << "\n";
    cout << "b=";
    cin >> *b;
    cout << "\n";
    cout << "c=";
    cin >> *c;
    cout << "\n";
}

/**
 // @brief �������� ������� ������� ����������� ��������� � �������� ������������ ������ �������
 // @param a : ����������� a ����������� ���������
 // @param b : ����������� b ����������� ���������
 // @param c : ����������� c ����������� ���������
 // @param x1 : ������ ������ ����������� ���������
 // @param x2 : ������ ������ ����������� ���������
 // @param roots : ���������� ������ ����������� ���������
 */
int main()
{
    int roots = 0;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    initCoeffofSqareEquation (&a, &b, &c);
    roots = SolveSqareEquation (a, b, c, &x1, &x2);
    assert (roots >= -1 && roots <= 2);
    PrintSolveSqareEquation (&roots, &x1, &x2);
    CheckSolveSqareEquation(x1, x2, roots);
}

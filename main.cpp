//! @file
//! @authors TieBeTie

#include "TXLib.h"
#include <iostream>
#include <math.h>
#include <vector>

//! @brief бесконечное количество корней квадратного уравнения
const int INF_Roots = -1;
//! @brief точность вычислений при решении
const double Precision = 1E-8;

using std::cin;
using std::cout;

/**
 // @brief Число равно ли нулю?
 // @param num : проверка данного числа
 // @return Правда или ложь
 */
bool is_zero (double num)
{
    return (num <= Precision && num >= - Precision);
}

/**
 // @brief Число не равно нулю?
 // @param num : Проверка данного числа
 // @return Правда или ложь
 */
bool no_zero (double num)
{
    return (num > Precision || num < - Precision);
}

/**
 // @brief Решает квадратное уравнение
 // @param a : коэффициент а квадратного уравнения
 // @param b : коэффициент b квадратного уравнения
 // @param c : коэффициент c квадратного уравнения
 // @param *x1 : первый корень квадратного уравнения
 // @param *x2 : второй корень квадратного уравнения
 // @param D : дискриминант квадратного трёхчлена
 // @param roots : второй корень квадратного уравнения
 // @return Количество корней
 */
int SolveSquareEquation (double a, double b, double c, double* x1, double* x2);

/**
 // @brief Вывод решения квадратного уравнения
 // @param *x1 : первый корень квадратного уравнения
 // @param *x2 : второй корень квадратного уравнения
 // @param *roots : количество корней квадратного уравнения
 */
void PrintSolveSquareEquation (int *roots, double* x1, double* x2);

/**
 // @brief Проверка вывода функции SolveSquareEquation, вы можете вставить свой тест, только не забудьте увеличить tests
 // @param a : выборка коэффицентов a квадратного уравнения
 // @param b : выборка коэффицентов b квадратного уравнения
 // @param c : выборка коэффицентов c квадратного уравнения
 // @param rootsCheck : массив правильного количества корней квадратного уравнения
 // @param    x1Check : массив правильных первых корней квадратного уравнения
 // @param    x2Check  :массив правильных вторых корней квадратного уравнения
 // @param    x1 : полученный от функции первый корень квадратного уравнения
 // @param    x2 : полученный от функции второй корень квадратного уравнения
 // @param roots : полученное от функции количество корней квадратного уравнения
 // @param tests : количество тестов
 */
void CheckSolveSquareEquation (double x1,double x2, int roots);

/**
 // @brief Ввод решения квадратного уравнения
 // @param *a : коэффициент a квадратного уравнения
 // @param *b : коэффициент b квадратного уравнения
 // @param *c : коэффициент c квадратного уравнения
 */
void initCoeffofSquareEquation (double* a, double* b, double* c);

/**
 // @brief Включена функция решения квадратного уравнения и проверка правильности данной функции
 // @param a : коэффициент a квадратного уравнения
 // @param b : коэффициент b квадратного уравнения
 // @param c : коэффициент c квадратного уравнения
 // @param x1 : первый корень квадратного уравнения
 // @param x2 : второй корень квадратного уравнения
 // @param roots : количество корней квадратного уравнения
 // @param cntInitCoeff : количество правильно введённых данных
 */
int main()
{
    int roots = 0;
    double a = 32, b = 0, c = 0, x1 = 0, x2 = 0;
    initCoeffofSquareEquation (&a, &b, &c);
    roots = SolveSquareEquation (a, b, c, &x1, &x2);
    assert (roots >= -1 && roots <= 2);
    PrintSolveSquareEquation (&roots, &x1, &x2);
    CheckSolveSquareEquation(x1, x2, roots);
}
// scanf("%*[^\n]");
void initCoeffofSquareEquation (double* a_ptr, double* b_ptr, double* c_ptr)
{
    int cntInitCoeff = 0;
    printf("Enter the coefficients of square equation\n");
    while (cntInitCoeff != 3)
    {
        cntInitCoeff = scanf("%lg %lg %lg", a_ptr, b_ptr, c_ptr);
        if (cntInitCoeff != 3)
        {
            printf("NO.\n");
            printf("Enter the coefficients of square equation\n");
            scanf("%*[^\n]");
        }
    }
}
int SolveSquareEquation (double a, double b, double c, double* x1, double* x2)
{
         if (no_zero (a) && no_zero (b) && no_zero (c))
         {
             double D = (b*b) - (4*a*c);
             if (D < - Precision)
             {
                 return (0);
             }
             else if (is_zero (D))
             {
                 *x1 = - b / (2*a);
                 return (1);
             }
             else if (D > Precision)
             {
                 D = sqrt(D);
                 *x1 = (- b + D) / (2*a);
                 *x2 = (- b - D) / (2*a);
                 assert (x1 != x2);
                 return (2);
             }
         }
    else if (no_zero (a) && no_zero (b) && is_zero (c))
         {
             *x1 = - b/a;
             *x2 = 0;
             return (2);
         }
    else if (no_zero (a) && is_zero (b) && no_zero (c))
         {
             if (a*c < 0)
             {
                 *x1 = sqrt(- c/a);
                 return (1);
             }
             else
             {
                 return (0);
             }
         }
    else if (no_zero (a) && is_zero (b) && is_zero (c))
         {
             *x1 = 0;
             return (1);
         }
    else if (is_zero (a) && no_zero (b) && no_zero (c))
         {
             *x1 = - c/b;
             return (1);
         }
    else if (is_zero (a) && no_zero (b) && is_zero (c))
         {
             *x1 = 0;
             return (1);
         }
    else if (is_zero (a) && is_zero (b) && no_zero (c))
         {
             return (0);
         }
    else if (is_zero (a) && is_zero (b) && is_zero (c))
         {
             return (INF_Roots);
         }
    else
         {
             assert(!"Ashipka!");
         }
}
void PrintSolveSquareEquation (int *roots, double* x1, double* x2)
{
    if (*roots != INF_Roots)
    {
        printf("Num of roots:%d.\n", *roots);
              if (*roots == 2)
        {
            printf("x1=%lg\n", *x1);
            printf("x2=%lg\n", *x2);
        }
        else if (*roots == 1)
        {
            printf( "x1=%lg\n", *x1);
        }
    }
    else if (*roots == INF_Roots)
    {
        printf("Num of roots:INFINITY\n");
    }
    printf("\n");
}
void CheckSolveSquareEquation (double x1,double x2, int roots)
{
    const int tests = 7;
    printf("Testing function...\n");
    int i = 1;
    double a[] =       {1,0,3,0,1,  Precision,1, 1};
    double b[] =       {2,0,0,0,3,- Precision,5, 5};
    double c[] =       {3,0,1,3,2,  Precision,6, 6};
    int rootsCheck[] = {4,-1,0,0,2,  -1      ,2, 2};
    double x1Check[] = {5,0,0,0,-1, 0       ,-3,-2};
    double x2Check[] = {6,0,0,0,-2, 0       ,-2,-3};

    for (i = 1; i <= tests; i++)
    {
        x1 = 0;
        x2 = 0;
        roots = 0;
        roots = SolveSquareEquation(a[i], b[i], c[i], &x1, &x2);
        assert (roots >= -1 && roots <= 2);
        if (rootsCheck[i] == roots && (x1Check[i] == x1 && x2Check[i] == x2 || x1Check[i] == x2 && x2Check[i] == x1))
        {
            printf("Test%d:OK\n", i);
        }
        else
        {
            printf("Test%d:ERROR, expected x1=%lg, x2=%lg, roots=%d,", i, x1Check[i], x2Check[i], rootsCheck[i]);
            printf(" if a=%lg, b=%lg, c=%lg, but x1=%lg, x2=%lg and roots=%d\n", a[i], b[i], c[i], x1, x2, roots);
        }
        x1 = 0;
        x2 = 0;
        roots = 0;
    }
}

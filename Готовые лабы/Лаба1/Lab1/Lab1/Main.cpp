#include "stdafx.h"
#include "Auxil.h"                            // вспомогательные функции 
#include <iostream>
#include <ctime>
#include <locale>
#include <unordered_map>

std::unordered_map<int, long double> container;

#define  CYCLE  1000000 // количество циклов  

long double fibonachi(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (container.find(n) != container.end())
        return container[n];
    long double result = fibonachi(n - 1) + fibonachi(n - 2);
    container[n] = result;
    return result;
}

int main()
{
    double  av1 = 0, av2 = 0;
    clock_t  t1 = 0, t2 = 0;
    setlocale(LC_ALL, "rus");
    auxil::start();                          // старт генерации 
    for (int j = 1; j <= 11; j++) {
        t1 = clock();                            // фиксация времени 
        for (int i = 0; i < CYCLE * j; i++)
        {
            av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
            av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
        }
        t2 = clock();                            // фиксация времени 
        long double fib = fibonachi(10 * j); // вычисление числа Фибоначчи
        std::cout << std::endl << "количество циклов:         " << CYCLE * j;
        std::cout << std::endl << "среднее значение (int):    " << av1 / (CYCLE * j);
        std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
        std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
        std::cout << std::endl << "                  (сек):   " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
        std::cout << std::endl << "номер числа Фибоначчи: " << 100 * j;
        std::cout << std::endl << "значение: " << fib;
        std::cout << std::endl;
        std::cout << std::endl;

    }
    system("pause");
    return 0;
}
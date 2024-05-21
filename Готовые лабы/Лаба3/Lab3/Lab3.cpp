#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#define N 5

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int d[N][N] = { //0   1    2    3     4        
                  { INF, 14, 28, INF, 7},    //  0
                  { 7, INF,  22,  61, 77},    //  1
                  { 9,  21, INF, 86, 56},    //  2 
                  { 24,  51,  28, INF, 21},    //  3
                  { 86,  73,  52,  20, INF} };   //  4  
    int r[N];                     // результат 
    int s = salesman(
        N,          // [in]  количество городов 
        (int*)d,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );
    cout << endl << "-- Задача коммивояжера -- ";
    cout << endl << "-- количество  городов: " << N;
    cout << endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)

            if (d[i][j] != INF) cout << setw(3) << d[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    cout << endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) cout << r[i] + 1  << "-->";
    cout << 1;
    cout << endl << "-- длина маршрута     : " << s;
    cout << endl;
    system("pause");
    return 0;
}
#include <iostream>
#include <iomanip> 
#include "Place.h"
using namespace std;

#define N (sizeof(AA)/2)
#define M 3

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	char  AA[][2] = { "A", "B", "C", "D" };
	cout << endl << " --- Генератор размещений ---";
	cout << endl << "Исходное множество: ";
	cout << "{ ";
	for (int i = 0; i < N; i++)
		cout << AA[i] << ((i < N - 1) ? ", " : " ");
	cout << "}";
	cout << endl << "Генерация размещений  из  " << N << " по " << M;
	combi::accomodation s(N, M);
	int  n = s.getfirst();
	while (n >= 0)
	{
		cout << endl << setw(2) << s.na << ": { ";
		for (int i = 0; i < 3; i++)
			cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");
		cout << "}";
		n = s.getnext();
	};
	cout << endl << "всего: " << s.count() << endl;
	system("pause");
	return 0;
}
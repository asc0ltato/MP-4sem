#include<iostream>
#include<iomanip>
#include"LCH.h"
#include"LCS.h"

using namespace std;

void main() {
	setlocale(LC_ALL, "rus");
	char z[100] = "";
	char x1[] = "QVTWNHO",
		y1[] = "RQTWYK";
	clock_t start1 = clock();
	int l = lcsd(x1, y1, z);
	clock_t end1 = clock();
	std::cout << std::endl
		<< "-- наибольшая общая подпоследовательость - LCS(динамическое программирование)" << std::endl;
	std::cout << std::endl << "последовательость X: " << x1;
	std::cout << std::endl << "последовательость Y: " << y1;
	std::cout << std::endl << "LCS: " << z;
	std::cout << std::endl << "длина LCS: " << l;
	std::cout << std::endl;

	char X[] = "QVTWNHO", Y[] = "RQTWYK";
	std::cout << std::endl << "-- вычисление длины LCS для X и Y(рекурсия)";
	std::cout << std::endl << "-- последовательность X: " << X;
	std::cout << std::endl << "-- последовательность Y: " << Y;
	clock_t start2 = clock();
	int s = lcs(
		sizeof(X) - 1,  // длина   последовательности  X   
		"QVTWNHO",       // последовательность X
		sizeof(Y) - 1,  // длина   последовательности  Y
		"RQTWYK"       // последовательность Y
	);
	clock_t end2 = clock();
	std::cout << std::endl << "-- длина LCS: " << s << std::endl;
	cout << "Время затраченное на нахождение обшей подпоследовательности(ДП): " << double(start1 - end1)  << "\n";
	cout << "Время затраченное на нахождение обшей подпоследовательности(рекурсия): " << double(start2 - end2) << "\n";
	system("pause");
}
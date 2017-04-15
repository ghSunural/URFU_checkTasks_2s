#include <iostream>
#include <cstring>
#include <conio.h>

#include "TSpecException.h"

#define ESC 27

using namespace std;

bool isPalindrome(int);
bool isValid(int);
void reverse(int);

int main() {

	setlocale(LC_CTYPE, "rus");
	cout << "ПРОВЕРКА НА ПАЛИНДРОМ\n";
	cout << "Для выхода нажмите ESC\n";

	while (_getch() != ESC) {

		int number;
		cin >> number;



		isPalindrome(number)
			? cout << "Да, число является палиндромом\n"
			: cout << "Нет, число не является палиндромом\n";

	}

	//system("pause");
	return 0;
}
//-------------------------------------------------
bool isPalindrome(int N) {

	if (N < 0) {
		throw TSpecException("Число должно быть натуральным");
	}


	int iCountDigits = countDigits(N);
	int tempN = N;

	while ((int)(tempN / 10)) {

		tempN /= 10;
	}


	//char string[] = N;
	cout << N << "\n";

	return false;
}
//-------------------------------------------------
int countDigits(int N) {

	int countDigits = 1;
	int leadingZeroCount = 0;

	while ((int)(N / 10)) {
		countDigits++;
		N /= 10;
	}

	return countDigits;
}


//equals









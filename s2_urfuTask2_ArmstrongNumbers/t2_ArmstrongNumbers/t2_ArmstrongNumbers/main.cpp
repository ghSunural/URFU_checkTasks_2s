#include <iostream>
#include "conio.h"

#include "TSpecException.h"

using namespace std;

void entryArray(int* &array, int &maxLenght, int);
void displayArmstrongNumber(int[], int);
bool isArmstrongNumber(int);
int countDigits(int);

//153, 370, 371, 407, 1634, 8208, 9474
int main() {

	setlocale(LC_CTYPE, "rus");
	cout << "ЧИСЛА АРМСТРОНГА \n";

	try {
		int* numberArray;
		int maxLenght;
		entryArray(numberArray, maxLenght, 0);
		displayArmstrongNumber(numberArray, maxLenght);

	}
	catch (const std::exception&) {
		cout << "Что-то пошло не так \n";
	}

	system("pause");
	return 0;
}
//-------------------------------------------------
bool isArmstrongNumber(int N) {

	if (N < 0) {
		throw TSpecException("Число должно быть натуральным");
	}

	int iCountDigits = countDigits(N);
	int summPow = 0;
	int tempN = N;

	while ((int)(tempN / 10)) {
		summPow += pow(tempN % 10, iCountDigits);
		tempN /= 10;
	}
	summPow += pow(tempN, iCountDigits);

	if (N == summPow) {

		return true;
	}

	return false;
}
//-------------------------------------------------
int countDigits(int N) {

	int countDigits = 1;

	while ((int)(N / 10)) {
		countDigits++;
		N /= 10;
	}

	return countDigits;
}

//-------------------------------------------------
void entryArray(int* &array, int &maxLenght, int breakChar) {

	cout << "Задайте максимальное количество проверяемых значений \n";
	cin >> maxLenght;
	cout << "Вводите \n";
	array = new int[maxLenght]();
	int currentValue = 0;
	int i = 0;
	do {
		cin.clear();
		cin >> currentValue;
		array[i] = currentValue;
	} while (i < maxLenght && currentValue);


}
//-------------------------------------------------
void displayArmstrongNumber(int array[], int arrayLenght) {

	cout << "Числа Армстронга: \n";
	for (int i = 0; i < arrayLenght; i++) {
		if (isArmstrongNumber(array[i]))
		{
			cout << array[i] << '\n';
		}
	}
}
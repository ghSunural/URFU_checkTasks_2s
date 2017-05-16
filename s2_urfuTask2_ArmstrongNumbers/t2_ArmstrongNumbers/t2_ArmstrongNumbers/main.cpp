#include <iostream>
#include <conio.h>

#include "TSpecException.h"

//CtrlK CtrlD

using namespace std;

void entryArray(int* &array, int &maxLenght);
void displayOnlyArmstrongNumber(int[], int);
bool isArmstrongNumber(int);
int countDigits(int);
bool isNaturalNumber(double N);


//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 
//54748, 92727, 93084, 548834, 1741725, 4210818, 9800817, 9926315, 
//24678050, 24678051, 88593477, 146511208, 472335975, 534494836, 912985153.
int main() {

	setlocale(LC_CTYPE, "rus");
	cout << "ЧИСЛА АРМСТРОНГА \n";

	try
	{
		int* numberArray;
		int maxLenght;
		entryArray(numberArray, maxLenght);
		displayOnlyArmstrongNumber(numberArray, maxLenght);
	}
	catch (TSpecException &e)
	{
		cout << e.getErrorMessage();
	}


	system("pause");
	return 0;
}
//-------------------------------------------------
bool isArmstrongNumber(int N) {

	int iCountDigits = countDigits(N);
	int sumDigitPowers = 0;
	int tempN = N;

	while ((int)(tempN / 10)) {
		sumDigitPowers += pow(tempN % 10, iCountDigits);
		tempN /= 10;
	}
	sumDigitPowers += pow(tempN, iCountDigits);

	if (N == sumDigitPowers) {

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
void entryArray(int *&array, int &maxLenght) {


	cout << "Задайте максимальное количество проверяемых значений \n";
	cin >> maxLenght;
	try {
		array = new int[maxLenght]; //()
	}
	catch (const std::exception&)
	{
		throw TSpecException("Количество значений должно быть натуральным числом\n");
	}

	cout << "Вводите \n";
	double currentValue;
	//int i = 0;

	for (size_t i = 0; i < maxLenght; i++)
	{
		//cin.clear();
		cin >> currentValue;
		if (!currentValue) {
			break;
		}

		if (!isNaturalNumber(currentValue))
		{
			continue;
		}
			

		array[i] = currentValue;
	}
	//while (i < maxLenght)	{	i++;}

}
//-------------------------------------------------
void displayOnlyArmstrongNumber(int array[], int arrayLenght) {

	cout << "Числа Армстронга: \n";
	for (int i = 0; i < arrayLenght; i++) {
		if (isArmstrongNumber(array[i]))
		{
			cout << array[i] << '\n';
		}

	}
}

bool isNaturalNumber(double N) {

	if (!(N - (int)N) && N > 0) {

		return true;
	}

	return false;
}
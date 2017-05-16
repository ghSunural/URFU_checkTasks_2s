#include <iostream>
#include <cstring>
#include <conio.h>

#include "TSpecException.h"

#define ESC 27

using namespace std;

bool isPalindrome(int);
void parseNumber(int number, int &countDigits, int &countPossibleLeadingZeros);
void fillArray(int *&digitsReverseArray, int number, int countDigits);
void reverseArray(int iArray[], int arrayLenght);
bool compareArrays(int iArray1[], int iArray2[], int arrayLenght);
void displayArray(int numberDigitsArray[], int number);
void copyArray(int fromArray1[], int toArray2[], int arrayLenght);

void main() {

	setlocale(LC_CTYPE, "rus");
	cout << "ПРОВЕРКА НА ПАЛИНДРОМ\n";
	cout << "Для начала выполнения нажмите любую клавишу\n";
	cout << "Для выхода нажмите ESC\n";

	while (_getch() != ESC) {

		int number;
		cout << "Задайте натуральное число: ";
		cin >> number;
		cout << "Задано число: " << number << "\n";
				

		//тернарная форма
		isPalindrome(number)
			? cout << "\nПАЛИНДРОМ!!!\n"
			: cout << "\nНЕ палиндром\n";
	}
}
//-------------------------------------------------
bool isPalindrome(int number) {
	
	int countDigits;
	int countPossibleLeadingZeros;
	int *digitsReversedArray;

	parseNumber(number, countDigits, countPossibleLeadingZeros);
	cout << "число: " << number << "\n";
	cout << "кол-во знаков всего: " << countDigits << "\n";
	cout << "кол-во возможных лидирующих нулей в палиндроме: " << countPossibleLeadingZeros << "\n";
	
	fillArray(digitsReversedArray, number, countDigits);

	int *digitsForwardArray = new int[countDigits];
	copyArray(digitsReversedArray, digitsForwardArray, countDigits);
	reverseArray(digitsForwardArray, countDigits);

	displayArray(digitsReversedArray, countDigits);
	displayArray(digitsForwardArray, countDigits);

	if (compareArrays(digitsReversedArray, digitsForwardArray, countDigits)) {
	
		return true;	
	}
	

	return false;
}
//-------------------------------------------------
void parseNumber(int number, int &totalCountDigits, int &countPossibleLeadingZeros) {

	int parsingRemain = number;
	int countDigits = 0;
	countPossibleLeadingZeros = 0;

	while (parsingRemain > 0)
	{
		countDigits++;
		if (!(parsingRemain % 10)) {
			countPossibleLeadingZeros++;
		}
		parsingRemain /= 10;
	}

	totalCountDigits = countDigits + countPossibleLeadingZeros;
}
//-------------------------------------------------
//-------------------------------------------------
void fillArray(int* &digitsReverseArray, int number, int countDigits) {
	
	try {
		digitsReverseArray = new int[countDigits]; //()
	}
	catch (const std::exception&)
	{
		throw TSpecException("\nКоличество значений должно быть натуральным числом\n");
	}

	for (size_t i = 0; i < countDigits; i++)
	{
		digitsReverseArray[i] = number % 10;
		number /= 10;
		cout << "итерация " << i << ": " << digitsReverseArray[i] << "\n";
	}

}
//-------------------------------------------------
void displayArray(int array[], int arrayLenght) {

	cout << "Массив : ";
	for (int i = 0; i < arrayLenght; i++) {
		cout << "[" <<array[i] << "] ";
	}
	cout << "\n";
}
//-------------------------------------------------

void reverseArray(int iArray[], int arrayLenght) {
		
	int startPtr = 0;
	int endPtr = arrayLenght - 1;
	int temp;

	for (size_t i = 0; i < arrayLenght/2; i++)
	{
		temp = iArray[startPtr];
		iArray[startPtr] = iArray[endPtr];
		iArray[endPtr] = temp;
		startPtr++;
		endPtr--;

		//displayArray(iArray, arrayLenght);
	}
	
	
}
//-------------------------------------------------
bool compareArrays(int iArray1[], int iArray2[], int arrayLenght) {

	cout << "Сравнение...";
	//bool compareResult = true;
	for (int i = 0; i < arrayLenght; i++) {
		
		if (iArray1[i] != iArray2[i])
		{
			return false;

		}
				
		
	}
	

	return true;
}
//-------------------------------------------------
void copyArray(int fromArray1[], int toArray2[], int arrayLenght) {

	for (int i = 0; i < arrayLenght; i++) {

		toArray2[i] = fromArray1[i];

	}


}


//-------------------------------------------------
bool isNaturalNumber(double N) {

	if (!(N - (int)N) && N > 0) {

		return true;
	}

	return false;
}










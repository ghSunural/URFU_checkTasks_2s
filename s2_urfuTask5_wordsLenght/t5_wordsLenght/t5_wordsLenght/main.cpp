#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>

#define ESC 27

using namespace std;

bool getAnswer(char string[]);
bool isDelimiter(char ch);
bool isSameLength(int, int);

int main() {

	setlocale(LC_CTYPE, "rus");
	cout << "ПРОВЕРКА ДЛИНЫ СЛОВ \n";
	cout << "Введите строку. В качестве разделителей слов используйте\n"<<
		    "пробел, ; :-.!? ";


	char string[100];

	while (_getch()!= ESC) {

		gets_s(string);
		cout << '\n';
		getAnswer(string)
			? cout << "Да, слова одинаковой длины \n"
			: cout << "Нет, слова разной длины\n";

	}


	//system("pause");
	return 0;

}
//-------------------------------------------------
bool getAnswer(char string[]) {

	int currentWordLength = 0;
	int lastWordLength = 0;

	int N = 0;
	while (string[N]) {

		if (!isDelimiter(string[N])) {
			currentWordLength++;
		}
		else {
			if (isSameLength(lastWordLength, currentWordLength)) {
				lastWordLength = currentWordLength;
				currentWordLength = 0;
			}
			else {
				return false;
			}
		}

		N++;
	}


	if (isSameLength(lastWordLength, currentWordLength)) {
		return true;
	}
	else {
		return false;
	}


	return true;
}

//-------------------------------------------------
bool isDelimiter(char ch) {

	char delimitersString[] = " ,;:-.!?";
	int N = 0;
	while (delimitersString[N]) {

		if (ch == delimitersString[N]) {

			return true;
		}
		N++;
	}

	return false;
}
//-------------------------------------------------
bool isSameLength(int length1, int length2) {

	if (!length1 || (length1 == length2)) {

		return true;
	}
	else {

		return false;
	}

}




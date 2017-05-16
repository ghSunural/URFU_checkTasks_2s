#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>

//strchr
#define ESC 27

using namespace std;

const int MAX_SIZE = 100;
const char DELIMITERS_STRING[] = " ,;:-.!?";

bool getAnswer(char string[]);
bool isDelimiter(char ch);
bool isTheSameLength(int, int);

int main() {

	setlocale(LC_CTYPE, "rus");
	cout << "ПРОВЕРКА ДЛИНЫ СЛОВ \n";
	cout << "Введите строку. В качестве разделителей слов используйте\n" <<
		"пробел, ; :-.!? " << "\n";

	char string[MAX_SIZE];
	char delimitersString[] = " ,;:-.!?";
	while (_getch() != ESC) {

		gets_s(string);
		cout << '\n';


		//
		//cout << string << '\n';

		getAnswer(string)
			? cout << "Да, слова одинаковой длины\n"
			: cout << "Нет, слова разной длины\n";

	}

	return 0;
}
//-------------------------------------------------
bool getAnswer(char string[]) {

	int currentWordLength = 0;
	int lastWordLength = 0;

	int ptrB = 0;
	int ptrE = 0;
	int ptrCur = 0;

	//пока не достигнут конец строки 
	while (string[ptrCur]) {

		//strchr(delemiters, string[ptrCur]) != NULL)
		while (string[ptrCur] && isDelimiter(string[ptrCur])) {
			ptrCur++;
		}
		ptrB = ptrCur;

		while (string[ptrCur] && !isDelimiter(string[ptrCur])) {
			ptrCur++;
		}
		ptrE = ptrCur;


		currentWordLength = ptrE - ptrB;
		if (!isTheSameLength(lastWordLength, currentWordLength)) {
			return false;
		}

		//cout << "l" << lastWordLength << "\n";
		//cout << "c"<< currentWordLength << "\n";
		lastWordLength = currentWordLength;

	}

	return true;
}

//-------------------------------------------------
bool isDelimiter(char ch) {
	
	int N = 0;
	while (DELIMITERS_STRING[N]) {

		if (ch == DELIMITERS_STRING[N]) {

			return true;
		}
		N++;
	}

	return false;
}
//-------------------------------------------------
bool isTheSameLength(int lastWordLength, int currentWordLength) {

	if (!lastWordLength || !currentWordLength || currentWordLength == lastWordLength) {

		return true;
	}
	else {

		return false;
	}

}




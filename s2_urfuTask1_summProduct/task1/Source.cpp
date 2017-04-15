/*Найти сумму произведений на их порядковый номер*/
#include <iostream>
using namespace std;

void main() {

	//кириллица в консоли
	setlocale(LC_CTYPE, "rus");

	int number;
	int countNumbers = 0;
	int multiplicateSum = 0;

	cout << "for display press 0" << '\n';
	cout << "Вводите любые целые числа" << '\n'
		 << "Для вывода суммы произведений на их порядковый номер нажмите 0" << '\n';

	while (true) {
		cin >> number;
		if (number == 0) {
			break;
		}
		countNumbers++;
		multiplicateSum += (countNumbers * number);
	}

	cout << "Сумма произведений:" << multiplicateSum << '\n';
	system("pause");
}


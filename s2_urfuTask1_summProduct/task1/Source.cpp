/*����� ����� ������������ �� �� ���������� �����*/
#include <iostream>
using namespace std;

void main() {

	//��������� � �������
	setlocale(LC_CTYPE, "rus");

	int number;
	int countNumbers = 0;
	int multiplicateSum = 0;

	cout << "for display press 0" << '\n';
	cout << "������� ����� ����� �����" << '\n'
		 << "��� ������ ����� ������������ �� �� ���������� ����� ������� 0" << '\n';

	while (true) {
		cin >> number;
		if (number == 0) {
			break;
		}
		countNumbers++;
		multiplicateSum += (countNumbers * number);
	}

	cout << "����� ������������:" << multiplicateSum << '\n';
	system("pause");
}


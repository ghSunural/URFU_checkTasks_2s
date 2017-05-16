

// Нахождение элементов массива на паре 07.02.17
#include <iostream>
using namespace std;
void entryArray(int &n, int *&a)
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void displayArray(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
}
int main()
{
	int k;
	int *m;

	entryArray(k, m);

	int min, max, p_min, p_max;
	min = max = m[0];//wow
	p_min = p_max = 0;
	for (int i = 1; i < k; i++)
	{
		int t = m[i];
		if (t < min)
		{
			min = t; p_min = i;
		}
		if (t > max)
		{
			max = t; p_max = i;
		}
	}
	int count = abs(p_max - p_min);
	if (count > 1)
	{
		count--;
		int *newm = new int[count];
		int begin, end;
		int kk = 0;
		begin = p_min < p_max ? p_min : p_max;
		end = p_max > p_min ? p_max : p_min;
		for (int i = begin + 1; i < end; i++)
		{
			newm[kk++] = m[i];
		}
		displayArray(count, newm);
	}
	else
	{
		cout << "No";
	}
	system("pause");
	return 0;
}

	/*
	regex posIntMask("^\d+$"); //-? первый символ минус
	if (regex_match(sMaxVerticesCount, posIntMask)) {
			iMaxVerticesCount = atoi(sMaxVerticesCount.c_str());
		}
		else {
			throw
				TPolygonException(TPolygonException::ILLEGAL_VALUE,
					"Неверные данные");
		}
		*/

		//iMaxVerticesCount = atoi(sMaxVerticesCount.c_str());

#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double F(double x0)
{
	return x0 - 1 / (3 + sin(3.6 * x0));
}

double F1(double x)
{
	return 1 / (3 + sin(3.6 * x));
}

double F2(double x)
{
	return -(cos(3.6 * x) * 3.6) / pow(3 + sin(3.6 * x), 2);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double a = 0, b = 0.85, e, x0, x1;
	int f = 1;

	cout << "Введите точность вычислений e (в ввиде 0.001):" << endl;
	cin >> e;

	if (abs(F2(a)) < 1) х0 = a; //	проверка условия сходимости и находждение первого приближения к корню
	else if (abs(F2(b)) < 1) x0 = b;
	else
	{
		cout << "Условие сходимости невыполнено";
		f = 0;
	}
	
	if (f == 1)
	{
		x1 = F1(x0); // следующее приближение к корню
		cout << "Новое приближение х1 = " << x1 << endl;
		while (abs(x0 - x1) > e) // приближение к корню до достижения нужной точности
		{
			x0 = x1;
			x1 = F1(x0);
			cout << "Новое приближение х1 = " << x1 << endl;
		}
		cout << "Корень:" << x1;
	}
	return 0;
}

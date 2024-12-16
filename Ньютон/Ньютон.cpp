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
	return 1 + (3.6 * cos(3.6 * x)) / pow(3 + sin(3.6 * x), 2);
}

double F2(double x)
{
	return -(pow(3.6, 2) * sin(3.6 * x) + (3 + sin(3.6 * x)) * 2 * pow(cos(3.6 * x), 2) * pow(3.6, 2)) / pow(3 + sin(3.6 * x), 4);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double a = 0, b = 0.85, e, x0, x1;

	cout << "Введите точность вычислений e (в ввиде 0.001):" << endl;
	cin >> e;

	if (F(a) * F2(a) > 0) x0 = a; // определение значения x0
	else x0 = b;

	x1 = x0 - F(x0) / F1(x0); // первое приближение к корню
	while (abs(x1 - x0) > e) // приближение к корню до достижения нужной точности
	{
		x0 = x1;
		x1 = x0 - F(x0) / F1(x0);
		cout << "Новое приближение х1 = " << x1 << endl;
	}
	cout << "Корень: " << x1 << endl;
	return 0;
}
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double F(double x0)
{
	return x0 - 1 / (3 + sin(3.6 * x0));
}

double R(double a, double b, double e)
{
	double x0 = (a + b) / 2;
	if (abs(a - b) <= e) return a;
	if (F(a) * F(x0) < 0) return R(a, x0, e);
	return R(x0, b, e);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double a = 0, b = 0.85, e;

	cout << "Введите точность вычислений e (в ввиде 0.001):" << endl;
	cin >> e;

	cout << R(a, b, e);
	return 0;
}
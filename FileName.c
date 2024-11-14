#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <stdio.h> 
#include <locale.h>  
#include <math.h>

double f1(double x) {
	double y;
	if (x <= 3) y = (x * x) - (3 * x) + 9;
	if (x > 3) y = 1 / ((x * x * x) + 3);
	return y;
}
double f2(double x) {
	double y;
	y = x * exp(sin(pow(x, 2)));

	return y;
}
int factorial(int N1)
{
	int f = 1;
	for (int i = 1; i <= N1; i++) {
		f = f * i;
	}
	return f;
}
double sin_n(double x1, int N) {
	double s = 0.0;
	double ch = x1;
	int zn = 1;
	int factorial(int N1);
	for (int k = 1; k <= N; k++) {
		s = s + ch;
		ch = pow(-1, k - 1) * (pow(x1, (2 * k) - 1)) / (factorial((2 * k) - 1));
	}
	return s;
}
double sin_eps(double x1, double eps) {
	double s = 0.0;
	double ch = x1;
	int zn = 1;
	int k = 1;
	while (fabs(ch) >= eps) {
		s += ch;
		ch = -ch * x1 * x1 / ((2 * k) * (2 * k + 1));
		zn *= -1;
		k++;
	}
	return s;
}
double main() {
	//1
	double f1(double x);
	double f2(double x);
	double c, d, x;
	setlocale(LC_ALL, "RUS");
	puts("Введите значение x");
	scanf_s("%lf", &x);
	c = f1(x);
	d = f2(x);
	printf("f1(x)=%lf , f2(x)=%lf\n ", c, d);
	printf("Произведение - %lf, разность квадратов - %lf, удвоенная сумма - %lf\n", c * d, (c * c) - (d * d), 2 * (c + d));

	//2.1
	double x1;
	puts("Введите значение x");
	scanf_s("%lf", &x1);
	printf("sin(x) = %2.2lf (стандартная библиотека Си)\n", sin(x1));

	//2.2
	double sin_n(double x1, int N);
	int N;
	printf("Введите число членов ряда N\n");
	scanf_s("%d", &N);
	double res1 = sin_n(x1, N);
	printf("sin(%.2f) = %.6f\n", x1, res1);


	//2.3
	double eps;
	double sin_eps(double x1, double eps);
	printf("Введите точность eps: ");
	scanf("%lf", &eps);
	double res2 = sin_eps(x, eps);
	printf("sin(%.2f) = %.6f\n", x, res2);
}


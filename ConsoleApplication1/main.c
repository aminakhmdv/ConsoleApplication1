#include <stdio.h>
#include <math.h>

double avtostep(double eps, double a, double b, double (*f)(double));
void func(double (*pf)(double), double (*f)(double), double eps, double a, double b);

double result;
double qarant, sredne;
double steps;
double eps1 = 1e-7; 
double eps2 = 1e-9; 
double eps3 = 1e-11; 

double kvadratur_form(double a, double b, double (*f)(double)) 
{
	return ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
}


// f(x) = sin x
double f1(double x)
{
	return sin(x);
}

double pf1(double x)
{
	return -cos(x);
}

// f(x) = 1/x , отрезок [a; b] не содержит 0;
double f2(double x)
{
	return 1 / x;
}

double pf2(double x)
{
	return log(x);
}



//f(x) = 10/(1+25*x2) ,  отрезок [a; b] (a < 0, b > 0).

double f3(double x)
{
	return 10 / (1 + (25 * (x * x)));
}

double pf3(double x)
{
	return 2 * (atan(5 * x));
}



int main() {
	double a, b;
	printf("a = ");
	scanf_s("%lf", &a);

	printf("b = ");
	scanf_s("%lf", &b);

	printf("For f1\n");
	func(pf1, f1, eps1, a, b);
	func(pf1, f1, eps2, a, b);
	func(pf1, f1, eps3, a, b);

	printf("For f2\n");
	func(pf2, f2, eps1, a, b);
	func(pf2, f2, eps3, a, b);
	func(pf2, f2, eps3, a, b);

	printf("For f3\n");
	func(pf3, f3, eps1, a, b);
	func(pf3, f3, eps3, a, b);
	func(pf3, f3, eps3, a, b);


	return 0;
}



double avtostep(double eps, double a, double b, double (*f)(double)) {

	double chi;
	double h = 0.1;
	double result = 0;
	double delta;
	qarant = 0, sredne = 0;
	steps = 0;


	while (a < b)
	{
		if (a + h > b)
		{
			h = b - a;
		}

		double I1 = kvadratur_form(a, a + h, f);
		double I2 = kvadratur_form(a, a + h / 2.0, f) + kvadratur_form(a + h / 2.0, a + h, f);

		delta = (I2 - I1) / 15;

		if (fabs(delta) <= eps) //если верно, то шаг принят
		{
			qarant = qarant + fabs(delta);
			sredne = sredne + delta;

			a = a + h;
			steps++;

			result = result + I2;
		}

		chi = pow(fabs(delta) / eps, 1.0 / 5.0);

		if (chi > 10)
		{
			chi = 10;
		}

		if (chi < 0.1)
		{
			chi = 0.1;
		}

		h = 0.95 * h / chi;
	}

	sredne = fabs(sredne);

	return result;
}

void func(double (*pf)(double), double (*f)(double), double eps, double a, double b) {

	result = avtostep(eps, a, b, f);
	double tocn = pf(b) - pf(a);
	double absol_err = fabs(result - tocn);

	printf("Result: %lg\n", result);
	printf("Exact: %lg\n", tocn);
	printf("Absolute error: %lg\n", absol_err);
	printf("Guaranteed error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iterations: %lg\n\n", steps);

}
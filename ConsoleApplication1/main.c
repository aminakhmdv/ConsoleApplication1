#include <stdio.h>
#include <math.h>

double avtostep(double eps, double a, double b, double (*f)(double));

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

double f4(double x)
{
	return 3 * x * sin(x*x*x) + 3 * x;
}



int main() {
	double a, b;
	printf("a = ");
	scanf_s("%lf", &a);

	printf("b = ");
	scanf_s("%lf", &b);

	//Для f1 при eps = 10^-7
	/*printf("For f1 at eps = 10^-7\n");

	result = avtostep(eps1, a, b, f1);
	printf("Result: %lg\n", result);

	double tocn1 = pf1(b) - pf1(a);
	double absol_err1 = fabs(result - tocn1);

	printf("Absolute error: %lg\n", absol_err1);
	printf("Guaranted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n");
	//Для f1 при eps = 10^-9
	printf("For f1 at eps = 10^-9\n");

	result = avtostep(eps2, a, b, f1);
	printf("Result: %lg\n", result);

	tocn1 = pf1(b) - pf1(a);
	absol_err1 = fabs(result - tocn1);

	printf("Absolute error: %lg\n", absol_err1);
	printf("Garanted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n");


	//Для f1 при eps = 10^-11
	printf("For f1 at eps = 10^-11\n");

	result = avtostep(eps3, a, b, f1);
	printf("Result: %lg\n", result);

	tocn1 = pf1(b) - pf1(a);
	absol_err1 = fabs(result - tocn1);

	printf("Absolute error: %lg\n", absol_err1);
	printf("Garanted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n\n\n\n\n");

	//Для f2 при eps = 10^-7
	printf("For f2 at eps = 10^-7\n");

	result = avtostep(eps1, a, b, f2);
	printf("Result: %lg\n", result);

	double tocn2 = pf2(b) - pf2(a);
	double absol_err2 = fabs(result - tocn2);

	printf("Absolute error: %lg\n", absol_err2);
	printf("Garanted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n");


	//Для f2 при eps = 10^-9
	printf("For f2 at eps = 10^-9\n");

	result = avtostep(eps2, a, b, f2);
	printf("Result: %lg\n", result);

	tocn2 = pf2(b) - pf2(a);
	absol_err2 = fabs(result - tocn2);

	printf("Absolute error: %lg\n", absol_err2);
	printf("Garanted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n");

	//Для f2 при eps = 10^-11
	printf("For f2 at eps = 10^-11\n");

	result = avtostep(eps3, a, b, f2);
	printf("Result: %lg\n", result);

	tocn2 = pf2(b) - pf2(a);
	absol_err2 = fabs(result - tocn2);

	printf("Absolute error: %lg\n", absol_err2);
	printf("Garanted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n\n\n\n\n");


	//Для f3 при eps = 10^-7
	printf("For f3 at eps = 10^-7\n");

	result = avtostep(eps1, a, b, f3);
	printf("Result: %lg\n", result);

	double tocn3 = pf3(b) - pf3(a);
	double absol_err3 = fabs(result - tocn3);

	printf("Absolute error: %lg\n", absol_err3);
	printf("Garanted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n");

	//Для f3 при eps = 10^-9
	printf("For f3 at eps = 10^-9\n");

	result = avtostep(eps2, a, b, f3);
	printf("Result: %lg\n", result);

	tocn3 = pf3(b) - pf3(a);
	absol_err3 = fabs(result - tocn3);

	printf("Absolute error: %lg\n", absol_err3);
	printf("Garanted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n");

	//Для f3 при eps = 10^-11
	printf("For f3 at eps = 10^-11\n");

	result = avtostep(eps3, a, b, f3);
	printf("Result: %lg\n", result);

	tocn3 = pf3(b) - pf3(a);
	absol_err3 = fabs(result - tocn3);

	printf("Absolute error: %lg\n", absol_err3);
	printf("Garanted error: %lg\n", qarant);
	printf("Normal error: %lg\n", sredne);
	printf("Iteratoin: %lg\n", steps);

	printf("\n\n\n\n\n");*/



	//Для f1 при eps = 10^-7
	printf("For f1 at eps = 10^-7\n");
	result = avtostep(eps1, a, b, f4);
	printf("Result: %lg\n", result);

	//Для f1 при eps = 10^-9
	printf("For f1 at eps = 10^-9\n");
	result = avtostep(eps2, a, b, f4);
	printf("Result: %lg\n", result);


	//Для f1 при eps = 10^-11
	printf("For f1 at eps = 10^-11\n");
	result = avtostep(eps3, a, b, f4);
	printf("Result: %lg\n", result);






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
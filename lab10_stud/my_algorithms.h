#pragma once

#include <complex>
#include "function.h"
#include "tab2d.h"
#include "element.h"

using std::complex;
using std::cout;
using std::endl;

/*
//--------------------------------------------------------------------------
template <typename T>
T zero(const Function<T>& f, T x, int& it)	throw(...);

//tylko dla typu complex<double>
template <int N>
void fractal(const Function<complex<double> >& f, const complex<double>& q) noexcept;

*/

bool is_close_to_zero(double value, double eps)
{
	return abs(value) < eps;
}

template <typename T>
bool is_close_to_zero(const complex<T> &value, T eps)
{
	return abs(value) < eps;
}

//--------------------------------------------------------------------------
template <typename T>
T zero(const Function<T> &f, T x, int &it)
{
	double eps = 1e-6; // dok�adno�� oblicze�
	int max_it = 50;   // maksymalna liczba iteracji

	T value = x - (f.value(x) / f.prim(x));

	it = 1;
	while (it < max_it && abs(f.prim(value)) > eps)
	{
		value = value - (f.value(value) / f.prim(value));
		++it;

		if (is_close_to_zero(f.value(value), eps))
			return value;
	}

	throw "Brak zbieznosci";
}

//--------------------------------------------------------------------------

template <int N>
void fractal(const Function<std::complex<double>> &f, const std::complex<double> &q) noexcept
{
	double qre = q.real();
	double qim = q.imag();

	tab2d<element, N> frrr; // wykorzystanie wzorca tablicy
	int it;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			try
			{
				zero(f, complex<double>(qre + i, qim + j), it);
			}
			catch (...)
			{
				// nawet je�li brak zbie�no�ci interesuje nas liczba wykonanych iteracji
			}
			frrr(i, j) = element(it);
		}

	cout << "FRAKTAL NEWTONA:" << endl;
	cout << frrr << endl;

	cout << "SKALA :" << endl;
	frrr.scale(std::cout);
	cout << endl
		 << endl;
}

//--------------------------------------------------------------------------

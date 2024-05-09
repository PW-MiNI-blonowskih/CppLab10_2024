#include <iostream>
using namespace std;
#include <complex>
#include "function.h"

#include "my_algorithms.h"
#include "tab2d.h"
#include "element.h"

using cmplx = complex<double>;

int main()
{
	/*
	cout << "---------------  ETAP 1: double -----------------------------------" << endl;
	try
	{
		double wsp1[]{1, 2, 3}; // w(x)=1+2*x+3*x^2
		double x1 = 3;

		Polynomial w1;
		w1.generate1(wsp1, 3);

		cout << endl
			 << "funkcja w1(x1) :" << endl;
		cout << " w1(x1) =" << w1.value(x1) << endl;
		cout << " w1'(x1)=" << w1.prim(x1) << endl;
	}
	catch (...)
	{
		cout << "Error Etap1: Nie wykonano obliczen dla wielomianu w1" << endl;
	}
	//-----------------------------------------------------------------------
	try
	{
		double zera[] { 1, 3, 5 };	//w(x)=(x-1)*(x-2)*(x-3)
		double x11 = 7;

		Polynomial w11;
		w11.generate2(zera,3);

		cout << "funkcja w11(x) :" << endl;
		cout << " w11(x11) =" << w11.value(x11) << endl;
		cout << " w11'(x11)=" << w11.prim(x11) << endl;

	}
	catch (...)
	{
		cout << "Error Etap1: Nie wykonano obliczen dla wielomianu w11" << endl;
	}

	*/

	cout << "---------------  ETAP 2: function template  -----------------------" << endl;
	// dla T=double

	try
	{
		double wsp1[]{1, 2, 3}; // w(x)=1+2*x+3*x^2
		double x1 = 3;

		Polynomial<double> w1;
		w1.generate1(wsp1, 3);

		cout << endl
			 << "funkcja w1(x) :" << endl;
		cout << " w1(x1) =" << w1.value(x1) << endl;
		cout << " w1'(x1)=" << w1.prim(x1) << endl;
	}
	catch (...)
	{
		cout << "Error Etap2: Nie wykonano obliczen dla wielomianu w1" << endl;
	}

	//-----------------------------------------------------------------------

	try
	{
		double zera[]{1, 3, 5}; // w(x)=(x-1)*(x-2)*(x-3)
		double x11 = 7;
		Polynomial<double> w11;

		w11.generate2(zera, 3);

		cout << "funkcja w11(x) :" << endl;
		cout << " w11(x11) =" << w11.value(x11) << endl;
		cout << " w11'(x11)=" << w11.prim(x11) << endl;
	}
	catch (...)
	{
		cout << "Error Etap2: Nie wykonano obliczen dla wielomianu w11" << endl;
	}

	// dla T=cmplx
	//------------------------------------------------------------------------

	try
	{
		cmplx wsp1[]{cmplx(1, 2), cmplx(3, 4), cmplx(5, 6)};
		cmplx x1 = cmplx(3, -7);

		Polynomial<cmplx> w2;
		w2.generate1(wsp1, 3);

		cout << endl
			 << "funkcja w2(x) :" << endl;
		cout << " w2(x1) = " << w2.value(x1) << endl;
		cout << " w2'(x1)= " << w2.prim(x1) << endl;
	}
	catch (...)
	{
		cout << "Error Etap2: Nie wykonano obliczen dla wielomianu w2" << endl;
	}
	//-----------------------------------------------------------------------
	try
	{
		cmplx zera[]{cmplx(1, 2), cmplx(3, 4), cmplx(5, 6)};
		cmplx x11 = cmplx(3, -7);

		Polynomial<cmplx> w22;
		w22.generate2(zera, 3);

		cout << "funkcja w22(x) :" << endl;
		cout << " w22(x11) = " << w22.value(x11) << endl;
		cout << " w22'(x11)= " << w22.prim(x11) << endl;
	}
	catch (...)
	{
		cout << "Error Etap2: Nie wykonano obliczen dla wielomianu w22" << endl;
	}

	cout << "---------------  ETAP 3 - zero  ----------------------------" << endl;

	/*

	try
	{
		double wsp[] { 1, 3, 5, 8 };

		Polynomial<double> w;
		w.generate1(wsp, 4);

		int it;


		try
		{
			double z = zero(w, 7., it);
			cout << "pierwiastek z=" << z << endl;
			cout << "liczba iteracji it=" << it << endl;
			cout << "f(z)=" << w.value(z) << endl;
		}
		catch (const char* s)
		{
			cout << s << endl;
		}

	}
	catch (...)
	{
		cout << "Error Etap3: nie znaleziono pierwiastka dla wielomianu w" << endl;
	}


	//---------------------------------------------------------------
	try
	{
		cmplx wsp[] { cmplx(1,2), cmplx(3,4), cmplx(5,6), cmplx(7,8) };

		Polynomial<cmplx> w1;
		w1.generate1(wsp, 4);

		int it;

		try
		{
			cmplx z1 = zero(w1, cmplx(0), it);
			cout << "pierwiastek z1=" << z1 << endl;
			cout << "liczba iteracji it=" << it << endl;
			cout << "f1(z1)=" << w1.value(z1) << endl;
		}
		catch (const char* s)
		{
			cout << s << endl;
		}

	}
	catch (...)
	{
		cout << "Error Etap3: nie znaleziono pierwiastka dla wielomianu w1" << endl;
	}
	//---------------------------------------------------------------
	try
	{
		cmplx zera[] { cmplx(1,2), cmplx(3,4), cmplx(5,6), cmplx(7,8) };

		Polynomial<cmplx> w2;
		w2.generate2(zera, 4);

		int it;

		try
		{
			cmplx z2 = zero(w2, cmplx(0), it);
			cout << "pierwiastek z2=" << z2 << endl;
			cout << "liczba iteracji it=" << it << endl;
			cout << "f2(z2)=" << w2.value(z2) << endl;
		}
		catch (const char* s)
		{
			cout << s << endl;
		}

	}
	catch (...)
	{
		cout << "Error Etap3: nie znaleziono pierwiastka dla wielomianu w2" << endl;
	}

	*/

	cout << "---------------  ETAP 4 - fraktale --------------------------------" << endl;

	/*
	const int K = 8;	//np K=4, K=5, K=6, K=7, K=8, K=9
	cmplx wsp3[K], wsp4[K];
	for (int i = 0; i < K; i++) {
		wsp3[i] = cmplx(1);
		wsp4[i] = i%2? cmplx(-2.*i,0):cmplx(2.*i,i);
	}

	//---------------------------------------
	try
	{
		Polynomial<cmplx> w3;
		w3.generate1(wsp3, K);

		fractal<50>(w3, cmplx(-25, -25));
	}
	catch (...)
	{
		cout << "Error Etap4: Nie wygenerowano fraktala dla wielomianu w3" << endl;
	}

	//---------------------------------------
	try
	{
		Polynomial<cmplx> w4;
		w4.generate2(wsp4, K);

		fractal<70>(w4, cmplx(0));
	}
	catch (...)
	{
		cout << "Error Etap4: Nie wygenerowano fraktala dla wielomianu w4" << endl;
	}


	*/
}

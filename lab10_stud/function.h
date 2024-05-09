#pragma once

#include <iostream>

class Function
{

public:
	Function() = default;
	Function(const Function &) = delete;
	Function &operator=(const Function &) = delete;

	virtual double value(double x) const = 0;
	virtual double prim(double x) const = 0;

	virtual ~Function() {}
};

//---------------------------------------------------
class Const : public Function
{
	double a;

public:
	Const(double a) : a{a} {}

	double value(double x) const override { return a; }
	double prim(double x) const override { return 0; }
};

class X : public Function
{
public:
	X() {}

	double value(double x) const override { return x; }
	double prim(double x) const override { return 1; }
};

class Plus : public Function
{
	Function *func1, *func2;

public:
	Plus(Function *func1, Function *func2) : func1{func1}, func2{func2} {}
	~Plus()
	{
		delete func1;
		delete func2;
	}

	double value(double x) const override
	{
		return func1->value(x) + func2->value(x);
	}

	double prim(double x) const override
	{
		return func1->prim(x) + func2->prim(x);
	}
};

class Minus : public Function
{
	Function *func1, *func2;

public:
	Minus(Function *func1, Function *func2) : func1{func1}, func2{func2} {}
	~Minus()
	{
		delete func1;
		delete func2;
	}

	double value(double x) const override
	{
		return func1->value(x) - func2->value(x);
	}

	double prim(double x) const override
	{
		return func1->prim(x) - func2->prim(x);
	}
};

class Multiplies : public Function
{
	Function *func1, *func2;

public:
	Multiplies(Function *func1, Function *func2) : func1{func1}, func2{func2} {}
	~Multiplies()
	{
		delete func1;
		delete func2;
	}

	double value(double x) const override
	{
		return func1->value(x) * func2->value(x);
	}

	double prim(double x) const override
	{
		return (func1->prim(x) * func2->value(x)) + (func2->prim(x) * func1->value(x));
	}
};

//--------------------------------------------------------------------------

class Polynomial : public Function
{
	Function *func;

public:
	Polynomial() : func{nullptr} {}
	~Polynomial() { delete func; }

	double value(double x) const override { return func->value(x); }
	double prim(double x) const override { return func->prim(x); }

	void generate1(double *c, int n)
	{
		Function *temp_func = new Const(c[n - 1]);

		for (int i{n - 2}; i >= 0; --i)
		{
			temp_func = new Plus(new Const(c[i]), new Multiplies(new X(), temp_func));
		}

		func = temp_func;
	}

	void generate2(double *z, int n)
	{
		Function *temp_func = new Const(1);

		for (int i{0}; i < n; ++i)
		{
			temp_func = new Multiplies(new Minus(new X(), new Const(z[i])), temp_func);
		}

		func = temp_func;
	}
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

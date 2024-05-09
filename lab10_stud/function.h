#pragma once

#include <iostream>

template <typename T>
class Function
{

public:
	Function() = default;
	Function(const Function &) = delete;
	Function &operator=(const Function &) = delete;

	virtual T value(T x) const = 0;
	virtual T prim(T x) const = 0;

	virtual ~Function() {}
};

//---------------------------------------------------
template <typename T>
class Const : public Function<T>
{
	T a;

public:
	Const(T a) : a{a} {}

	T value(T x) const override { return a; }
	T prim(T x) const override { return 0; }
};

template <typename T>
class X : public Function<T>
{
public:
	X() {}

	T value(T x) const override { return x; }
	T prim(T x) const override { return 1; }
};

template <typename T>
class Plus : public Function<T>
{
	Function<T> *func1, *func2;

public:
	Plus(Function<T> *func1, Function<T> *func2) : func1{func1}, func2{func2} {}
	~Plus()
	{
		delete func1;
		delete func2;
	}

	T value(T x) const override
	{
		return func1->value(x) + func2->value(x);
	}

	T prim(T x) const override
	{
		return func1->prim(x) + func2->prim(x);
	}
};

template <typename T>
class Minus : public Function<T>
{
	Function<T> *func1, *func2;

public:
	Minus(Function<T> *func1, Function<T> *func2) : func1{func1}, func2{func2} {}
	~Minus()
	{
		delete func1;
		delete func2;
	}

	T value(T x) const override
	{
		return func1->value(x) - func2->value(x);
	}

	T prim(T x) const override
	{
		return func1->prim(x) - func2->prim(x);
	}
};

template <typename T>
class Multiplies : public Function<T>
{
	Function<T> *func1, *func2;

public:
	Multiplies(Function<T> *func1, Function<T> *func2) : func1{func1}, func2{func2} {}
	~Multiplies()
	{
		delete func1;
		delete func2;
	}

	T value(T x) const override
	{
		return func1->value(x) * func2->value(x);
	}

	T prim(T x) const override
	{
		return (func1->prim(x) * func2->value(x)) + (func2->prim(x) * func1->value(x));
	}
};

//--------------------------------------------------------------------------

template <typename T>
class Polynomial : public Function<T>
{
	Function<T> *func;

public:
	Polynomial() : func{nullptr} {}
	~Polynomial() { delete func; }

	T value(T x) const override { return func->value(x); }
	T prim(T x) const override { return func->prim(x); }

	void generate1(T *c, int n)
	{
		Function<T> *temp_func = new Const<T>(c[n - 1]);

		for (int i{n - 2}; i >= 0; --i)
		{
			temp_func = new Plus<T>(new Const<T>(c[i]), new Multiplies<T>(new X<T>(), temp_func));
		}

		func = temp_func;
	}

	void generate2(T *z, int n)
	{
		Function<T> *temp_func = new Const<T>(1);

		for (int i{0}; i < n; ++i)
		{
			temp_func = new Multiplies<T>(new Minus<T>(new X<T>(), new Const<T>(z[i])), temp_func);
		}

		func = temp_func;
	}
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

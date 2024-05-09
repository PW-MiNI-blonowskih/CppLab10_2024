#pragma once

#include <iostream>

   

class Function
{

public:
	Function() = default;
	Function(const Function&) = delete;
	Function& operator=(const Function&) = delete;

	virtual double value(double x) const = 0;
	virtual double prim(double x) const = 0;

	virtual ~Function() { }
};

//---------------------------------------------------
class Const :public Function
{
	//uzupe³nij


};


class X :public Function
{
	//uzupe³nij



};


class Plus : public Function
{
	//uzupe³nij



};


class Minus : public Function
{
	//uzupe³nij


};


class Multiplies : public Function
{
	//uzupe³nij



};

//--------------------------------------------------------------------------


class Polynomial : public Function
{
	//uzupe³nij




};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



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
	//uzupe�nij


};


class X :public Function
{
	//uzupe�nij



};


class Plus : public Function
{
	//uzupe�nij



};


class Minus : public Function
{
	//uzupe�nij


};


class Multiplies : public Function
{
	//uzupe�nij



};

//--------------------------------------------------------------------------


class Polynomial : public Function
{
	//uzupe�nij




};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#pragma once
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

class element
{
	static const char z = '#';
	int color;

public:
	element(int color = 0) : color(color) {}

	element &operator++()
	{
		color++;
		return *this;
	}

	friend bool operator>(const element &e1, const element &e2)
	{
		return e1.color > e2.color;
	}
	friend bool operator<(const element &e1, const element &e2)
	{
		return e1.color < e2.color;
	}

	friend std::ostream &operator<<(std::ostream &out, const element &el)
	{
#ifdef _WIN32
		// ustawia kolor do wypisania znaku
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), el.color);
		out << el.z;

		// powr�t do warto�ci domy�lnych konsoli
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

#elif __linux__
		out << "\033[38;5;" << el.color << "m";
		out << el.z;
		out << "\033[0m";

#endif
		return out;
	}
};

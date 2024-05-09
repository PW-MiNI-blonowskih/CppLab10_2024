#pragma once
#include <iostream>

template <typename T, int N>
class tab2d
{
	T tab[N][N];

public:
	tab2d();
	T &operator()(int i, int j);
	T maks() const;
	T min() const;
	void scale(std::ostream &out) const;

	friend std::ostream &operator<<(std::ostream &out, const tab2d &t);
};

template <typename T, int N>
std::ostream &operator<<(std::ostream &out, const tab2d<T, N> &t)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			out << t.tab[i][j];
		out << endl;
	}
	return out;
}

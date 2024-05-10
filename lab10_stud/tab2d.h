#pragma once
#include <iostream>

template <typename T, int N>
class tab2d
{
	T tab[N][N];

public:
	tab2d()
	{
		for (int i{0}; i < N; ++i)
			for (int j{0}; j < N; ++j)
				tab[i][j] = 0;
	}

	T &operator()(int i, int j)
	{
		return tab[i][j];
	}

	T maks() const
	{
		T m = tab[0][0];

		for (int i{0}; i < N; ++i)
			for (int j{0}; j < N; ++j)
				if (tab[i][j] > m)
					m = tab[i][j];

		return m;
	}

	T min() const
	{
		T m = tab[0][0];

		for (int i{0}; i < N; ++i)
			for (int j{0}; j < N; ++j)
				if (tab[i][j] < m)
					m = tab[i][j];

		return m;
	}

	void scale(std::ostream &out) const
	{
		T m1 = min();
		T m2 = maks();

		while (!(m1 > m2))
		{
			out << m1;
			++m1;
		}
	}

	template <typename U, int M>
	friend std::ostream &operator<<(std::ostream &out, const tab2d<U, M> &t);
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

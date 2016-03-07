#include "Mandlebrot.h"

/// Initialization consists of setting the maximun number of iterations.
Mandlebrot::Mandlebrot(int maxIter)
{
	_maxIter = maxIter;
};

int Mandlebrot::operator() (std::complex<double> c)
{
	/// The initial
	std::complex<double> fNow = c;

	int iter = 0;
	while (iter < _maxIter && abs(fNow) <= 2)
	{
		iter++;
		fNow = pow(fNow, 2) + c;
	}

	return iter;
};

int Mandlebrot::operator() (double reC, double imC)
{
	std::complex<double> c = std::complex<double>(reC, imC);
	return operator() (c);
};
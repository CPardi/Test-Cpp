#ifndef __Mandlebrot_h_included__
#define __Mandlebrot_h_included__

#include<complex>

public struct Mandlebrot
{
private:
	int _maxIter;

public:
	Mandlebrot(int maxIter);

	int operator() (std::complex<double> c);

	int operator() (double reC, double imC);
};

#endif // __Mandlebrot_h_included__
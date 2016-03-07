#ifndef __Mandlebrot_h_included__
#define __Mandlebrot_h_included__

#include<complex>

/// A functor to calculate the number of iterations before convergence of the mandlebrot sequence.

/// A simple escape time algorithm as described on Wikipedia is used for calculations.
public struct Mandlebrot
{
private:
	/// The maximun number of iterations to consider in the escape time algorithm.
	int _maxIter;

public:
	/// Initializes a new Mandlebrot instance.
	Mandlebrot(int maxIter);

	/// Calculate the number of iterations for f(z_n+1) = f(z_n)^2 + c, while |f(z)|<=2, from a complex number c.
	int operator() (std::complex<double> c);

	/// Calculate the number of iterations for f(z_n+1) = f(z_n)^2 + c, while |f(z)|<=2, from the real and imaginary components of c.
	int operator() (double reC, double imC);
};

#endif // __Mandlebrot_h_included__
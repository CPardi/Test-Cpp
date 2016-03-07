#include "Grid.h"

template<class resultType> 
Grid<resultType>::Grid(int xPoints, int yPoints, resultType x0, resultType xMax, resultType y0, resultType yMax)
{
	// Set the classes public fields.
	XPoints = xPoints;
	YPoints = yPoints;

	// Intialize vectors.
	_xValues.resize(xPoints);
	_yValues.resize(yPoints);

	// Calculate the grid widths.
	double xWidth = xMax - x0;
	double yWidth = yMax - y0;

	// Calculate the grid spacings.
	double dx = xWidth / (xPoints - 1);
	double dy = yWidth / (yPoints - 1);

	// Fill values for the x-axis.
	for (int i = 0; i < xPoints; i++)
	{
		_xValues[i] = x0 + i*dx;
	}

	// Fill values for the y-axis.
	for (int j = 0; j < yPoints; j++)
	{
		_yValues[j] = y0 + j*dy;
	}
};

template<class resultType> 
resultType Grid<resultType>::X(int i)
{
	return _xValues[i];
};

template<class resultType> 
resultType Grid<resultType>::Y(int j)
{
	return _yValues[j];
};
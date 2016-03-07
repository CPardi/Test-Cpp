#include "Grid.h"

template<class resultType> Grid<resultType>::Grid(int xPoints, int yPoints, resultType x0, resultType xMax, resultType y0, resultType yMax)
{
	XPoints = xPoints;
	YPoints = yPoints;

	_xValues.resize(xPoints);
	_yValues.resize(yPoints);

	double xWidth = xMax - x0;
	double yWidth = yMax - y0;

	double dx = xWidth / (xPoints - 1);
	double dy = yWidth / (yPoints - 1);

	for (int i = 0; i < xPoints; i++)
	{
		_xValues[i] = x0 + i*dx;
}

for (int j = 0; j < yPoints; j++)
{
	_yValues[j] = y0 + j*dy;
}
};

template<class resultType> resultType Grid<resultType>::X(int i)
{
	return _xValues[i];
};

template<class resultType> resultType Grid<resultType>::Y(int j)
{
	return _yValues[j];
};


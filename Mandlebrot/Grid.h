#ifndef __Grid_h_included__
#define __Grid_h_included__

#include<vector>

/// This class represents a two dimensional grid.

/// @param resultType The type to return the x-y coordinate as.
template<class resultType>
public class Grid
{
private:
	/// The x-values of the grid.
	std::vector<resultType> _xValues;

	/// The y-values of the grid.
	std::vector<resultType> _yValues;

public:
	/// Intializes a new Grid instance.
	/// @param xPoints The number of points to represent the x-axis.
	/// @param yPoints The number of points to represent the y-axis.
	/// @param x0 The value of x at the zeroth point.
	/// @param xMax The value of x at the xPoint point.
	/// @param y0 The value of y at the zeroth point.
	/// @param yMax The value of y at the yPoint point.
	Grid(int xPoints, int yPoints, resultType x0, resultType xMax, resultType y0, resultType yMax);

	/// The number of points used to represent the x-axis.
	int XPoints;

	/// The number of points used to represent the y-axis.
	int YPoints;

	/// The value of the x-coordinate for the index i.
	/// @param i The x-axis index for the wanted grid value.
	resultType X(int i);

	/// The value of the y-coordinate for the index j.
	/// @param j The y-axis index for the wanted grid value.
	resultType Y(int j);
};

#include "Grid.hxx"

#endif // __Grid_h_included__
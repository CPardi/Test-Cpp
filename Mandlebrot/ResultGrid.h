#ifndef __ResultGrid_h_included__
#define __ResultGrid_h_included__

#include<vector>

#include "Grid.h"

/// This class hold the values of a function evaluated on a two dimensional grid.

/// @param resultType The return type of the calculator functor.
/// @param calculator THe type of the functor passed in the constructor.
template<class resultType, class calculator>
public class ResultGrid
{
private:
	/// The function values evaluated on a two dimensional grid.
	std::vector<std::vector<resultType>> _value;

public:
	/// Initializes a ResultGrid instance.
	/// @param grid The grid to evaluate the function at.
	/// @param calc The functor from which to calcuate function values.
	ResultGrid(Grid<double> grid, calculator calc);

	/// The number of points used to represent the x-axis.
	int XPoints;

	/// The number of points used to represent the y-axis.
	int YPoints;

	/// The value of a function at the indecies i and j.
	/// @param i The x-axis index for the wanted value.
	/// @param j The y-axis index for the wanted value.
	resultType Point(int i, int j);
};

#include "ResultGrid.hxx"

#endif // __ResultGrid_h_included__
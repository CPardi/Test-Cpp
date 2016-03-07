#include "ResultGrid.h"

template<class resultType, class calculator> 
ResultGrid<resultType, calculator>::ResultGrid(Grid<double> grid, calculator calc)
{
	XPoints = grid.XPoints;
	YPoints = grid.YPoints;
	_value.resize(grid.XPoints, std::vector<resultType>(grid.YPoints, 0));

	for (int i = 0; i < XPoints; i++)
	{
		for (int j = 0; j < YPoints; j++)
		{
			_value[i][j] = calc(grid.X(i), grid.Y(j));
		}
	}
};

template<class resultType, class calculator> 
resultType ResultGrid<resultType, calculator>::Point(int i, int j)
{
	return _value[i][j];
};

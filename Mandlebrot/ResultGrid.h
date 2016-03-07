#ifndef __ResultGrid_h_included__
#define __ResultGrid_h_included__

#include<vector>

#include "Grid.h"

template<class resultType, class calculator>
public class ResultGrid
{
private:
	std::vector<std::vector<resultType>> _value;

public:
	ResultGrid(Grid<double> grid, calculator calc);

	int XPoints, YPoints;

	resultType Point(int i, int j);
};

#include "ResultGrid.hxx"

#endif // __ResultGrid_h_included__
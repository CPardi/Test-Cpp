#ifndef __Grid_h_included__
#define __Grid_h_included__

#include<vector>

template<class resultType>
public class Grid
{
private:
	std::vector<resultType> _xValues;
	std::vector<resultType> _yValues;

public:
	Grid(int xPoints, int yPoints, resultType x0, resultType xMax, resultType y0, resultType yMax);

	int XPoints, YPoints;

	resultType X(int i);

	resultType Y(int j);
}; 

#include "Grid.hxx"

#endif // __Grid_h_included__
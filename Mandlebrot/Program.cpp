#using <System.Windows.Forms.dll>
#using <System.dll>
#using <System.Drawing.dll>
#include <complex>
#include <vector>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

template<class resultType>
public class Grid
{
private:
	std::vector<resultType> _xValues;
	std::vector<resultType> _yValues;

public:
	Grid(int xPoints, int yPoints, resultType x0, resultType xMax, resultType y0, resultType yMax)
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
	}

	int XPoints, YPoints;

	resultType X(int i)
	{
		return _xValues[i];
	}
	
	resultType Y(int j)
	{
		return _yValues[j];
	}
};

template<class resultType, class calculator>
public class ResultGrid
{
private:
	std::vector<std::vector<resultType>> _value;

public:
	ResultGrid(Grid<double> grid, calculator calc)
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
	}

	int XPoints, YPoints;

	resultType Point(int i, int j)
	{
		if (i < 0 || i >= XPoints)
		{
			throw gcnew IndexOutOfRangeException("Argument 'i=" + i + "' was out of range.");
		}

		if (j < 0 || j >= YPoints)
		{
			throw gcnew IndexOutOfRangeException("Argument 'j=" + j + "' was out of range.");
		}

		return _value[i][j];
	}
};

public struct Mandlebrot
{
private:
	int _maxIter;
	
public:
	Mandlebrot(int maxIter)
	{
		_maxIter = maxIter;
	}

	int operator() (std::complex<double> c)
	{		
		std::complex<double> fNow = c;

		int iter = 0;
		while (iter < _maxIter && abs(fNow) <= 2)
		{
			iter++;
			fNow = pow(fNow, 2) + c;
		}

		return iter;
	}

	int operator() (double reC, double imC)
	{
		std::complex<double> c = std::complex<double>(reC, imC);
		return operator() (c);
	}
};

public ref class Program : public Form
{
private:
	const int _numBrushes = 128;
	array<Color>^ _brushes = gcnew array<Color>(_numBrushes);
	PictureBox ^box = gcnew PictureBox();

	Bitmap^ redraw()
	{			
		Rectangle canvasRectangle = ClientRectangle;
		box->SetBounds(canvasRectangle.X, canvasRectangle.Y, canvasRectangle.Width, canvasRectangle.Height);
		Mandlebrot mandle = (_numBrushes - 1);
		Grid<double> grid(canvasRectangle.Width, canvasRectangle.Height, -2.5, 1.0, -1.0, 1.0);
		ResultGrid<int, Mandlebrot> results(grid, mandle);

		Bitmap ^bitmap = gcnew Bitmap(canvasRectangle.Width, canvasRectangle.Height);

		for (int i = 0; i < canvasRectangle.Width; i++)
		{
			for (int j = 0; j < canvasRectangle.Height; j++)
			{
				bitmap->SetPixel(i, j, _brushes[results.Point(i,j)]);
			}
		}

		return bitmap;
	}
	
	void onResize(System::Object^ object, EventArgs^ e)
	{
		box->Image = redraw();
	}

public:
	Program() {
		Text = "Mandlebrot";
		SetBounds(1, 1, 300, 300);
		
		for (int i = 0; i < _numBrushes; i++)
		{
			_brushes[i] = Color::FromArgb(255, 128-(Byte)i, 0, 0);
		}
		
		this->Controls->Add(box);
		box->Image = redraw();

		this->ResizeEnd += gcnew EventHandler(this, &Program::onResize);
	}
};

int main() {

	Application::Run(gcnew Program);

}
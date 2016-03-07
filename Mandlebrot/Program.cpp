#include "Program.h"

	Program::Program() 
	{
		Text = "Mandlebrot";
		SetBounds(1, 1, 300, 300);

		for (int i = 0; i < _numBrushes; i++)
		{
			_brushes[i] = Color::FromArgb(255, 128 - (Byte)i, 0, 0);
		}

		this->Controls->Add(box);
		box->Image = redraw();

		this->ResizeEnd += gcnew EventHandler(this, &Program::onResize);
	};
	
	void Program::onResize(System::Object^ object, EventArgs^ e)
	{
		box->Image = redraw();
	};

	Bitmap^ Program::redraw()
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
				bitmap->SetPixel(i, j, _brushes[results.Point(i, j)]);
			}
		}

		return bitmap;
	};
#include "Program.h"

/// Sets the form's text, bounds and resize handler. Also initalizates the color palete and adds a picture box control.
Program::Program()
{
	// Setup the forms properties.
	Text = "Mandlebrot";
	SetBounds(1, 1, 300, 300);
	this->ResizeEnd += gcnew EventHandler(this, &Program::onResize);
	this->Controls->Add(box);
	
	// Intialize the color palete.
	for (int i = 0; i < _numBrushes; i++)
	{
		_color[i] = Color::FromArgb(255, 128 - (Byte)i, 0, 0);
	}

	// Draw the initial mandlebrot.
	box->Image = redraw();
};

/// When the form is resized call the redraw routine.
void Program::onResize(System::Object^ object, EventArgs^ e)
{
	box->Image = redraw();
};

/// A grid with the same number of point as the number of pixel within the picturebox is constructed. Result are then calculated
/// on the points of this grid and the value used with the color pallete to set each pixel in a bitmap.
Bitmap^ Program::redraw()
{
	// Make the picture box fille the forms client area.
	Rectangle canvasRectangle = ClientRectangle;
	box->SetBounds(canvasRectangle.X, canvasRectangle.Y, canvasRectangle.Width, canvasRectangle.Height);

	// Setup a mandlebrot functor, a grid and a results grid.
	Mandlebrot mandle = (_numBrushes - 1);
	Grid<double> grid(canvasRectangle.Width, canvasRectangle.Height, -2.5, 1.0, -1.0, 1.0);
	ResultGrid<int, Mandlebrot> results(grid, mandle);

	// Create the bitmap that will store the graph.
	Bitmap ^bitmap = gcnew Bitmap(canvasRectangle.Width, canvasRectangle.Height);

	// Set the pixels in the bitmap.
	for (int i = 0; i < canvasRectangle.Width; i++)
	{
		for (int j = 0; j < canvasRectangle.Height; j++)
		{
			bitmap->SetPixel(i, j, _color[results.Point(i, j)]);
		}
	}

	// Return the bitmap.
	return bitmap;
};
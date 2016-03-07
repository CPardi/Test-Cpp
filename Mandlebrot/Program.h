#ifndef __Program_h_included__
#define __Program_h_included__

#include <complex>

#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

#include "Mandlebrot.h"
#include "Grid.h"
#include "ResultGrid.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

/// The main form where results are displayed.

/// This form displays the results of the mandlebrot calculation drawn onto a .Net PictureBox element.
public ref class Program : public Form
{
private:
	/// The number of colors within the color palete.
	const int _numBrushes = 128;

	/// The color palate used in the display of results.
	array<Color>^ _color = gcnew array<Color>(_numBrushes);

	/// The .Net container that the mandlebrot results will be displayed.
	PictureBox ^box = gcnew PictureBox();

	/// Returns a .Net Bitmap containing the drawn mandlebrot results
	Bitmap^ redraw();

	/// Specifies that the mandlebrot results should be recalcuated on resizing the form.
	void onResize(System::Object^ object, EventArgs^ e);

public:
	/// Intializes the Program class.
	Program();
};

#endif // __Program_h_included__

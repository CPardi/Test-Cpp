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

public ref class Program : public Form
{
private:
	const int _numBrushes = 128;
	
	array<Color>^ _brushes = gcnew array<Color>(_numBrushes);
	
	PictureBox ^box = gcnew PictureBox();
	
	Bitmap^ redraw();

	void onResize(System::Object^ object, EventArgs^ e);

public:
	Program();
};

#endif // __Program_h_included__


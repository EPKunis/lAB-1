#include "Widget.h"

wxIMPLEMENT_APP(Widget);

Widget::Widget()
{
}

Widget::~Widget()
{
}

bool Widget::OnInit()
{
	frame = new cMain;
	frame->Show();

	return true;
}

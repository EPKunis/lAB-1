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
	m_frame1 = new cMain;
	m_frame1->Show();

	return true;
}

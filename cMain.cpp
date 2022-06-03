#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "LAB 1 MIN SWEAPER", wxPoint(30,30), wxSize(800, 600))
{
	button1 = new wxButton(this, wxID_ANY, "Click Me", wxPoint(10, 10), wxSize(150, 50));
	//text = new wxText(this, wxID_ANY, "Click Me", wxPoint(10, 10), wxSize(150, 50));
	button1 = new wxButton(this, wxID_ANY, "Click Me", wxPoint(10, 10), wxSize(150, 50));
}

cMain::~cMain()
{
}

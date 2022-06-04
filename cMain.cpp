#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(10001, OnButtonClicked)

wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "LAB 1 MIN SWEAPER", wxPoint(30,30), wxSize(800, 600))
{
	btn = new wxButton * [nFieldWidth *  nFieldHeight];
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	
	evt.Skip();
}

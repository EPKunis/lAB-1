#pragma once

#include "wx/wx.h"
class cMain : public wxFrame
{
	public:
		cMain();
		~cMain();

public:
	wxButton* button1 = nullptr;
	wxTextCtrl* text = nullptr;
	wxListBox* box = nullptr;
};


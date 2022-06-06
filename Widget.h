#pragma once
#include "wx/wx.h"
#include "cMain.h"

class Widget : public wxApp
{
public:
	Widget();
	~Widget();


private:
	cMain* frame = nullptr;

public:
	virtual bool OnInit();
};





#pragma once
#include "wx/wx.h"
#include "cMain.h"

class Widget : public wxApp
{
public:
	Widget();
	~Widget();


private:
	cMain* m_frame1 = nullptr;

public:
	virtual bool OnInit();
};





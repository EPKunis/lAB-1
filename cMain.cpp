#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(10001, OnButtonClicked)

wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "LAB 1 MIN SWEAPER", wxPoint(30,30), wxSize(800, 600))
{
	btn = new wxButton * [nFieldWidth *  nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldHeight, nFieldWidth, 0, 0);

	nField = new int[nFieldWidth * nFieldHeight];

	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
			grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);

			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);

			nField[y * nFieldWidth + x] = 0;
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	
	int x = (evt.GetId() - 10000) % nFieldWidth;
	int y = (evt.GetId() - 10000) / nFieldWidth;

	if (bFirstClick)
	{
		int mines = 30;

		while (mines)
		{
			int mine_x = rand() % nFieldWidth;
			int mine_y = rand() % nFieldHeight;

			if (nField[mine_y * nFieldWidth + mine_x] == 0 && mine_x != x && mine_y != y)
			{
				nField[mine_y * nFieldWidth + mine_x] = -1;
				mines--;
			}
		}

		bFirstClick = false;
	}

	btn[y * nFieldWidth + x]->Enable(false);

	if (nField[y*nFieldWidth + x] == -1)
	{
		wxMessageBox("KKKKKAAAAAAAAAA BBOOOOOOOOOOOOM - GAME OVER");

		bFirstClick = true;
		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{
				nField[y * nFieldWidth + x] = 0;
				btn[y * nFieldWidth + x]->SetLabel("");
				btn[y * nFieldWidth + x]->Enable(true);
			}
		}
	}
	else
	{
		int mine_count = 0;
		for (int j = -1; j < 2; j++)
		{
			for (int k = -1; k < 2; k++)
			{
				if (x + j >= 0 && x + j < nFieldWidth && y + k >= 0 && y + k < nFieldHeight)
				{
					if (nField[(y + k)*nFieldWidth + (x + j)] == -1)
					
						mine_count++;
					

				}
			}
		}

		if (mine_count > 0)
		{
			btn[y * nFieldWidth + x]->SetLabel(std::to_string(mine_count));
		}
	}

	evt.Skip();
}

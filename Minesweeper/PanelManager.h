#pragma once
#include "StartMenu.h"
#include "PauseMenu.h"
#include "SettingsMenu.h"
#include <wx/wxprec.h>

class PanelManager : public wxPanel {
public:
	PanelManager(wxWindow* parent);

	wxBoxSizer* sizer;

	StartMenu* startMenu;
	PauseMenu* pauseMenu;
	SettingsMenu* settingsMenu;

private:
	//void AddPanel(wxPanel* panel, int index);
	void ShowPanel(int iPanel);
	//void OnStartGame(wxCommandEvent& event);
	//void OnSettings(wxCommandEvent& event);
};

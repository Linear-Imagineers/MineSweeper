#ifndef __HEADER_STARTMENU
#define __HEADER_STARTMENU

#pragma once
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/bitmap.h>

#include "MinesweeperGame.h"

class StartMenu : public wxPanel {
public:
	StartMenu(wxWindow* parent);// , SettingsMenu* settings);
private:
	void OnStartGame(wxCommandEvent& event);
	void OnSettings(wxCommandEvent& event);
};
#endif
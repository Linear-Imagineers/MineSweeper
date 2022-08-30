#ifndef __HEADER_STATISTICSMENU
#define __HEADER_STATISTICSMENU
#pragma once

#include <wx/panel.h>
#include <wx/button.h>

class StatisticsMenu : public wxPanel
{
public:
	StatisticsMenu(wxWindow* parent);
	void OnExit(wxCommandEvent& event);
};

#endif 

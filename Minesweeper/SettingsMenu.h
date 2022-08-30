#ifndef __HEADER_SETTINGSMENU
#define __HEADER_SETTINGSMENU
#pragma once

#include <wx/panel.h>

class SettingsMenu : public wxPanel
{
public:
    SettingsMenu(wxWindow* parent);
    void OnExit(wxCommandEvent& event);
};

#endif
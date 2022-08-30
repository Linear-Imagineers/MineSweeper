#ifndef __HEADER_PAUSEMENU
#define __HEADER_PAUSEMENU

#pragma once
#include <wx/panel.h>
#include <wx/button.h>
class PauseMenu : public wxPanel
{
public:
    PauseMenu(wxWindow* parent);

    // Event handlers
    void OnResumeGame(wxCommandEvent& event);
    void OnSettings(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
};

#endif
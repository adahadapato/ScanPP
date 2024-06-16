#pragma once

#include <wx/wx.h>
#include"RegistryHLP.h"
//#include "MainWindow.h"

#define BUTTON_HIEGHT  27
#define BUTTON_TOP 314
#define TEXTBOX_HIEGHT 21


class LoginWindow : public wxDialog
{
public:
    LoginWindow(wxWindow* parent, const wxString& title);

    // Destructor
    //virtual ~LoginWindow();

private:
    wxStaticText* _lblUsername;
    wxStaticText* _lblPassword;
    wxTextCtrl* _txtUsername;
    wxTextCtrl* _txtPassword;
    wxButton* _btnLogin;
    wxButton* _btnQuit;


    // for check user is logged in or no
    bool logged_in = false;

private:
    /****************************************************************
    * Define helper functions
    *****************************************************************/
    //Declare helper functions
    //void OnMouseEvent(wxMouseEvent& evt);
    void CreateControls();
    void SetUpSizers(wxPanel* _panel);
    void BindEventHandlers();

    /****************************************************************
    * Define Event Handlers
    *****************************************************************/
    void BtnQuit_Clicked(wxCommandEvent& WXUNUSED(event));
    void BtnLogin_Clicked(wxCommandEvent& WXUNUSED(event));
    void OnClose(wxCloseEvent& event);

private:
    //wxDECLARE_EVENT_TABLE();

    enum
    {
        BUTTON_Login = wxID_HIGHEST + 1
    };
};


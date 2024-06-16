#include "LoginWindow.h"
#include"Schools.h"


LoginWindow::LoginWindow(wxWindow* parent, const wxString& title)
	: wxDialog(parent, wxID_ANY, title, wxPoint(wxID_ANY, wxID_ANY), wxSize(340, 150))
{
    this->CenterOnParent();
    CreateControls();
    //SetUpSizers();
    BindEventHandlers();
}

//LoginWindow::~LoginWindow()
//{
//}

void LoginWindow::CreateControls()
{
    wxPanel* _panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER);

    _lblUsername = new wxStaticText(_panel, wxID_ANY, wxT("UserId: "), wxPoint(16,23), wxSize(70, 13));
    _lblPassword = new wxStaticText(_panel, wxID_ANY, wxT("Password: "), wxPoint(16, 48), wxSize(70, 13));
    _txtUsername = new wxTextCtrl(_panel, wxID_ANY,"", wxPoint(75, 20), wxSize(100, TEXTBOX_HIEGHT));
    _txtPassword = new wxTextCtrl(_panel, wxID_ANY, wxString(""), wxPoint(75, 48), wxSize(230, TEXTBOX_HIEGHT), wxTE_PASSWORD);
    _btnLogin = new wxButton(_panel, BUTTON_Login, wxT("Login"), wxPoint(147, 74), wxSize(75, BUTTON_HIEGHT));
    _btnQuit = new wxButton(_panel, wxID_EXIT, ("Close"), wxPoint(231, 74), wxSize(75, BUTTON_HIEGHT));

    //SetUpSizers(_panel);
}

void LoginWindow::SetUpSizers(wxPanel* _panel)
{
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);



    hbox1->Add(_lblUsername, 0);
    hbox1->Add(_txtUsername, 1);
    hbox2->Add(_lblPassword, 0);
    hbox2->Add(_txtPassword, 1);
    hbox3->Add(_btnLogin);
    hbox3->Add(_btnQuit);

    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    vbox->Add(hbox2, 1, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);
    vbox->Add(hbox3, 2, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);

    _panel->SetSizer(vbox);
    CenterOnParent();
    Centre();
}

void LoginWindow::BindEventHandlers()
{
    // if user click close button window
    Bind(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(LoginWindow::OnClose), this);
    _btnLogin->Bind(wxEVT_BUTTON, &LoginWindow::BtnLogin_Clicked, this);
    _btnQuit->Bind(wxEVT_BUTTON, &LoginWindow::BtnQuit_Clicked, this);
}

void LoginWindow::BtnQuit_Clicked(wxCommandEvent& WXUNUSED(event))
{
    Destroy();
    Close(true);
}

void LoginWindow::BtnLogin_Clicked(wxCommandEvent& WXUNUSED(event))
{
    //Schools  _schools;
    //std:vector<Schools> _schools = GetSchools("bece", "2024");
    
    //_client->Get<vector<Schools>>(TEXT("schools//bece//2024"));

    wxString username = _txtUsername->GetValue();
    wxString password = _txtPassword->GetValue();

   // HTTPClient* _httpClient= new HTTPClient();
    //_httpClient->Connect();

    if (username.empty() || password.empty()) 
    {
        wxMessageBox(wxT("Please complete all entries"), wxT("Operator Login!"), wxICON_ERROR);
    }
    else 
    {
        if (username == "admin" && password == "password") 
        {
            BOOL status;
            RegistryHLP* _regHelper = new RegistryHLP();
            // user is logged in and destroy form login
            logged_in = true;
            status = _regHelper->WriteStringToRegistry(HKEY_CURRENT_USER, TEXT("software\\necoscan"), TEXT("Logout"), TEXT("False")); //read string
            Destroy();
        }
        else 
        {
            wxMessageBox(wxT("Username or Password incorrect."), wxT("Warning"), wxICON_WARNING);
        }
    }
}

void LoginWindow::OnClose(wxCloseEvent& event)
{
    if (!logged_in){}
        //  close parent frame also if user not logged in
       // GetParent()->Close();
        //GetParent()->Enable();
    this->Destroy();
        event.Skip();
}



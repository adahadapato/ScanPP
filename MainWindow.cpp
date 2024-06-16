#include "MainWindow.h"



MainWindow::MainWindow(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	
	this->SetClientSize(721, 361);
	this->Center();
	CreateControls();
	//SetUpSizers();
	BindEventHandlers();

	/*wxPanel* _panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
	wxStatusBar* _sbar = CreateStatusBar();
	_sbar->SetDoubleBuffered(true);*/

	
	//Text boxes
	
	/*wxTextCtrl* _txtExamYear = new wxTextCtrl(_panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));
	wxTextCtrl* _txtExamType = new wxTextCtrl(_panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));*/


	////Buttons
	//wxButton* _btnHouseKeeping = new wxButton(_panel, wxID_ANY,"House Keeping", wxPoint(300, 275), wxSize(200, BUTTON_HIEGHT));
	//wxButton* _btnRefresh = new wxButton(_panel, wxID_ANY, "Refresh", wxPoint(300, 275), wxSize(200, BUTTON_HIEGHT));
	//wxButton* _btnOk = new wxButton(_panel, wxID_ANY, "OK", wxPoint(300, 275), wxSize(200, BUTTON_HIEGHT));
	//wxButton* _btnClose = new wxButton(_panel, wxID_ANY, "Close", wxPoint(300, 275), wxSize(200, BUTTON_HIEGHT));
}


void MainWindow::OnMouseEvent(wxMouseEvent& evt)
{
}

void MainWindow::CreateControls()
{
	wxFont _mainFont(wxFontInfo(wxSize(0, 13)));
	_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
	_panel->SetFont(_mainFont);
	//_panel->SetBackgroundColour(*wxGREEN);


	_panel1 = new wxPanel(_panel, wxID_ANY, wxPoint(17,9), wxSize(691, 90), wxWANTS_CHARS | wxSUNKEN_BORDER);
	_panel1->SetFont(_mainFont);

	//wxFont _totalScannedFont(), wxFONTWEIGHT_BOLD)


	//Buttons
	_btnHouseKeeping = new wxButton(_panel, wxID_ANY, "House Keeping", wxPoint(17, BUTTON_TOP), wxSize(148, BUTTON_HIEGHT));
	_btnRefresh = new wxButton(_panel, wxID_ANY, "Refresh", wxPoint(173, BUTTON_TOP), wxSize(93, BUTTON_HIEGHT));
	_btnOk = new wxButton(_panel, wxID_ANY, "OK", wxPoint(548, BUTTON_TOP), wxSize(75, BUTTON_HIEGHT));
	_btnClose = new wxButton(_panel, wxID_ANY, "Close", wxPoint(632, BUTTON_TOP),wxSize(75, BUTTON_HIEGHT));

	////Labels
	_lblExamYear = new wxStaticText(_panel1, wxID_ANY, "Year", wxPoint(20, 25), wxDefaultSize);
	_lblExamType = new wxStaticText(_panel1, wxID_ANY, "Examination", wxPoint(222, 25), wxDefaultSize);
	_lblState = new wxStaticText(_panel1, wxID_ANY, "State", wxPoint(24, 59), wxDefaultSize);
	_lblSubjects = new wxStaticText(_panel1, wxID_ANY, "Subject", wxPoint(222, 59), wxDefaultSize);
	_lblPaper = new wxStaticText(_panel1, wxID_ANY, "Paper", wxPoint(573, 59), wxDefaultSize);
	_lblTotalScanned = new wxStaticText(_panel, wxID_ANY, "Total Scanned", wxPoint(17, 139), wxSize(140, 165), 
		(wxALIGN_CENTRE_HORIZONTAL| wxALIGN_CENTRE_VERTICAL| wxSUNKEN_BORDER));
	_lblTotalScanned->SetBackgroundColour(*wxRED);
	_lblTotalScanned->SetForegroundColour(*wxWHITE);
	_lblTotalScanned->SetFont(wxFontInfo(wxSize(0, 15)));

	
	
	
	//Middle Banner
	_middleBanner = new wxStaticText(_panel, wxID_ANY, "", wxPoint(17, 104), wxSize(691, 29), wxSUNKEN_BORDER);
	_middleBanner->SetBackgroundColour(*wxBLACK);

	_lblProgress = new wxStaticText(_middleBanner, wxID_ANY, "Progress:", wxPoint(154, 3), wxSize(70, 16));
	//_lblProgress = new wxStaticText(_middleBanner, wxID_ANY, "Progress:", wxDefaultPosition, wxSize(70, 16));
	_lblProgress->SetBackgroundColour(*wxBLACK);
	_lblProgress->SetForegroundColour(*wxWHITE);


	////Textboxes
	_txtExamYear = new wxTextCtrl(_panel1, wxID_ANY, "", wxPoint(120, 25), wxSize(80, TEXTBOX_HIEGHT), wxTE_READONLY);
	_txtExamType = new wxTextCtrl(_panel1, wxID_ANY, "", wxPoint(347, 25), wxSize(208, TEXTBOX_HIEGHT), wxTE_READONLY);
	_txtTotalScanned = new wxTextCtrl(_panel, wxID_ANY, "0", wxPoint(20, 198), wxSize(-1, TEXTBOX_HIEGHT), wxTE_READONLY|wxTE_CENTER);
	_txtTotalScanned->SetBackgroundColour(*wxRED);
	_txtTotalScanned->SetForegroundColour(*wxWHITE);
	//_txtTotalScanned->SetDefaultStyle(wxTextAttr(*wxWHITE));
	

	////ComboBoxes
	_cmbState = new wxChoice(_panel1, wxID_ANY, wxPoint(64, 59), wxSize(139, 23));
	_cmbSubjects = new wxChoice(_panel1, wxID_ANY, wxPoint(287, 59), wxSize(272, 23));
	_cmbPaper = new wxChoice(_panel1, wxID_ANY, wxPoint(625, 59), wxSize(56, 23));

	//ListBox
	_lstFiles = new wxListBox(_panel, wxID_ANY, wxPoint(161, 139), wxSize(545, 165));
}

void MainWindow::SetUpSizers()
{
	//wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	//wxBoxSizer* _upperSizer = new wxBoxSizer(wxVERTICAL);
	//wxBoxSizer* _examsSizer = new wxBoxSizer(wxHORIZONTAL);//exams details region
	////Add controls ie: exams year labels and textbox and exams type labales and textbox

	////_examsSizer->Add(_lblExamYear, wxSizerFlags().Align(wxBottom));
	////_examsSizer->AddSpacer(5);
	////_examsSizer->Add(_txtExamYear);

	////_examsSizer->AddSpacer(10);

	//_examsSizer->Add(_lblExamType, wxSizerFlags().Align(wxBottom));
	//_examsSizer->AddSpacer(5);
	//_examsSizer->Add(_txtExamType);

	//wxBoxSizer* _subjectSizer = new wxBoxSizer(wxHORIZONTAL);
	//_subjectSizer->Add(_lblState, wxSizerFlags().Align(wxBottom));
	//_subjectSizer->AddSpacer(5);
	//_subjectSizer->Add(_cmbState);
	//_subjectSizer->AddSpacer(10);
	//_subjectSizer->Add(_lblSubjects, wxSizerFlags().Align(wxBottom));
	//_subjectSizer->AddSpacer(5);
	//_subjectSizer->Add(_cmbSubjects, wxSizerFlags().Expand());
	//_subjectSizer->AddSpacer(10);

	//_subjectSizer->Add(_lblPaper);
	//_subjectSizer->AddSpacer(5);
	//_subjectSizer->Add(_cmbPaper);
	//_upperSizer->Add(_examsSizer, wxSizerFlags().Border(wxALL, 5).Expand());
	//_upperSizer->AddSpacer(5);
	//_upperSizer->Add(_subjectSizer);

	//wxBoxSizer* _middleSizer = new wxBoxSizer(wxHORIZONTAL);

	//wxBoxSizer* _progressSizer = new wxBoxSizer(wxHORIZONTAL);


	//wxBoxSizer* _buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

	//mainSizer->Add(_upperSizer, wxSizerFlags().Expand());


	//wxGridSizer* outerSizer = new wxGridSizer(1);
	//outerSizer->Add(mainSizer, wxSizerFlags().Border(wxALL, 25).Expand());

	//_panel->SetSizer(outerSizer);
	//outerSizer->SetSizeHints(this);

}

void MainWindow::BindEventHandlers()
{
	_btnHouseKeeping->Bind(wxEVT_BUTTON, &MainWindow::BtnHouseKeeping_Clicked, this);
	_btnRefresh->Bind(wxEVT_BUTTON, &MainWindow::BtnRefresh_Clicked, this);
	_btnOk->Bind(wxEVT_BUTTON, &MainWindow::BtnOK_Clicked, this);
	_btnClose->Bind(wxEVT_BUTTON, &MainWindow::BtnClose_Clicked, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainWindow::OnWindowClosed, this);

}

void MainWindow::LoadDEfaultValues()
{

}

void MainWindow::BtnHouseKeeping_Clicked(wxCommandEvent& e)
{

}

void MainWindow::BtnRefresh_Clicked(wxCommandEvent& e)
{

}

void MainWindow::BtnOK_Clicked(wxCommandEvent& e)
{

}

void MainWindow::BtnClose_Clicked(wxCommandEvent& e)
{
	wxGenericMessageDialog dialog(this, "Are you sure you want to logout now", "Close form", wxYES_NO, wxDefaultPosition);
	int result = dialog.ShowModal();
	if (result == wxID_NO) {
		return;
	}

	BOOL status;
	RegistryHLP* _regHelper = new RegistryHLP();
	// user is logged in and destroy form login
	status = _regHelper->WriteStringToRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, TEXT("Logout"), TEXT("True")); //read string
	this->Destroy();
	//this->Close(true);
	e.Skip();
}

void MainWindow::OnWindowClosed(wxCloseEvent& e)
{
	Destroy();
	//Close(true);
	e.Skip();
}

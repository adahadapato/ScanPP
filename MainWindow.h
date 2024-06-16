#pragma once

#include <wx/wx.h>
#include "RegistryHLP.h"

#define BUTTON_HIEGHT  27
#define BUTTON_TOP 314
#define TEXTBOX_HIEGHT 21

class MainWindow : public wxFrame
{
public:
	MainWindow(const wxString& title);

private:

	/****************************************************************
	* Define helper functions
	*****************************************************************/
	//Declare helper functions
	void OnMouseEvent(wxMouseEvent& evt);
	void CreateControls();
	void SetUpSizers();
	void BindEventHandlers();
	void LoadDEfaultValues();


	/****************************************************************
	* Define Event Handlers
	*****************************************************************/
	void BtnHouseKeeping_Clicked(wxCommandEvent& e);
	void BtnRefresh_Clicked(wxCommandEvent& e);
	void BtnOK_Clicked(wxCommandEvent& e);
	void BtnClose_Clicked(wxCommandEvent& e);
	void OnWindowClosed(wxCloseEvent& e);


	/******************************************************************
	* Declare controls variables
	******************************************************************/
	//Panel
	wxPanel* _panel;
	wxPanel* _panel1;

	//Buttons
	wxButton* _btnHouseKeeping;
	wxButton* _btnRefresh;
	wxButton* _btnOk;
	wxButton* _btnClose;

	//Labels
	wxStaticText* _headlineText;
	wxStaticText* _lblExamYear;
	wxStaticText* _lblExamType;
	wxStaticText* _lblSubjects;
	wxStaticText* _lblState;
	wxStaticText* _lblPaper;
	wxStaticText* _lblTotalScanned;
	wxStaticText* _lblProgress;


	//Textboxes
	wxTextCtrl* _txtExamYear;
	wxTextCtrl* _txtExamType;
	wxTextCtrl* _txtTotalScanned;

	//ComboBoxes
	wxChoice* _cmbState;
	wxChoice* _cmbSubjects;
	wxChoice* _cmbPaper;

	//ListBox
	wxListBox* _lstFiles;

	//Middle black banner
	wxStaticText* _middleBanner;

	//
	/*wxStaticText* headlineText;
	wxTextCtrl* inputField;
	wxButton* addButton;
	wxCheckListBox* checkListBox;
	wxButton* clearButton;*/

};


//---------------------------------------------------------------------------
//
// Name:        arquiteturaDlg.h
// Author:      Renato "Lond"
// Created:     3/7/2007 14:49:58
// Description: arquiteturaDlg class declaration
//
//---------------------------------------------------------------------------

#ifndef __ARQUITETURADLG_h__
#define __ARQUITETURADLG_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/stattext.h>
#include <wx/filedlg.h>
#include <wx/tglbtn.h>
#include <wx/listbox.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/statline.h>
#include <wx/panel.h>
////Header Include End
#include <wx/image.h>
#include "londGrid.h"
#include "arquitetura.h"

////Dialog Style Start
#undef arquiteturaDlg_STYLE
#define arquiteturaDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class arquiteturaDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		arquiteturaDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("arquitetura"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = arquiteturaDlg_STYLE);
		virtual ~arquiteturaDlg();
		void WxGrid1CellChange(wxGridEvent& event);
		void WxCheckBox23Click(wxCommandEvent& event);
		void set_pr1(bool);
		void set_pr2(bool);
		void set_pr3(bool);
		void set_pr4(bool);
		void set_pr5(bool);
		void set_prX(bool);
		void set_prY(bool);
		void set_ppc(bool);
		void set_prEnd(bool);
		void set_palu1(bool);
		void set_palu2(bool);
		void set_palu3(bool);
		void set_palu4(bool);
		void set_palu5(bool);
		void set_pir(bool);
		void set_prDados(bool);
		void set_pmem(bool);
		void set_pmux_a1(bool);
		void set_pmux_b1(bool);
		void set_pmux_b2(bool);
		void set_pmux_b3(bool);
		void set_pmux_c1(bool);
		void set_pmux_c2(bool);
		void set_r1(int value);
		void set_r2(int value);
		void set_r3(int value);
		void set_r4(int value);
		void set_r5(int value);
		void set_rX(int value);
		void set_rY(int value);
		void set_pc(int value);
		void set_ir(int value);
		void set_rEnd(int value);
		void set_rDados(int value);
		void WxButton1Click(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
	
	private:
		/*
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxToggleButton *WxToggleButton6;
		wxToggleButton *WxToggleButton5;
		wxToggleButton *WxToggleButton4;
		wxToggleButton *WxToggleButton3;
		wxFileDialog *WxOpenFileDialog1;
		wxToggleButton *WxToggleButton2;
		wxToggleButton *WxToggleButton1;
		wxStaticBox *WxStaticBox3;
		wxButton *WxButton6;
		wxButton *WxButton5;
		wxButton *WxButton4;
		wxListBox *WxListBox1;
		wxButton *WxButton3;
		wxButton *WxButton2;
		wxRadioButton *WxRadioButton3;
		wxRadioButton *WxRadioButton2;
		wxRadioButton *WxRadioButton1;
		wxStaticBox *WxStaticBox2;
		wxButton *WxButton1;
		wxTextCtrl *WxEdit12;
		wxStaticBox *WxStaticBox1;
		wxStaticBitmap *WxStaticBitmap5;
		wxCheckBox *WxCheckBox23;
		wxCheckBox *WxCheckBox22;
		wxCheckBox *WxCheckBox21;
		wxCheckBox *WxCheckBox20;
		wxCheckBox *WxCheckBox19;
		wxCheckBox *WxCheckBox18;
		wxCheckBox *WxCheckBox17;
		wxCheckBox *WxCheckBox16;
		wxCheckBox *WxCheckBox15;
		wxCheckBox *WxCheckBox14;
		wxCheckBox *WxCheckBox13;
		wxCheckBox *WxCheckBox12;
		wxCheckBox *WxCheckBox11;
		wxCheckBox *WxCheckBox10;
		wxCheckBox *WxCheckBox9;
		wxCheckBox *WxCheckBox8;
		wxCheckBox *WxCheckBox7;
		wxCheckBox *WxCheckBox6;
		wxCheckBox *WxCheckBox5;
		wxCheckBox *WxCheckBox4;
		wxCheckBox *WxCheckBox3;
		wxCheckBox *WxCheckBox2;
		wxCheckBox *WxCheckBox1;
		wxStaticLine *WxStaticLine51;
		wxStaticLine *WxStaticLine50;
		wxStaticLine *WxStaticLine49;
		wxStaticLine *WxStaticLine48;
		wxStaticLine *WxStaticLine47;
		wxStaticLine *WxStaticLine46;
		wxStaticLine *WxStaticLine45;
		wxStaticLine *WxStaticLine44;
		wxStaticLine *WxStaticLine43;
		wxStaticLine *WxStaticLine42;
		wxStaticLine *WxStaticLine41;
		wxStaticLine *WxStaticLine40;
		wxStaticLine *WxStaticLine39;
		wxStaticLine *WxStaticLine38;
		wxStaticLine *WxStaticLine37;
		wxStaticLine *WxStaticLine36;
		wxStaticLine *WxStaticLine35;
		wxStaticLine *WxStaticLine34;
		wxStaticLine *WxStaticLine31;
		wxStaticLine *WxStaticLine30;
		wxStaticLine *WxStaticLine27;
		wxStaticLine *WxStaticLine24;
		wxStaticLine *WxStaticLine23;
		wxStaticLine *WxStaticLine22;
		wxStaticBitmap *WxStaticBitmap4;
		wxStaticBitmap *WxStaticBitmap3;
		wxStaticBitmap *WxStaticBitmap2;
		wxStaticBitmap *WxStaticBitmap1;
		wxStaticLine *WxStaticLine6;
		wxStaticLine *WxStaticLine5;
		wxStaticLine *WxStaticLine4;
		wxStaticLine *WxStaticLine3;
		wxStaticLine *WxStaticLine2;
		wxTextCtrl *WxEdit11;
		wxTextCtrl *WxEdit10;
		wxTextCtrl *WxEdit9;
		wxTextCtrl *WxEdit8;
		wxTextCtrl *WxEdit7;
		wxTextCtrl *WxEdit6;
		wxTextCtrl *WxEdit5;
		wxTextCtrl *WxEdit2;
		wxTextCtrl *WxEdit3;
		wxTextCtrl *WxEdit1;
		wxTextCtrl *WxEdit4;
		wxStaticLine *WxStaticLine1;
		wxGrid *WxGrid1;
		wxStaticLine *WxStaticLine33;
		wxStaticLine *WxStaticLine32;
		wxStaticLine *WxStaticLine29;
		wxStaticLine *WxStaticLine28;
		wxStaticLine *WxStaticLine26;
		wxStaticLine *WxStaticLine25;
		wxStaticLine *WxStaticLine21;
		wxStaticLine *WxStaticLine20;
		wxStaticLine *WxStaticLine19;
		wxStaticLine *WxStaticLine18;
		wxStaticLine *WxStaticLine17;
		wxStaticLine *WxStaticLine16;
		wxStaticLine *WxStaticLine15;
		wxStaticLine *WxStaticLine14;
		wxStaticLine *WxStaticLine13;
		wxStaticLine *WxStaticLine12;
		wxStaticLine *WxStaticLine11;
		wxStaticLine *WxStaticLine10;
		wxStaticLine *WxStaticLine9;
		wxStaticLine *WxStaticLine8;
		wxStaticLine *WxStaticLine7;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		*/
		wxPanel *WxPanel1;
		wxPanel *WxPanel2;
		wxTextCtrl *WxEdit11;
		wxTextCtrl *WxEdit10;
		wxTextCtrl *WxEdit9;
		wxTextCtrl *WxEdit8;
		wxTextCtrl *WxEdit7;
		wxTextCtrl *WxEdit6;
		wxTextCtrl *WxEdit5;
		wxTextCtrl *WxEdit4;
		wxTextCtrl *WxEdit3;
		wxTextCtrl *WxEdit2;
		wxTextCtrl *WxEdit1;
		wxStaticLine *WxStaticLine1;
		wxStaticLine *WxStaticLine2;
		wxStaticLine *WxStaticLine3;
		wxStaticLine *WxStaticLine4;
		wxStaticLine *WxStaticLine5;
		wxStaticLine *WxStaticLine6;
		wxStaticLine *WxStaticLine7;
		wxStaticLine *WxStaticLine8;
		wxStaticLine *WxStaticLine9;
		wxStaticLine *WxStaticLine10;
		wxStaticLine *WxStaticLine11;
		wxStaticLine *WxStaticLine12;
		wxStaticLine *WxStaticLine13;
		wxStaticLine *WxStaticLine14;
		wxStaticLine *WxStaticLine15;
		wxStaticLine *WxStaticLine16;
		wxStaticLine *WxStaticLine17;
		wxStaticLine *WxStaticLine18;
		wxStaticLine *WxStaticLine19;
		wxStaticLine *WxStaticLine20;
		wxStaticLine *WxStaticLine21;
		wxStaticLine *WxStaticLine22;
		wxStaticLine *WxStaticLine23;
		wxStaticLine *WxStaticLine24;
		wxStaticLine *WxStaticLine25;
		wxStaticLine *WxStaticLine26;
		wxStaticLine *WxStaticLine27;
		wxStaticLine *WxStaticLine28;
		wxStaticLine *WxStaticLine29;
		wxStaticLine *WxStaticLine30;
		wxStaticLine *WxStaticLine31;
		wxStaticLine *WxStaticLine32;
		wxStaticLine *WxStaticLine33;
		wxStaticLine *WxStaticLine34;
		wxStaticLine *WxStaticLine35;
		wxStaticLine *WxStaticLine36;
		wxStaticLine *WxStaticLine37;
		wxStaticLine *WxStaticLine38;
		wxStaticLine *WxStaticLine39;
		wxStaticLine *WxStaticLine40;
		wxStaticLine *WxStaticLine41;
		wxStaticLine *WxStaticLine42;
		wxStaticLine *WxStaticLine43;
		wxStaticLine *WxStaticLine44;
		wxStaticLine *WxStaticLine45;
		wxStaticLine *WxStaticLine46;
		wxStaticLine *WxStaticLine47;
		wxStaticLine *WxStaticLine48;
		wxStaticLine *WxStaticLine49;
		wxStaticLine *WxStaticLine50;
		wxStaticLine *WxStaticLine51;
		
//		wxToggleButton *WxToggleButton1;
		wxCheckBox *WxCheckBox1;
		wxCheckBox *WxCheckBox2;
		wxCheckBox *WxCheckBox3;
		wxCheckBox *WxCheckBox4;
		wxCheckBox *WxCheckBox5;
		wxCheckBox *WxCheckBox6;
		wxCheckBox *WxCheckBox7;
		wxCheckBox *WxCheckBox8;
		wxCheckBox *WxCheckBox9;
		wxCheckBox *WxCheckBox10;
		wxCheckBox *WxCheckBox11;
		wxCheckBox *WxCheckBox12;
		wxCheckBox *WxCheckBox13;
		wxCheckBox *WxCheckBox14;
		wxCheckBox *WxCheckBox15;
		wxCheckBox *WxCheckBox16;
		wxCheckBox *WxCheckBox17;
		wxCheckBox *WxCheckBox18;
		wxCheckBox *WxCheckBox19;
		wxCheckBox *WxCheckBox20;
		wxCheckBox *WxCheckBox21;
		wxCheckBox *WxCheckBox22;
		wxCheckBox *WxCheckBox23;

		wxStaticBitmap *WxStaticBitmap1;
		wxStaticBitmap *WxStaticBitmap2;
		wxStaticBitmap *WxStaticBitmap3;
		wxStaticBitmap *WxStaticBitmap4;

		wxStaticBitmap *WxStaticBitmap5;

		wxGrid *WxGrid1;
		
		wxStaticBox *WxStaticBox1;
		wxTextCtrl *WxEdit12;
		wxFileDialog *WxOpenFileDialog1;
		wxButton *WxButton1;
		wxButton *WxButton3;
		public:
		wxListBox *WxListBox1;
		void WxButton2Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		void WxButton5Click(wxCommandEvent& event);
		void WxButton6Click(wxCommandEvent& event);
		private:

		
		wxStaticBox *WxStaticBox2;
		wxRadioButton *WxRadioButton1;
		wxRadioButton *WxRadioButton2;
		wxRadioButton *WxRadioButton3;
		wxButton *WxButton2;
//		wxStaticText *WxStaticText1;
//		wxSlider *WxSlider1;
		wxButton *WxButton4;
		wxButton *WxButton5;
		wxButton *WxButton6;
		int microAtual;
	
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;

		wxStaticBox *WxStaticBox3;
		public:
		wxToggleButton *zeroFlagButton;
		wxToggleButton *negFlagButton;
		wxToggleButton *carryFlagButton;
		wxToggleButton *menorFlagButton;
		wxToggleButton *equFlagButton;
		wxToggleButton *maiorFlagButton;
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT11 = 1141,
			ID_WXSTATICTEXT10 = 1140,
			ID_WXSTATICTEXT9 = 1139,
			ID_WXSTATICTEXT8 = 1138,
			ID_WXSTATICTEXT7 = 1137,
			ID_WXSTATICTEXT6 = 1136,
			ID_WXSTATICTEXT5 = 1135,
			ID_WXSTATICTEXT4 = 1134,
			ID_WXSTATICTEXT3 = 1133,
			ID_WXSTATICTEXT2 = 1132,
			ID_WXSTATICTEXT1 = 1131,
			ID_WXTOGGLEBUTTON6 = 1130,
			ID_WXTOGGLEBUTTON5 = 1129,
			ID_WXTOGGLEBUTTON4 = 1128,
			ID_WXTOGGLEBUTTON3 = 1127,
			ID_WXTOGGLEBUTTON2 = 1126,
			ID_WXTOGGLEBUTTON1 = 1125,
			ID_WXSTATICBOX3 = 1124,
			ID_WXBUTTON6 = 1123,
			ID_WXBUTTON5 = 1121,
			ID_WXBUTTON4 = 1120,
			ID_WXLISTBOX1 = 1117,
			ID_WXBUTTON3 = 1116,
			ID_WXBUTTON2 = 1113,
			ID_WXRADIOBUTTON3 = 1112,
			ID_WXRADIOBUTTON2 = 1111,
			ID_WXRADIOBUTTON1 = 1110,
			ID_WXSTATICBOX2 = 1109,
			ID_WXBUTTON1 = 1108,
			ID_WXEDIT12 = 1107,
			ID_WXSTATICBOX1 = 1105,
			ID_WXSTATICBITMAP5 = 1118,
			ID_WXCHECKBOX23 = 1104,
			ID_WXCHECKBOX22 = 1102,
			ID_WXCHECKBOX21 = 1101,
			ID_WXCHECKBOX20 = 1100,
			ID_WXCHECKBOX19 = 1099,
			ID_WXCHECKBOX18 = 1098,
			ID_WXCHECKBOX17 = 1097,
			ID_WXCHECKBOX16 = 1096,
			ID_WXCHECKBOX15 = 1095,
			ID_WXCHECKBOX14 = 1094,
			ID_WXCHECKBOX13 = 1093,
			ID_WXCHECKBOX12 = 1092,
			ID_WXCHECKBOX11 = 1091,
			ID_WXCHECKBOX10 = 1090,
			ID_WXCHECKBOX9 = 1089,
			ID_WXCHECKBOX8 = 1088,
			ID_WXCHECKBOX7 = 1087,
			ID_WXCHECKBOX6 = 1086,
			ID_WXCHECKBOX5 = 1085,
			ID_WXCHECKBOX4 = 1084,
			ID_WXCHECKBOX3 = 1083,
			ID_WXCHECKBOX2 = 1082,
			ID_WXCHECKBOX1 = 1081,
			ID_WXSTATICLINE51 = 1079,
			ID_WXSTATICLINE50 = 1078,
			ID_WXSTATICLINE49 = 1077,
			ID_WXSTATICLINE48 = 1076,
			ID_WXSTATICLINE47 = 1075,
			ID_WXSTATICLINE46 = 1074,
			ID_WXSTATICLINE45 = 1073,
			ID_WXSTATICLINE44 = 1072,
			ID_WXSTATICLINE43 = 1071,
			ID_WXSTATICLINE42 = 1070,
			ID_WXSTATICLINE41 = 1069,
			ID_WXSTATICLINE40 = 1068,
			ID_WXSTATICLINE39 = 1065,
			ID_WXSTATICLINE38 = 1064,
			ID_WXSTATICLINE37 = 1062,
			ID_WXSTATICLINE36 = 1061,
			ID_WXSTATICLINE35 = 1060,
			ID_WXSTATICLINE34 = 1058,
			ID_WXSTATICLINE31 = 1054,
			ID_WXSTATICLINE30 = 1053,
			ID_WXSTATICLINE27 = 1050,
			ID_WXSTATICLINE24 = 1047,
			ID_WXSTATICLINE23 = 1046,
			ID_WXSTATICLINE22 = 1045,
			ID_WXSTATICBITMAP4 = 1029,
			ID_WXSTATICBITMAP3 = 1028,
			ID_WXSTATICBITMAP2 = 1027,
			ID_WXSTATICBITMAP1 = 1026,
			ID_WXSTATICLINE6 = 1025,
			ID_WXSTATICLINE5 = 1024,
			ID_WXSTATICLINE4 = 1023,
			ID_WXSTATICLINE3 = 1022,
			ID_WXSTATICLINE2 = 1021,
			ID_WXEDIT11 = 1014,
			ID_WXEDIT10 = 1013,
			ID_WXEDIT9 = 1012,
			ID_WXEDIT8 = 1011,
			ID_WXEDIT7 = 1010,
			ID_WXEDIT6 = 1009,
			ID_WXEDIT5 = 1008,
			ID_WXEDIT2 = 1005,
			ID_WXEDIT3 = 1006,
			ID_WXEDIT1 = 1002,
			ID_WXEDIT4 = 1007,
			ID_WXSTATICLINE1 = 1017,
			ID_WXGRID1 = 1016,
			ID_WXSTATICLINE33 = 1056,
			ID_WXSTATICLINE32 = 1055,
			ID_WXSTATICLINE29 = 1052,
			ID_WXSTATICLINE28 = 1051,
			ID_WXSTATICLINE26 = 1049,
			ID_WXSTATICLINE25 = 1048,
			ID_WXSTATICLINE21 = 1044,
			ID_WXSTATICLINE20 = 1043,
			ID_WXSTATICLINE19 = 1042,
			ID_WXSTATICLINE18 = 1041,
			ID_WXSTATICLINE17 = 1040,
			ID_WXSTATICLINE16 = 1039,
			ID_WXSTATICLINE15 = 1038,
			ID_WXSTATICLINE14 = 1037,
			ID_WXSTATICLINE13 = 1036,
			ID_WXSTATICLINE12 = 1035,
			ID_WXSTATICLINE11 = 1034,
			ID_WXSTATICLINE10 = 1033,
			ID_WXSTATICLINE9 = 1032,
			ID_WXSTATICLINE8 = 1031,
			ID_WXSTATICLINE7 = 1030,
			ID_WXPANEL1 = 1020,
			////GUI Enum Control ID End
			ID_WXPANEL2 = 1300,
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif

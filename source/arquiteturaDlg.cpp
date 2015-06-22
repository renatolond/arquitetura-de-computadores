//---------------------------------------------------------------------------
//
// Name:        arquiteturaDlg.cpp
// Author:      Renato "Lond"
// Created:     3/7/2007 14:49:58
// Description: arquiteturaDlg class implementation
//
//---------------------------------------------------------------------------

#include "arquiteturaDlg.h"

/*
//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/arquiteturaDlg_WxStaticBitmap4_XPM.xpm"
#include "Images/arquiteturaDlg_WxStaticBitmap3_XPM.xpm"
#include "Images/arquiteturaDlg_WxStaticBitmap2_XPM.xpm"
#include "Images/arquiteturaDlg_WxStaticBitmap1_XPM.xpm"
////Header Include End
*/

//----------------------------------------------------------------------------
// arquiteturaDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(arquiteturaDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(arquiteturaDlg::OnClose)
	EVT_BUTTON(ID_WXBUTTON6,arquiteturaDlg::WxButton6Click)
	EVT_BUTTON(ID_WXBUTTON5,arquiteturaDlg::WxButton5Click)
	EVT_BUTTON(ID_WXBUTTON4,arquiteturaDlg::WxButton4Click)
	EVT_BUTTON(ID_WXBUTTON3,arquiteturaDlg::WxButton3Click)
	EVT_BUTTON(ID_WXBUTTON2,arquiteturaDlg::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON1,arquiteturaDlg::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

arquiteturaDlg::arquiteturaDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

arquiteturaDlg::~arquiteturaDlg()
{
} 

void arquiteturaDlg::CreateGUIControls()
{
    int WxPanelX = 7, WxPanelY = 160;
    
	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(WxPanelX,WxPanelY), wxSize(650,400));
	WxPanel1->SetBackgroundColour(wxColour(*wxBLACK));
	WxPanel2 = new wxPanel(this, ID_WXPANEL2, wxPoint(0,0), wxSize(3,58));

    wxGridTableBase *table = new londGrid();

    WxGrid1 = new wxGrid(WxPanel1, ID_WXSTATICBITMAP1, wxPoint(44,150), wxSize(110, 145));
	WxGrid1->SetTable(table, true);
	WxGrid1->SetRowLabelSize(0);

	WxGrid1->DisableDragGridSize();
	WxGrid1->DisableDragRowSize();
	WxGrid1->DisableDragColSize();

	WxGrid1->SetDefaultColSize(50);
	WxGrid1->SetColSize(0, 50);
	WxGrid1->SetColSize(1, 35);
	WxGrid1->SetDefaultCellAlignment(wxALIGN_CENTRE,wxALIGN_CENTRE);
	WxGrid1->SetEditable(false);

	WxStaticLine1 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE1, wxPoint(110,15), wxSize(522,-1), wxLI_HORIZONTAL); /* Linha de cima, conecta saída da alu a entrada dos Regs */
	WxStaticLine2 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE2, wxPoint(632,15), wxSize(-1,370), wxLI_VERTICAL); /* Linha da direita, idem */
	WxStaticLine3 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE3, wxPoint(73,385), wxSize(560,-1), wxLI_HORIZONTAL); /* Linha de baixo, idem */
	WxStaticLine4 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE4, wxPoint(71,357), wxSize(-1,30), wxLI_VERTICAL); 
	WxStaticLine5 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE5, wxPoint(202,357), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine6 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE6, wxPoint(391,327), wxSize(-1,58), wxLI_VERTICAL);
	WxStaticLine7 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE7, wxPoint(108,15), wxSize(-1,27), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até mux_a
	WxStaticLine8 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE8, wxPoint(172,15), wxSize(-1,30), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até RX
	WxStaticLine9 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE9, wxPoint(231,15), wxSize(-1,30), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até R0
	WxStaticLine10 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE10, wxPoint(292,15), wxSize(-1,30), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até R1
	WxStaticLine11 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE11, wxPoint(352,15), wxSize(-1,30), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até PC
	WxStaticLine12 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE12, wxPoint(413,15), wxSize(-1,30), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até R2
	WxStaticLine13 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE13, wxPoint(471,15), wxSize(-1,30), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até R3
	WxStaticLine14 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE14, wxPoint(531,15), wxSize(-1,30), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até R4
	WxStaticLine15 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE15, wxPoint(590,15), wxSize(-1,30), wxLI_VERTICAL); // Linha de cima (Saída da ALU) até RY
	WxStaticLine16 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE16, wxPoint(46,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine17 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE17, wxPoint(10,15), wxSize(36,-1), wxLI_HORIZONTAL);
	WxStaticLine18 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE18, wxPoint(10,15), wxSize(-1,225), wxLI_VERTICAL);
	WxStaticLine19 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE19, wxPoint(10,240), wxSize(34,-1), wxLI_HORIZONTAL);
	WxStaticLine20 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE20, wxPoint(82,77), wxSize(-1,24), wxLI_VERTICAL);
	WxStaticLine21 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE21, wxPoint(82,120), wxSize(-1,30), wxLI_VERTICAL); // RDados até Memória/Mux_b, 1ª parte
	WxStaticLine22 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE22, wxPoint(84,135), wxSize(130,-1), wxLI_HORIZONTAL); // RDados até mux_b, 2ª parte
	WxStaticLine23 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE23, wxPoint(214,135), wxSize(-1,35), wxLI_VERTICAL); // RDados até mux_b, 3ª parte
	WxStaticLine24 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE24, wxPoint(172,64), wxSize(-1,60), wxLI_VERTICAL); // RX até mux_b, 1ª parte 
	WxStaticLine25 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE25, wxPoint(172,124), wxSize(75,-1), wxLI_HORIZONTAL); // RX até mux_b, 2ª parte
	WxStaticLine26 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE26, wxPoint(247,124), wxSize(-1,46), wxLI_VERTICAL); // RX até mux_b, 3ª parte
	WxStaticLine27 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE27, wxPoint(229,65), wxSize(-1,48), wxLI_VERTICAL); // R0 até mux_b, 1ª parte
	WxStaticLine28 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE28, wxPoint(229,113), wxSize(51,-1), wxLI_HORIZONTAL); // R0 até mux_b, 2ª parte
	WxStaticLine29 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE29, wxPoint(280,113), wxSize(-1,61), wxLI_VERTICAL); // R0 até mux_b, 3ª parte
	WxStaticLine30 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE30, wxPoint(290,64), wxSize(-1,38), wxLI_VERTICAL); // R1 até mux_b, 1ª parte
	WxStaticLine31 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE31, wxPoint(290,102), wxSize(24,-1), wxLI_HORIZONTAL); // R1 até mux_b, 2ª parte
	WxStaticLine32 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE32, wxPoint(314,102), wxSize(-1,68), wxLI_VERTICAL); // R1 até mux_b, 3ª parte
	WxStaticLine33 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE33, wxPoint(351,64), wxSize(-1,106), wxLI_VERTICAL); // PC até mux_b
	WxStaticLine34 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE34, wxPoint(279,206), wxSize(-1,26), wxLI_VERTICAL); // mux_b até alu, parte 1
	WxStaticLine35 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE35, wxPoint(281,232), wxSize(50,-1), wxLI_HORIZONTAL); // mux_b até alu, parte 2
	WxStaticLine36 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE36, wxPoint(331,232), wxSize(-1,27), wxLI_VERTICAL); // mux_b até alu, parte 3
	WxStaticLine37 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE37, wxPoint(411,64), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine38 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE38, wxPoint(411,94), wxSize(20,-1), wxLI_HORIZONTAL);
	WxStaticLine39 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE39, wxPoint(431,94), wxSize(-1,76), wxLI_VERTICAL);
	WxStaticLine40 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE40, wxPoint(468,64), wxSize(-1,106), wxLI_VERTICAL);
	WxStaticLine41 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE41, wxPoint(529,64), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine42 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE42, wxPoint(505,94), wxSize(24,-1), wxLI_HORIZONTAL);
	WxStaticLine43 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE43, wxPoint(505,94), wxSize(-1,76), wxLI_VERTICAL);
	WxStaticLine44 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE44, wxPoint(588,64), wxSize(-1,41), wxLI_VERTICAL);
	WxStaticLine45 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE45, wxPoint(542,105), wxSize(46,-1), wxLI_HORIZONTAL);
	WxStaticLine46 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE46, wxPoint(542,105), wxSize(-1,65), wxLI_VERTICAL);
	WxStaticLine47 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE47, wxPoint(491,206), wxSize(-1,26), wxLI_VERTICAL); // mux_c até ula, p1
	WxStaticLine48 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE48, wxPoint(441,232), wxSize(50,-1), wxLI_HORIZONTAL); // mux_c até ula, p2
	WxStaticLine49 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE49, wxPoint(441,232), wxSize(-1,27), wxLI_VERTICAL); // mux_c até ula, p3
	WxStaticLine50 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE50, wxPoint(71,295), wxSize(-1,42), wxLI_VERTICAL); // Rend até mem
	WxStaticLine51 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE51, wxPoint(202,295), wxSize(-1,42), wxLI_VERTICAL); // IR até UC
	
	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, wxT("0000"), wxPoint(62,101), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit1")); // RDados
	WxEdit2 = new wxTextCtrl(WxPanel1, ID_WXEDIT2, wxT("0000"), wxPoint(152,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit2")); // RX
	WxEdit3 = new wxTextCtrl(WxPanel1, ID_WXEDIT3, wxT("0000"), wxPoint(211,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit3")); // R0
	WxEdit4 = new wxTextCtrl(WxPanel1, ID_WXEDIT4, wxT("0000"), wxPoint(272,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit4")); // R1
	WxEdit5 = new wxTextCtrl(WxPanel1, ID_WXEDIT5, wxT("0000"), wxPoint(332,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit5")); // PC
	WxEdit6 = new wxTextCtrl(WxPanel1, ID_WXEDIT6, wxT("0000"), wxPoint(393,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit6")); // R2
	WxEdit7 = new wxTextCtrl(WxPanel1, ID_WXEDIT7, wxT("0000"), wxPoint(451,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit7")); // R3
	WxEdit8 = new wxTextCtrl(WxPanel1, ID_WXEDIT8, wxT("0000"), wxPoint(511,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit8")); // R4
	WxEdit9 = new wxTextCtrl(WxPanel1, ID_WXEDIT9, wxT("0000"), wxPoint(570,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit9")); // RY
	WxEdit10 = new wxTextCtrl(WxPanel1, ID_WXEDIT10, wxT("0000"), wxPoint(56,338), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit10")); // Rend
	WxEdit11 = new wxTextCtrl(WxPanel1, ID_WXEDIT11, wxT("0000"), wxPoint(184,338), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit11")); // iR

	WxEdit1->SetMaxLength(4);
	WxEdit2->SetMaxLength(4);
	WxEdit3->SetMaxLength(4);
	WxEdit4->SetMaxLength(4);
	WxEdit5->SetMaxLength(4);
	WxEdit6->SetMaxLength(4);
	WxEdit7->SetMaxLength(4);
	WxEdit8->SetMaxLength(4);
	WxEdit9->SetMaxLength(4);
	WxEdit10->SetMaxLength(4);
	WxEdit11->SetMaxLength(4);

	WxEdit1->SetEditable(false);
	WxEdit2->SetEditable(false);
	WxEdit3->SetEditable(false);
	WxEdit4->SetEditable(false);
	WxEdit5->SetEditable(false);
	WxEdit6->SetEditable(false);
	WxEdit7->SetEditable(false);
	WxEdit8->SetEditable(false);
	WxEdit9->SetEditable(false);
	WxEdit10->SetEditable(false);
	WxEdit11->SetEditable(false);

	wxImage image;
	wxBitmap ula;
	wxBitmap mux_a;
	wxBitmap mux_b;
	wxBitmap mux_c;
	wxBitmap uc;

	if ( !image.LoadFile("Images/ula.jpg") )
		wxLogError(wxT("Não carregou a imagem."));
	else
		ula = wxBitmap( image );
	WxStaticBitmap1 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP1, ula, wxPoint(297,259), wxSize(189,68));

	if ( !image.LoadFile("Images/mux_a.jpg") )
		wxLogError(wxT("Não carregou a imagem."));
	else
		mux_a = wxBitmap( image );
	WxStaticBitmap2 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP2, mux_a, wxPoint(22,42), wxSize(115,35));

	if ( !image.LoadFile("Images/mux_b.jpg") )
		wxLogError(wxT("Não carregou a imagem."));
	else
		mux_b = wxBitmap( image );
	WxStaticBitmap3 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP3, mux_b, wxPoint(200,170), wxSize(166,36));

	if ( !image.LoadFile("Images/mux_c.jpg") )
		wxLogError(wxT("Não carregou a imagem."));
	else
		mux_c = wxBitmap( image );
	WxStaticBitmap4 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP4, mux_c, wxPoint(409,170), wxSize(167,36));
	
	if ( !image.LoadFile("Images/uc.gif") )
		wxLogError(wxT("Não carregou a imagem."));
	else
		uc = wxBitmap( image );
	WxStaticBitmap5 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP5, uc, wxPoint(170,231), wxSize(64,64) );
	/* Pontos de controle */
	WxCheckBox1 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX1, wxT(""), wxPoint(487,258), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox1")); // ponto de controle 1 da alu
	WxCheckBox2 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX2, wxT(""), wxPoint(487,275), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox2")); // ponto de controle 2 da alu
	WxCheckBox3 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX3, wxT(""), wxPoint(487,292), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox3")); // ponto de controle 3 da alu
	WxCheckBox4 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX4, wxT(""), wxPoint(487,309), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox4")); // ponto de controle 4 da alu
	WxCheckBox5 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX5, wxT(""), wxPoint(487,326), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox5")); // ponto de controle 5 da alu
	
	WxCheckBox6 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX6, wxT(""), wxPoint(177,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox6"));
	WxCheckBox7 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX7, wxT(""), wxPoint(236,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox7"));
	WxCheckBox8 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX8, wxT(""), wxPoint(297,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox8"));
	WxCheckBox9 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX9, wxT(""), wxPoint(357,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox9"));
	WxCheckBox10 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX10, wxT(""), wxPoint(418,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox10"));
	WxCheckBox11 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX11, wxT(""), wxPoint(476,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox11"));
	WxCheckBox12 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX12, wxT(""), wxPoint(536,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox12"));
	WxCheckBox13 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX13, wxT(""), wxPoint(595,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox13"));
	
	WxCheckBox14 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX14, wxT(""), wxPoint(87,81), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox14"));
	WxCheckBox15 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX15, wxT(""), wxPoint(140,66), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox15"));
	
	WxCheckBox16 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX16, wxT(""), wxPoint(181,168), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox16"));
	WxCheckBox17 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX17, wxT(""), wxPoint(181,185), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox17"));
	WxCheckBox18 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX18, wxT(""), wxPoint(181,202), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox18"));
	
	WxCheckBox19 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX19, wxT(""), wxPoint(579,170), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox19"));
	WxCheckBox20 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX20, wxT(""), wxPoint(579,187), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox20"));
	
	WxCheckBox21 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX21, wxT(""), wxPoint(76,360), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox21"));
	WxCheckBox22 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX22, wxT(""), wxPoint(207,360), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox22"));
	WxCheckBox23 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX23, wxT(""), wxPoint(24,280), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox23"));

	WxCheckBox1->Enable(false);
	WxCheckBox2->Enable(false);
	WxCheckBox3->Enable(false);
	WxCheckBox4->Enable(false);
	WxCheckBox5->Enable(false);
	WxCheckBox6->Enable(false);
	WxCheckBox7->Enable(false);
	WxCheckBox8->Enable(false);
	WxCheckBox9->Enable(false);
	WxCheckBox10->Enable(false);
	WxCheckBox11->Enable(false);
	WxCheckBox12->Enable(false);
	WxCheckBox13->Enable(false);
	WxCheckBox14->Enable(false);
	WxCheckBox15->Enable(false);
	WxCheckBox16->Enable(false);
	WxCheckBox17->Enable(false);
	WxCheckBox18->Enable(false);
	WxCheckBox19->Enable(false);
	WxCheckBox20->Enable(false);
	WxCheckBox21->Enable(false);
	WxCheckBox22->Enable(false);
	WxCheckBox23->Enable(false);
	
	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, wxT("Arquivo fonte"), wxPoint(7,7), wxSize(185,146));
	WxEdit12 = new wxTextCtrl(this, ID_WXEDIT12, wxT(""), wxPoint(13,24), wxSize(121,19), 0, wxDefaultValidator, wxT("WxEdit12"));
	WxOpenFileDialog1 =  new wxFileDialog(this, wxT("Arquivo assembly"), wxT("."), wxT(""), wxT("*.asm"), wxOPEN);
	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Procurar"), wxPoint(136,24), wxSize(50,19), 0, wxDefaultValidator, wxT("WxButton1"));
	WxButton3 = new wxButton(this, ID_WXBUTTON3, wxT("Ler instruções"), wxPoint(113,45), wxSize(75,19), 0, wxDefaultValidator, wxT("WxButton3"));
	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(this, ID_WXLISTBOX1, wxPoint(12,65), wxSize(175,83), arrayStringFor_WxListBox1, wxLB_SINGLE);

	WxStaticBox2 = new wxStaticBox(this, ID_WXSTATICBOX2, wxT("Modo de execução:"), wxPoint(193,7), wxSize(185,146));
	WxRadioButton1 = new wxRadioButton(this, ID_WXRADIOBUTTON1, wxT("Execução completa"), wxPoint(202,22), wxSize(113,17), wxRB_GROUP, wxDefaultValidator, wxT("WxRadioButton1"));
	WxRadioButton2 = new wxRadioButton(this, ID_WXRADIOBUTTON2, wxT("Parar a cada instrução"), wxPoint(202,40), wxSize(132,17), 0, wxDefaultValidator, wxT("WxRadioButton2"));
	WxRadioButton3 = new wxRadioButton(this, ID_WXRADIOBUTTON3, wxT("Parar a cada microinstrução"), wxPoint(202,58), wxSize(155,17), 0, wxDefaultValidator, wxT("WxRadioButton3"));
	WxButton2 = new wxButton(this, ID_WXBUTTON2, wxT("Executar"), wxPoint(300,131), wxSize(75,19), 0, wxDefaultValidator, wxT("WxButton2"));
	WxButton5 = new wxButton(this, ID_WXBUTTON5, wxT("Resetar máquina"), wxPoint(196,91), wxSize(88,19), 0, wxDefaultValidator, wxT("WxButton5"));
	WxButton6 = new wxButton(this, ID_WXBUTTON6, wxT("Resetar registradores"), wxPoint(196,111), wxSize(113,19), 0, wxDefaultValidator, wxT("WxButton6"));
//	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Velocidade de execução:"), wxPoint(219,81), wxDefaultSize, 0, wxT("WxStaticText1"));
//	WxSlider1 = new wxSlider(this, ID_WXSLIDER1, 0, 0, 3000, wxPoint(205,95), wxSize(150,30), wxSL_HORIZONTAL | wxSL_SELRANGE , wxDefaultValidator, wxT("WxSlider1"));
//	WxSlider1->SetRange(0,3000);
//	WxSlider1->SetValue(0);
	
	WxButton4 = new wxButton(this, ID_WXBUTTON4, wxT("Próxima"), wxPoint(196,131), wxSize(75,19), 0, wxDefaultValidator, wxT("WxButton4"));
	WxButton4->Show(false);

	WxStaticBox3 = new wxStaticBox(this, ID_WXSTATICBOX3, wxT("Flags"), wxPoint(380,7), wxSize(185,146));
	zeroFlagButton = new wxToggleButton(this, ID_WXTOGGLEBUTTON1, wxT("Zero Flag"), wxPoint(390,33), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton1"));
	negFlagButton = new wxToggleButton(this, ID_WXTOGGLEBUTTON2, wxT("Neg Flag"), wxPoint(481,33), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton2"));
	carryFlagButton = new wxToggleButton(this, ID_WXTOGGLEBUTTON3, wxT("Carry Flag"), wxPoint(390,75), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton3"));
	menorFlagButton = new wxToggleButton(this, ID_WXTOGGLEBUTTON4, wxT("Menor Flag"), wxPoint(481,75), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton4"));
	equFlagButton = new wxToggleButton(this, ID_WXTOGGLEBUTTON5, wxT("Equ Flag"), wxPoint(390,115), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton5"));
	maiorFlagButton = new wxToggleButton(this, ID_WXTOGGLEBUTTON6, wxT("Maior Flag"), wxPoint(481,115), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton6"));
	zeroFlagButton->Enable(false);
	negFlagButton->Enable(false);
	carryFlagButton->Enable(false);
	equFlagButton->Enable(false);
	maiorFlagButton->Enable(false);
	menorFlagButton->Enable(false);

	WxStaticText1 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT1, wxT("RX"), wxPoint(177,68), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText2 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT2, wxT("R0"), wxPoint(236,68), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxStaticText2->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, wxT("R1"), wxPoint(297,68), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxStaticText3->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText4 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT4, wxT("PC"), wxPoint(357,68), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxStaticText4->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText5 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT5, wxT("R2"), wxPoint(418,68), wxDefaultSize, 0, wxT("WxStaticText5"));
	WxStaticText5->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText6 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT6, wxT("RDados"), wxPoint(87,120), wxDefaultSize, 0, wxT("WxStaticText6"));
	WxStaticText6->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText7 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT7, wxT("R3"), wxPoint(476,68), wxDefaultSize, 0, wxT("WxStaticText7"));
	WxStaticText7->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText8 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT8, wxT("R4"), wxPoint(536,68), wxDefaultSize, 0, wxT("WxStaticText8"));
	WxStaticText8->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText9 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT9, wxT("RY"), wxPoint(595,68), wxDefaultSize, 0, wxT("WxStaticText9"));
	WxStaticText9->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText10 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT10, wxT("IR"), wxPoint(207,318), wxDefaultSize, 0, wxT("WxStaticText10"));
	WxStaticText10->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText11 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT11, wxT("REnd"), wxPoint(76,318), wxDefaultSize, 0, wxT("WxStaticText11"));
	WxStaticText11->SetForegroundColour(wxColour(*wxWHITE));
	/*
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(7,160), wxSize(650,400));
	WxPanel1->SetBackgroundColour(wxColour(*wxBLACK));
	WxPanel1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine7 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE7, wxPoint(108,15), wxSize(-1,27), wxLI_VERTICAL);
	WxStaticLine7->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine8 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE8, wxPoint(172,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine8->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine9 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE9, wxPoint(231,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine9->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine10 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE10, wxPoint(292,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine10->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine11 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE11, wxPoint(352,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine11->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine12 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE12, wxPoint(413,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine12->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine13 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE13, wxPoint(471,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine13->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine14 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE14, wxPoint(531,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine14->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine15 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE15, wxPoint(590,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine15->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine16 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE16, wxPoint(46,15), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine16->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine17 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE17, wxPoint(10,15), wxSize(36,-1), wxLI_HORIZONTAL);
	WxStaticLine17->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine17->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine17->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine18 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE18, wxPoint(10,15), wxSize(-1,225), wxLI_VERTICAL);
	WxStaticLine18->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine19 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE19, wxPoint(10,240), wxSize(34,-1), wxLI_HORIZONTAL);
	WxStaticLine19->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine19->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine19->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine20 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE20, wxPoint(82,77), wxSize(-1,24), wxLI_VERTICAL);
	WxStaticLine20->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine21 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE21, wxPoint(82,120), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine21->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine25 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE25, wxPoint(172,124), wxSize(75,-1), wxLI_HORIZONTAL);
	WxStaticLine25->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine25->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine25->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine26 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE26, wxPoint(247,124), wxSize(-1,46), wxLI_VERTICAL);
	WxStaticLine26->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine26->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine26->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine28 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE28, wxPoint(229,113), wxSize(51,-1), wxLI_HORIZONTAL);
	WxStaticLine28->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine28->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine28->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine29 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE29, wxPoint(280,113), wxSize(-1,61), wxLI_VERTICAL);
	WxStaticLine29->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine29->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine29->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine32 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE32, wxPoint(314,102), wxSize(-1,68), wxLI_VERTICAL);
	WxStaticLine32->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine33 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE33, wxPoint(351,64), wxSize(-1,106), wxLI_VERTICAL);
	WxStaticLine33->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxGrid1 = new wxGrid(WxPanel1, ID_WXGRID1, wxPoint(44,150), wxSize(110,145), wxHSCROLL);
	WxGrid1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));
	WxGrid1->SetDefaultColSize(50);
	WxGrid1->SetDefaultRowSize(19);
	WxGrid1->SetRowLabelSize(0);
	WxGrid1->SetColLabelSize(25);
	WxGrid1->CreateGrid(6,2,wxGrid::wxGridSelectCells);

	WxStaticLine1 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE1, wxPoint(110,15), wxSize(522,-1), wxLI_HORIZONTAL);
	WxStaticLine1->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine1->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit4 = new wxTextCtrl(WxPanel1, ID_WXEDIT4, wxT("0000"), wxPoint(272,45), wxSize(40,19), 0, wxDefaultValidator, wxT("WxEdit4"));
	WxEdit4->SetMaxLength(4);
	WxEdit4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, wxT("0000"), wxPoint(62,101), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit1"));
	WxEdit1->SetMaxLength(4);
	WxEdit1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit3 = new wxTextCtrl(WxPanel1, ID_WXEDIT3, wxT("0000"), wxPoint(211,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit3"));
	WxEdit3->SetMaxLength(4);
	WxEdit3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit2 = new wxTextCtrl(WxPanel1, ID_WXEDIT2, wxT("0000"), wxPoint(152,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit2"));
	WxEdit2->SetMaxLength(4);
	WxEdit2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit5 = new wxTextCtrl(WxPanel1, ID_WXEDIT5, wxT("0000"), wxPoint(332,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit5"));
	WxEdit5->SetMaxLength(4);
	WxEdit5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit6 = new wxTextCtrl(WxPanel1, ID_WXEDIT6, wxT("0000"), wxPoint(393,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit6"));
	WxEdit6->SetMaxLength(4);
	WxEdit6->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit7 = new wxTextCtrl(WxPanel1, ID_WXEDIT7, wxT("0000"), wxPoint(451,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit7"));
	WxEdit7->SetMaxLength(4);
	WxEdit7->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit8 = new wxTextCtrl(WxPanel1, ID_WXEDIT8, wxT("0000"), wxPoint(511,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit8"));
	WxEdit8->SetMaxLength(4);
	WxEdit8->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit9 = new wxTextCtrl(WxPanel1, ID_WXEDIT9, wxT("0000"), wxPoint(570,45), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit9"));
	WxEdit9->SetMaxLength(4);
	WxEdit9->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit10 = new wxTextCtrl(WxPanel1, ID_WXEDIT10, wxT("0000"), wxPoint(56,338), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit10"));
	WxEdit10->SetMaxLength(4);
	WxEdit10->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit11 = new wxTextCtrl(WxPanel1, ID_WXEDIT11, wxT("0000"), wxPoint(184,338), wxSize(40,19), wxHSCROLL, wxDefaultValidator, wxT("WxEdit11"));
	WxEdit11->SetMaxLength(4);
	WxEdit11->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine2 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE2, wxPoint(632,15), wxSize(-1,370), wxLI_VERTICAL);
	WxStaticLine2->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticLine2->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine3 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE3, wxPoint(73,385), wxSize(560,-1), wxLI_HORIZONTAL);
	WxStaticLine3->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine4 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE4, wxPoint(71,357), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine5 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE5, wxPoint(202,357), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine6 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE6, wxPoint(391,327), wxSize(-1,58), wxLI_VERTICAL);
	WxStaticLine6->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	wxBitmap WxStaticBitmap1_BITMAP(arquiteturaDlg_WxStaticBitmap1_XPM);
	WxStaticBitmap1 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP1, WxStaticBitmap1_BITMAP, wxPoint(297,259), wxSize(189,68));
	WxStaticBitmap1->Enable(false);
	WxStaticBitmap1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	wxBitmap WxStaticBitmap2_BITMAP(arquiteturaDlg_WxStaticBitmap2_XPM);
	WxStaticBitmap2 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP2, WxStaticBitmap2_BITMAP, wxPoint(22,42), wxSize(115,35));
	WxStaticBitmap2->Enable(false);
	WxStaticBitmap2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	wxBitmap WxStaticBitmap3_BITMAP(arquiteturaDlg_WxStaticBitmap3_XPM);
	WxStaticBitmap3 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP3, WxStaticBitmap3_BITMAP, wxPoint(200,170), wxSize(166,36));
	WxStaticBitmap3->Enable(false);
	WxStaticBitmap3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	wxBitmap WxStaticBitmap4_BITMAP(arquiteturaDlg_WxStaticBitmap4_XPM);
	WxStaticBitmap4 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP4, WxStaticBitmap4_BITMAP, wxPoint(409,170), wxSize(167,36));
	WxStaticBitmap4->Enable(false);
	WxStaticBitmap4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine22 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE22, wxPoint(84,135), wxSize(130,-1), wxLI_HORIZONTAL);
	WxStaticLine22->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine22->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine22->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine23 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE23, wxPoint(214,135), wxSize(-1,35), wxLI_VERTICAL);
	WxStaticLine23->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine23->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine23->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine24 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE24, wxPoint(172,64), wxSize(-1,60), wxLI_VERTICAL);
	WxStaticLine24->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine24->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine24->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine27 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE27, wxPoint(229,65), wxSize(-1,48), wxLI_VERTICAL);
	WxStaticLine27->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine27->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine27->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine30 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE30, wxPoint(290,64), wxSize(-1,38), wxLI_VERTICAL);
	WxStaticLine30->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine30->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine30->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine31 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE31, wxPoint(290,102), wxSize(24,-1), wxLI_HORIZONTAL);
	WxStaticLine31->SetForegroundColour(wxColour(255,255,0));
	WxStaticLine31->SetBackgroundColour(wxColour(*wxBLACK));
	WxStaticLine31->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine34 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE34, wxPoint(279,206), wxSize(-1,26), wxLI_VERTICAL);
	WxStaticLine34->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine35 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE35, wxPoint(281,232), wxSize(50,-1), wxLI_HORIZONTAL);
	WxStaticLine35->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine36 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE36, wxPoint(331,232), wxSize(-1,27), wxLI_VERTICAL);
	WxStaticLine36->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine37 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE37, wxPoint(411,64), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine37->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine38 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE38, wxPoint(411,94), wxSize(20,-1), wxLI_HORIZONTAL);
	WxStaticLine38->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine39 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE39, wxPoint(431,94), wxSize(-1,76), wxLI_VERTICAL);
	WxStaticLine39->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine40 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE40, wxPoint(468,64), wxSize(-1,106), wxLI_VERTICAL);
	WxStaticLine40->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine41 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE41, wxPoint(529,64), wxSize(-1,30), wxLI_VERTICAL);
	WxStaticLine41->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine42 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE42, wxPoint(505,94), wxSize(24,-1), wxLI_HORIZONTAL);
	WxStaticLine42->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine43 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE43, wxPoint(505,94), wxSize(-1,76), wxLI_VERTICAL);
	WxStaticLine43->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine44 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE44, wxPoint(588,64), wxSize(-1,41), wxLI_VERTICAL);
	WxStaticLine44->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine45 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE45, wxPoint(542,105), wxSize(46,-1), wxLI_HORIZONTAL);
	WxStaticLine45->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine46 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE46, wxPoint(542,105), wxSize(-1,65), wxLI_VERTICAL);
	WxStaticLine46->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine47 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE47, wxPoint(491,206), wxSize(-1,26), wxLI_VERTICAL);
	WxStaticLine47->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine48 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE48, wxPoint(441,232), wxSize(50,-1), wxLI_HORIZONTAL);
	WxStaticLine48->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine49 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE49, wxPoint(441,232), wxSize(-1,27), wxLI_VERTICAL);
	WxStaticLine49->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine50 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE50, wxPoint(71,295), wxSize(-1,42), wxLI_VERTICAL);
	WxStaticLine50->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine51 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE51, wxPoint(202,295), wxSize(-1,42), wxLI_VERTICAL);
	WxStaticLine51->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox1 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX1, wxT(""), wxPoint(487,258), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox1"));
	WxCheckBox1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox2 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX2, wxT(""), wxPoint(487,275), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox2"));
	WxCheckBox2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox3 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX3, wxT(""), wxPoint(487,292), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox3"));
	WxCheckBox3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox4 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX4, wxT(""), wxPoint(487,309), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox4"));
	WxCheckBox4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox5 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX5, wxT(""), wxPoint(487,326), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox5"));
	WxCheckBox5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox6 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX6, wxT(""), wxPoint(177,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox6"));
	WxCheckBox6->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox7 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX7, wxT(""), wxPoint(236,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox7"));
	WxCheckBox7->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox8 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX8, wxT(""), wxPoint(297,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox8"));
	WxCheckBox8->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox9 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX9, wxT(""), wxPoint(357,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox9"));
	WxCheckBox9->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox10 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX10, wxT(""), wxPoint(418,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox10"));
	WxCheckBox10->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox11 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX11, wxT(""), wxPoint(476,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox11"));
	WxCheckBox11->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox12 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX12, wxT(""), wxPoint(536,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox12"));
	WxCheckBox12->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox13 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX13, wxT(""), wxPoint(595,25), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox13"));
	WxCheckBox13->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox14 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX14, wxT(""), wxPoint(87,81), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox14"));
	WxCheckBox14->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox15 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX15, wxT(""), wxPoint(21,24), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox15"));
	WxCheckBox15->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox16 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX16, wxT(""), wxPoint(181,168), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox16"));
	WxCheckBox16->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox17 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX17, wxT(""), wxPoint(181,185), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox17"));
	WxCheckBox17->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox18 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX18, wxT(""), wxPoint(181,202), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox18"));
	WxCheckBox18->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox19 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX19, wxT(""), wxPoint(579,170), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox19"));
	WxCheckBox19->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox20 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX20, wxT(""), wxPoint(579,187), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox20"));
	WxCheckBox20->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox21 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX21, wxT(""), wxPoint(76,360), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox21"));
	WxCheckBox21->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox22 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX22, wxT(""), wxPoint(207,360), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox22"));
	WxCheckBox22->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxCheckBox23 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX23, wxT(""), wxPoint(24,280), wxSize(17,17), 0, wxDefaultValidator, wxT("WxCheckBox23"));
	WxCheckBox23->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticBitmap5 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP5, wxNullBitmap, wxPoint(170,231), wxSize(64,64) );
	WxStaticBitmap5->Enable(false);
	WxStaticBitmap5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, wxT("Arquivo fonte:"), wxPoint(7,7), wxSize(185,146));
	WxStaticBox1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit12 = new wxTextCtrl(this, ID_WXEDIT12, wxT(""), wxPoint(13,24), wxSize(121,19), 0, wxDefaultValidator, wxT("WxEdit12"));
	WxEdit12->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Procurar"), wxPoint(136,24), wxSize(50,19), 0, wxDefaultValidator, wxT("WxButton1"));
	WxButton1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticBox2 = new wxStaticBox(this, ID_WXSTATICBOX2, wxT("Modo de execução:"), wxPoint(193,7), wxSize(185,146));
	WxStaticBox2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton1 = new wxRadioButton(this, ID_WXRADIOBUTTON1, wxT("Execução completa"), wxPoint(202,22), wxSize(113,17), wxRB_GROUP, wxDefaultValidator, wxT("WxRadioButton1"));
	WxRadioButton1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton2 = new wxRadioButton(this, ID_WXRADIOBUTTON2, wxT("Parar a cada instrução"), wxPoint(202,40), wxSize(132,17), 0, wxDefaultValidator, wxT("WxRadioButton2"));
	WxRadioButton2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton3 = new wxRadioButton(this, ID_WXRADIOBUTTON3, wxT("Parar a cada microinstrução"), wxPoint(202,58), wxSize(155,17), 0, wxDefaultValidator, wxT("WxRadioButton3"));
	WxRadioButton3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, wxT("Executar"), wxPoint(315,131), wxSize(60,19), 0, wxDefaultValidator, wxT("WxButton2"));
	WxButton2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton3 = new wxButton(this, ID_WXBUTTON3, wxT("Ler instruções"), wxPoint(113,45), wxSize(75,19), 0, wxDefaultValidator, wxT("WxButton3"));
	WxButton3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(this, ID_WXLISTBOX1, wxPoint(12,65), wxSize(175,83), arrayStringFor_WxListBox1, wxLB_SINGLE);
	WxListBox1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton4 = new wxButton(this, ID_WXBUTTON4, wxT("Próxima"), wxPoint(313,111), wxSize(62,19), 0, wxDefaultValidator, wxT("WxButton4"));
	WxButton4->Show(false);
	WxButton4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton5 = new wxButton(this, ID_WXBUTTON5, wxT("Resetar máquina"), wxPoint(196,111), wxSize(88,19), 0, wxDefaultValidator, wxT("WxButton5"));
	WxButton5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton6 = new wxButton(this, ID_WXBUTTON6, wxT("Resetar registradores"), wxPoint(196,131), wxSize(113,19), 0, wxDefaultValidator, wxT("WxButton6"));
	WxButton6->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticBox3 = new wxStaticBox(this, ID_WXSTATICBOX3, wxT("Flags"), wxPoint(380,7), wxSize(185,146));
	WxStaticBox3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxToggleButton1 = new wxToggleButton(this, ID_WXTOGGLEBUTTON1, wxT("Zero Flag"), wxPoint(390,33), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton1"));
	WxToggleButton1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxToggleButton2 = new wxToggleButton(this, ID_WXTOGGLEBUTTON2, wxT("Neg Flag"), wxPoint(481,33), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton2"));
	WxToggleButton2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxOpenFileDialog1 =  new wxFileDialog(this, wxT("Arquivo assembly"), wxT("."), wxT(""), wxT("*.asm"), wxOPEN);

	WxToggleButton3 = new wxToggleButton(this, ID_WXTOGGLEBUTTON3, wxT("Carry Flag"), wxPoint(390,75), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton3"));
	WxToggleButton3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxToggleButton4 = new wxToggleButton(this, ID_WXTOGGLEBUTTON4, wxT("Menor Flag"), wxPoint(481,75), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton4"));
	WxToggleButton4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxToggleButton5 = new wxToggleButton(this, ID_WXTOGGLEBUTTON5, wxT("Equ Flag"), wxPoint(390,115), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton5"));
	WxToggleButton5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxToggleButton6 = new wxToggleButton(this, ID_WXTOGGLEBUTTON6, wxT("Maior Flag"), wxPoint(481,115), wxSize(75,19), 0, wxDefaultValidator, wxT("WxToggleButton6"));
	WxToggleButton6->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText1 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT1, wxT("RX"), wxPoint(178,68), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetForegroundColour(wxColour(255,255,255));
	WxStaticText1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText2 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT2, wxT("R0"), wxPoint(237,68), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxStaticText2->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, wxT("R1"), wxPoint(298,68), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxStaticText3->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText4 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT4, wxT("PC"), wxPoint(357,68), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxStaticText4->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText5 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT5, wxT("R2"), wxPoint(416,69), wxDefaultSize, 0, wxT("WxStaticText5"));
	WxStaticText5->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText6 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT6, wxT("RDados"), wxPoint(89,123), wxDefaultSize, 0, wxT("WxStaticText6"));
	WxStaticText6->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText6->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText7 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT7, wxT("R3"), wxPoint(474,68), wxDefaultSize, 0, wxT("WxStaticText7"));
	WxStaticText7->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText7->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText8 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT8, wxT("R4"), wxPoint(533,67), wxDefaultSize, 0, wxT("WxStaticText8"));
	WxStaticText8->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText8->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText9 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT9, wxT("RY"), wxPoint(594,68), wxDefaultSize, 0, wxT("WxStaticText9"));
	WxStaticText9->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText9->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText10 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT10, wxT("IR"), wxPoint(207,318), wxDefaultSize, 0, wxT("WxStaticText10"));
	WxStaticText10->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText10->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText11 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT11, wxT("REnd"), wxPoint(77,320), wxDefaultSize, 0, wxT("WxStaticText11"));
	WxStaticText11->SetForegroundColour(wxColour(*wxWHITE));
	WxStaticText11->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	SetTitle(wxT("arquitetura"));
	SetIcon(wxNullIcon);
	SetSize(8,8,670,600);
	Center();
	
	////GUI Items Creation End
	*/
	SetTitle(wxT("arquitetura"));
	SetIcon(wxNullIcon);
	SetSize(8,8,670,600);
	Center();
	microAtual = 0;
}

void arquiteturaDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

void arquiteturaDlg::set_pr1(bool state)
{
	WxCheckBox7->SetValue(state);
}

void arquiteturaDlg::set_pr2(bool state)
{
	WxCheckBox8->SetValue(state);
}

void arquiteturaDlg::set_pr3(bool state)
{
	WxCheckBox10->SetValue(state);
}

void arquiteturaDlg::set_pr4(bool state)
{
	WxCheckBox11->SetValue(state);
}

void arquiteturaDlg::set_pr5(bool state)
{
	WxCheckBox12->SetValue(state);
}

void arquiteturaDlg::set_prX(bool state)
{
	WxCheckBox6->SetValue(state);
}

void arquiteturaDlg::set_prY(bool state)
{
	WxCheckBox13->SetValue(state);
}

void arquiteturaDlg::set_ppc(bool state)
{
	WxCheckBox9->SetValue(state);
}

void arquiteturaDlg::set_prEnd(bool state)
{
	WxCheckBox21->SetValue(state);
}

void arquiteturaDlg::set_palu1(bool state)
{
	WxCheckBox1->SetValue(state);
}

void arquiteturaDlg::set_palu2(bool state)
{
	WxCheckBox2->SetValue(state);
}

void arquiteturaDlg::set_palu3(bool state)
{
	WxCheckBox3->SetValue(state);
}

void arquiteturaDlg::set_palu4(bool state)
{
	WxCheckBox4->SetValue(state);
}

void arquiteturaDlg::set_palu5(bool state)
{
	WxCheckBox5->SetValue(state);
}

void arquiteturaDlg::set_pir(bool state)
{
	WxCheckBox22->SetValue(state);
}

void arquiteturaDlg::set_prDados(bool state)
{
	WxCheckBox14->SetValue(state);
}

void arquiteturaDlg::set_pmem(bool state)
{
	WxCheckBox23->SetValue(state);
}

void arquiteturaDlg::set_pmux_a1(bool state)
{
	WxCheckBox15->SetValue(state);
}

void arquiteturaDlg::set_pmux_b1(bool state)
{
	WxCheckBox16->SetValue(state);
}

void arquiteturaDlg::set_pmux_b2(bool state)
{
	WxCheckBox17->SetValue(state);
}

void arquiteturaDlg::set_pmux_b3(bool state)
{
	WxCheckBox18->SetValue(state);
}

void arquiteturaDlg::set_pmux_c1(bool state)
{
	WxCheckBox19->SetValue(state);
}

void arquiteturaDlg::set_pmux_c2(bool state)
{
	WxCheckBox20->SetValue(state);
}

void arquiteturaDlg::set_r1(int value)
{
	WxEdit3->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_r2(int value)
{
	WxEdit4->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_r3(int value)
{
	WxEdit6->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_r4(int value)
{
	WxEdit7->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_r5(int value)
{
	WxEdit8->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_rX(int value)
{
	WxEdit2->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_rY(int value)
{
	WxEdit9->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_pc(int value)
{
	WxEdit5->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_rEnd(int value)
{
	WxEdit10->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_rDados(int value)
{
	WxEdit1->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

void arquiteturaDlg::set_ir(int value)
{
	WxEdit11->SetValue(wxString::Format(_T("%04X"), value).Right(4));
	this->Refresh();
	this->Update();
}

/*
 * WxButton1Click
 */
void arquiteturaDlg::WxButton1Click(wxCommandEvent& event)
{
	if ( WxOpenFileDialog1->ShowModal() == wxID_OK )
	{
		WxEdit12->SetValue(WxOpenFileDialog1->GetPath());
	}
}

/*
 * WxButton3Click
 */
void arquiteturaDlg::WxButton3Click(wxCommandEvent& event)
{
	if ( WxEdit12->GetValue() != "" )
	{
		WxListBox1->Clear();
		leArq(WxEdit12->GetValue(), this);
		WxGrid1->ForceRefresh();
	}
	else
		wxLogMessage(_T("Por favor, informe um arquivo."));
}

/*
 * WxButton2Click
 */
void arquiteturaDlg::WxButton2Click(wxCommandEvent& event)
{
	bool isInstrBreak, isMicroBreak;
	isInstrBreak = isMicroBreak = false;
	uniCont.zeraPc();
	microAtual = 0;
	
	if ( WxRadioButton1->GetValue() ) // execução completa
	{
		isInstrBreak = isMicroBreak = false;
	}
	else if ( WxRadioButton2->GetValue() )
	{
		isInstrBreak = true;
	}
	else if ( WxRadioButton3->GetValue() )
	{
		isMicroBreak = true;
	}
	if ( uniCont.instr(microAtual, isInstrBreak, isMicroBreak) )
	{
		WxButton4->Show();
	}
	else
	{
		WxButton4->Show(false);
		wxLogMessage(_T("Fim das instruções."));
	}
	this->Refresh();
	this->Update();
}

/*
 * WxButton4Click
 */
void arquiteturaDlg::WxButton4Click(wxCommandEvent& event)
{
	bool isInstrBreak, isMicroBreak;
	isInstrBreak = isMicroBreak = false;

	if ( WxRadioButton1->GetValue() ) // execução completa
	{
		isInstrBreak = isMicroBreak = false;
	}
	else if ( WxRadioButton2->GetValue() )
	{
		isInstrBreak = true;
	}
	else if ( WxRadioButton3->GetValue() )
	{
		isMicroBreak = true;
	}
	if ( uniCont.instr(microAtual, isInstrBreak, isMicroBreak) )
	{
		WxButton4->Show();
	}
	else
	{
		WxButton4->Show(false);
		wxLogMessage(_T("Fim das instruções."));
	}
	this->Refresh();
	this->Update();
}

/*
 * WxButton5Click
 */
void arquiteturaDlg::WxButton5Click(wxCommandEvent& event)
{
	WxListBox1->Clear();
	for ( int i = 0 ; i < MAXMEM ; i++ )
	{
		mem[i] = 0;
	}
	uniCont.zeraTudo();
	carryFlagButton->SetValue(false);
	zeroFlagButton->SetValue(false);
	negFlagButton->SetValue(false);
	menorFlagButton->SetValue(false);
	equFlagButton->SetValue(false);
	maiorFlagButton->SetValue(false);
	WxButton4->Show(false);
}

/*
 * WxButton6Click
 */
void arquiteturaDlg::WxButton6Click(wxCommandEvent& event)
{
	uniCont.zeraTudo();
}

//---------------------------------------------------------------------------
//
// Name:        arquiteturaApp.cpp
// Author:      Renato "Lond"
// Created:     3/7/2007 14:49:58
// Description: 
//
//---------------------------------------------------------------------------

#include "arquiteturaApp.h"
#include "arquiteturaDlg.h"
#include "arquitetura.h"

IMPLEMENT_APP(arquiteturaDlgApp)

bool arquiteturaDlgApp::OnInit()
{
	wxInitAllImageHandlers();
	
	arquiteturaDlg* dialog = new arquiteturaDlg(NULL);
	SetTopWindow(dialog);
	dialog->Show(true);

	/* Pega as instruções do arquivo e joga pra memória */
	instrucoes = map<string, int>();
	populaInstrucoes(dialog);

	/* Pega as microInstruções do arquivo e joga pra memória */
	microInstrucoes = map<int, vector<string> >();
	populaMicroInstrucoes(dialog);

	/* Zera toda a memória */
	for ( int i = 0 ; i < MAXMEM ; i++ )
	{
		mem[i] = 0;
	}
	
	uniCont = uc(memPos, dialog);

	return true;
}
 
int arquiteturaDlgApp::OnExit()
{
	return 0;
}

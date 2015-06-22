//---------------------------------------------------------------------------
//
// Name:        arquiteturaApp.h
// Author:      Renato "Lond"
// Created:     3/7/2007 14:49:58
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __ARQUITETURADLGApp_h__
#define __ARQUITETURADLGApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class arquiteturaDlgApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif

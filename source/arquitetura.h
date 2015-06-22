#ifndef INC_ARQUITETURA_H
#define INC_ARQUITETURA_H

/*#ifndef STD_IOSTREAM
#define STD_IOSTREAM
#include <iostream>
#endif STD_IOSTREAM */

#ifndef STD_FSTREAM
#define STD_FSTREAM
#include <fstream>
#endif /* STD_FSTREAM */

#ifndef STD_SSTREAM
#define STD_SSTREAM
#include <sstream>
#endif /* STD_SSTREAM */

#ifndef STD_CSTDLIB
#define STD_CSTDLIB
#include <cstdlib>
#endif /* STD_CSTDLIB */

#ifndef STD_CSTRING
#define STD_CSTRING
#include <cstring>
#endif /* STD_CSTRING */

#ifndef STD_VECTOR
#define STD_VECTOR
#include <vector>
#endif /* STD_MAP */

#ifndef STD_MAP
#define STD_MAP
#include <map>
#endif /* STD_MAP */

#include <boost/regex.hpp>
#include <wx/log.h>

class arquiteturaDlg;

#include "uc.h"
#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

using namespace std;

vector<string> split ( string , char );
void leArq(const wxChar *, arquiteturaDlg *);
void populaInstrucoes( arquiteturaDlg * );
void populaMicroInstrucoes( arquiteturaDlg * );
string intToStr ( int );
int strToInt ( string );
int strbinToInt ( string );
string intToStrbin ( int );
bool isNum ( string );
string tiraEspacos( string );

extern map<string, int> instrucoes;
extern map<int, vector<string> > microInstrucoes;
#define MAXMEM 16*16*16*16
extern short int mem[MAXMEM];

#define TAMPROXMICRO 11
extern int memPos;
extern uc uniCont;

#endif /* _INC_ARQUITETURA_H */

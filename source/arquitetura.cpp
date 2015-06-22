#include "arquitetura.h"

#include "alu.cpp"
#include "uc.cpp"
#include "arquiteturaDlg.h"

map<string, int> instrucoes;
map<int, vector<string> > microInstrucoes;
short int mem[MAXMEM];
int memPos = 0;
uc uniCont;

void leArq(const wxChar *arquivo, arquiteturaDlg *dialog)
{
	fstream instr, instr2;
	string linha, instrucao, label, regOrig, regDest;
	vector<string> vect = vector<string>();
	map<string, int> labels;
	
	instr.open(arquivo, ios::in);
	if ( !instr.is_open() )
	{
		wxLogFatalError(_("Erro ao abrir arquivo"));
//		perror("Erro ao abrir arquivo");
//		exit(-1);
	}
	int i = memPos;

	string regexp = string();
	regexp += "(([A-Za-z_][A-Za-z0-9_]*)[ \r\n\t]*:)?"; /* Label, opcional */
	regexp += "(";
	regexp += "[ \r\n\t]*([A-Za-z]+)"; /* Instrucão */
	regexp += "[ \r\n\t]+<[ \r\n\t]*";
	regexp += "(\\([A-Za-z][A-Za-z0-9]*\\)|[A-Za-z][A-Za-z0-9]*|[-+]?[1-9][0-9]*[Hh]?|[+-]?0|#[A-Za-z_][A-Za-z0-9_]*)"; /* Primeiro operando */
	regexp += "[ \r\n\t]*(,[ \r\n\t]*(\\([A-Za-z][A-Za-z0-9]*\\)|[A-Za-z][A-Za-z0-9]*|[-+]?[1-9][0-9]*[Hh]?))?"; /* Segundo operando, opcional */
	regexp += "[ \r\n\t]*>"; 
	regexp += ")?";
	regexp += "[ \r\n\t]*(;(.*))?";
	
	
	boost::regex reg_instr(regexp);
	boost::match_flag_type flags = boost::match_default;
	boost::match_results<std::string::const_iterator> what;

	while ( !instr.eof() )
	{
		getline(instr, linha);

		if ( boost::regex_match(linha, reg_instr) )
		{
			regex_search(linha, what, reg_instr, flags);

			if ( what[2] != "" )
			{
				labels[what[2]] = i;
			}

			if ( what[4] == "" )
			{
				continue;
			}
			/*cout << "Tudo: " << what[0] << endl;
			cout << "Label: " << what[2] << endl;
			cout << "instrucao: " << what[4] << endl;
			cout << "Op1: " << what[5] << endl;
			cout << "Op2: " << what[7] << endl;
			cout << "Comments: " << what[9] << endl;
			cout << endl;*/

			string op1, op2, teste = "";

			op1 = what[5].str();
			op2 = what[7].str();

			if ( isNum(op1) )
			{
				op1 = "NUM";
			}
			if ( isNum(op2) )
			{
				op2 = "NUM";
			}
			if ( op1.at(0) == '#' )
			{
				op1 = "LAB";
			}
			if ( op1 != "" && op2 != "" )
			{
				teste = what[4].str() + " <" + op1 + "," + op2 + ">";
			}
			else if ( op1 != "" )
			{
				teste = what[4].str() + " <" + op1 + ">";
			}
			if ( teste != "" && instrucoes.find(teste) != instrucoes.end() )
			{
				i++;
				if ( isNum(what[5]) )
					i++;
				if ( isNum(what[7]) )
					i++;
				if ( what[5].str().at(0) == '#' )
					i++;
			} 
			else if ( teste != "" )
			{
				wxLogFatalError(_("Erro: Instrução desconhecida -- %s"),teste.c_str());
//				cerr << "Erro: Instrução desconhecida -- " << teste << endl;
//				exit(1);
			}
		}
		else
		{
			wxLogFatalError(_("Erro: Formato de instrução desconhecido -- %s"),linha.c_str());
//			cerr << "Erro: Formato de instrução desconhecido -- " << linha << endl;
//			exit(-1);
		}
	}
	instr.close();
	
	instr2.open(arquivo, ios::in);
	if ( !instr2.is_open() )
	{
		wxLogFatalError(_("Erro ao abrir arquivo"));
//		perror("Erro ao abrir arquivo");
//		exit(-1);
	}
	i = memPos;

	while ( !instr2.eof() )
	{
		getline(instr2, linha);
		if ( boost::regex_match(linha, reg_instr) )
		{
			regex_search(linha, what, reg_instr, flags);
			if ( what[4] == "" )
			{
				continue;
			}
			/*cout << "Tudo: " << what[0] << endl;
			cout << "Label: " << what[2] << endl;
			cout << "instrucao: " << what[4] << endl;
			cout << "Op1: " << what[5] << endl;
			cout << "Op2: " << what[7] << endl;
			cout << "Comments: " << what[9] << endl;
			cout << endl;*/

			string op1, op2, teste = "";

			op1 = what[5].str();
			op2 = what[7].str();

			if ( isNum(op1) )
			{
				op1 = "NUM";
			}
			if ( isNum(op2) )
			{
				op2 = "NUM";
			}
			if ( op1.at(0) == '#' )
			{
				op1 = "LAB";
			}
			if ( op1 != "" && op2 != "" )
			{
				teste = what[4].str() + " <" + op1 + "," + op2 + ">";
			}
			else if ( op1 != "" )
			{
				teste = what[4].str() + " <" + op1 + ">";
			}
			if ( teste != "" && instrucoes.find(teste) != instrucoes.end() )
			{
				/* Insere na posição atual de memória essa instrução encontrada, soma mais um
				 * a posição atual
				 * instrucoes.find(teste)->second; */
				 mem[i++] = instrucoes.find(teste)->second;
				 if ( isNum(what[5]) )
					 mem[i++] = strToInt(what[5]);
				 if ( isNum(what[7]) )
					 mem[i++] = strToInt(what[7]);
				 if ( what[5].str().at(0) == '#' )
				 {
					string tempsubstr = what[5].str().substr(1);
					if ( labels.find(tempsubstr) != labels.end() )
					{
						mem[i++] = labels[tempsubstr];
					}
					else
					{
						wxLogFatalError(_("Erro: Label não declarado -- %s"),tempsubstr.c_str());
//						cerr << "Erro: Label não declarado -- " << tempsubstr << endl;
					}
				 }
				if ( op1 != "" && op2 != "" )
				{
					if ( what[2].str() != "" )
						teste = what[2].str() + ": " + what[4].str() + " <" + what[5].str() + " , " + what[7].str() + ">";
					else
						teste = what[4].str() + " <" + what[5].str() + " , " + what[7].str() + ">";
				}
				else if ( op1 != "" )
				{
					if ( what[2].str() != "" )
						teste = what[2].str() + ": " + what[4].str() + " <" + what[5].str() + ">";
					else
						teste = what[4].str() + " <" + what[5].str() + ">";
				}
				dialog->WxListBox1->Append(teste);
			} 
			else if ( teste != "" )
			{
				wxLogFatalError(_("Erro: Instrução desconhecida -- %s"),teste.c_str());
//				cerr << "Erro: Instrução desconhecida -- " << teste << endl;
//				exit(1);
			}
		}
		else
		{
			wxLogFatalError(_("Erro: Formato de instrução desconhecido -- %s"),linha.c_str());
//			cerr << "Erro: Formato de instrução desconhecido -- " << linha << endl;
//			exit(-1);
		}
	}
}

void populaInstrucoes( arquiteturaDlg *dialog )
{
	string linha = string();
	vector<string> vect = vector<string>();
	
	fstream f("instrucoes.db", ios::in);
	
	string regexp;
	
	regexp = "(([A-Za-z0-9<>(), ]*)@([0-9]*))?([ \n\r\t]*#(.*))?[\n\r\t ]*";
	boost::regex instr(regexp);
	boost::match_flag_type flags = boost::match_default;
	boost::match_results<std::string::const_iterator> what;
	int linhaN = 1;

	while ( !f.eof() )
	{
		getline(f, linha);
		if ( linha == "" )
		{
			linhaN++;
			continue;
		}
			
		if ( boost::regex_match(linha, instr) )
		{
			
			regex_search(linha, what, instr, flags);
			/* cout << "Tudo " << what[0] << endl; 
			cout << "Tudo, exceto comentários" << what[1] << endl;
			cout << "Mnemônimo + operandos " << what[2] << endl;
			cout << "Só o número do entry point " << what[3] << endl;
			cout << "os comentários, com espaços precedentes " << what[4] << endl;
			cout << "só os comentários " << what[5] << endl;
			*/
			
			/*vect = split ( temp, '@' );
			instrucoes[vect.at(0)] = vect.at(1);*/
			instrucoes[what[2]] = strToInt(what[3]);
			linhaN++;
			
		}
		else
		{
			wxLogFatalError(_("Erro ao ler instrução, na linha %d: %s"),linhaN, linha.c_str());
//			cerr << "Erro ao ler instrução, na linha " << linhaN << ": " << linha << endl;
//			exit(1);
		}
	}
}

void populaMicroInstrucoes(arquiteturaDlg *dialog)
{
	string linha = string();
	string T1, T2, T3;
	int microN;

	fstream f("micros.db", ios::in);

	string regexp;
	
	regexp = "(([0-9]*)@\\(([01 ]*)\\|([01 ]*)\\|([01 ]*)\\))?([ \n\r\t]*#(.*))?[ \n\r\t]*";
	boost::regex instr(regexp);
	boost::match_flag_type flags = boost::match_default;
	boost::match_results<std::string::const_iterator> what;
	
	int linhaN = 1;
	
	while ( !f.eof() )
	{
		getline(f,linha);
		if ( linha == "" ) 
		{
			linhaN++;
			continue;
		}

		if ( boost::regex_match(linha, instr) )
		{
			regex_search(linha, what, instr, flags);
			/* cout << "Tudo " << what[0] << endl;
			cout << "Só a micros " << what[1] << endl;
			cout << "Número da micro " << what[2] << endl;
			cout << "T1 " << what[3] << endl;
			cout << "T2 " << what[4] << endl;
			cout << "T3 " << what[5] << endl;
			cout << "Depois da micro" << what[6] << endl;
			cout << "Comentários" << what[7] << endl; */

			microN = strToInt(what[2]);

			T1 = tiraEspacos(what[3]);
			T2 = tiraEspacos(what[4]);
			T3 = tiraEspacos(what[5]);

			vector<string> Ts;
			Ts.push_back(T1);
			Ts.push_back(T2);
			Ts.push_back(T3);
			
			microInstrucoes[microN] = Ts;
			linhaN++;
		}
		else
		{
			wxLogFatalError(_("Erro ao ler microinstrução, na linha %d: %s"),linhaN, linha.c_str());
			//cerr << "Erro ao ler microinstrução, na linha : " << linha << endl;
			//exit(1);
		}
	}
}

string tiraEspacos(string str)
{
	string temp = string();
	for ( unsigned int i = 0 ; i < str.size() ; i++ )
	{
		if ( str[i] == ' ' )
			continue;
		else
			temp += str[i];
	}

	return temp;
}

vector<string> split ( string str , char separator )
{
	unsigned int i;
	string teste = string();
	vector<string> teste_vec = vector<string>();
	
	for ( i = 0 ; i < str.size() ; i++ )
	{
		if ( str.at(i) != separator )
		{
			teste += str.at(i);
		}
		else
		{
			teste_vec.push_back(teste);
			teste = string();
		}
	}
	teste_vec.push_back(teste);
	return teste_vec;
}

string intToStr ( int numero )
{
	string temp = string();
	stringstream ss;
	ss << numero;
	ss >> temp;
	return temp;
}

int strToInt ( string str )
{
	int temp;
	stringstream(str) >> temp;
	return temp;
}

bool isNum ( string str )
{
	unsigned int i;
	i = 0;
	
	if ( str[i] == '+' || str[i] == '-' )
	{
        i++;
    }
    
	for ( ; i < str.size() ; i++ )
		if ( str[i] < '0' || str[i] > '9' )
			return false;
	if ( i == 0 )
		return false;

	return true;
}

int strbinToInt ( string str )
{
	int temp = 0;
	int pot = 1;
	for ( int i = str.size()-1 ; i >= 0 ; i-- , pot*=2 )
	{
		if ( str.at(i) != '0' && str.at(i) != '1' )
		{
			wxLogFatalError(_("Erro na conversão de binário pra decimal de : %s"),str.c_str());
//			cerr << "Erro na conversão de binário pra decimal de " << str << endl;
//			exit(1);
		}

		temp += pot * (str.at(i)-'0');
	}

	return temp;
}

string intToStrbin ( int bin )
{
	string temp = string();
	while ( bin )
	{
		temp = intToStr(bin%2) + temp;
		bin /= 2;
	}

	return temp;
}


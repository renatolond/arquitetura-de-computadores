#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <boost/regex.hpp>
#include <map>
#define TAMPROXMICRO 11
using namespace std;

string intToStr ( int );
int strToInt ( string );
int strbinToInt ( string );
string intToStrbin ( int , int tam = 0);
bool isNum ( string );

int main ()
{
	string arquivo;
	int startNum;
	
	cout << "Arquivo pra converter?" << endl;
	cin >> arquivo;
	cout << "Número em que ele deve começar?" << endl;
	cin >> startNum;
	
	fstream f, fout;
	f.open(arquivo.c_str(), ios::in);
	if ( !f.is_open() )
	{
		perror("Erro ao abrir arquivo");
		exit(-1);
	}
	
	fout.open("saida.txt", ios::out);
	if ( !f.is_open() )
	{
		perror("Erro ao abrir arquivo");
		exit(-1);
	}
	
	string regexp;
	
	regexp = "(([0-9]*)@\\(([01]{" + intToStr(TAMPROXMICRO) + "})([01 ]*)\\|([01]{" + intToStr(TAMPROXMICRO) + " })([01 ]*)\\|([01]{" + intToStr(TAMPROXMICRO) + "})([01 ]*)\\))?([ \n\r\t]*#(.*))?[ \n\r\t]*";
	boost::regex instr(regexp);
	boost::match_flag_type flags = boost::match_default;
	boost::match_results<std::string::const_iterator> what;
	
	string linha, novaLinha;
	map<int, int> mapinha = map<int, int>();
	int i = startNum;
	bool first = true;
	mapinha[7] = 7;
	while ( !f.eof() )
	{
		getline(f,linha);
		
		if ( boost::regex_match(linha, instr) )
		{
			regex_search(linha, what, instr, flags);
			novaLinha = string();
			/*
			if ( what[1] != "" )
			{
				cout << "Tudo " << what[0] << endl;
				cout << "Micro " << what[1] << endl;
				cout << "Número da micro " << what[2] << endl;
				cout << "próxima micro(1) " << what[3] << endl;
				cout << "pontos(1) " << what[4] << endl;
				cout << "próxima micro(2) " << what[5] << endl;
				cout << "pontos(2) " << what[6] << endl;
				cout << "próxima micro(3) " << what[7] << endl;
				cout << "pontos(3) " << what[8] << endl;
				cout << "comments(tudo) " << what[9] << endl;
				cout << "comments(só comentário) " << what[10] << endl;
			}*/
			if ( what[1] != "" )
			{
				int tempN1, tempN2, tempN3;
				tempN1 = strToInt(what[2]);
				tempN2 = strbinToInt(what[3]);
				novaLinha += intToStr(i) + "@"; // novalinha = num@
				mapinha[tempN1] = i;
				if ( mapinha.find(tempN2) != mapinha.end() )
				{
					tempN3 = mapinha.find(tempN2)->second; // agora a proxima instrução é a que estava no mapa
				}
				else
				{
					if ( tempN2 == (tempN1+1) )
					{
						tempN3 = i+1;
					}
					else
					{
						cout << strbinToInt(what[3]) << " " << what[3] << " " << tempN2 << endl;
						cout << "caso não esperado. aconteceu em: " << what[1] << endl;
						exit(-1);
					}
				}
				novaLinha += "(" + intToStrbin(tempN3, TAMPROXMICRO) + what[4] + "|" + intToStrbin(tempN3, TAMPROXMICRO) + what[6] + "|" + intToStrbin(tempN3, TAMPROXMICRO) + what[8] + ")";
				//cout << novaLinha << endl;
				i++;
			}
			novaLinha += what[9];
			
			fout << novaLinha << endl;
		}
		else
		{
			cout << "Erro na conversão!" << endl;
			exit(-1);
		}
	}
	
	return 0;
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
			cerr << "Erro na conversão de binário pra decimal de " << str << endl;
			exit(1);
		}

		temp += pot * (str.at(i)-'0');
	}

	return temp;
}

string intToStrbin ( int bin , int tam )
{
	string temp = string();
	int i = 0;
	while ( bin )
	{
		temp = intToStr(bin%2) + temp;
		bin /= 2;
		i++;
	}
	
	while ( i < tam )
	{
		temp = "0" + temp;
		i++;
	}

	return temp;
}


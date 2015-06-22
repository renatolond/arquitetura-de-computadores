#ifndef INC_UC_H
#define INC_UC_H

#include "alu.h"

#ifndef STD_VECTOR
#define STD_VECTOR
#include <vector>
#endif /* STD_MAP */

#ifndef STD_STRING
#define STD_STRING
#include <string>
#endif /* STD_STRING */

#include "arquiteturaDlg.h"

using namespace std;

class uc
{
	private:
		/* ULA */
		alu alu1;

		/* Registradores */
		short int r1,
		    r2,
		    r3,
		    r4,
		    r5,
		    rX,
		    rY,
		    rDados, /* Receber / Enviar pra mem�ria */
		    pc, /* Posi��o atual da mem�ria - Program Counter */
		    ir, /* Instruction Register */
		    rEnd, /* Endere�a mem�ria */
		    rmem,
		    sAlu,
		    mux_a, mux_b, mux_c;

		/* Pontos de controle */
		bool pr1,
		     pr2,
		     pr3,
		     pr4,
		     pr5,
		     prX,
		     prY,
		     prDados,
		     ppc,
		     pir,
		     prEnd,
		     pmem, /* controla a mem�ria: 0 l�, 1 escreve */
		     palu1, palu2, palu3, palu4, palu5, /* pontos de controle da ALU */
		     pmux_a1, /* controla se RDados recebe a mem�ria ou a sa�da da ALU */
		     pmux_b1, pmux_b2, pmux_b3, /* controla RDados, RX, R1, R2 e PC */
		     pmux_c1, pmux_c2, /* controla R3, R4, R5, RY */
		     pflags;
		int microAt;
		arquiteturaDlg *dialog;

	public:
		uc();
		uc(int, arquiteturaDlg*);
		void zeraPc();
		void zeraTudo();
		bool instr(int &, bool, bool); /* instru��o atual, micro atual, ismicrobreak, isinstrbreak */
		bool micro(int &, bool); /* micro atual, ismicrobreak */
		short int mux(string, vector<short int *> );
		void processa (int &);
};

#endif /* INC_UC_H */

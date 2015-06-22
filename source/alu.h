#ifndef INC_ALU_H
#define INC_ALU_H

#include "arquiteturaDlg.h"

class alu
{
	public:
	alu();
	void setaDialog(arquiteturaDlg *);
	void zeraFlags();
	short int fazOp(short int , short int , short int , bool);
	bool zeroFlag, negFlag, equFlag, menorFlag, maiorFlag, carryFlag;
	arquiteturaDlg *dialog;
};
#endif /* INC_ALU_H */

alu::alu ()
{
}

void alu::zeraFlags ()
{
	zeroFlag = negFlag = equFlag = menorFlag = maiorFlag = carryFlag = false;
	dialog->carryFlagButton->SetValue(false);
	dialog->zeroFlagButton->SetValue(false);
	dialog->negFlagButton->SetValue(false);
	dialog->menorFlagButton->SetValue(false);
	dialog->equFlagButton->SetValue(false);
	dialog->maiorFlagButton->SetValue(false);
}

void alu::setaDialog ( arquiteturaDlg *dlg )
{
	dialog = dlg;
}

short int alu::fazOp ( short int a , short int b , short int op , bool flags)
{
	int res = 0;
	/*zeroFlag = negFlag = equFlag = menorFlag = maiorFlag = carryFlag = false;
	dialog->carryFlagButton->SetValue(false);
	dialog->zeroFlagButton->SetValue(false);
	dialog->negFlagButton->SetValue(false);
	dialog->menorFlagButton->SetValue(false);
	dialog->equFlagButton->SetValue(false);
	dialog->maiorFlagButton->SetValue(false);*/

	switch ( op )
	{
		case 0:
			res = 0;
			break;
		case 1:
			res = a;
			break;
		case 2:
			res = ~a;
			break;
		case 3:
			res = -a;
			break;
		case 4:
			res = b;
			break;
		case 5:
			res = ~b;
			break;
		case 6:
			res = -b;
			break;
		case 7:
			res = a + b;
			if ( ((double)a*b)>0 && ((double)b*res)<0 && flags )
			{
				carryFlag = true; dialog->carryFlagButton->SetValue(true);
			}
			break;
		case 8:
			res = a - b;
			if ( res == 0 && flags )
			{
				equFlag = true;	dialog->equFlagButton->SetValue(true);
			}
			if ( res > 0 && flags )
			{
				maiorFlag = true; dialog->maiorFlagButton->SetValue(true);
			}
			if ( res < 0 && flags )
			{
				menorFlag = true; dialog->menorFlagButton->SetValue(true);
			}
			break;
		case 9:
			res = b - a;
			if ( res == 0 && flags )
			{
				equFlag = true; dialog->equFlagButton->SetValue(true);
			}
			if ( res > 0 && flags )
			{
				maiorFlag = true; dialog->maiorFlagButton->SetValue(true);
			}
			if ( res < 0 && flags )
			{
				menorFlag = true; dialog->menorFlagButton->SetValue(true);
			}
			break;
		case 10:
			res = a + 1;
			if ( (a*1)>0 && res*a<0 && flags )
			{
				carryFlag = true; dialog->carryFlagButton->SetValue(true);
			}
			break;
		case 11:
			res = a - 1;
			break;
		case 12:
			res = b + 1;
			if ( (b*1)>0 && b*res<0 && flags )
			{
				carryFlag = true; dialog->carryFlagButton->SetValue(true);
			}
			break;
		case 13:
			res = b - 1;
			break;
		case 14:
			res = a & b;
			break;
		case 15:
			res = ~(a & b);
			break;
		case 16:
			res = a | b;
			break;
		case 17:
			res = ~(a | b);
			break;
		case 18:
			res = a^b;
			break;
		case 19:
			res = a << 1;
			break;
		case 20:
			res = a >> 1;
			break;
		case 21:
			res = b << 1;
			break;
		case 22:
			res = b >> 1;
			break;
		default:
			wxLogFatalError(_("Erro na alu!"));
//			cout << "Erro na alu!" << endl;
//			exit(1);
	}
	
	if ( res == 0 && flags )
	{
		zeroFlag = true; dialog->zeroFlagButton->SetValue(true);
	}
	if ( res < 0 && flags )
	{
		negFlag = true; dialog->negFlagButton->SetValue(true);
	}
//    wxLogMessage(wxString::Format(_("Res: %d"), res));
	return res;
}

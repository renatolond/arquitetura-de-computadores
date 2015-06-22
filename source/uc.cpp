uc::uc()
{
}

void uc::zeraPc()
{
	pc = 0;
	dialog->set_pc(0);
}

void uc::zeraTudo()
{
	r1 = r2 = r3 = r4 = r5 = rX = rY = rDados = pc = ir = rEnd = sAlu = mux_a = mux_b = mux_c = rmem = 0;
	dialog->set_r1(0);
	dialog->set_r2(0);
	dialog->set_r3(0);
	dialog->set_r4(0);
	dialog->set_r5(0);
	dialog->set_rX(0);
	dialog->set_rY(0);
	dialog->set_rDados(0);
	dialog->set_pc(0);
	dialog->set_ir(0);
	dialog->set_rEnd(0);
	pr1 = pr2 = pr3 = pr4 = pr5 = prX = prY = prDados = ppc = pir = prEnd = pmem = palu1 = palu2 = palu3 = palu4 = palu5 = pmux_a1 = pmux_b1 = pmux_b2 = pmux_b3 = pmux_c1 = pmux_c2 = false;
	dialog->set_pr1(false);
	dialog->set_pr2(false);
	dialog->set_pr3(false);
	dialog->set_pr4(false);
	dialog->set_pr5(false);
	dialog->set_prX(false);
	dialog->set_prY(false);
	dialog->set_prDados(false);
	dialog->set_ppc(false);
	dialog->set_pir(false);
	dialog->set_prEnd(false);
	dialog->set_pmem(false);
	dialog->set_palu1(false);
	dialog->set_palu2(false);
	dialog->set_palu3(false);
	dialog->set_palu4(false);
	dialog->set_palu5(false);
	dialog->set_pmux_a1(false);
	dialog->set_pmux_b1(false);
	dialog->set_pmux_b2(false);
	dialog->set_pmux_b3(false);
	dialog->set_pmux_c1(false);
	dialog->set_pmux_c2(false);
}

uc::uc(int memStart, arquiteturaDlg* dlg)
{
	dialog = dlg;
	alu1.setaDialog(dlg);
	/* Inicializa o sistema, botando o pc no início indicado pelo programa */
	r1 = r2 = r3 = r4 = r5 = rX = rY = rDados = pc = ir = rEnd = sAlu = mux_a = mux_b = mux_c = rmem = 0;
	dialog->set_r1(0);
	dialog->set_r2(0);
	dialog->set_r3(0);
	dialog->set_r4(0);
	dialog->set_r5(0);
	dialog->set_rX(0);
	dialog->set_rY(0);
	dialog->set_rDados(0);
	dialog->set_pc(0);
	dialog->set_ir(0);
	dialog->set_rEnd(0);
	pr1 = pr2 = pr3 = pr4 = pr5 = prX = prY = prDados = ppc = pir = prEnd = pmem = palu1 = palu2 = palu3 = palu4 = palu5 = pmux_a1 = pmux_b1 = pmux_b2 = pmux_b3 = pmux_c1 = pmux_c2 = false;
	dialog->set_pr1(false);
	dialog->set_pr2(false);
	dialog->set_pr3(false);
	dialog->set_pr4(false);
	dialog->set_pr5(false);
	dialog->set_prX(false);
	dialog->set_prY(false);
	dialog->set_prDados(false);
	dialog->set_ppc(false);
	dialog->set_pir(false);
	dialog->set_prEnd(false);
	dialog->set_pmem(false);
	dialog->set_palu1(false);
	dialog->set_palu2(false);
	dialog->set_palu3(false);
	dialog->set_palu4(false);
	dialog->set_palu5(false);
	dialog->set_pmux_a1(false);
	dialog->set_pmux_b1(false);
	dialog->set_pmux_b2(false);
	dialog->set_pmux_b3(false);
	dialog->set_pmux_c1(false);
	dialog->set_pmux_c2(false);
	pc = memStart;
}

bool uc::instr(int &microAtual, bool isInstrBreak, bool isMicroBreak)
{
	while ( 1 )
	{
//		if ( isMicroBreak )
//		{
//			return micro(microAtual, isMicroBreak);
//		}

		micro(microAtual, isMicroBreak);
		if ( mem[pc] == 0 )
			break;
		if ( isInstrBreak || isMicroBreak )
		{
			return true;
		}

	}

	return false;
}

bool uc::micro(int &microAtual, bool isMicroBreak)
{
	string pMicro, micro;
	int proximaMicro;
	vector<string> micros;
	while ( 1 )
	{
		micros = microInstrucoes[microAtual];
		micro = micros.at(0);
		pMicro = micro.substr(0,TAMPROXMICRO); /* Depois ajeitar o tamanho da micro */
		proximaMicro = strbinToInt(pMicro);
		/* Agora, faz o T1: */

		pr1 = pr2 = pr3 = pr4 = pr5 = prX = prY = prDados = ppc = pir = prEnd = pmem = palu1 = palu2 = palu3 = palu4 = palu5 = pmux_a1 = pmux_b1 = pmux_b2 = pmux_b3 = pmux_c1 = pmux_c2 = false;
		
		int i = 0;
		pr1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr1(pr1);
		pr2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr2(pr2);
		pr3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr3(pr3);
		pr4 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr4(pr4);
		pr5 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr5(pr5);
		prX = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prX(prX);
		prY = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prY(prY);
		prDados = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prDados(prDados);
		ppc = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_ppc(ppc);
		pir = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pir(pir);
		prEnd = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prEnd(prEnd);
		pmem = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmem(pmem);
		palu1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu1(palu1);
		palu2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu2(palu2);
		palu3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu3(palu3);
		palu4 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu4(palu4);
		palu5 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu5(palu5);
		pmux_a1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_a1(pmux_a1);
		pmux_b1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b1(pmux_b1);
		pmux_b2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b2(pmux_b2);
		pmux_b3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b3(pmux_b3);
		pmux_c1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_c1(pmux_c1);
		pmux_c2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_c2(pmux_c2);
		pflags = micro.at(TAMPROXMICRO + i++) - '0';
		if ( pflags )
		{
			alu1.zeraFlags();
		}
		processa(proximaMicro);
		
		/* Agora, o T2: */
		micro = micros.at(1);
		pMicro = micro.substr(0,TAMPROXMICRO); /* Depois ajeitar o tamanho da micro */
		proximaMicro = strbinToInt(pMicro);
		
		i = 0;
		pr1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr1(pr1);
		pr2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr2(pr2);
		pr3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr3(pr3);
		pr4 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr4(pr4);
		pr5 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr5(pr5);
		prX = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prX(prX);
		prY = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prY(prY);
		prDados = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prDados(prDados);
		ppc = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_ppc(ppc);
		pir = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pir(pir);
		prEnd = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prEnd(prEnd);
		pmem = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmem(pmem);
		palu1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu1(palu1);
		palu2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu2(palu2);
		palu3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu3(palu3);
		palu4 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu4(palu4);
		palu5 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu5(palu5);
		pmux_a1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_a1(pmux_a1);
		pmux_b1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b1(pmux_b1);
		pmux_b2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b2(pmux_b2);
		pmux_b3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b3(pmux_b3);
		pmux_c1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_c1(pmux_c1);
		pmux_c2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_c2(pmux_c2);
		pflags = micro.at(TAMPROXMICRO + i++) - '0';

		processa(proximaMicro);
		/* E o T3 */
		micro = micros.at(2);
		pMicro = micro.substr(0,TAMPROXMICRO); /* Depois ajeitar o tamanho da micro */
		proximaMicro = strbinToInt(pMicro);
		
		i = 0;
		pr1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr1(pr1);
		pr2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr2(pr2);
		pr3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr3(pr3);
		pr4 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr4(pr4);
		pr5 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pr5(pr5);
		prX = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prX(prX);
		prY = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prY(prY);
		prDados = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prDados(prDados);
		ppc = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_ppc(ppc);
		pir = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pir(pir);
		prEnd = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_prEnd(prEnd);
		pmem = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmem(pmem);
		palu1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu1(palu1);
		palu2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu2(palu2);
		palu3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu3(palu3);
		palu4 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu4(palu4);
		palu5 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_palu5(palu5);
		pmux_a1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_a1(pmux_a1);
		pmux_b1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b1(pmux_b1);
		pmux_b2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b2(pmux_b2);
		pmux_b3 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_b3(pmux_b3);
		pmux_c1 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_c1(pmux_c1);
		pmux_c2 = micro.at(TAMPROXMICRO + i++) - '0'; dialog->set_pmux_c2(pmux_c2);
		pflags = micro.at(TAMPROXMICRO + i++) - '0';

		processa(proximaMicro);
		
		microAtual = proximaMicro;
		
		if ( microAtual == 0 )
		{
			break;
		}
		if ( isMicroBreak )
		{
			return true;
		}
	}

	return false;
}

void uc::processa (int &proximaMicro)
{
	string temp;
	vector<short int *> tempV;

	temp = (pmux_a1)?'1':'0';
	tempV.push_back(&rmem); tempV.push_back(&sAlu);
	mux_a = mux(temp, tempV);
	tempV = vector<short int *>();

	if ( prDados )
	{
		rDados = mux_a; dialog->set_rDados(rDados);
	}
	if ( prX )
	{
		rX = sAlu; dialog->set_rX(rX);
	}
	if ( pr1 )
	{
		r1 = sAlu; dialog->set_r1(r1);
	}
	if ( pr2 )
	{
		r2 = sAlu; dialog->set_r2(r2);
	}
	if ( pr3 )
	{
		r3 = sAlu; dialog->set_r3(r3);
	}
	if ( pr4 )
	{
		r4 = sAlu; dialog->set_r4(r4);
	}
	if ( pr5 )
	{
		r5 = sAlu; dialog->set_r5(r5);
	}
	if ( prY )
	{
		rY = sAlu; dialog->set_rY(rY);
	}
	if ( ppc )
	{
		pc = sAlu; dialog->set_pc(pc);
	}
	if ( pir )
	{
		ir = sAlu; dialog->set_ir(ir);
	}
	if ( prEnd )
	{
		while ( rEnd < 0 )
		{
			rEnd += MAXMEM;
		}
		while ( rEnd > MAXMEM )
		{
			rEnd -= MAXMEM;
		}
		rEnd = sAlu; dialog->set_rEnd(rEnd);
	}

	temp = (pmux_b1)?'1':'0';
	temp += (pmux_b2)?'1':'0';
	temp += (pmux_b3)?'1':'0';
	tempV.push_back(&rDados); tempV.push_back(&rX); tempV.push_back(&r1); tempV.push_back(&r2); tempV.push_back(&pc);
	mux_b = mux(temp, tempV);
	tempV = vector<short int *>();

	temp = (pmux_c1)?'1':'0';
	temp += (pmux_c2)?'1':'0';
	tempV.push_back(&r3); tempV.push_back(&r4); tempV.push_back(&r5); tempV.push_back(&rY);
	mux_c = mux(temp, tempV);
	tempV = vector<short int *>();
	
	temp = (palu1)?'1':'0';
	temp += (palu2)?'1':'0';
	temp += (palu3)?'1':'0';
	temp += (palu4)?'1':'0';
	temp += (palu5)?'1':'0';
	
	sAlu = alu1.fazOp(mux_b, mux_c, strbinToInt(temp), pflags);

	if ( pmem )
		mem[rEnd] = rDados;
	else
		rmem = mem[rEnd];

	if ( pir )
	{
		/* Então uma nova instrução foi carregada */
		proximaMicro = ir;
		
		if ( ir == 1144 )
		{
			if ( alu1.zeroFlag )
				proximaMicro = 1141;
			else
				proximaMicro = 1144;
		}
		if ( ir == 1145 )
		{
			if ( alu1.negFlag )
				proximaMicro = 1141;
			else
				proximaMicro = 1144;
		}
		if ( ir == 1146 )
		{
			if ( alu1.equFlag )
				proximaMicro = 1141;
			else
				proximaMicro = 1144;
		}
		if ( ir == 1147 )
		{
			if ( alu1.menorFlag )
				proximaMicro = 1141;
			else
				proximaMicro = 1144;
		}
		if ( ir == 1148 )
		{
			if ( alu1.maiorFlag )
				proximaMicro = 1141;
			else
				proximaMicro = 1144;
		}
		if ( ir == 1149 )
		{
			if ( alu1.carryFlag )
				proximaMicro = 1141;
			else
				proximaMicro = 1144;
		}
		/* fazer alterações necessárias */
	}
}

short int uc::mux ( string bin, vector<short int *> res )
{
	unsigned int temp;
	temp = strbinToInt(bin);
	if ( temp > res.size() )
	{
		wxLogVerbose(_("Atenção: mux tentou acessar uma via vazia"));
//		cout << "Atenção: Mux tentou acessar uma via vazia" << endl;
		return 0;
	}
	return * res.at(temp);
}

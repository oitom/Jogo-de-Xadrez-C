#include <stdio.h>
#include <allegro.h>

int CHECK_MATE1 = 0;//VARIAVEL PARA O FIM DO JOGO
int CHECK_MATE2 = 0;//VARIAVEL PARA O FIM DO JOGO

int CHECK1 = 0;//VARIAVEL PARA CHECK
int CHECK2 = 0;//VARIAVEL PARA CHECK

int VEZ = -1;//PARA NUMEROS DE JOGADAS E A RODADA DOS JOGADORES

int TAB[8][8];//PARA CONTROLAR O TABULEIRO

int AX = 0, AY = 0;//CORDENADAS DA ESCOLHA
int BX = 0, BY = 0;//CORDENADAS DO DESTINO

int PX[64], PY[64];//CORDENADAS POSSIVEIS
int IPOSS = 0;//CONTADOR POSSIBILIDADES

int VA = 0, VB = 0;
int I=0;

void POSICIONA_MATRIZ()
{
	int X=0, Y=0;

	for(X = 0; X < 8; X++)//DISPOE PECAS NO TABULEIRO 
	{
		for(Y = 0; Y < 8; Y++)
		{
			TAB[X][Y] = 0;
			//DISPOSICAO PEOES
			if(Y == 1)
				TAB[X][Y] = 2;
			if(Y == 6)
				TAB[X][Y] = 1;
			//DISPOSICAO CAVALOS
			if((Y == 0 && X == 1)||(Y == 0 && X == 6))
				TAB[X][Y] = 4;
			if((Y == 7 && X == 1)||(Y == 7 && X == 6))
				TAB[X][Y] = 3;
			//DISPOSICAO TORRES
			if((Y == 7 && X == 7)||(Y == 7 && X == 0))
				TAB[X][Y] = 5;
			if((Y == 0 && X == 0)||(Y == 0 && X == 7))
				TAB[X][Y] = 6;
			//DISPOSICAO BISPOS
			if((Y == 7 && X == 2)||(Y == 7 && X == 5))
				TAB[X][Y] = 7;
			if((Y == 0 && X == 2)||(Y == 0 && X == 5))
				TAB[X][Y] = 8;
			//DISPOSICAO RAINHA
			if((Y == 7 && X == 3))
				TAB[X][Y] = 9;
			if((Y == 0 && X == 3))
				TAB[X][Y] = 10;
			//DIPOSICAO REI
			if((Y == 7 && X == 4))
				TAB[X][Y] = 11;
			if((Y == 0 && X == 4))
				TAB[X][Y] = 12;
		}
	}
}

void VOLTA()//PARA VOLTAR A JOGADA
{
    TAB[AX][AY] = VA;//VOLTANDO JOGADA
	TAB[BX][BY] = VB;//VONTANDO JOGADA
}


int PTROCA(int SX, int SY, int EX, int EY)//FUNÇÃO PARA TROCA DOS VALORES NO TABULEIRO
{   
	TAB[BX][BY] = TAB[AX][AY];
	TAB[AX][AY] = 0;
	return 0;
}


int possib(int MUDX, int MUDY, int PVEZ)//CALCULA A POSSIBILIDADE DENTRO DAS POSSIBILIDADES 
{
	if(TAB[AX+MUDX][AY+MUDY] == 0)//VERIFICA SE A CASA ESTA VAZIA
	{
		PX[IPOSS] = AX+MUDX;//ATRIBUI POSSIBILIDADE EM x
		PY[IPOSS] = AY+MUDY;//ATRIBUI POSSIBILIDADE EM Y	
		IPOSS++;//INCREMENTA A POSSIBILIDADE
		return 1;
	}
	else
	{
		if(TAB[AX+MUDX][AY+MUDY] != 0 && TAB[AX+MUDX][AY+MUDY] % 2 != PVEZ)//VERIFICA SE OCUPADA E SE OCUPADA SE NÃO É DA MESMA COR
		{	
			PX[IPOSS] = AX+MUDX;//ATRIBUI POSSIBILIDADE EM x
			PY[IPOSS] = AY+MUDY;//ATRIBUI POSSIBILIDADE EM Y	
			IPOSS++;//INCREMENTA A POSSIBILIDADE
		}		
		return 0;
	}
}


int PEAO()//CARACTERISTICAS DE POSSIBILIDADES DO PEAO
{
	if(TAB[AX][AY] % 2 == 0)// VERIFICA SA COR
	{
		if(TAB[AX][AY+1] == 0)//VERIFICA SE A CASA A FRENTE ESTA VAZIA
		{
			possib(0,+1,1);
		}
		if(TAB[AX][AY+2] == 0)//VERIFICA SE A CASA A FRENTE ESTA VAZIA
		{
			if(AY == 1)
			{
				possib(0,+2,1);//CASO SEJA O PRIMEIRO MOVIMENTO
			}
		}
		if(TAB[AX+1][AY+1] != 0 && TAB[AX+1][AY+1] % 2 == 1)//VERIFICA SE UM INIMIGO ESTA AO LADO DIAGONAL ESQUERDA
		{
			possib(1,1,0);
		}
		if(TAB[AX-1][AY+1] != 0 && TAB[AX-1][AY+1] % 2 == 1)//VERIFICA SE UM INIMIGO ESTA AO LADO DIAGONAL DIREITA
		{
			possib(-1,1,0);
		}
	}
	else
	{
		if(TAB[AX][AY-1] == 0)//VERIFICA SE A CASA A FRENTE ESTA VAZIA
		{
			possib(0,-1,1);
		}
		if(TAB[AX][AY-2] == 0)//VERIFICA SE A CASA A FRENTE ESTA VAZIA
		{
			if(AY == 6)
			{
				possib(0,-2,1);//CASO SEJA O PRIMEIRO MOVIMENTO
			}
		}
		if(TAB[AX+1][AY-1] != 0 && TAB[AX+1][AY-1] % 2 == 0)//VERIFICA SE UM INIMIGO ESTA AO LADO DIAGONAL ESQUERDA
		{
			possib(1,-1,1);
		}
		if(TAB[AX-1][AY-1] != 0 && TAB[AX-1][AY-1] % 2 == 0)//VERIFICA SE UM INIMIGO ESTA AO LADO DIAGONAL DIREITA
		{
			possib(-1,-1,1);
		}
	}
	return 0;
}


int CAVALO()
{
	if(TAB[AX][AY] % 2 == 0)// VERIFICA SA COR
	{
		//possib E UM PROSSIDIMETO PRIMEIO ENVIO X, DEPOIS Y, A COR
		possib(2,1,0);//POSSIBILIDADE SEMPRE TESTADA
		possib(2,-1,0);//POSSIBILIDADE SEMPRE TESTADA
		possib(-2,1,0);//POSSIBILIDADE SEMPRE TESTADA
		possib(-2,-1,0);//POSSIBILIDADE SEMPRE TESTADA
		
		possib(1,2,0);//POSSIBILIDADE SEMPRE TESTADA
		possib(1,-2,0);//POSSIBILIDADE SEMPRE TESTADA
		possib(-1,2,0);//POSSIBILIDADE SEMPRE TESTADA
		possib(-1,-2,0);//POSSIBILIDADE SEMPRE TESTADA
	}
	else
	{
		possib(2,1,1);//POSSIBILIDADE SEMPRE TESTADA
		possib(2,-1,1);//POSSIBILIDADE SEMPRE TESTADA
		possib(-2,1,1);//POSSIBILIDADE SEMPRE TESTADA
		possib(-2,-1,1);//POSSIBILIDADE SEMPRE TESTADA
		
		possib(1,2,1);//POSSIBILIDADE SEMPRE TESTADA
		possib(1,-2,1);//POSSIBILIDADE SEMPRE TESTADA
		possib(-1,2,1);//POSSIBILIDADE SEMPRE TESTADA
		possib(-1,-2,1);//POSSIBILIDADE SEMPRE TESTADA
	}
	return 0;
}


int TORRE()//POSSIBILIDADE DE MOVIMENTO DA TORRE
{
	if(TAB[AX][AY] % 2 == 0)// VERIFICA SA COR
	{
		for(I = 1; I < 8; I++)
		{
		    if(possib(0,I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(0,-I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,0,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,0,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		
	}
	else
	{
		for(I = 1; I < 8; I++)
		{
		    if(possib(0,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(0,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,0,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,0,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
	}
	return 0;
}


int BISPO()
{
	if(TAB[AX][AY] % 2 == 0)// VERIFICA SA COR
	{	
		for(I = 1; I < 8; I++)
		{
		    if(possib(I,I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,-I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,-I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
	}
	else
	{
		for(I = 1; I < 8; I++)
		{
		    if(possib(I,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
		    if(possib(0,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(0,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I= 1; I < 8; I++)
		{
			if(possib(I,0,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,0,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
	}
	return 0;
}


int RAINHA()
{

	if(TAB[AX][AY] % 2 == 0)// VERIFICA SA COR
	{
		for(I = 1; I < 8; I++)
		{
		    if(possib(0,I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(0,-I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,0,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,0,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}	
		for(I = 1; I < 8; I++)
		{
		    if(possib(I,I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,-I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,-I,0) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
	}
	else
	{
		for(I = 1; I < 8; I++)
		{
		    if(possib(I,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}		
		for(I = 1; I < 8; I++)
		{
		    if(possib(I,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
		    if(possib(0,I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(0,-I,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(I,0,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
		for(I = 1; I < 8; I++)
		{
			if(possib(-I,0,1) == 0)//POSSIBILIDADE SEMPRE
				I = 9;
		}
	}
	return 0;
}


int REI()
{
	if(TAB[AX][AY] % 2 == 0)// VERIFICA SA COR
	{
		//VERIFICANDO AS POSSIBILIDADES DO REI
		possib(-1,0,0);
		possib(1,0,0);
		possib(0,-1,0);
		possib(0,1,0);
		possib(-1,-1,0);
		possib(1,1,0);
		possib(1,-1,0);
		possib(-1,1,0);
		if(AY == 0 && AX == 4 && TAB[AX + 1][AY] == 0 && TAB[AX + 2][AY] == 0 && TAB[AX + 3][AY] == 6)
		{
			possib(2,0,0);
		}
	}
	else
	{
		//VERIFICANDO AS POSSIBILIDADES DO REI
		possib(-1,0,1);
		possib(1,0,1);
		possib(0,-1,1);
		possib(0,1,1);
		possib(-1,-1,1);
		possib(1,1,1);
		possib(1,-1,1);
		possib(-1,1,1);
		if(AY == 7 && AX == 4 && TAB[AX + 1][AY] == 0 && TAB[AX + 2][AY] == 0 && TAB[AX + 3][AY] == 6)
		{
			possib(2,0,0);
		}
	}
	return 0;
}


int POSSIVEL(int X, int Y)
{
	for(I = 0; I < 64; I++)//AS POSSIBILIDADE DO PARAMETRO
	{
		if(X == PX[I] && Y == PY[I])
			return 1;
	}
	return 0;
}


int CORDENADAS_PECA(int X, int Y)//CHAMA PARA CRIAR AS POSSIVEIS JOGADAS
{
	if(TAB[X][Y] == 1 || TAB[X][Y] == 2)
		PEAO();//CHAMA POSSIAILIDADES DE PEAO
	if(TAB[X][Y] == 3 || TAB[X][Y] == 4)
		CAVALO();//CHAMA POSSIAILIDADES DE CAVALO
	if(TAB[X][Y] == 5 || TAB[X][Y] == 6)
		TORRE();//CHAMA POSSIAILIDADES DE TORRE
	if(TAB[X][Y] == 7 || TAB[X][Y] == 8)
		BISPO();//CHAMA POSSIAILIDADES DE AISPO
	if(TAB[X][Y] == 9 || TAB[X][Y] == 10)
		RAINHA();//CHAMA POSSIAILIDADES DE RAINHA
	if(TAB[X][Y] == 11|| TAB[X][Y] == 12)
		REI();//CHAMA POSSIAILIDADES DE REI
	return 0;
}

char D(int NUM)
{
	if(NUM == 0)
		return '.';
	if(NUM == 1)
		return '*';
	if(NUM == 2)
		return 'P';
	if(NUM == 3)
		return '$';
	if(NUM == 4)
		return 'H';
	if(NUM == 5)
		return '#';
	if(NUM == 6)
		return 'T';
	if(NUM == 7)
		return '+';
	if(NUM == 8)
		return 'B';
	if(NUM == 9)
		return '%';
	if(NUM == 10)
		return 'Q';
	if(NUM == 11)
		return '@';
	if(NUM == 12)
		return 'R';
	else 
		return ' ';
}


void ESVAZIA_POSS()
{
	for(I = 0; I < 64; I++)//ZERAR POSSIBILIDADES
	{
		PX[I] = -1;//ATRIBUINDO A POSSIBILIDADE NULA EM X
		PY[I] = -1;//ATRIBUINDO A POSSIBILIDADE NULA EM Y
		IPOSS = 0;//VOLTA INDICE DE POSSIBILIDADES
	}
}

int VER_CHECK(int PX, int PY, int P)
{
	int X = 0, Y=0;

	for(X = 0; X < 8; X++)//VERIFICA POSSIBILIDADES PECAS DO JOGADOR NO TABULEIRO 
	{
		for(Y = 0; Y < 8; Y++)
		{
			if(TAB[X][Y] % 2 == P && TAB[X][Y] != 0)
			{
				AX = X; AY = Y;
				CORDENADAS_PECA(X, Y);
				if(POSSIVEL(PX, PY) == 1)
				{
					ESVAZIA_POSS();
					return 1;
				}
				ESVAZIA_POSS();
			}
		}
	}
	return 0;
}

int CHECK()
{
	int AAX = 0, AAY = 0;
	int R1X = -1, R1Y = -1;
	int R2X = -1, R2Y = -1;
	int X = 0, Y = 0;
	
	for(X = 0; X < 8; X++)//ENCONTRANDO REI DO JOGADOR DA RODADA
	{
		for(Y = 0; Y < 8; Y++)
		{
			if(TAB[X][Y] == 12)
			{
				R2X = X;
				R2Y = Y;
			}
			if(TAB[X][Y] == 11)
			{
				R1X = X;
				R1Y = Y;
			}
		}
	}
	AAX = AX; AAY = AY;

	CHECK2 = VER_CHECK(R1X, R1Y, 0);
	CHECK1 = VER_CHECK(R2X, R2Y, 1);

	AX = AAX; AY = AAY;
	return 0;//NAO ENCONTRADO AMEAÇA SAI AFIRMANDO
}

int CHEQUE_MATE(int P)
{
	int AAX = 0, AAY = 0;
	int I = 0, X =0, Y = 0;
	
	for(X = 0; X < 8; X++)//VERIFICA POSSIBILIDADES PECAS DO JOGADOR NO TABULEIRO 
	{
		for(Y = 0; Y < 8; Y++)
		{
			if(TAB[X][Y] % 2 == P && TAB[X][Y] != 0)
			{
				AX = X; AY = Y;
				CORDENADAS_PECA(X, Y);
				do
				{
					I++;
					PTROCA(X, Y, PX[I],PY[I]);
					if(CHECK() == 1)
					{
						//printf("CHECK MATE");
						AX = AAX; AY = AAY;
						return 0;
					}
					VOLTA();
				}while(PX[I] != -1);
				I = 0;
				ESVAZIA_POSS();
			}
		}
	}
	AX = AAX; AY = AAY;
	
	
	return 1;
}

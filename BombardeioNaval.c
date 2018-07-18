#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct rank 
{
	int pontos;
	char nome[5];
}ranking;

void limpaTela() /*Funciona para limpar a tela do terminal*/
{
#ifdef __WIN32__
system("CLS");
#else
    system("clear");
#endif
};

void tabuleiro_5(int tabuleiro[5][5])  /*essa funcao inicia todos os elementos do tabuleiro 5x5 com 0*/
{
	int i, a;
	for(i=0;i<5;i++)
	{
		for(a=0;a<5;a++)
		{
			tabuleiro[i][a] = 0;
		}
	}
}

void tabuleiro_7(int tabuleiro[7][7]) /*essa funcao inicia todos os elementos do tabuleiro 7x7 com 0*/
{
	int i, a;
	for(i=0;i<7;i++)
	{
		for(a=0;a<7;a++)
		{
			tabuleiro[i][a] = 0;
		}
	}
}

void tabuleiro_9(int tabuleiro[9][9]) /*essa funcao inicia todos os elementos do tabuleiro 7x7 com 0*/
{
	int i, a;
	for(i=0;i<9;i++)
	{
		for(a=0;a<9;a++)
		{
			tabuleiro[i][a] = 0;
		}
	}
}

void rand_5(int tabuleiro[5][5])/*essa funcao utiliza da funcao random para determinar aonde os barcos ficaram alocados no tabuleiro 5x5*/
{
	srand(time(NULL));
	int navio_1[2], navio_2[2], navio_3[2], navio_4[2],i,a;
	navio_4[0] = rand()%5;
	navio_4[1] = rand()%2;
	for(i=navio_4[1],a=0;a<4;i++,a++)
	{
		tabuleiro[navio_4[0]][i] = 1;
	}
	do
	{
		navio_3[0] = rand()%5;
	}while(navio_3[0]==navio_4[0]);
	navio_3[1] = rand()%3;
	for(i=navio_3[1],a=0;a<3;i++,a++)
	{
		tabuleiro[navio_3[0]][i] = 1;
	}
	do
	{
		navio_2[0] = rand()%5;
	}while(navio_2[0]==navio_4[0] || navio_2[0]==navio_3[0]);
	navio_2[1] = rand()%4;
	for(i=navio_2[1],a=0;a<2;i++,a++)
	{
		tabuleiro[navio_2[0]][i] = 1;
	}
	do
	{
		navio_1[0] = rand()%5;
		navio_1[1] = rand()%5;
	}while(tabuleiro[navio_1[0]][navio_1[1]] != 0);
	tabuleiro[navio_1[0]][navio_1[1]] = 1;
}

void rand_7(int tabuleiro[7][7])/*essa funcao utiliza da funcao random para determinar aonde os barcos ficaram alocados no tabuleiro 7x7*/
{
	srand(time(NULL));
	int navio_1[2], navio_2[2],navio_2b[2], navio_3[2], navio_4[2],i,a;
	navio_4[0] = rand()%7;
	navio_4[1] = rand()%4;
	for(i=navio_4[1],a=0;a<4;i++,a++)
	{
		tabuleiro[navio_4[0]][i] = 1;
	}
	do
	{
		navio_3[0] = rand()%7;
	}while(navio_3[0]==navio_4[0]);
	navio_3[1] = rand()%5;
	for(i=navio_3[1],a=0;a<3;i++,a++)
	{
		tabuleiro[navio_3[0]][i] = 1;
	}
	do
	{
		navio_2[0] = rand()%7;
	}while(navio_2[0]==navio_4[0] || navio_2[0]==navio_3[0]);
	navio_2[1] = rand()%6;
	for(i=navio_2[1],a=0;a<2;i++,a++)
	{
		tabuleiro[navio_2[0]][i] = 1;
	}
	do
	{
		navio_2b[0] = rand()%7;
	}while(navio_2b[0]==navio_4[0] || navio_2b[0]==navio_3[0] || navio_2b[0]==navio_2[0]);
	navio_2b[1] = rand()%6;
	for(i=navio_2b[1],a=0;a<2;i++,a++)
	{
		tabuleiro[navio_2b[0]][i] = 1;
	}
	do
	{
		navio_1[0] = rand()%7;
		navio_1[1] = rand()%7;
	}while(tabuleiro[navio_1[0]][navio_1[1]] != 0);
	tabuleiro[navio_1[0]][navio_1[1]] = 1;
	do
	{
		navio_1[0] = rand()%7;
		navio_1[1] = rand()%7;
	}while(tabuleiro[navio_1[0]][navio_1[1]] != 0);
	tabuleiro[navio_1[0]][navio_1[1]] = 1;
	do
	{
		navio_1[0] = rand()%7;
		navio_1[1] = rand()%7;
	}while(tabuleiro[navio_1[0]][navio_1[1]] != 0);
	tabuleiro[navio_1[0]][navio_1[1]] = 1;
}

void rand_9(int tabuleiro[9][9])/*essa funcao utiliza da funcao random para determinar aonde os barcos ficaram alocados no tabuleiro 9x9*/
{
	srand(time(NULL));
	int navio_1[2], navio_1b[2], navio_1c[2], navio_1d[2], navio_2[2], navio_3[2], navio_3b[2], navio_4[2], navio_4b[2], navio_5[2],i,a;
	navio_5[0] = rand()%9;
	navio_5[1] = rand()%3;
	for(i=navio_5[1],a=0;a<5;a++,i++)
	{
		tabuleiro[navio_5[0]][i] = 1;
	}
	do
	{
	navio_4[0] = rand()%9;
	navio_4[1] = rand()%4;
	}while(navio_4[0]==navio_5[0]);
	for(i=navio_4[1],a=0;a<4;a++,i++)
	{
		tabuleiro[navio_4[0]][i] = 1;
	}
	do
	{
	navio_4b[0] = rand()%9;
	navio_4b[1] = rand()%4;
	}while(navio_4b[0]==navio_5[0] || navio_4b[0] == navio_4[0]);
	for(i=navio_4b[1],a=0;a<4;a++,i++)
	{
		tabuleiro[navio_4b[0]][i] = 1;
	}

	do
	{
		navio_3[0] = rand()%9;
	}while(navio_3[0]==navio_4[0] || navio_3[0]==navio_4b[0] || navio_3[0]==navio_5[0]);
	navio_3[1] = rand()%7;
	for(i=navio_3[1],a=0;a<3;a++,i++)
	{
		tabuleiro[navio_3[0]][i] = 1;
	}

	do
	{
		navio_3b[0] = rand()%9;
	}while(navio_3b[0]==navio_4[0] || navio_3b[0]==navio_4b[0] || navio_3b[0]==navio_5[0] || navio_3b[0]==navio_3[0]);
	navio_3b[1] = rand()%7;
	for(i=navio_3[1],a=0;a<3;a++,i++)
	{
		tabuleiro[navio_3b[0]][i] = 1;
	}

	do
	{
		navio_2[0] = rand()%9;
	}while(navio_2[0]==navio_4[0] || navio_2[0]==navio_3[0] || navio_2[0]==navio_3b[0] || navio_2[0]==navio_4b[0] || navio_2[0]==navio_5[0]);
	navio_2[1] = rand()%8;
	for(i=navio_2[1],a=0;a<2;i++,a++)
	{
		tabuleiro[navio_2[0]][i] = 1;
	}
	do
	{
		navio_1[0] = rand()%9;
		navio_1[1] = rand()%9;
	}while(tabuleiro[navio_1[0]][navio_1[1]] != 0);
	tabuleiro[navio_1[0]][navio_1[1]] = 1;

	do
	{
		navio_1b[0] = rand()%9;
		navio_1b[1] = rand()%9;
	}while(tabuleiro[navio_1b[0]][navio_1b[1]] != 0);
	tabuleiro[navio_1b[0]][navio_1b[1]] = 1;

	do
	{
		navio_1c[0] = rand()%9;
		navio_1c[1] = rand()%9;
	}while(tabuleiro[navio_1c[0]][navio_1c[1]] != 0);
	tabuleiro[navio_1c[0]][navio_1c[1]] = 1;


	do
	{
		navio_1d[0] = rand()%9;
		navio_1d[1] = rand()%9;
	}while(tabuleiro[navio_1d[0]][navio_1d[1]] != 0);
	tabuleiro[navio_1d[0]][navio_1d[1]] = 1;

	}

void mostrar_5(int tabuleiro[5][5]) /*Essa funcao mostra na tela o tabuleiro 5x5 que sera visto pelo usuario durante o jogo*/
{
	int a, i;
	for(a=-1;a<5;a++)
	{
		if(a!=-1)
		{
			printf("%d+ ", a+1);
		}
		for(i=0;i<5;i++)
		{
			if(a==-1)
			{
				printf("   1 2 3 4 5\n   + + + + +");
				break;
			}
			if(tabuleiro[a][i]==1 || tabuleiro[a][i] == 0)
			{
				printf("~ ");
			}
			else if(tabuleiro[a][i]==-1)
			{
				printf("= ");
			}
			else if(tabuleiro[a][i]==-2)
			{
				printf("X ");
			}
		}
		printf("\n");
	}
}

void mostrar_7(int tabuleiro[7][7]) /*Essa funcao mostra na tela o tabuleiro 7x7 que sera visto pelo usuario durante o jogo*/
{
	int a, i;
	for(a=-1;a<7;a++)
	{
		if(a!=-1)
		{
			printf("%d+ ", a+1);
		}
		for(i=0;i<7;i++)
		{
			if(a==-1)
			{
				printf("   1 2 3 4 5 6 7\n   + + + + + + + ");
				break;
			}
			if(tabuleiro[a][i]==1 || tabuleiro[a][i] == 0)
			{
				printf("~ ");
			}
			else if(tabuleiro[a][i]==-1)
			{
				printf("= ");
			}
			else if(tabuleiro[a][i]==-2)
			{
				printf("X ");
			}
		}
		printf("\n");
	}
}

void mostrar_9(int tabuleiro[9][9]) /*Essa funcao mostra na tela o tabuleiro 9x9 que sera visto pelo usuario durante o jogo*/
{
	int a, i;
	for(a=-1;a<9;a++)
	{
		if(a!=-1)
		{
			printf("%d+ ", a+1);
		}
		for(i=0;i<9;i++)
		{
			if(a==-1)
			{
				printf("   1 2 3 4 5 6 7 8 9\n   + + + + + + + + + ");
				break;
			}
			if(tabuleiro[a][i]==1 || tabuleiro[a][i] == 0)
			{
				printf("~ ");
			}
			else if(tabuleiro[a][i]==-1)
			{
				printf("= ");
			}
			else if(tabuleiro[a][i]==-2)
			{
				printf("X ");
			}
		}
		printf("\n");
	}
}

int tiro_linha(int tam) /*essa funcao eh resposavel por ler a linha em que o jogador deseja realizar a jogada e retorna o valor da mesma menos 1*/
{
	int linha;
	printf("Digite a linha do tiro: ");
	scanf("%d", &linha);
	if(linha<1 || linha>tam)
	{
		while(linha<1 || linha>tam)
		{
			printf("Linha invalida digite novamente: ");
			scanf("%d", &linha);
		}
	}
	return linha-1;
}

int tiro_coluna(int tam) /*essa funcao eh resposavel por ler a coluna em que o jogador deseja realizar a jogada e retorna o valor da mesma menos 1*/
{
	int coluna;
	printf("Digite a coluna do tiro: ");
	scanf("%d", &coluna);
	if(coluna<1 || coluna>tam)
	{
		while(coluna<1 || coluna>tam)
		{
			printf("Coluna invalida digite novamente: ");
			scanf("%d", &coluna);
		}
	}
	limpaTela();
	return coluna-1;
}

void quantidade_barco5(int linha, int coluna, int tabuleiro[5][5])/*essa funcao calcula e exibe na tela quantos barcos existem  na coluna e na linha em que o jogador fez sua jogada no tabuleiro5x5*/
{
	int a, barcos_linha=0, barcos_coluna=0;
	for(a=0;a<5;a++)
	{
		if(tabuleiro[linha][a]==1)
		{
			barcos_linha++;
		}
	}
	printf("Existem mais %d barco(s) nessa linha\n\n", barcos_linha);
	for(a=0;a<5;a++)
	{
		if(tabuleiro[a][coluna]==1)
		{
			barcos_coluna++;
		}
	}
	printf("Existem mais %d barco(s) nessa coluna\n\n", barcos_coluna);

}

void quantidade_barco7(int linha, int coluna, int tabuleiro[7][7])/*essa funcao calcula e exibe na tela quantos barcos existem  na coluna e na linha em que o jogador fez sua jogada no tabuleiro7x7*/
{
	int a, barcos_linha=0, barcos_coluna=0;
	for(a=0;a<7;a++)
	{
		if(tabuleiro[linha][a]==1)
		{
			barcos_linha++;
		}
	}
	printf("Existem mais %d barco(s) nessa linha\n\n", barcos_linha);
	for(a=0;a<7;a++)
	{
		if(tabuleiro[a][coluna]==1)
		{
			barcos_coluna++;
		}
	}
	printf("Existem mais %d barco(s) nessa coluna\n\n", barcos_coluna);

}

void quantidade_barco9(int linha, int coluna, int tabuleiro[9][9])/*essa funcao calcula e exibe na tela quantos barcos existem  na coluna e na linha em que o jogador fez sua jogada no tabuleiro9x9*/
{
	int a, barcos_linha=0, barcos_coluna=0;
	for(a=0;a<9;a++)
	{
		if(tabuleiro[linha][a]==1)
		{
			barcos_linha++;
		}
	}
	printf("Existem mais %d barco(s) nessa linha\n\n", barcos_linha);
	for(a=0;a<9;a++)
	{
		if(tabuleiro[a][coluna]==1)
		{
			barcos_coluna++;
		}
	}
	printf("Existem mais %d barco(s) nessa coluna\n\n", barcos_coluna);

}

void iniciar_rank(char arquivo[11]) /*inicia todos os ranks com 0, caso nao exisitisse um ranking posteriormente*/
{
	FILE *placar;
	ranking rank_r[3];
	int i;
	placar = fopen(arquivo, "wb");
	for(i=0;i<3;i++)
	{
		strcpy(rank_r[i].nome, "vaz");
		rank_r[i].pontos = 0;
	}
	fwrite(&rank_r, sizeof(rank_r), 1, placar);
	rewind(placar);
	fclose(placar);
}

void gravar_rank(int pontos, int qual, char arquivo[11]) /*registra a pontuacao do jogador caso esteja entre uma das 3 maiores*/
{
	FILE *placar;
	ranking rank_r[3];
	placar = fopen(arquivo, "r+b");
	fread(&rank_r, sizeof(rank_r), 1, placar);
	if(qual==0)	
	{
		rewind(placar);
		rank_r[2].pontos = rank_r[1].pontos;
		rank_r[1].pontos = rank_r[0].pontos;
		strcpy(rank_r[2].nome, rank_r[1].nome);
		strcpy(rank_r[1].nome, rank_r[0].nome);
		printf("Parabens voce esta entre as 3 melhores pontuacoes!\n\n");
		printf("Digite seu nickname com ate 3 letras\n");
		scanf("%s", rank_r[0].nome);
		limpaTela();
		rank_r[0].pontos = pontos;
		
		
	}
	else if (qual == 1)
	{
		rank_r[2].pontos = rank_r[1].pontos;
		strcpy(rank_r[2].nome, rank_r[1].nome);
		printf("Parabens voce esta entre as 3 melhores pontuacoes!\n\n");
		printf("Digite seu nickname com ate 3 letras\n");
		scanf("%s", rank_r[1].nome);
		limpaTela();
		rank_r[1].pontos = pontos;
	}
	else if (qual ==2)
	{
		printf("Parabens voce esta entre as 3 melhores pontuacoes!\n\n");
		printf("Digite seu nickname com ate 3 letras\n");
		scanf("%s", rank_r[2].nome);
		limpaTela();
		rank_r[2].pontos = pontos;
	}
	rewind(placar);
	fwrite(&rank_r, sizeof(rank_r), 1, placar);
	fclose(placar);
	
}

int checar_rank(int pontos, char arquivo[11]) /*checa se a pontuacao do jogador esta entre as 3 maiores e caso esteja grava a mesma no ranking*/
{
	FILE *placar;
	int i;
	ranking rank_r[3];
	placar = fopen(arquivo, "r+b");
	if(placar==NULL)
	{
		rewind(placar);
		fclose(placar);
		iniciar_rank(arquivo);
		gravar_rank(pontos, 0, arquivo);
		return 1;
	}
	fread(&rank_r, sizeof(rank_r), 1, placar);
	fclose(placar);
	for(i=0;i<3;i++)
	{
		if((rank_r[i].pontos)<(pontos))
		{
			gravar_rank(pontos, i, arquivo);
			return 1;
		}
	}
	return 0;
}

void ver_rank(char arquivo[11])/*funcao que exibe as top 3 pontuacoes do jogo, a qual corresponde ao item 4 do menu*/
{
	FILE *placar;
	ranking rank_r[3];
	int i;
	placar = fopen(arquivo, "rb");
	if(placar ==NULL)
	{
		printf("Ainda nao ha melhores placares registrados\n");
	}
	else
	{
		rewind(placar);
		fread(&rank_r, sizeof(rank_r), 1, placar);
		for(i=0;i<3;i++)
		{
			if(rank_r[i].pontos!=0)
			{
				printf("TOP %d: -%s- com %d pontos!\n\n", i+1, rank_r[i].nome, rank_r[i].pontos);
			}
		}
	}
	
}

int jogo_5(int tabuleiro[5][5]) /*Essa funcao eh resposavel pelo jogo em si, pois reune todas as outras acima para formar o jogo no modo 5x5*/
{
	int verificador, linha, coluna, pontos=0, multiplicador = 1; /*b, c; //variaveis para orientação do gabarito do tabuleiro*/
	tabuleiro_5(tabuleiro);
	rand_5(tabuleiro);
	for(verificador=10;verificador>0;)
	{
		/*for(b=0;b<5;b++)
		{
			for(c=0;c<5;c++)
			{
				printf("%d ", tabuleiro[b][c]);
			}
			printf("\n");
		} //GABARITO DO JOGO - mostra o tabuleiro com as posições dos navios, onde 1 é navio, 0 é agua, -2 é tiro errado e -1 tiro certo*/
		mostrar_5(tabuleiro);
		linha = tiro_linha(5);
		coluna = tiro_coluna(5);
		if(tabuleiro[linha][coluna]==1)
		{
			printf("\nVoce acertou!\n\n");
			verificador--;
			tabuleiro[linha][coluna] = -1;
			pontos = pontos + 10*multiplicador;
			multiplicador++;
			if(verificador>0)
			{
				quantidade_barco5(linha, coluna, tabuleiro);
			}
		}
		else if(tabuleiro[linha][coluna]==0)
		{
			printf("\nVoce errou!\n\n");
			tabuleiro[linha][coluna] = -2;
			multiplicador=1;
		}
		else
		{
			printf("\nCoordenadas ja escolhidas, tente novamente\n");
			continue;
		}
	}
	printf("PARABENS! VOCE FEZ %d PONTOS\n\n", pontos);
	checar_rank(pontos, "placa5.bin");
	return pontos;
}

int jogo_7(int tabuleiro[7][7]) /*Essa funcao eh resposavel pelo jogo em si, pois reune todas as outras acima para formar o jogo no modo 7x7*/
{
	int verificador, linha, coluna, pontos=0, multiplicador = 1;/* b, c; //variaveis para orientação do gabarito do tabuleiro*/
	tabuleiro_7(tabuleiro);
	rand_7(tabuleiro);
	for(verificador=14;verificador>0;)
	{
		/*for(b=0;b<7;b++)
		{
			for(c=0;c<7;c++)
			{
				printf("%d ", tabuleiro[b][c]);
			}
			printf("\n");
		} //GABARITO DO JOGO - mostra o tabuleiro com as posições dos navios, onde 1 é navio, 0 é agua, -2 é tiro errado e -1 tiro certo*/
		mostrar_7(tabuleiro);
		linha = tiro_linha(7);
		coluna = tiro_coluna(7);
		if(tabuleiro[linha][coluna]==1)
		{
			printf("\nVoce acertou!\n");
			verificador--;
			tabuleiro[linha][coluna] = -1;
			pontos = pontos + 10*multiplicador;
			multiplicador++;
			if(verificador>0)
			{
				quantidade_barco7(linha, coluna, tabuleiro);
			}
		}
		else if(tabuleiro[linha][coluna]==0)
		{
			printf("\nVoce errou!\n");
			tabuleiro[linha][coluna] = -2;
			multiplicador=1;
		}
		else
		{
			printf("\nCoordenadas ja escolhidas, tente novamente\n");
			continue;
		}
	}
	printf("PARABENS! VOCE FEZ %d PONTOS\n\n", pontos);
	checar_rank(pontos, "placa7.bin");
	return pontos;
}

int jogo_9(int tabuleiro[9][9]) /*Essa funcao eh resposavel pelo jogo em si, pois reune todas as outras acima para formar o jogo no modo 9x9*/
{
	int verificador, linha, coluna, pontos=0, multiplicador = 1;/*  b, c; //variaveis para orientação do gabarito do tabuleiro*/
	tabuleiro_9(tabuleiro);
	rand_9(tabuleiro);
	for(verificador=25;verificador>0;)
	{
		/*for(b=0;b<9;b++)
		{
			for(c=0;c<9;c++)
			{
				printf("%d ", tabuleiro[b][c]);
			}
			printf("\n");
		} //GABARITO DO JOGO - mostra o tabuleiro com as posições dos navios, onde 1 é navio, 0 é agua, -2 é tiro errado e -1 tiro certo*/
		mostrar_9(tabuleiro);
		linha = tiro_linha(9);
		coluna = tiro_coluna(9);
		if(tabuleiro[linha][coluna]==1)
		{
			printf("\nVoce acertou!\n");
			verificador--;
			tabuleiro[linha][coluna] = -1;
			pontos = pontos + 10*multiplicador;
			multiplicador++;
			if(verificador>0)
			{
				quantidade_barco9(linha, coluna, tabuleiro);
			}
		}
		else if(tabuleiro[linha][coluna]==0)
		{
			printf("\nVoce errou!\n");
			tabuleiro[linha][coluna] = -2;
			multiplicador=1;
		}
		else
		{
			printf("\nCoordenadas ja escolhidas, tente novamente\n");
			continue;
		}
	}
	printf("PARABENS! VOCE FEZ %d PONTOS\n\n", pontos);
	checar_rank(pontos, "placa9.bin");
	return pontos;
}

void menu() /*orienta o programa em si*/
{

	int tabuleiro5[5][5], tabuleiro7[7][7], tabuleiro9[9][9], a, rk;
	int resp;
	int opcao;

	printf("\n--------Bem Vindo ao Bombardeio Naval--------\n");
	printf("Digite:\n1 - Jogar\n2 - Como Jogar\n3 - Placar de Lideres\n4 - Creditos\n5 - Encerrar\n\n");
	scanf("%d", &opcao);
	limpaTela();
	
	switch(opcao)
	{
	case 1:
		printf("Selecione a dificuldade(5,7,9):\n");
		scanf("%d", &a);

		if((a != 5) && (a != 7) && (a != 9))
		{
			while((a != 5) && (a != 7) && (a != 9))
			{
				printf("Selecione a dificuldade(5,7,9):\n");
				scanf("%d", &a);
			}
		}

		if(a == 5)
		{
			jogo_5(tabuleiro5);
		}else if(a == 7)
		{
			jogo_7(tabuleiro7);
		}else if(a == 9)
		{
			jogo_9(tabuleiro9);
		}

		printf("Deseja Jogar Novamente?(1 - Sim/0 - Nao)\n");
		scanf("%d", &resp);
		limpaTela();
		while(resp ==1)
		{
			if(resp == 1)
			{
				printf("Selecione a dificuldade(5,7,9):\n");
				scanf("%d", &a);

				if((a != 5) && (a != 7) && (a != 9))
				{
					while((a != 5) && (a != 7) && (a != 9))
					{
						printf("Selecione a dificuldade(5,7,9):\n");
						scanf("%d", &a);
					}
				}

				if(a == 5)
				{
					jogo_5(tabuleiro5);
				}else if(a == 7)
				{
					jogo_7(tabuleiro7);
				}else if(a == 9)
				{
					jogo_9(tabuleiro9);
				}
			}else if(resp == 0)
			{
				menu();
			}else
			{
				printf("Valor invalido\n");
				menu();
			}
			printf("Deseja Jogar Novamente?(1 - Sim/0 - Nao)\n");
			scanf("%d", &resp);
			limpaTela();
		}

		if(resp != 1)
		{
			menu();
		}


	break;

	case 2:
		printf("\nExistem tres tipos de tabuleiros, que correspodem a 3 tipos de dificuldade, facil, mediano e dificil.\n");
		printf("Na dificuldade facil e um tabuleiro 5x5.\nNa mediana um tabuleiro 7x7.\nE na dificil um tabuleiro 9x9.\n");
		printf("Ao inciar uma partida voce devera escolher o nivel de dificuldade digitando uma das 3 entradas(5,7,9).\n");
		printf("Depois voce seleciona as coordenadas em que deseja realizar o tiro.\n");
		printf("Em caso de acerto, recebera dicas de onde estao outros barcos.\n");
		printf("Em caso de acerto o \"~\" que representa a agua no tabuleiro trocara por um \"=\" e em caso de erro por um \"X\".\n");
		printf("O jogo encerra apos o acerto de todos os barcos.\n\n");
		printf("Digite um inteiro qualquer para retornar ao menu\n\n");
		scanf("%d", &opcao);
		limpaTela();
		if(opcao != 0)
		{
			menu();
		}else
		{
			menu();
		}
	break;

	case 3:
		printf("Qual ranking deseja exibir?(5,7,9)\n");
		scanf("%d", &rk);
		limpaTela();
		if((rk != 5) && (rk != 7) && (rk != 9))
		{
			while((rk != 5) && (rk != 7) && (rk != 9))
				{
					printf("VALOR INVALIDO\n");
					printf("Qual ranking deseja exibir?(5,7,9)\n");
					scanf("%d", &rk);
					limpaTela();
				}
		}
		
		if(rk == 5){
			ver_rank("placa5.bin");
		}else if(rk == 7){
			ver_rank("placa7.bin");
		}else if(rk == 9){
			ver_rank("placa9.bin");
		}
		
		
		printf("Digite um inteiro qualquer para retornar ao menu\n\n");
		scanf("%d", &opcao);
		limpaTela();
		if(opcao != 0)
		{
			menu();
		}else
		{
			menu();
		}
	break;

	case 4:
		printf("\nDensenvolvido por:\nLucas Sampaio\nMatheus Araujo\nMarco Antonio\nWillian Gomes\n\n");
		printf("Projeto de Computacao 1\n\n");
		printf("Digite um inteiro qualquer para retornar ao menu\n");
		scanf("%d", &opcao);
		limpaTela();
		if(opcao != 0)
		{
			menu();
		}else
		{
			menu();
		}
	break;

	case 5:
		printf("\nFIM_DO_PROGRAMA");
		exit(0);
	break;

	default:
		printf("\nValor Invalido\n");
		menu();

	}
}

int main()
{
	menu();
}
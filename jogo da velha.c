#include <stdio.h>
#include <stdlib.h>

void Desenha(char matriz[][3]){
	printf("=========== JOGO DA VELHA ============ \n|\t\t\t\t     |\n");
	
	printf("|              1     2    3          |\n");
	printf("|      1    |  %c |  %c |  %c |         |\n",matriz[0][0],matriz[0][1],matriz[0][2]);
	printf("|          ------------------        |\n");
	printf("|      2    |  %c |  %c |  %c |         |\n",matriz[1][0],matriz[1][1],matriz[1][2]);
	printf("|          ------------------        |\n");
	printf("|      3    |  %c |  %c |  %c |         |\n",matriz[2][0],matriz[2][1],matriz[2][2]);
	printf("|          ------------------        |\n");
	printf("|\t\t\t\t     |\n======================================\n");
}

void ExecutaJogada(char matriz[][3], int player){
	
	int linha, coluna,teste = 0;
	if(player==1) printf("\nJOGADOR X\n");
	
	else printf("\nJOGADOR O\n");
	
	printf("\n---------------------------");
	printf("\n|Escolha a linha e coluna|:");
	printf("\n---------------------------\n");
	scanf("%d %d", &linha,&coluna);
	
	if(player==1){
		
		if(matriz[linha-1][coluna-1] != ' '){
			do{
				printf("------------------------------------------------------");
				printf("\n|Jogada invalida, escolha linha e coluna novamente!|:\n");
				printf("------------------------------------------------------\n");
				scanf("%d %d", &linha,&coluna);
				if(matriz[linha-1][coluna-1] == ' ') teste = 1;
			}while(teste==0);
		}
		matriz[linha-1][coluna-1] = 'X';
		system("cls");
		Desenha(matriz);
	}
	
	else{
		
		if(matriz[linha-1][coluna-1] != ' '){
			
			do{
				printf("------------------------------------------------------");
				printf("\n|Jogada invalida, escolha linha e coluna novamente!|:\n");
				printf("------------------------------------------------------\n");
				scanf("%d %d", &linha,&coluna);
				if(matriz[linha-1][coluna-1] == ' ') teste = 1;
			}while(teste==0);
		}
		
		matriz[linha-1][coluna-1] = 'O';
		system("cls");
		Desenha(matriz);
	}
}

int X(char matriz[][3]){
	
	if(matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]=='X') return 1;
	
	if(matriz[1][0]=='X' && matriz[1][1]=='X' && matriz[1][2]=='X') return 1;
	
	if(matriz[2][0]=='X' && matriz[2][1]=='X' && matriz[2][2]=='X') return 1;
	
	if(matriz[0][0]=='X' && matriz[1][0]=='X' && matriz[2][0]=='X') return 1;
	
	if(matriz[0][1]=='X' && matriz[1][1]=='X' && matriz[2][1]=='X') return 1;
	
	if(matriz[0][2]=='X' && matriz[1][2]=='X' && matriz[2][2]=='X') return 1;
	
	if(matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='X') return 1;
	
	if(matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='X') return 1;
	
	else return 0;
	
}

int O(char matriz[][3]){
	
	if(matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]=='O') return 1;
	
	if(matriz[1][0]=='O' && matriz[1][1]=='O' && matriz[1][2]=='O') return 1;
	
	if(matriz[2][0]=='O' && matriz[2][1]=='O' && matriz[2][2]=='O') return 1;
	
	if(matriz[0][0]=='O' && matriz[1][0]=='O' && matriz[2][0]=='O') return 1;
	
	if(matriz[0][1]=='O' && matriz[1][1]=='O' && matriz[2][1]=='O') return 1;
	
	if(matriz[0][2]=='O' && matriz[1][2]=='O' && matriz[2][2]=='O') return 1;
	
	if(matriz[0][0]=='O' && matriz[1][1]=='O' && matriz[2][2]=='O') return 1;
	
	if(matriz[0][2]=='O' && matriz[1][1]=='O' && matriz[2][0]=='O') return 1;
	
	else return 0;
	
}

int TestaVitoria(char matriz[][3]){
	
	int vitoriaX, vitoriaO,teste=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(matriz[i][j] == ' ') teste++;
		}
	}
	
	vitoriaX = X(matriz);
	vitoriaO = O(matriz);
	
	if(vitoriaX == 1){
		printf("\n\t -> O jogador X venceu! <-\n");
		return 1;
	}
	
	else if(vitoriaO == 1){
		printf("\n\t -> O jogador X venceu! <-\n");
		return 1;
	}
	
	else if(teste == 0){
		printf("\n\t## O jogo deu velha! ##");
		return 1;	
	} 
	
	else return 0;
	
}

int main ()
{
	int cont = 0,player,teste;
	char matriz[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}, };
	char escolha;
	Desenha(matriz);
	
	while(cont<9){
		
			player = 1;
			ExecutaJogada(matriz, player);
			teste = TestaVitoria(matriz);
			if(teste==1) return 0;
			
			player = -1;
			ExecutaJogada(matriz, player);
		cont++;
		teste = TestaVitoria(matriz);
		if(teste==1) return 0;
	}
	TestaVitoria(matriz);
	
	return 0;
}


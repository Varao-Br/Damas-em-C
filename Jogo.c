#include <stdio.h>
#define clear printf("\e[1;1H\e[2J");
#define NEW_POSITION positions[newPos[0]][newPos[1]]
#define OLD_POSITION positions[oldPos[0]][oldPos[1]]

char positions[8][8];

void initGame(void);
void printGame(void);
void p1Move(void); 
void p2Move(void);
int rules(char ,char *, char *);
int winCheck(void);

int main(void){	
	char detect;
	do{
	clear
	puts("Bem-vindo ao projeto Damas em C");
	puts("Pressione \"Enter\" para continuar");
	}while(scanf("%c", &detect), detect != '\n');
	initGame();
	do{
		clear
		printGame();
		p1Move();
		clear
		printGame();
		p2Move();
		
	}while(!winCheck());
	
	
	
}

void initGame(void){
	int i, j;
	for(i=0; i<8; i++)
		for(j=0; j<8;j++){
			if(i<3 && (i+j)%2)
				positions[i][j] = 'O';
			
			else if(i>4 && (i+j)%2)
				positions[i][j] = 'X';
		}	
}

void printGame(void){
	int i,j;
	for(i=0; i<8; i++){
		puts("   --- --- --- --- --- --- --- ---");
		for(j=0; j<8;j++){
			if(!j)
				printf("%d ",i+1);
			if(positions[i][j])
				printf("| %c ", positions[i][j]);
			else
				printf("|   ");
		}
		puts("|");
		}	
		puts("   --- --- --- --- --- --- --- ---");
		puts("    A   B   C   D   E   F   G   H ");
}

void p1Move(void){
	char oldPos[2], newPos[2]; //oldPos and newPos = (x ,y); Pos[0] = x   Pos[1] = y
	printf("\nDigite a posicao que quer jogar, Jogador 1(Ex A1 B2): ");
	setbuf(stdin, NULL);
	scanf("%c%c %c%c", &oldPos[1], &oldPos[0], &newPos[1], &newPos[0]);
	oldPos[0] -= 49;
	oldPos[1] -= 65;
	newPos[0] -= 49;
	newPos[1] -= 65;
	while(!rules('X', oldPos, newPos)){
		printf("\nOcorreu algum problema, tente novamente: ");
		setbuf(stdin, NULL);
		scanf("%c%c %c%c", &oldPos[1], &oldPos[0], &newPos[1], &newPos[0]);
		oldPos[0] -= 49;
		oldPos[1] -= 65;
		newPos[0] -= 49;
		newPos[1] -= 65;
	}
	if(rules('X', oldPos, newPos) == 1){
		NEW_POSITION = 'X'; 
		OLD_POSITION = '\0';
	}
	else{
		if(rules('X', oldPos, newPos) == 21){
			positions[newPos[0]-1][newPos[1]+1] = 'X';
			NEW_POSITION = OLD_POSITION = '\0';
		}
		else
			positions[newPos[0] - 1][newPos[1]-1] = 'X';
			NEW_POSITION = OLD_POSITION = '\0';
	}
}

void p2Move(void){
	char oldPos[2], newPos[2]; //oldPos and newPos = (x ,y); Pos[0] = x   Pos[1] = y
	printf("\nDigite a posicao que quer jogar, Jogador 2(Ex A1 B2): ");
	setbuf(stdin, NULL);
	scanf("%c%c %c%c", &oldPos[1], &oldPos[0], &newPos[1], &newPos[0]);
	oldPos[0] -= 49;
	oldPos[1] -= 65;
	newPos[0] -= 49;
	newPos[1] -= 65;
	while(!rules('O', oldPos, newPos)){
		printf("\nOcorreu algum problema, tente novamente: ");
		setbuf(stdin, NULL);
		scanf("%c%c %c%c", &oldPos[1], &oldPos[0], &newPos[1], &newPos[0]);
		oldPos[0] -= 49;
		oldPos[1] -= 65;
		newPos[0] -= 49;
		newPos[1] -= 65;
	}
	if(rules('O', oldPos, newPos) == 1){
		NEW_POSITION = 'O'; 
		OLD_POSITION = '\0';
	}
	else{
		if(rules('O', oldPos, newPos) == 21){
			positions[newPos[0] + 1][newPos[1]+1] = 'O';
			NEW_POSITION = OLD_POSITION = '\0';
		}
		else
			positions[newPos[0] + 1][newPos[1]-1] = 'O';
			NEW_POSITION = OLD_POSITION = '\0';
			
	}
}

int rules(char player,char oldPos[2], char newPos[2]){ //0 se ocorreu erro, 1 se sucedeu e 2[0, 1] caso mate uma peça

	char diagon;
	if(positions[oldPos[0]][oldPos[1]] != player)//Não selecionou a peça
		return 0;
	if(positions[oldPos[0]][oldPos[1]] == positions[newPos[0]][newPos[1]])//Não se moveu
		return 0;
	if(newPos[1] < 0 || newPos[1] > 7 || oldPos[1] < 0 || oldPos[1] > 7) //limite do tabuleiro
		return 0;
		
	if(oldPos[1] - newPos[1] <= -1) // 0 indo para a esquerda, 1 para a direita
		diagon = 1;
	else
		diagon = 0; 
		
	if(positions[newPos[0]][newPos[1]] != '\0'){ //se mover na mesma posição de outra peça
		if (positions[newPos[0]][newPos[1]] == player)
			return 0;
		if (diagon && !positions[newPos[0] + (player == 'X')?-1:1][newPos[1]+1]){
			return 21;
		}
		if(!diagon && !positions[newPos[0] + (player == 'X')?-1:1][newPos[1]-1]) 
			return 20;
		return 0;
		
	}
	return 1;
}

int winCheck(void){
	int p1, p2, i, j;
	for(i=p1=p2=0; i<8; i++)
		for(j=0; j<8;j++){
			if(positions[i][j] = 'O')
				p1++;	
			if(positions[i][j] = 'X')
				p2++;
			if(p1 && p2)
				return 0;
		}
	return p1?1:2;			

}


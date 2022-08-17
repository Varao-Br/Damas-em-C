#include <stdio.h>
#define clear printf("\e[1;1H\e[2J");

char positions[8][8];

void initGame(void);
void printGame(void);
void p1Move(void); 
void p2Move(void);
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
	int oldLine, newLine;
	char oldColumn, newColumn;
	printf("\nDigite a posicao que quer jogar, Jogador 1(Ex A1 B2): ");
	setbuf(stdin, NULL);
	scanf("%c%d %c%d", &oldColumn, &oldLine, &newColumn, &newLine);
	while(positions[oldLine-1][((int)oldColumn)-65] != 'X'){
		printf("\nOcorreu algum problema, tente novamente: ");
		setbuf(stdin, NULL);
		scanf("%c%d %c%d", &oldColumn, &oldLine, &newColumn, &newLine);
	}
	positions[newLine-1][((int)newColumn)-65] = positions[oldLine-1][((int)oldColumn)-65]; 
	positions[oldLine-1][((int)oldColumn)-65] = '\0';
	
}

void p2Move(void){
	int oldLine, newLine;
	char oldColumn, newColumn;
	printf("\nDigite a posicao que quer jogar, Jogador 2(Ex A1 B2): ");
	setbuf(stdin, NULL);
	scanf("%c%d %c%d", &oldColumn, &oldLine, &newColumn, &newLine);
	while(positions[oldLine-1][((int)oldColumn)-65] != 'O'){
		printf("\nOcorreu algum problema, tente novamente: ");
		setbuf(stdin, NULL);
		scanf("%c%d %c%d", &oldColumn, &oldLine, &newColumn, &newLine);
	}
	positions[newLine-1][((int)newColumn)-65] = positions[oldLine-1][((int)oldColumn)-65]; 
	positions[oldLine-1][((int)oldColumn)-65] = '\0';
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


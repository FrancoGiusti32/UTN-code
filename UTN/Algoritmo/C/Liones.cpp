#include <iostream>
using namespace std;
void showBoard(int board[6]);
void inicializarBoard(int board[6]);
void fillPlayerBoard(int board[6]);
void fillBoard(int board[6]);
void juego(int board[6],int player1[6],int player2[6]);
int main(int argc, char *argv[]) {
	int board[6] ;
	int player1[6];
	int player2[6];
	int play=0;
	do{
	fillBoard(board);
	fillPlayerBoard(player1);
	fillPlayerBoard(player2);
	juego(board,player1,player2);
	cout<<"Quiere serguir jugando? [1]si/[0]no"<<endl;
	cin>>play;
	}while(play!=0);
	cout<<"GRACIAS POR JUGAR";
	return 0;
}

void juego(int board[6],int player1[6],int player2[6]){
	int puntosP1=0;
	int puntosP2=0;
	for(int i=0;i<6;i++){
		if(player1[i]==1&&board[i] == 1||board[i]==1 && player2[i]==1){
			if(player1[i]==1&&player2[i]==1){
				puntosP1=puntosP1+10;
				puntosP2=puntosP2+10;
			}else if(player1[i]==1){
			puntosP1=puntosP1-5;
			}else{
			puntosP2=puntosP2-5;
			}
		}
	}
	cout<<"Los puntos del jugador 1 son: "<<puntosP1<<endl;
	cout<<"los puntos del jugador 2 son "<<puntosP2<<endl;
	cout<<"leon"<<endl;
	showBoard(board);
	cout<<"Ply1"<<endl;
	showBoard(player1);
	cout<<"Ply2"<<endl;
	showBoard(player2);
}

void fillPlayerBoard(int board[6]){
	inicializarBoard(board);
	int cazadores=3;
	int pocisionCazador;
		while(cazadores!=0){
		cout<<"Donde quiere colocar su cazador?";
		cout<<endl;
			showBoard(board);
			cin>>pocisionCazador;
			if(board[pocisionCazador-1]!=1){
				board[pocisionCazador-1]=1;
				cazadores--;
			}
	}
		
}
void fillBoard(int board[6] ){
int amauntofLions= 3;
inicializarBoard(board);
	while(amauntofLions>=1){
		for (int i=0;i<6;i++){
			if(board[i]!=1){
				if(amauntofLions==0){
					break;
				}
				int random=rand();
				if(random%2==0){
					board[i]=1;
					amauntofLions--;
				}
			}
		}
	}
}
		
void inicializarBoard(int board[6]){
	for(int i=0;i<6;i++){
		board[i]=0;
	}
}
void showBoard(int board[6] ){
	for (int i =0; i<6;i++){
		cout<<"|";
		cout<<board[i];
		cout<<"|";
	}
	cout<<endl;
}
				

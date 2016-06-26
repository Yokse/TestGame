#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void gotoxy(int x, int y){
	
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);

	
}

void OcultarCursor(){
	
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon,&cci);		
	
}

class NAVE{
	
	int x,y;
	int vidas;
	int corazones;


public:
	
	int VID(){ return vidas; }
	int X(){ return x; }
	int Y(){ return y; }
	NAVE(int _x, int _y, int _corazones, int _vidas);
	void pintar();
	void borrar();
	void mover();
	void pintar_corazones();
	void morir();
	void COR(){ corazones--; }
	
	
};
	
	NAVE::NAVE(int _x, int _y, int _corazones, int _vidas){
		
		
		y = _y;
		x = _x;
		corazones = _corazones;
		vidas = _vidas;
		
	}



void NAVE::pintar(){
	
	gotoxy(x,y); printf("  %c", 203);
	gotoxy(x,y+1); printf(" %c%c%c", 219, 219, 219);
	gotoxy(x,y+2); printf("%c%c%c%c%c",219,219,219,219,219);
	
	
}

void NAVE::borrar(){
	
	gotoxy(x,y); printf("           ");
	gotoxy(x,y+1); printf("         ");
	gotoxy(x,y+2); printf("         ");
	
}

void NAVE::mover(){
	
	if(kbhit()){
			
			
			char tecla = getch();
			borrar();
			if(tecla == IZQUIERDA && x>3) x-=2;
			if(tecla == DERECHA && x+6 < 77) x+=2;
			if(tecla == ARRIBA && y>4) y--;
			if(tecla == ABAJO && y+3 < 33) y++;
			if(tecla == 'e') corazones--;
			pintar();
			pintar_corazones();
		}
	
}

void limites(){
	
	for(int i = 2 ; i <78 ; i++){
	
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i,33); printf("%c", 205);
	
	}
	
for(int i = 4 ; i < 33 ; i++){
	
		gotoxy(2,i); printf("%c", 186);
		gotoxy(77,i); printf("%c", 186);
	
	}
	
	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2,33); printf("%c",200);
	gotoxy(77,3); printf("%c",187);
	gotoxy(77,33); printf("%c",188);
	
}

void NAVE::pintar_corazones(){
	
	gotoxy(40,2); printf("LIFES -> %d",vidas);
	gotoxy(58,2); printf("HEARTHS ->");
	gotoxy(70,2); printf("     ");
	for( int i = 0 ; i < corazones ; i++){
		
		gotoxy(70+i,2); printf("%c",64);
		
	}

}
	
void NAVE::morir(){
	
	if(corazones == 0){
		
		borrar();
		gotoxy(x,y); printf("   **   ");
		gotoxy(x,y+1); printf("  ****  ");
		gotoxy(x,y+2); printf("   **");
		Sleep(200);
		
		borrar();
		
		gotoxy(x,y); printf(" * ** *");
		gotoxy(x,y+1); printf("  **** ");
		gotoxy(x,y+2); printf(" * ** *");
		Sleep(200);
		
		borrar();
		vidas--;
		corazones = 3;
		pintar_corazones();
		pintar();
		Sleep(150);
		borrar();
		Sleep(150);
		pintar();
		Sleep(150);
		borrar();
		Sleep(150);
		pintar();
		Sleep(150);
		borrar();
		Sleep(150);
		pintar();
		
				
	}
	
}

class AST{
	
	int x,y;
	
public:
	
	AST(int _y, int _x);
	void pintar();
	void mover();
	void choque(struct NAVE &N);
	
	
};

AST::AST (int _y, int _x){
	
	x = _x;
	y = _y;
	
}

void AST::pintar(){
	
	gotoxy(x,y); printf("%c",184);
	
}

void AST::mover(){
	
	gotoxy(x,y); printf(" ");
	y++;
	
	if(y > 32){
		
		x = rand()%71 + 4;
		y = 4;
		
	}
	
	pintar();
	
}

void AST::choque(struct NAVE &N){
	
	if( x >= N.X() && x < N.X()+6 && y >= N.Y() && y <= N.Y()+2 ){
		
		N.COR();
		N.borrar();
		N.pintar();
		N.pintar_corazones();
		x = rand()%71 + 4;
		y = 4;
				
	}
	
}

void GAME_OVER(){
	
}

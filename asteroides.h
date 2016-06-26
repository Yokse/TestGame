#include "Funciones.h"

void asteroides(){
	
	int x;
	int y;
	limites();
	OcultarCursor();
	NAVE N(7,7,3, 3);
	N.pintar_corazones();
	N.pintar();
	
	AST ast1(10,4); AST ast2(5,8); AST ast3(17,3);
	
	bool game_over = false;
	
	
	while(!game_over){
		
		ast1.mover(); ast2.mover(); ast3.mover();
		ast1.choque(N); ast2.choque(N); ast3.choque(N);
		N.morir();
		N.mover();
		
		if(N.VID() == -1) game_over = true;
		
		Sleep(30);
		
	}
	
	
system("CLS");
limites();
GAME_OVER();

	
}

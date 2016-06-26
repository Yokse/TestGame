#include <iostream>
#include <conio.h>
#include "asteroides.h"

using namespace std;

int main(){
	inicio:
	cout <<"Esta aplicacion ha sido desarrolada por Quikki y por Banderblade" << "\n\n\n" << "Seleccione el juego al que desea jugar: " << "\n"<< "---------------------------------------" << "\n" << "1. Asteroides" << "\n" << "2. Proximamente..." << "\n3. Salir"<< endl;
	cin >> opcion;
	switch(opcion){
		case 1:
			inicio1:
			cout << "1. Comenzar a jugar" << "\n" << "2. Explicar controles" << "\n" << "3. Volver al menu" << endl;
			cin >> opcion;
			switch(opcion){
				case 1:
					asteroides();
					break;
				case 2:
					cout << "El juego consiste en esquivar los asteroides que vienen desde arriba, la nave la mueves con las flechas de direccion";
					getch();
					system("CLS");
					goto inicio1;
					break;
				case 3:
					system("CLS");
					goto inicio;
					break;
				default:
					cout << "Esa opcion no es valida";
					getch();
					system("CLS");
					goto inicio1;
					break;
			}
			break;
		case 2:
			cout << "Esta opcion estara disponible proximamente";
			getch();
			system("CLS");
			goto inicio;
			break;
		case 3:
			cout << "Esperamos que la aplicacion haya sido de su agrado"
	}
}

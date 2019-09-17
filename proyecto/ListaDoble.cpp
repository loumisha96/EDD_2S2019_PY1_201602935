#include <iostream>
#include <string>
using namespace std;


class Nodo {
public:
	string copia;
	Nodo* sig;
	Nodo* ant;
Nodo(string copia) {
		this->copia = copia;
		this->sig = 0;
		this->ant = 0;
	}
	
};
class ListaDoble {
	public:
		Nodo* primero;
	ListaDoble() {
		this->primero = 0;
	}
	bool vacia() {
		return primero == 0;
	}
	void insertar(string filtro) {
		Nodo *nuevo = new Nodo(filtro);
		if (vacia()) {
			primero = nuevo;
			primero->sig = primero;
			primero->ant = primero;
			
		}
		else {
			primero->ant = nuevo;
			nuevo->ant = primero->ant;
			nuevo->sig = primero;
		}

	}
};
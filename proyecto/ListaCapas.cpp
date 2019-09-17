#include <iostream>
#include <string>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

class Nodo{
	public:
		string color;
		int x;
		int y;
		Nodo * sig;
		Nodo *ant;
		Nodo *up;
		Nodo *down;
	Nodo (int x, int y, string color) {
		this->x = x;
		this->y = y;
		this->color = color;
		this->sig = 0;
		this->ant = 0;
		this->up = 0;
		this->down = 0;
	}
};
class ListaCapas{
   public:
		Nodo *primero;
		ListaCapas* sig;
		ListaCapas* ant;
		int capa;
		ListaCapas(int capa) {
			this->primero = new Nodo(0, 0, "Raiz");
			this->capa = capa;
			this->sig = 0;
			this->ant = 0;
	    }

	bool vacia() {
		if (primero->sig == 0) {
			return true;
		}
		else
		{
			return false;
		}
		
	}

	Nodo *insertarColumna(int x, int y, string color) {
		Nodo *nuevo = new Nodo(x, y, "Columna");
		Nodo *aux = primero;
		bool encontrado = false;
		if (vacia()) {
			primero->sig = nuevo;
			nuevo->ant = primero;
			return nuevo;
		}
		else {
			while (true) {
				if (aux->x == nuevo->x) {
					aux->x = nuevo->x;
				}
				else if (aux->x > nuevo->x) {
					encontrado = true;
					break;
				}
				if (aux->sig != 0) {
					aux = aux->sig;
				}
				else {
					break;
				}
			}
			if (encontrado) {
				nuevo->sig = aux;
				aux->ant->sig = nuevo;
				nuevo->ant = aux->ant;
				aux->ant = nuevo;
			}
			else {
				aux->sig = nuevo;
				nuevo->ant = aux;
			}
			return nuevo;
		}

	}
	Nodo *insertarFila(int x, int y, string color) {
		Nodo *nuevo = new Nodo(x, y, "Fila");
		Nodo *aux = primero;
		bool encontrado = false;
		if (primero->down==0) {
			primero->down = nuevo;
			nuevo->up = primero;
			return nuevo;
		}
		else {
			while (true) {
				if ((aux->y == nuevo->y)) {
					aux->y = nuevo->y;
				}
				else if (aux->y > nuevo->y) {
					encontrado = true;
					break;
				}
				if (aux->down != 0) {
					aux = aux->down;
				}
				else {
					break;
				}
			}
			if (encontrado) {
				nuevo->down = aux;
				aux->up->down = nuevo;
				nuevo->up = aux->up;
				aux->up = nuevo;
			}
			else {
				aux->down = nuevo;
				nuevo->up = aux;
			}
			return nuevo;
		}
	}
	void insertarElemento(int x, int y, string color) {
		Nodo* nuevo = new Nodo(x, y, color);
		Nodo* columna = insertarColumna(x, y, "Columna");
		Nodo* fila = insertarFila(x, y, "Fila");
		
		Nodo *auxC = columna;
		Nodo *auxF = fila;
		while (auxC->down != NULL) {
			auxC = auxC->down;
		}
		auxC->down = nuevo;
		nuevo->up = auxC;
		while (auxF->sig != NULL) {
			auxF = auxF->sig;
		}
		auxF->sig = nuevo;
		nuevo->ant = auxF;

		
	}
	void printcolumna() {
		Nodo* aux = primero;
		while (aux->down != 0) {
			while (aux->sig != 0) {
				cout << "Columna =" << aux->x << "Fila :" << aux->y << "dato:" << aux->color << endl;
			}
			aux = aux->down;
		}
		printcolumna();
	}
};
class Cubo {
public:
	ListaCapas *primera;
	
	Cubo() {
		this->primera = 0;
	}
	void insertar( int capa, ListaCapas *nueva) {
		bool encontrado = false;
		
		if (primera == 0) {
			primera = nueva;
		}
		else {
			ListaCapas* aux = primera;
			while (true) {
				if ((aux->capa == nueva->capa)) {
					aux->capa = nueva->capa;
				}
				else if (aux->capa > nueva->capa) {
					encontrado = true;
					break;
				}
				if (aux->sig != 0) {
					aux = aux->sig;
				}
				else {
					break;
				}
			}
			if (encontrado) {
				nueva->sig= aux;
				aux->ant->sig = nueva;
				nueva->ant = aux->ant;
				aux->ant = nueva;
			}
			else {
				aux->sig = nueva;
				nueva->ant = aux;
			}

		}
	}
};

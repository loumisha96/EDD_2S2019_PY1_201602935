#include <iostream>
#include <string>
#include "stdio.h"
#include "stdlib.h"
#include "ListaCapas.cpp"
using namespace std;

class hoja {
	public:
		Cubo *cubo;
		hoja* left;
		hoja* right;
		string nombre;
		hoja(Cubo *cubo, string nombre) {
			this->cubo = cubo;
			this->left = 0;
			this->right = 0;
			this->nombre = nombre;
	    }
	
};
class arbol {
public:
	hoja* raiz;
	
    arbol() {
		this->raiz = 0;
		
	}
	void insertar(Cubo *cubo, string nombre) {
		if (this->raiz == 0) {
			this->raiz = new hoja(cubo, nombre);
			
		}
		else {
			insertar(raiz, new hoja(cubo,nombre));
		}
	}
	void insertar(hoja* actual, hoja* nuevo) {
		if (nuevo->nombre.compare(actual->nombre) < 0) {
			if (actual->left == 0) {
				actual->left = nuevo;
			}
			else
				insertar(actual->left, nuevo);
		}
		else if (nuevo->nombre.compare(actual->nombre)>0) {
			if (actual->right == 0) {
				actual->right = nuevo;
			}
			else
				insertar(actual->right, nuevo);
		}
	}
	hoja * buscar(string nombre) {
		return buscar(this-> raiz, nombre);
	}
	hoja* buscar(hoja* actual, string nombre) {
		if (actual == 0)
			return 0;
		if (actual->nombre == nombre) {
			return actual;
		}
		else {
			if (nombre.compare(actual->nombre) < 0)
				return buscar(actual->left, nombre);
			else if (nombre.compare(actual->nombre) > 0)
				return buscar(actual->right, nombre);
		} 
	}
	//void graficar() {

	//}
};

#include <iostream>
#include "listaMatriz.cpp"

using namespace std;


int main() {
	Lista* s = new Lista();
	s->insertarElemento(3, 5, "e1");
	s->insertarElemento(2, 5, "e2");
	s->insertarElemento(4, 1, "e3");
	s->insertarElemento(5, 3, "e4");
	s->insertarElemento(2, 2, "e5");
	s->insertarElemento(1, 8, "e6");
	return 0;
};


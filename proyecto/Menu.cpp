#include <iostream>
#include <string>
#include <fstream>



#include "ABB.cpp"

using namespace std;

void LeerArchivoInicial(string nombre);
void LeerArchivo(string nombre, int capa);
void split(string linea);
void splitInsertar(string linea,int capa, int fila, ListaCapas* c);
void AbrirImagen(string nombre);

arbol *Arbol = new arbol();


int main() {
	cout << "1 - Insert image" << endl;
	cout << "2 - Select image" << endl;
	cout << "3 - Apply filters" << endl;
	cout << "4 - Manual editing" << endl;
	cout << "5 - Export Image" << endl;
	cout << "6 - Reports" << endl;
	int opcion;
	cin >> opcion;
	string nombre;
	string var;
	switch (opcion)
	{
	case 1:
		cout << "Nombre de archivo" << endl;
		cin >> nombre;
		var = nombre + ".csv";
		AbrirImagen(nombre);
		LeerArchivoInicial(var);
		
		break;
	case 2:
		
		break;
	case 3:
		cout << "1. Negative" << endl;
		cout << "2. Grayscale" << endl;
		cout << "3. Mirror" << endl;
		cout << "4. Collage" << endl;
		cout << "5. Mosaic" << endl;
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		cout << "1. Imported Images Report" << endl;
		cout << "2. Image Layer Report" << endl;
		cout << "3. Linear Matrix Report" << endl;
		cout << "4. Traversal Report" << endl;
		cout << "5. Filters Report" << endl;
		break;
	default:
		break;
	}
	return 0;
};
void AbrirImagen(string nombre) {
	ifstream archivo;
	archivo.open("C:\/Users\/lourd\/Desktop\/usac\/EDD\/proyecto\/proyecto\/"+nombre, ios::in);
	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea)) {
			if (linea == "ï»¿Layer;File") {
				linea = " ";
			}
			else {
				split(linea);

			}

		}
		archivo.close();
	}
	else {
		cout << "No se encontró el archivo";
	}
}
void LeerArchivoInicial(string nombre) {
	fstream archivo;
	archivo.open(nombre, ios::in);
	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea)) {
			if (linea == "Layer,File") {
				linea = " ";
			}
			else {
				split(linea);
				
			}
			
		}
		archivo.close();
	}
	else {
		cout << "No se encontró el archivo";
	}
};


void LeerArchivo(string nombre, int capa) {
	Cubo* cubo = new Cubo();
	fstream archivo;
	archivo.open(nombre, ios::in);
	int fila = 0;
	ListaCapas* c = new ListaCapas(capa);
	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea)) {
			if (linea == "Layer,File") {
				linea = " ";
			}
			else if (linea == "Config; Value") {

			}
			else {
				
				splitInsertar(linea, capa, fila, c);
				fila++;
			}

		}
		cubo->insertar(capa, c);
		Arbol->insertar(cubo, nombre);
		archivo.close();
		c->printcolumna();
	}
	else {
		cout << "No se encontró el archivo";
	}
};
void split(string linea) {
	string word = "";
	int capa = 0;
	
	string word2 = "";
	
	for (auto x : linea) {
		if (x == ',') {
			
			capa = atoi(word.c_str());
			
			word = "";
		}
		else if (x == 'ï'|| x == '»'|| x == '¿') {
			word = "";
		}
		else {
			word = word + x;
		}
	}
	if (capa != 0) {
		LeerArchivo(word, capa);
		
	}
	else {
         //insertar
	}
	
};

void splitInsertar(string linea, int capa, int fila, ListaCapas *c) {
	
	string word = "";
	int guion=0;
	string word2 = "";
	
	int columna=0;
	for (auto x : linea) {
		if (x == ',') {
			columna++;
			
			if (word == "x") {
				
				word = "";
			}
			
			else
			{
				c->insertarElemento(columna, fila, word);
				word = " ";
			}
				
			
		}
		
		else if (x == 'ï'|| x== '»'|| x == '¿') {
			cout << word << endl;
			word = "";
		}
		else {
			
			word = word + x;
		}
		
		
	}
	columna++;
	c->insertarElemento(columna, fila, word);
	word = " ";
	
	
};




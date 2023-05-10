#include <iostream>
using namespace std;

struct socios{
    int edad;
    string nombre;
    string apellido;
    string direccion;
    string menbresia;
};

typedef struct nodo{
    int id;
    socios info;
    nodo *ant;
    nodo *sig;

}Nodo;

void setInfo(Nodo *);

Nodo *crearNodo(int);
bool insertarNodo(Nodo *&, Nodo *);
bool buscarNodo(Nodo*, int);
Nodo *obtenerReferencia(Nodo *, int);
int contarNodos(Nodo*);
bool modificarDatoNodo(Nodo*, int);
bool reemplazarNodo(Nodo*&, Nodo *);
bool borrarNodo(Nodo*&, int);
void limpiarLista(Nodo*&);
bool mostrarContenidoNodo(Nodo *, int);
void mostrarContenidoLista(Nodo *);

void sociosPorEdad(Nodo *, int);
void sociosPorRangoEdad(Nodo *, int, int);

void MostrarMismoNombre(Nodo*);
void MostrarMismoApellido(Nodo*,string);
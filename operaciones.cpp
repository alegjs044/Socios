#include "header.hpp"




void setInfo(Nodo *elemento){
    string nombre;
    string apellido;
    string direccion;
    string menbresia;
    int edad;
    cout<<"Ingrese la edad:";
    cin >> edad;
    cin.ignore();
    cout<<"Agrega el nombre:";
    getline(cin, nombre);
    cout<<"Agrega Apellido:";
    getline(cin, apellido);
    cout<<"Agrega la direccion:";
    getline(cin, direccion);
    cout<<"Agrega El tipo de menbrecia:";
    getline(cin, menbresia);

    elemento->info.edad = edad;
    elemento->info.nombre = nombre;
    elemento->info.apellido = apellido;
    elemento->info.direccion = direccion;
    elemento->info.menbresia = menbresia;
}

Nodo *crearNodo(int id)
{
    Nodo *nuevo = nullptr;
    nuevo = new Nodo;
    if (nuevo != nullptr)
    {
        nuevo->id = id;
        nuevo->sig = nullptr;
    }
    return nuevo;
}

bool insertarNodo( Nodo*& inicio, Nodo* nuevo )
{
    Nodo* nav = NULL;

    if( inicio == NULL )
    {
        inicio = nuevo;
        nuevo->sig = inicio;
        return 1;
    }

    if( nuevo->id == inicio->id )
    {
        return -1;
    }

    nav = inicio;

    while( nav->sig != inicio && (nuevo->id > nav->sig->id || nuevo->id < inicio->id ))
    {
        nav = nav->sig;
    }

    if( nav->sig != inicio && nuevo->id == nav->sig->id )
    {
        return -1;
    }

    nuevo->sig = nav->sig;
    nav->sig = nuevo;

    if( nuevo->id < inicio->id ){
        inicio = nuevo;
    }

    return 1;
} 
bool buscarNodo(Nodo *lista, int id)
{
    Nodo *nav = nullptr;
    if (lista == nullptr)
    {
        return false;
    }
    nav = lista;
    while (nav->sig != lista && nav->id != id)
    {

        nav = nav->sig;
    }
    if (nav->id == id)
    {
        return true;
    }
    return false;
}

Nodo *obtenerReferencia(Nodo *lista, int id)
{
    Nodo *nav = nullptr;
    if (lista == nullptr)
    {
        return nav;
    }
    nav = lista;
    while (nav->sig != lista && nav->id != id)
    {

        nav = nav->sig;
    }
    if (nav->id == id)
    {
        return nav;
    }
    return nullptr;
}
int contarNodos(Nodo *lista)
{
    Nodo *nav = nullptr;
    int cantidad = 0;
    if (lista == nullptr)
    {
        return 0;
    }
    nav = lista;
    cantidad++;
    while (nav->sig != lista)
    {
        cantidad++;
        nav = nav->sig;
    }
    return cantidad;
}
bool modificarDatoNodo(Nodo *lista, int id)
{
    Nodo *nav = nullptr;
    string nombre;
    int edad;
    if (lista == nullptr)
    {
        return false;
    }
    nav = lista;
    if (nav->id == id)
    {
        
        setInfo(nav);
        return true;
    }
    nav = nav->sig;
    while (nav != lista)
    {
        if (nav->id == id)
        {
            setInfo(nav);
            return true;
        }
        nav = nav->sig;
    }
    return false;
}
bool reemplazarNodo(Nodo *&lista, Nodo *nuevo)
{
    Nodo *nav = nullptr;
    Nodo *aux = nullptr;
    if(lista == nullptr){
        return false;
    }
    nav = lista;
    if(nuevo->id == nav->id){

        while (nav->sig != lista)
        {
            nav = nav->sig;
        }
        aux = lista;
        nav->sig = nuevo;
        nuevo->sig = aux->sig;
        lista = nuevo;
        delete aux;
        return true;
    }
    while(nav->sig != lista && nav->sig->id != nuevo->id){
        nav = nav->sig;
    }
    if(nav->sig->id != nuevo->id){
        return false;
    }
    aux = nav->sig;
    nav->sig = nuevo;
    nuevo->sig = aux->sig;
    delete aux;

    return true;
}
bool borrarNodo(Nodo *&lista, int id)
{
    Nodo *nav = nullptr;
    Nodo *aux = nullptr;
    if (lista == nullptr)
    {
        return false;
    }
    nav = lista;
    if(nav->id == id && nav->sig == lista){

        aux = nav;
        lista = nullptr;
        delete aux;
        return true;
    }

    while (nav->sig != lista && nav->sig->id != id)
    {
        nav = nav->sig;
    }
    if (nav->sig->id != id)
    {
        return false;
    }
    if(id == lista->id){
        lista = nav->sig;
    }
    aux = nav->sig;
    nav->sig = aux->sig;
    delete aux;

    return true;
}


void limpiarLista(Nodo *&lista)
{
    Nodo *nav = nullptr;
    Nodo *aux = nullptr;
    if (lista == nullptr)
    {
        cout<<"Esta vacia la lista"<<endl;
        return;
    }
    nav = lista;
    aux = nav->sig;
    nav->sig = nullptr;
    while (aux != nullptr)
    {
        nav = aux->sig;
        delete aux;
        aux = nav;
    }
    lista = aux;
    cout<<"Se limpio la lista";
}

bool mostrarContenidoNodo(Nodo *lista, int id)
{
    Nodo *nav = nullptr;
    if (lista == nullptr)
    {
        return false;
    }
    nav = lista;
    while (nav->sig != lista && nav->id != id)
    {
        nav = nav->sig;
    }
    if (id == nav->id)
    {
        cout<<"No de menbresia: "<<nav->id<<endl;
        cout<<"Edad:"<<nav->info.edad<<endl;
        cout<<"Nombre: "<<nav->info.nombre<<endl;
        cout<<"Apellido: "<<nav->info.apellido<<endl;
        cout<<"Direccion:"<<nav->info.direccion<<endl;
        return true;
    }
    return false;
}

void mostrarContenidoLista(Nodo *lista)
{
    Nodo *nav = nullptr;

    if (lista == nullptr)
    {
        cout << "No hay ningun alemento" << endl;
        return;
    }
    nav = lista;
    cout<<"No de menbresia: "<<nav->id<<endl;
    cout<<"Edad:"<<nav->info.edad<<endl;
    cout<<"Nombre: "<<nav->info.nombre<<endl;
    cout<<"Apellido: "<<nav->info.apellido<<endl;
    cout<<"Direccion:"<<nav->info.direccion<<endl;
    nav = nav->sig;
    while (nav != lista)
    {
        cout<<"No de menbresia: "<<nav->id<<endl;
        cout<<"Edad:"<<nav->info.edad<<endl;
        cout<<"Nombre: "<<nav->info.nombre<<endl;
        cout<<"Apellido: "<<nav->info.apellido<<endl;
        cout<<"Direccion:"<<nav->info.direccion<<endl;
        nav = nav->sig;
    }
}


void sociosPorEdad(Nodo *lista, int edad){
    Nodo *nav = nullptr;
    if(lista == nullptr){
        cout<<"No hay socios registrados"<<endl;
        return;
    }
    nav =  lista;
    if(lista->info.edad == edad){
        cout<<"No de menbresia: "<<nav->id<<endl;
        cout<<"Edad:"<<nav->info.edad<<endl;
        cout<<"Nombre: "<<nav->info.nombre<<endl;
        cout<<"Apellido: "<<nav->info.apellido<<endl;
        cout<<"Direccion:"<<nav->info.direccion<<endl;
    }
    nav = nav->sig;
    while(nav != lista){
        if(nav->info.edad == edad){
            cout<<"=========================="<<endl;
            cout<<"No de menbresia: "<<nav->id<<endl;
            cout<<"Edad:"<<nav->info.edad<<endl;
            cout<<"Nombre: "<<nav->info.nombre<<endl;
            cout<<"Apellido: "<<nav->info.apellido<<endl;
            cout<<"Direccion:"<<nav->info.direccion<<endl;
        }   
        nav = nav->sig;
    }

}

void sociosPorRangoEdad(Nodo *lista, int edadMin, int edadMax){
    Nodo *nav = nullptr;
    if(lista == nullptr){
        cout<<"No hay socios registrados"<<endl;
        return;
    }
    nav =  lista;
    if(nav->info.edad >= edadMin && nav->info.edad <= edadMax){
        cout<<"No de menbresia: "<<nav->id<<endl;
        cout<<"Edad:"<<nav->info.edad<<endl;
        cout<<"Nombre: "<<nav->info.nombre<<endl;
        cout<<"Apellido: "<<nav->info.apellido<<endl;
        cout<<"Direccion:"<<nav->info.direccion<<endl;
    }
    nav = nav->sig;
    while(nav != lista){
        if(nav->info.edad >= edadMin && nav->info.edad <= edadMax){
            cout<<"=========================="<<endl;
            cout<<"No de menbresia: "<<nav->id<<endl;
            cout<<"Edad:"<<nav->info.edad<<endl;
            cout<<"Nombre: "<<nav->info.nombre<<endl;
            cout<<"Apellido: "<<nav->info.apellido<<endl;
            cout<<"Direccion:"<<nav->info.direccion<<endl;
        }   
        nav = nav->sig;
    }

}
void MostrarMismoNombre(Nodo*lista){
    Nodo* nav_i=NULL;
    Nodo* nav_j=NULL;    
    nav_i= new Nodo;
    nav_j= new Nodo;
    int i=0,j=0;
    if(lista==NULL){
        return;
    }
    nav_j=lista;
    
    if(nav_j->info.nombre==nav_i->info.nombre && i!=j){
            cout<<nav_i->id<<" , "<<nav_j->id<<" "<<nav_i->info.nombre<<" \n Es el nombre de socios que se repite";
        }
 while(nav_j!=NULL){
    }
 nav_i=nav_i->sig;
 i++;

}
    
void MostrarMismoApellido(Nodo* lista, string apellido){
    Nodo* nav_i=NULL;
    Nodo* nav_j=NULL;
    nav_i=new Nodo;
    nav_j= new Nodo;
      int i=0,j=0;
    if(lista==NULL){
        return;
    }
    nav_j=lista;
        if(nav_j->info.apellido==nav_j->info.apellido && nav_j->info.apellido==nav_j->info.apellido){
            cout<<nav_i->info.apellido<<"\n"<<nav_j->info.apellido<<"\nApellido de socios que se repite ";
        }
        while(nav_j!=NULL){  
        }
     nav_j=nav_j->sig;
     j++;
 }

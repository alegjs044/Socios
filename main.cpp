#include "header.hpp"
using namespace std;

int main(){
    Nodo *lista = nullptr;
    int opcion = 0;
    int id = 0, edad, edadMax;
    string nombre;
    string apellido;
    Nodo *nuevo = nullptr;

    Nodo *aux = nullptr;
    do{
        cout<<"===========Menu=========="<<endl;
        cout<<"1.-Insertar Socio"<<endl;
        cout<<"2.-Buscar Socio"<<endl;
        cout<<"3.-Obtener referencia"<<endl;
        cout<<"4.-Contar Socios"<<endl;
        cout<<"5.-Modificar Socios"<<endl;
        cout<<"6.-Remplazar Socios"<<endl;
        cout<<"7.-Borrar Socio"<<endl;   
        cout<<"8.-Limpiar lista"<<endl;
        cout<<"9.-Mostrar informacion socio"<<endl;
        cout<<"10.-Mostrar contenido lista"<<endl;
        cout<<"11.-Socios con el mismo Nombre"<<endl;
        cout<<"12.-Socios con el mismo Apellido"<<endl;
        cout<<"13.-Mostrar socios con cierta edad"<<endl;
        cout<<"14.-Socios que se encuentran en un intervalo de edad"<<endl;
        cout<<"15.-Borrar registros con menbresia mayor a"<<endl;
        cout<<"16.-Borrar registros con menbresia menor a"<<endl;
        cout<<"17.-Salir"<<endl;
        cout<<"Ingresa que opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout<<"Ingresa el id: ";
            cin >> id;
            cin.ignore();
            nuevo = crearNodo(id);
            setInfo(nuevo);
            if(insertarNodo(*&lista, nuevo)){
                cout<<"Se inserto"<<endl;
            }else{
                cout<<"No se inserto"<<endl;
                delete nuevo;
            }
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 2:
            cout<<"Ingresa el ID: ";
            cin >> id;cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            if (buscarNodo(lista,id))
            {
                cout<<"Existe el nodo"<<endl;
            }else{
                cout<<"No existe el nodo"<<endl;
            }
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            
            break;
        case 3:
            cout<<"Ingresa el id: ";
            cin >> id;
            aux = nullptr;
            aux = obtenerReferencia(lista, id);
            if(aux != nullptr){
                cout<<"La direccion de memoria es: "<<aux<<endl;
            }else{
                cout<<"No existe el nodo"<<endl;
            }
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 4:
            cout<<"Hay "<<contarNodos(lista)<<" Nodos"<<endl;
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 5:
            cout<<"Ingresa el ID: ";
            cin >> id;
            if(modificarDatoNodo(lista, id)){
                cout<<"Se modifico con exito"<<endl;
            }else{
                cout<<"No existe el nodo";
            }
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 6:
            nuevo = nullptr;
            cout<<"Ingrese el id: ";
            cin >> id;
            cin.ignore();
            nuevo = crearNodo(id);
            setInfo(nuevo);
            if(reemplazarNodo(*&lista, nuevo)){
                cout<<"Se remplazo con exito"<<endl;
            }else{
                delete nuevo;
                cout<<"No se remplazo"<<endl;
            }
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 7:
            cout<<"Ingrese el ID: ";
            cin >> id;
            if(borrarNodo(*&lista, id)){
                cout<<"Se borro el nodo"<<endl;
            }else{
                cout<<"No existe el nodo"<<endl;
            }
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 8:
            limpiarLista(*&lista);
            cout<<"Se limpio la lista"<<endl;
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 9:
            cout<<"Ingresa el id: ";
            cin >> id;
            if(!mostrarContenidoNodo(lista, id)){
                cout<<"No existe ese nodo"<<endl;
            }
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 10:
            mostrarContenidoLista(lista);
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 11:
            MostrarMismoNombre(lista);
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 12:
            MostrarMismoApellido(lista,apellido);
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;
        case 13:
            cout<<"Ingresa la edad de los usuarios:";
            cin >> edad;
            sociosPorEdad(lista, edad);
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            
            break;
        case 14:
            cout<<"Agrega la edad minima:";
            cin >> edad;
            cout<<"Agrega edad Maxima:";
            cin >> edadMax;
            sociosPorRangoEdad(lista, edad, edadMax);
            cout<<"==Presiona Enter para continuar=="<<endl;
            getchar();
            getchar();
            break;

        case 17:
            cout<<"================ADIOS================"<<endl;
            break;
        default:
            break;
        }

    }while (opcion != 17);
}


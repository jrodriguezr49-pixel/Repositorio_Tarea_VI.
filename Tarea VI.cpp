#include <iostream>
using namespace std;

struct Nodo {
    string accion;
    Nodo* siguiente;
};


void push (Nodo*& tope, string texto)
{
    Nodo* Nuevo = new Nodo();
	Nuevo -> accion = texto;
    Nuevo->siguiente = tope;
    tope = Nuevo;
}
void mostrar (Nodo* tope)
{
    if (tope == NULL){
        cout << "No hay elementos\n";
        return;
    }

    while (tope != NULL)
    {
        cout << " " << tope->accion << endl;
     	tope = tope->siguiente;
    }
}
//Se cambia el tipo de dato a string porque el dato no se elimina definitivamente sino que solo cambia de pila
string pop(Nodo*& tope)
{
    if (tope == NULL)
        return "";

    Nodo* temp = tope;
    string accion = temp->accion;
    tope = temp->siguiente;
    delete temp;

    return accion;
}


void vaciarPila(Nodo*& tope)
{
    while (tope != NULL)
    {
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
}

int main() {

    Nodo* acciones = NULL;
    Nodo* rehacer = NULL;

    int opcion;
    string texto;
    
    cout << "Realizado por Javier David Rodriguez Rosales" << endl;
    cout << "Este codigo fue modificado en base a la tarea V, quitando algunas funciones"<< endl;

    do {   
        
        cout << "1. Ingresar contenido\n";
        cout << "2. Deshacer\n";
        cout << "3. Rehacer\n";
        cout << "4. Mostrar contenido\n";
        cout << "5. Mostrar pila para rehacer\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        //se utiliza cin.ignore para que el clic en el boton enter no se tome como contenido
        cin.ignore();

        switch(opcion) {

        case 1:
            cout << "Ingrese contenido: ";
            getline(cin, texto);
            push(acciones, texto);
            vaciarPila(rehacer);
            break;

        case 2:
            if (acciones == NULL)
                cout << "No hay acciones para deshacer\n";
            else
                push(rehacer, pop(acciones));
            break;

        case 3:
            if (rehacer == NULL)
                cout << "No hay acciones para rehacer\n";
            else
                push(acciones, pop(rehacer));
            break;

        case 4:
            cout << "\nContenido actual:\n";
            mostrar(acciones);
            break;

        case 5:
            cout << "\nContenido actual:\n";
            mostrar(rehacer);
            break;

        }

    } while(opcion != 6);

    vaciarPila(acciones);
    vaciarPila(rehacer);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

enum colores{verde, amarillo, anaranjado, rojo};

struct Chile
{
    string nombre;
    float shu;
    string colores;
};

Chile pedirDato()
{
    Chile unChile;
    cout << "Ingrese el nombre del chile: ";
    getline(cin, unChile.nombre);
    cout << "SHU: ";
    cin >> unChile.shu;
    cout <<"Ingrese el color del chile: ";
    cin >> unChile.colores;
    cin.ignore();
    return unChile;
}
void mostrarDato(Chile unChile)
{
    cout << endl<< "Nombre del chile: " << unChile.nombre;
    cout << endl<< "SHU:" << unChile.shu;
    cout << endl<< "Color del chile: " << unChile.colores;
}

void mostrarDatos(Chile unChile)
{
    if (unChile.shu >= 50000)
    {
        cout << endl<< "   Estos chiles contienen mas de 50000 SHUs";
        cout << endl<< "Nombre del chile: " << unChile.nombre;
        cout << endl<< "SHU:" << unChile.shu;
        cout << endl<< "Color del chile: " << unChile.colores;
    }
}

enum comparacion {menorque, mayorque,igualque};

bool comparar(Chile a, comparacion operador, Chile b)
{
    bool resultado = false;
    switch (operador)
    {
    case menorque: resultado = a.shu < b.shu; break;
    case mayorque: resultado = a.shu > b.shu; break;
    case igualque: resultado = a.shu == b.shu; break;
    }
    return resultado;
}
typedef Chile T;

struct Nodo
{
    T info;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *Arbol;

Arbol crearArbol(T x);

//Agregar nodos a un arbol
void asignarIzq(Arbol a, T unDato);
void asignarDer(Arbol a, T unDato);
void agregarNodo(Arbol a);
void menurecorrer(Arbol arbol);
//Recorrer un arbol
void preorden(Arbol a);
void inorden(Arbol a);
void postorden(Arbol a);
void recorrerArbol(Arbol a);
void recorrerArbolinorden(Arbol a);
void recorrerArbolPreorden(Arbol a);

void crearPersonalizado(Arbol p);

int main()
{
    Arbol arbol = crearArbol(pedirDato());

    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "\n\tMenu: \n";
        cout << "\t1) Agregar otro chile\n";
        cout << "\t2) Recorrer todos los chiles\n";
        cout << "\t3) Salir\n";
        cout << "\tOpcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1: agregarNodo(arbol); break;
        case 2: menurecorrer(arbol); break;
        case 3: continuar = false; break;
        default: cout << "Opcion erronea!" << endl; break;
        }
    } while (continuar);

    return 0;
}

void menurecorrer(Arbol arbol){
    bool continuar = true;
    do
    {
        int opcion = 0;
       
        cout << "\t1) In-Orden\n";
        cout << "\t2) Post-Orden\n";
        cout << "\t3) Pre-orden\n";
        cout << "\t4) Salir\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1: recorrerArbolinorden(arbol); continuar = false; break;
        case 2: recorrerArbol(arbol); continuar = false; break;
        case 3: recorrerArbolPreorden(arbol); continuar = false; break;
        case 4: continuar = false; break;
        default: cout << "Opcion erronea!" << endl; break;
        }
    } while (continuar);
}

Arbol crearArbol(T x)
{
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

void asignarIzq(Arbol a, T unDato)
{
    if (a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if (a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, T unDato)
{
    if (a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if (a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a)
{
    cout << "Dato a agregar:\n";
    T unDato = pedirDato();

    Arbol p = a;

    while (true)
    {
        if (comparar(unDato, igualque, p->info))
        {
            cout << "Error: dato ya existe!" << endl;
            return;
        }
        else if (comparar(unDato, menorque, p->info))
        {
            if (p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else
        {
            if (p->der == NULL)
                break;
            else
                p = p->der;
        }
    }

    if (comparar(unDato, menorque, p->info))
        asignarIzq(p, unDato);
    else
        asignarDer(p, unDato);
}

void preorden(Arbol a)
{
    if (a != NULL)
    {
        cout << "\n";
        mostrarDato(a->info);
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a)
{
    if (a != NULL)
    {
        inorden(a->izq);
        cout << "\n";
        mostrarDato(a->info);
        inorden(a->der);
    }
}
void postorden(Arbol a)
{
    if (a != NULL)
    {
        postorden(a->izq);
        postorden(a->der);
        cout << "\n";
        mostrarDatos(a->info);
    }
}
void recorrerArbol(Arbol a)
{
  
    cout << "\nRecorrido post-orden:";
    postorden(a);
    cout << endl;
}
void recorrerArbolinorden(Arbol a)
{
 
    cout << "\nRecorrido in-orden:";
    inorden(a);
    cout << endl;
}

void recorrerArbolPreorden(Arbol a){
    cout << "\nRecorrido pre-orden:";
    preorden(a);
    cout << endl;
}
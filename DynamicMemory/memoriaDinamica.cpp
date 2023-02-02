/*
1. Crea un programa que asigne dinámicamente memoria para un entero, luego asigna un valor a ese entero y finalmente imprime el valor del entero. Asegúrate de liberar la memoria una vez que hayas terminado de usarla.
*/

#include <iostream>
using namespace std;

int main() {
    // Creamos un puntero de tipo entero y asignamos memoria dinámicamente para almacenar un entero
    int *p = new int;
    // Asignamos el valor 5 al entero almacenado en la dirección de memoria asignada
    *p = 5;
    // Imprimimos el valor del entero
    cout << *p << endl;
    // Liberamos la memoria asignada dinámicamente
    delete p;
    return 0;
}

/*
2. Crea un programa que asigne dinámicamente memoria para un arreglo de enteros, luego asigna valores a ese arreglo y finalmente imprime los valores del arreglo. Asegúrate de liberar la memoria una vez que hayas terminado de usarla.
*/


#include <iostream>

using namespace std;

int main() {
    int *p = new int[5]; // Puntero "p" que apunta a un bloque de memoria asignado dinámicamente para almacenar 5 enteros
    for (int i = 0; i < 5; i++) {
        p[i] = i; // Asignamos el valor de "i" en cada posición del bloque de memoria
    }
    for (int i = 0; i < 5; i++) {
        cout << p[i] << endl; // Imprimimos el valor almacenado en cada posición del bloque de memoria
    }
    delete [] p; // Liberamos el bloque de memoria asignado dinámicamente
    return 0;
}


/*
3. Crea un programa que utilice un puntero a una estructura que contiene un entero y un puntero a otra estructura. Asigna dinámicamente memoria para las estructuras y asegúrate de liberar la memoria una vez que hayas terminado de usarla.
*/

#include <iostream> // Incluimos la biblioteca iostream para usar cout y endl
using namespace std;

// Declaramos una estructura nodo que contiene un entero y un puntero al siguiente nodo
struct nodo {
    int dato; // Campo para guardar el dato
    nodo *sig; // Puntero al siguiente nodo
};

int main() {
    // Creamos un nuevo nodo usando la keyword new
    nodo *p = new nodo;
    // Asignamos un valor al campo dato del nodo
    p->dato = 5;
    // Asignamos un nuevo nodo al campo sig del nodo actual
    p->sig = new nodo;
    // Asignamos un valor al campo dato del siguiente nodo
    p->sig->dato = 10;
    // Asignamos un valor NULL al campo sig del siguiente nodo para indicar que es el último nodo
    p->sig->sig = NULL;
    // Imprimimos el valor del primer nodo
    cout << p->dato << endl;
    // Imprimimos el valor del segundo nodo
    cout << p->sig->dato << endl;
    // Liberamos la memoria del segundo nodo usando la keyword delete
    delete p->sig;
    // Liberamos la memoria del primer nodo usando la keyword delete
    delete p;
    return 0;
}


/*
4. Crea una clase que tenga un constructor que asigne dinámicamente memoria para un entero y un destructor que libere la memoria una vez que la clase ya no es necesaria.
*/

#include <iostream> // Incluimos la biblioteca iostream para usar cout y endl
using namespace std;


class MiClase {
    private:
        int *ptr_entero; // Puntero para almacenar la dirección de memoria asignada dinámicamente

    public:
        // Constructor
        MiClase() {
            // Asignamos memoria dinámicamente para un entero
            ptr_entero = new int;
        }
        //metodo setter
        void setValor(int val){
            *ptr_entero = val;
        }

        // Método getter para obtener el valor almacenado en el entero
        int getValor() {
            return *ptr_entero;
        }

        // Destructor
        ~MiClase() {
            // Liberamos la memoria asignada dinámicamente
            delete ptr_entero;
        }
};

int main() {
    // Creamos un objeto de la clase "MiClase"
    MiClase obj;
    obj.setValor(5);
    // Imprimiendo el valor almacenado en el entero.
    cout << obj.getValor() << endl;
    return 0;
}

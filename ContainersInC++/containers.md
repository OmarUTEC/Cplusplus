# Containers in C++

<p align="center">
  <img src="containers2.jpg" />
</p>

Los contenedores en C++ son estructuras de datos que almacenan y permiten el acceso y manipulación de colecciones de objetos. La biblioteca estándar de C++ proporciona una serie de contenedores para diferentes usos, como vector, list, deque, array, map y set, que ofrecen diferentes ventajas en términos de tiempo de acceso, tamaño dinámico, capacidad de inserción y eliminación de elementos, entre otras cosas.

Los contenedores se diseñan para ser rápidos, flexibles y fáciles de usar, y se utilizan ampliamente en la programación de C++ para representar y manipular colecciones de objetos de manera eficiente. Además, la biblioteca estándar de C++ también proporciona una amplia gama de algoritmos que pueden usarse con los contenedores, lo que permite realizar tareas como ordenación, búsqueda, filtrado, etc. de manera fácil y eficiente.

<p align="center">
  <img src="containers.jpg" />
</p>


# Seqence Containers

Los contenedores secuenciales en C++ son aquellos que mantienen los elementos en un orden secuencial y proporcionan acceso eficiente a los elementos a lo largo de la secuencia.

* **Vector**: Un contenedor dinámico que mantiene sus elementos en un orden secuencial y proporciona acceso constante a ellos.

```c++
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myVector; // Declara un vector vacío

    myVector.push_back(5); // Agrega un elemento al final del vector
    myVector.push_back(10);
    myVector.push_back(15);

    std::cout << "El tamaño del vector es: " << myVector.size() << std::endl; // Imprime "El tamaño del vector es: 3"

    for (int i : myVector) // Itera a través de los elementos del vector
        std::cout << i << " ";
    std::cout << std::endl; // Imprime "5 10 15"

    myVector.pop_back(); // Elimina el último elemento del vector

    std::cout << "El tamaño del vector es: " << myVector.size() << std::endl; // Imprime "El tamaño del vector es: 2"

    return 0;
}
```

**Un vector es un contenedor de plantilla de C++ que almacena una secuencia de elementos del mismo tipo. En este ejemplo se declara un vector vacío de enteros y se agrega algunos elementos al final del vector utilizando la función push_back(). Luego se imprime el tamaño del vector y se itera a través de los elementos del vector utilizando un bucle for. Finalmente, se elimina el último elemento del vector utilizando la función pop_back().**

* **Deque**: Un contenedor doblemente terminado que permite inserción y eliminación de elementos tanto en el principio como en el final en tiempo constante.

```c++
#include <iostream>
#include <deque>

int main()
{
    std::deque<int> myDeque; // Declara un deque vacío

    myDeque.push_back(5); // Agrega un elemento al final del deque
    myDeque.push_front(10); // Agrega un elemento al inicio del deque
    myDeque.push_back(15);

    std::cout << "El tamaño del deque es: " << myDeque.size() << std::endl; // Imprime "El tamaño del deque es: 3"

    for (int i : myDeque) // Itera a través de los elementos del deque
        std::cout << i << " ";
    std::cout << std::endl; // Imprime "10 5 15"

    myDeque.pop_back(); // Elimina el último elemento del deque

    std::cout << "El tamaño del deque es: " << myDeque.size() << std::endl; // Imprime "El tamaño del deque es: 2"

    return 0;
}
```

**Un deque es un contenedor de plantilla de C++ que almacena una secuencia de elementos del mismo tipo. A diferencia de un vector, un deque permite agregar y eliminar elementos tanto al inicio como al final del contenedor. En este ejemplo se declara un deque vacío de enteros y se agrega algunos elementos tanto al inicio como al final del deque utilizando las funciones push_front() y push_back(). Luego se imprime el tamaño del deque y se itera a través de los elementos del deque utilizando un bucle for. Finalmente, se elimina el último elemento del deque utilizando la función pop_back().**

* **Array**: Un contenedor de tamaño fijo que proporciona acceso constante a sus elementos.

```c++
#include <iostream>
#include <array>

int main()
{
    std::array<int, 3> myArray = {5, 10, 15}; // Declara un array de tamaño 3 y lo inicializa

    std::cout << "El tamaño del array es: " << myArray.size() << std::endl; // Imprime "El tamaño del array es: 3"

    for (int i : myArray) // Itera a través de los elementos del array
        std::cout << i << " ";
    std::cout << std::endl; // Imprime "5 10 15"

    myArray[1] = 20; // Modifica un elemento en el array

    for (int i : myArray) // Itera a través de los elementos del array
        std::cout << i << " ";
    std::cout << std::endl; // Imprime "5 20 15"

    return 0;
}
```

**Un array es un contenedor de plantilla de C++ que almacena una secuencia fija de elementos del mismo tipo. A diferencia de un vector o un deque, el tamaño de un array es fijo y no puede ser cambiado durante la ejecución del programa. En este ejemplo se declara un array de tamaño 3 e inicializa los elementos con algunos valores. Luego se imprime el tamaño del array y se itera a través de los elementos del array utilizando un bucle for. Finalmente, se modifica un elemento en el array y se itera a través de los elementos del array de nuevo.**

* **List**: Un contenedor doblemente enlazado que permite inserción y eliminación de elementos en cualquier parte de la lista en tiempo constante. A diferencia de los vectores y deques, la lista no proporciona acceso constante a sus elementos, pero es muy útil cuando se necesita manipular elementos en cualquier parte de la secuencia.

```c++
#include <iostream>
#include <list>

int main()
{
    std::list<int> myList; // Declara una lista vacía

    myList.push_back(5); // Agrega un elemento al final de la lista
    myList.push_front(10); // Agrega un elemento al inicio de la lista
    myList.push_back(15);

    std::cout << "El tamaño de la lista es: " << myList.size() << std::endl; // Imprime "El tamaño de la lista es: 3"

    for (int i : myList) // Itera a través de los elementos de la lista
        std::cout << i << " ";
    std::cout << std::endl; // Imprime "10 5 15"

    myList.pop_back(); // Elimina el último elemento de la lista

    std::cout << "El tamaño de la lista es: " << myList.size() << std::endl; // Imprime "El tamaño de la lista es: 2"

    return 0;
}
```

**Una lista es un contenedor de plantilla de C++ que almacena una secuencia de elementos del mismo tipo. A diferencia de un vector o un deque, una lista está implementada como una lista doblemente enlazada, lo que significa que los elementos están conectados entre sí mediante punteros. Esto permite agregar y eliminar elementos tanto al inicio como al final de la lista con un tiempo de ejecución constante. En este ejemplo se declara una lista vacía de enteros y se agrega algunos elementos tanto al inicio como al final de la lista utilizando las funciones push_front() y push_back(). Luego se imprime el tamaño de la lista y se itera a través de los elementos de la lista utilizando un bucle for. Finalmente, se elimina el último elemento de la lista utilizando la función pop_back().**


# Associative Containers

Los contenedores asociativos son un tipo de contenedor en C++ que permiten almacenar pares clave-valor, en lugar de elementos simples. Los contenedores asociativos incluyen `map`, `unordered_map`, `set` y `unordered_set`. La clave se utiliza como un identificador para cada valor y permite acceder y buscar elementos de manera eficiente. Los contenedores asociativos están diseñados para tener un tiempo de búsqueda y acceso constante, lo que los hace ideales para aplicaciones en las que se requiere un acceso rápido a los elementos basados en una clave. Hay dos tipos principales de contenedores asociativos en C++: los que usan una tabla hash (`unordered_map` y `unordered_set`) y los que usan un árbol de búsqueda binaria (`map` y `set`).

* **map**: Un contenedor que almacena pares key-value en una estructura de árbol de búsqueda binaria, permitiendo un acceso eficiente y un ordenamiento basado en la clave.

```c++
#include <iostream>
#include <map>

int main() {
  // Crear un mapa que almacena valores enteros con claves de cadenas
  std::map<std::string, int> edades;

  // Agregar elementos al mapa
  edades["Juan"] = 30;
  edades["María"] = 25;
  edades["Pedro"] = 35;

  // Imprimir los elementos del mapa
  std::cout << "Edad de Juan: " << edades["Juan"] << std::endl;
  std::cout << "Edad de María: " << edades["María"] << std::endl;
  std::cout << "Edad de Pedro: " << edades["Pedro"] << std::endl;

  // Modificar un valor en el mapa
  edades["Juan"] = 31;

  // Imprimir el nuevo valor
  std::cout << "Nueva edad de Juan: " << edades["Juan"] << std::endl;

  return 0;
}
```

* **set**: Un contenedor que almacena claves únicas en una estructura de árbol de búsqueda binaria, permitiendo un acceso eficiente y un ordenamiento basado en la clave.

```c++
#include <iostream>
#include <set>

int main() {
  // Crear un conjunto de enteros
  std::set<int> numeros;

  // Agregar elementos al conjunto
  numeros.insert(5);
  numeros.insert(3);
  numeros.insert(7);

  // Verificar si un elemento está en el conjunto
  if (numeros.count(3)) {
    std::cout << "El número 3 está en el conjunto" << std::endl;
  }

  // Recorrer y mostrar los elementos del conjunto
  for (int numero : numeros) {
    std::cout << numero << " ";
  }
  std::cout << std::endl;

  return 0;
}

/*
El número 3 está en el conjunto
3 5 7
*/
```

* **unordered_map**: Un contenedor que almacena pares clave-valor en una tabla hash, permitiendo un acceso rápido basado en la clave sin un ordenamiento específico.

* **unordered_set**: Un contenedor que almacena claves únicas en una tabla hash, permitiendo un acceso rápido basado en la clave sin un ordenamiento específico.
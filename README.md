# C++
C++ es un lenguaje de programación de propósito general desarrollado por Bjarne Stroustrup en 1983.


# Punteros en C++

1. **¿Qué son los punteros en C++?**

Los punteros son variables especiales que almacenan la dirección de memoria de otra variable. Un puntero es una variable que contiene la dirección de memoria de otra variable en lugar de su valor.

2. **Declaración y asignación de punteros**

Para declarar un puntero, se utiliza el operador * antes del nombre de la variable. Por ejemplo, int *ptr; declara un puntero ptr al tipo int. Para asignar un valor a un puntero, se utiliza el operador & antes del nombre de la variable. Por ejemplo, ptr = &x; asigna la dirección de memoria de x a ptr.

3. **Uso de punteros**

Los punteros se utilizan comúnmente para:

* Acceder a los elementos de un array
* Pasar parámetros a funciones por referencia
* Crear y utilizar variables dinámicas
* Crear y utilizar punteros a clases

4. **Operadores de punteros**

* El operador * se utiliza para obtener el valor al que apunta un puntero.
* El operador & se utiliza para obtener la dirección de memoria de una variable.
* El operador -> se utiliza para acceder a los miembros de un objeto a través de un puntero al objeto.
* El operador [] se utiliza para acceder a los elementos de un array a través de un puntero al array.

5. **Ejemplo de uso de punteros**

```c++
#include <iostream>
int main(){
    int x = 5;
    int *ptr = &x;
    std::cout << *ptr; // imprime 5
    *ptr = 10;
    std::cout << x; // imprime 10
    return 0;
}
```
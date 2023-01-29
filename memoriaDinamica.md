# Memoria Dinamica en C++

La memoria dinámica en C++ se refiere a la asignación de memoria en tiempo de ejecución en lugar de en tiempo de compilación. Esto significa que el tamaño de la memoria asignada no está fijo y puede ser modificado durante la ejecución del programa.

**Formas en las que se puede utilizar la memoria dinámica en C++:**

* **new**: es un operador que se utiliza para asignar memoria dinámica. El espacio de memoria se reserva en el heap (pila) y se devuelve un puntero al primer byte de la memoria asignada. Ejemplo:

```c++
int *p = new int; // asigna memoria para un entero
```

* **delete**: es un operador que se utiliza para liberar la memoria asignada dinámicamente. El operador delete se utiliza con un puntero al espacio de memoria asignado dinámicamente para liberarlo. Ejemplo:

```c++
delete p; // libera la memoria asignada para el entero
```

* **new [] y delete []**: se utilizan para asignar y liberar memoria dinámica para arreglos. Ejemplo:

```c++
int *p = new int[10]; // asigna memoria para un arreglo de 10 enteros
delete[] p; // libera la memoria asignada para el arreglo de enteros
```

**Es importante tener en cuenta que si no se libera la memoria asignada dinámicamente, puede causar una pérdida de memoria (memory leak). Por lo tanto, es importante asegurarse de liberar la memoria una vez que ya no es necesaria.**
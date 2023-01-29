# Threads

<p align="center">
  <img src="hilo.png" />
</p>

Los hilos (threads) son una característica de C++ que permite ejecutar varios procesos de manera concurrente en un mismo programa. Esto significa que varios hilos pueden ejecutarse simultáneamente en un mismo proceso, lo que permite aprovechar al máximo el potencial de los procesadores multicore.

Para utilizar hilos en C++, primero debes incluir la biblioteca <thread>. Luego, puedes crear un objeto de la clase std::thread y pasarle una función o una expresión lambda como argumento. La función o expresión lambda será ejecutada en el hilo creado.

**Aquí tienes un ejemplo básico de como crear y ejecutar un hilo en C++:**

```c++
#include <iostream>
#include <thread>

void funcion_hilo() {
    cout << "Soy un hilo!" << endl;
}

int main() {
    std::thread hilo(funcion_hilo);
    hilo.join(); // Esperamos a que el hilo termine de ejecutarse antes de terminar el programa principal
    return 0;
}
```

Además de crear y ejecutar un hilo, también puedes esperar a que un hilo termine su ejecución usando el método `join()` o detenerlo temporalmente usando el método `detach()`.

**En C++ 11 también se introdujo el uso de variables compartidas entre hilos, para ello se utilizan las clases atomic y mutex.**

La clase `std::atomic` es una clase plantilla que permite crear variables compartidas entre hilos que son seguras en términos de acceso concurrente.

Mientras que la clase `std::mutex` es una clase que permite controlar el acceso a una sección crítica de código para evitar conflictos de acceso concurrente.
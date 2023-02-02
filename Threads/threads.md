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

## Mutex

Un **mutex** es un mecanismo de sincronización utilizado para controlar el acceso a un recurso compartido. Es esencialmente una variable booleana que puede ser adquirida (verdadera) o liberada (falsa). Una vez que un hilo adquiere el mutex, los demás hilos que intentan adquirirlo se bloquean hasta que el hilo que lo posee lo libere.

En **C++**, los **mutex** se pueden manejar mediante la clase `std::mutex` de la biblioteca estándar. Para adquirir un mutex, se utiliza el método `lock()` y para liberarlo, se utiliza el método `unlock()`. También se puede utilizar la clase `std::unique_lock` para manejar un mutex de manera más conveniente, ya que esta clase proporciona un mecanismo de bloqueo automático, lo que significa que el mutex se libera automáticamente cuando el objeto `std::unique_lock` se destruye.

**Es importante notar que los mutex son solo útiles para sincronizar el acceso a un recurso compartido entre diferentes hilos, no son necesarios para sincronizar el acceso a un recurso compartido dentro de un solo hilo.**

**Ejemplo de como utilizar un mutex en C++:**

```c++
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Declaramos un objeto mutex llamado "mtx"

void funcion1() {
    mtx.lock(); // Adquirimos el bloqueo del mutex
    std::cout << "Soy la función 1 y tengo el bloqueo del mutex" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Esperamos 1 segundo
    mtx.unlock(); // Liberamos el bloqueo del mutex
}

void funcion2() {
    mtx.lock(); // Adquirimos el bloqueo del mutex
    std::cout << "Soy la función 2 y también tengo el bloqueo del mutex" << std::endl;
    mtx.unlock(); // Liberamos el bloqueo del mutex
}

int main() {
    std::thread t1(funcion1); // Creamos un thread que ejecuta la función 1
    std::thread t2(funcion2); // Creamos otro thread que ejecuta la función 2

    t1.join(); // Esperamos a que el thread t1 termine
    t2.join(); // Esperamos a que el thread t2 termine

    return 0;
}
```

En este ejemplo, creamos dos funciones (`funcion1` y `funcion2`) que imprimen un mensaje en pantalla y adquieren y liberan el bloqueo del mutex "mtx" utilizando los métodos `lock()` y `unlock()`.

En el `main()` creamos dos threads (`t1` y `t2`) que ejecutan las funciones `funcion1` y `funcion2` respectivamente. Al ejecutarse en paralelo, los threads compiten por adquirir el bloqueo del mutex, y solo uno de ellos puede tenerlo en cualquier momento. El otro thread se "duerme" hasta que el bloqueo sea liberado.

**Nota**: El objeto `std::this_thread::sleep_for` es utilizado para simular una tarea que dura un tiempo determinado y no es necesario para el funcionamiento del Mutex.

## Atomic

Los objetos atomic son variables que garantizan la atomicitud de las operaciones que se realizan en ellas. Esto significa que, aunque varios hilos puedan acceder a una variable atómica al mismo tiempo, siempre se asegura que una operación completa en una variable atómica se realice de manera consistente, sin que los cambios realizados por un hilo se vean afectados por los cambios realizados por otro hilo.

En C++, la clase `std::atomic` proporciona una interfaz para trabajar con variables atómicas. Esta clase proporciona varios métodos para realizar operaciones atómicas en las variables, como `store`, `load`, `exchange` y `compare_exchange_weak`.

**Uso de una variable atómica en C++**

```c++
#include <iostream>
#include <atomic>
#include <thread>

// Declaramos una variable atomica con un valor inicial de 0
std::atomic<int> variable_atomica(0);

// Funcion que incrementa la variable atomica 10,000 veces
void incrementa_variable(){
    for(int i=0;i<10000;i++){
        // Incrementamos la variable atomica
        variable_atomica++;
    }
}

int main(){
    // Creamos dos hilos y los ejecutamos
    std::thread th1(incrementa_variable);
    std::thread th2(incrementa_variable);
    // Esperamos a que los hilos terminen
    th1.join();
    th2.join();
    // Imprimimos el valor final de la variable atomica
    std::cout<<variable_atomica<<std::endl;
    return 0;
}
```

En este ejemplo, creamos una **variable atómica** variable_atomica y dos hilos que incrementan su valor 10000 veces. Al usar una variable atómica, estamos seguros de que el resultado final será 20000, ya que las operaciones de incremento se realizan de manera atómica y no hay riesgo de que los cambios realizados por un hilo se vean afectados por los cambios realizados por otro hilo.

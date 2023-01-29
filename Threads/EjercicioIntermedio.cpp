/*
un programa en C++ que muestra el uso de hilos y la sincronización entre ellos:
*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex;
int contador = 0;

void incrementaContador() {
  for (int i = 0; i < 1000000; ++i) {
    std::lock_guard<std::mutex> lock(mutex);
    ++contador;
  }
}

int main() {
  std::thread hilo1(incrementaContador);
  std::thread hilo2(incrementaContador);
  hilo1.join();
  hilo2.join();
  std::cout << "El contador final es: " << contador << std::endl;
  return 0;
}

/*
En este ejemplo, se crean dos hilos que llaman a la función 
incrementaContador. La función usa un std::lock_guard para
 proteger el acceso a la variable compartida contador y evitar 
 conflictos de concurrencia. Una vez que ambos hilos han
  terminado de ejecutarse, se muestra el valor final de 
  la variable contador.
*/
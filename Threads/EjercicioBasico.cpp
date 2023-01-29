/*
Ejemplo básico de código C++ que muestra cómo crear y utilizar hilos:
*/

#include <iostream>
#include <thread>

void funcion_hilo() {
  std::cout << "Ejecutando hilo" << std::endl;
}

int main() {
  std::thread hilo(funcion_hilo);
    std::cout << std::endl;
  std::cout << "Ejecutando el hilo principal" << std::endl;
  std::cout << std::endl;
  hilo.join();
  return 0;
}

/*
En este ejemplo, se crea un hilo llamando a la función funcion_hilo y
 luego se espera a que el hilo termine con hilo.join().
*/
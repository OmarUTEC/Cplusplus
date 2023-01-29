/*
un programa en C++ que muestra el uso de hilos y 
la programación concurrente avanzada:
*/

#include <iostream>
#include <thread>
#include <future>

int funcionAsincrona(int x, int y) {
  return x + y;
}

int main() {
  std::future<int> resultado = std::async(funcionAsincrona, 10, 20);
  std::cout << "Calculando la suma en segundo plano..." << std::endl;
  std::cout << "El resultado es: " << resultado.get() << std::endl;
  return 0;
}

/*
En este ejemplo, se usa la función std::async para crear
 una tarea asíncrona que ejecuta la función funcionAsincrona
  en un hilo separado. La tarea devuelve un std::future que
  puede ser utilizado para obtener el resultado de la operación 
  una vez que esté disponible. La función resultado.get() se 
  utiliza para esperar el resultado y mostrarlo en pantalla.
*/
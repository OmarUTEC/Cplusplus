// Plantilla de clase en C++ que implementa una pila 

#include <iostream>
#include <vector>

// Declaración de la plantilla de clase Stack
template <typename T>
class Stack {
  private:
    // Vector de elementos de tipo T para almacenar los valores de la pila
    std::vector<T> items;

  public:
    // Función para agregar un elemento a la pila
    void push(T item) {
        items.push_back(item);
    }

    // Función para eliminar y devolver el elemento de la parte superior de la pila
    T pop() {
        // Verificar si la pila está vacía
        if (items.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        // Obtener el elemento de la parte superior de la pila
        T item = items.back();
        // Eliminar el elemento de la pila
        items.pop_back();
        // Devolver el elemento
        return item;
    }

    // Función para verificar si la pila está vacía
    bool empty() const {
        return items.empty();
    }

    // Función para obtener el tamaño de la pila
    int size() const {
        return items.size();
    }
};

int main(){
    // Crear un objeto de la clase Stack de enteros
    Stack<int> s;
    // Agregar elementos a la pila
    s.push(1);
    s.push(2);
    s.push(3);
    // Eliminar y mostrar el elemento de la parte superior de la pila
    std::cout << "Top item: " << s.pop() << std::endl;
    // Mostrar el tamaño de la pila
    std::cout << "Stack size: " << s.size() << std::endl;

    return 0;
}

// Ejemplos prácticos sobre el uso de punteros en C++


// 1. Ejemplo de acceso a los elementos de un array a través de un puntero:
# include <iostream>
int main(){

    int array[5] = {1, 2, 3, 4, 5};
    int *ptr = array;
    std::cout << *ptr;    // imprime 1
    std::cout << *(ptr+1);// imprime 2

    return 0;
}

// 2. Ejemplo de paso de parámetros a una función por referencia:
# include <iostream>
void increment(int *value) {
   (*value)++;
}
int main(){
    int x = 5;
    increment(&x);
    std::cout << x; // imprime 6
    return 0;
}

// 3. Ejemplo de creación y uso de variables dinámicas:
# include <iostream>
int main(){
    int *ptr = new int;
    *ptr = 5;
    std::cout << *ptr; // imprime 5
    delete ptr;
    return 0;
}

// 4. Ejemplo de creación y uso de punteros a clases:
# include <iostream>
class Example {
public:
   int value;
};
int main(){
    Example *object = new Example;
    object->value = 5;
    std::cout << object->value; // imprime 5
    delete object;
}
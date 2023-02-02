#include <iostream>
#include <vector>

int main()
{
    // Declarar un vector de enteros para almacenar los números ingresados por el usuario.
    std::vector<int> numbers;
    int input;
    // Solicitar al usuario que ingrese un número entero (0 para finalizar).
    std::cout << "Ingresa un número entero (0 para finalizar): ";
    std::cin >> input;

    // Leer y almacenar los números ingresados hasta que se ingrese el número 0.
    while (input != 0)
    {
        numbers.push_back(input);
        std::cout << "Ingresa un número entero (0 para finalizar): ";
        std::cin >> input;
    }

    // Sumar los números almacenados en el vector.
    int sum = 0;
    for (int num : numbers)
    {
        sum += num;
    }

    // Mostrar el resultado de la suma.
    std::cout << "La suma de los números ingresados es " << sum << std::endl;
    return 0;
}


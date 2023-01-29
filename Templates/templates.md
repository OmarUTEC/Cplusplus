# Templates

Los templates de C++ son una característica de la programación genérica que permite escribir código que puede trabajar con diferentes tipos de datos sin tener que escribir una versión separada para cada tipo. Aquí hay una guía completa sobre cómo usar los templates en C++:

**Características claves**

1. **Creación de un template**: Para crear un template, se debe agregar la palabra clave `template` seguida de los parámetros de tipo entre paréntesis angulares `<>`. Por ejemplo, aquí está una plantilla de función que intercambia dos valores:

```c++
template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
```

2. **Uso de un template**: Para usar una plantilla, simplemente llame a la función o clase proporcionando los tipos de datos específicos entre paréntesis angulares. Por ejemplo:

```c++
int x = 5, y = 10;
swap<int>(x, y);
```

3. **Parámetros de tipo**: Los templates pueden tener uno o más parámetros de tipo, que se especifican entre paréntesis angulares. Por ejemplo:

```c++
template <typename T, typename U>
U max(T a, U b) {
  return (a > b) ? a : b;
}
```

4. **Parámetros de clase**: Además de los parámetros de tipo, los templates de clases pueden tener parámetros de clase, que se especifican después de los paréntesis de la clase. Por ejemplo:

```c++
template <typename T, int N>
class Vector {
  T data[N];
  // ...
};
```

5. **Sobrecarga de templates**: Es posible sobrecargar una plantilla para admitir diferentes números o tipos de parámetros. Por ejemplo:

```c++
template <typename T>
T sum(T a, T b) {
  // Devuelve la suma de dos argumentos de tipo T
  return a + b;
}

template <typename T, typename U>
auto sum(T a, U b) -> decltype(a + b) {
  // Devuelve la suma de dos argumentos de tipos diferentes T y U
  // La keyword "decltype" se usa para determinar el tipo de retorno
  // que es el resultado de la operación de suma de los argumentos de tipos diferentes T y U
  return a + b;
}
```
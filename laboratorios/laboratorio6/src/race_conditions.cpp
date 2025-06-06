/*
Ejemplos de race conditions en memoria compartida
*/

#include <iostream>
#include <thread>
#include <vector>

int counter = 0;

void increment() {
    /*
    Si múltiples hilos ejecutan este bucle simultáneamente, pueden leer el mismo valor
    de counter antes de que se actualice, resultando en un conteo incorrecto.
    */
    for (int i = 0; i < 1000; ++i) {
        ++counter; // Incremento no atómico
    }
}

std::vector<int> myList;

void push1() {
    // Hilo 1
    myList.push_back(1);
}

void push2() {
    // Hilo 2
    myList.push_back(2);
}

int main() {
    std::thread t1(increment), t2(increment);
    t1.join(); t2.join();

    std::cout << "Valor del contador (esperado: 2000): " << counter << "\n";

    std::thread t3(push1), t4(push2);
    t3.join(); t4.join();

    std::cout << "Tamaño de myList: " << myList.size() << "\n";

    return 0;
}

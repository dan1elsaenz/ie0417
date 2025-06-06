#include <iostream>
#include <mutex> // Biblioteca para uso de mutex
#include <thread>
#include <vector>

std::mutex mtx; // Declaración de mutex

// Función que realiza un incremento seguro para un contador en memoria compartida
void safeIncrement(int &counter) {
    std::lock_guard<std::mutex> lock(mtx);
    ++counter; // Ningún otro hilo modifica el contador

    // mtx se libera automáticamente cuando lock sale del ámbito
}

int main() {
    int counter = 0;
    std::vector<std::thread> threads;
    for (int i = 0; i < 100; ++i) {
        threads.emplace_back(safeIncrement, std::ref(counter));
    }
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Contador final: " << counter << "\n";
    return 0;
}

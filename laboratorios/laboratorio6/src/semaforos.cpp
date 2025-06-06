#include <iostream>
#include <semaphore> // Biblioteca para uso de semáforos
#include <thread>
#include <vector>

// Semáforo binario (similar a un mutex)
std::counting_semaphore<1> sem(1); // Si se coloca otro número, permite que esa cantidad de hilos accedan al espacio

// Función para acceder a recurso compartido
void accessResource(int id) {
    sem.acquire(); // Decrementa el contador y bloquea si el contador es cero
    // Sección crítica de ejemplo
    std::cout << "Hilo " << id << " accede al recurso\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "Hilo " << id << " libera el recurso\n";
    sem.release(); // Incrementa el contador y desbloquea a un hilo
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(accessResource, i);
    }
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}

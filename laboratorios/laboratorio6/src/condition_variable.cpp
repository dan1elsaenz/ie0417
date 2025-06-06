#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex mtx; // Declaración de mutex
std::condition_variable cv; // Declaración de condition_variable
bool ready = false; // Declaración de variable para notificar

// Función que pone hilo en espera
void waitingThread() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return ready; }); // Espera hasta que ready sea true
    // Continuar ejecución
    std::cout << "Hilo notificado, continúa ejecución\n";
}

// Función que notifica a un hilo que se cumplió la condición
void notifyingThread() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simula trabajo
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one(); // Notifica a uno de los hilos en espera
    std::cout << "Notificación enviada\n";
}

int main() {
    std::thread t1(waitingThread);
    std::thread t2(notifyingThread);

    t1.join();
    t2.join();
    return 0;
}


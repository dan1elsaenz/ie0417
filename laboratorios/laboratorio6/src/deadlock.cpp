#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

/*
Explicación: 
- Hilo A adquiere el recurso 1, espera por el recurso 2
- Hilo B adquiere el recurso 2, espera por el recurso 1
- Ninguno puede avanzar porque dependen de recursos entre sí
*/

std::mutex mtx1, mtx2;

void threadA() {
    std::lock_guard<std::mutex> lock1(mtx1); // Recurso 1
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(mtx2); // Recurso 2 forma parte de B
    std::cout << "Hilo A finalizó\n";
}

void threadB() {
    std::lock_guard<std::mutex> lock2(mtx2); // Recurso 2
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock1(mtx1); // Recurso 1 forma parte de 1
    std::cout << "Hilo B finalizó\n";
}

int main() {
    std::thread t1(threadA);
    std::thread t2(threadB);

    t1.join();
    t2.join();

    return 0;
}

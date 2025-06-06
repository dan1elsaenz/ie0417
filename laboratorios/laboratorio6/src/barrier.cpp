#include <iostream>
#include <barrier>
#include <thread>

std::barrier sync_point(5); // Barrera para 5 hilos


std::mutex print_mutex; // Mutex para la impresión ordenada de los hilos en threadFunction

void threadFunction(int id) {
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout << "Hilo " << id << " antes de la barrera\n";
    }
    sync_point.arrive_and_wait();
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout << "Hilo " << id << " después de la barrera\n";
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(threadFunction, i);
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}

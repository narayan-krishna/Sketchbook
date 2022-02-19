#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <condition_variable>
#include <string>

void print_string(std::string input, int *sp, 
                  std::condition_variable* conditions,
                  int condition_number, int to_signal) {
    std::mutex m;
    for (int i = 0; i < 10; i ++) {
        std::unique_lock<std::mutex> mutex_lock(m);
        conditions[condition_number].wait(mutex_lock, 
                    [&] { return *sp == condition_number; });
        std::cout << input << std::endl;
        sleep(1);
        *sp = to_signal;
        conditions[to_signal].notify_one();
        mutex_lock.unlock();
    }
}

int main () {
    int signal = 0;
    int *sp = &signal;

    std::condition_variable *conditions = new std::condition_variable[2];

    std::thread marco_thread(print_string, "marco", sp, conditions, 0, 1); 
    std::thread polo_thread(print_string, "polo", sp, conditions, 1, 0); 

    marco_thread.join();
    polo_thread.join();

    std::cout << "\nc++ version: " << __cplusplus << "\n" << std::endl;

    return 0;
}
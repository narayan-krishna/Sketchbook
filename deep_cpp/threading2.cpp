#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <condition_variable>
#include <string>

void print_string(std::string input, bool* signal, 
                    std::condition_variable* cvs, bool id) {

    std::mutex m;
    for (int i = 0; i < 10; i ++) {
        // std::unique_lock<std::mutex> mutex_lock(m);
        // cvs[id].wait(mutex_lock, [&]{ return *signal == id; });
        std::cout << input << std::endl;
        sleep(1);
        // *signal = !(*signal);
        // cvs[*signal].notify_one();
        // mutex_lock.unlock();
    }
}

void handle_io (std::string val) {
    // while () {

    // }
}

int main () {

    bool signal = 0;
    bool *signal_p = &signal;

    std::condition_variable *cv = new std::condition_variable[2];

    std::thread marco_thread(print_string, "marco", signal_p, cv, 0);
    std::thread polo_thread(print_string, "polo", signal_p, cv, 1);

    // try {

    // } catch () {
    //     marco_thread.join();
    //     polo_thread.join();
    // }

    marco_thread.join();
    polo_thread.join();


    std::cout << "\nc++ version: " << __cplusplus << "\n" << std::endl;

    return 0;
}
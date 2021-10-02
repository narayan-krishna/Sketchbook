#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

constexpr size_t num_threads = 2;
constexpr size_t loop = 6;

/*make an extra mutex for main*/
std::mutex mutex[num_threads + 2]; 
std::condition_variable condition[2];
std::vector<int> evolve(num_threads, 0); /*when this is full, all threads have completed task*/
                  /*when this is 0 none of them have*/
                  /*wait till this is full before going to main*/
// int sum = 0;
void print() {
    for(auto &n : evolve) {
        std::cout << n;
    }
    std::cout << std::endl;
}


// int sum = 0;

void do_work(const size_t rank) {
    for(size_t  i = 0; i < loop; i++) {
        std::unique_lock<std::mutex> mutex_lock(mutex[rank]);
        condition[1].wait(mutex_lock, [rank]{return (evolve[rank] == 0);});

        std::cout << "Thread " << rank << " is processing" << std::endl;
        // {
        //     const std::lock_guard<std::mutex> lck_grd(mutex[num_threads+1]);
        //     sum ++;
        // }
        evolve[rank] = 1;

        condition[0].notify_one();
        mutex_lock.unlock();
    }
    // std::cout << "Thread " << rank << " is exiting" << std::endl;
}

bool sum_checker(){
    int sum = 0;
    for(auto &n : evolve) {
        sum += n;
    }
    return (sum == num_threads);
}

int main(){
    std::thread threads[num_threads];

    for (size_t i = 0; i < num_threads; i++) {
        threads[i] = std::thread(do_work, i);
    }

    // std::cout << "begin processing here" << std::endl;
    // std::thread thread_one = std::thread(do_work, 0);
    for(size_t k = 0; k < loop; k++) {
        std::unique_lock<std::mutex> mutex_lock(mutex[num_threads]);
        condition[0].wait(mutex_lock, [&]{return sum_checker();});
        
        std::cout << "main processing" << std::endl;
        std::fill(evolve.begin(), 
            evolve.end(), 0);
        // sum = 0; 
        condition[1].notify_all();
        mutex_lock.unlock();
    }
    
    std::cout << "main exiting" << std::endl;
    
    // thread_one.join();

    for (size_t i = 0; i < num_threads; ++i) {
        threads[i].join();    
    }
    return 0;
}







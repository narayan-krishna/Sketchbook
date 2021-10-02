#include <iostream>
#include <math.h>
#include <vector>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

#define THREAD_COUNT 15 
#define TIME_FRAME 16

class Task {
private:
int work_array[10][10];

void init_array(){
    for(int i = 0; i < 10; i ++) {
        for(int j = 0; j < 10; j ++) {
            work_array[i][j] = 1;
        }
    }
}

int do_work(int count) {
    int product = 0;
    for (int c = 0; c < count; c++) {
        for(int g = 0; g < 5; g++) {
            for(int i = 0 ; i < 10; i ++) {
                product *= work_array[i][g]; 
            }

            for(int j = 0; j < 10; j ++) {
                product *= work_array[j][g+5]; 
            }
        }
    }
    return product;
}

public:
int rank;
int period;
int scheduler_time_step;

Task(int p, int r) {
    period = p;
    rank = r;
    start();
}

~Task(){}

bool start() {
    // do_work(period);
    temp();
    return true;
}

void temp() {
    cout << "rank " << rank << " has arrived" << endl;
}

};


class RMS {

public:

struct ThreadTask{
    int period;
    mutex *m;
    thread *t;
};

vector<ThreadTask> thread_tasks;

int current_time_step = 0;
mutex *main_m;
condition_variable main_cv;

condition_variable thread_cv;

RMS() {
    main_m = new mutex;
    add_thread_tasks();
    schedule_thread_tasks();
    join_threads();
}

~RMS() {
    for(auto &task : thread_tasks) {
        delete task.m;
        delete task.t;
        cout << "task thread deleted" << endl;
    }
    thread_tasks.resize(0);

    delete main_m;
    cout << "main tools deleted" << endl;
}

void add_thread_tasks() {
    for(int i = 0; i < THREAD_COUNT; i++) {
        int period = pow(2, i);
        thread_tasks.push_back(
            {   
                period,
                new mutex,
                new thread([&, i, period](){ 
                    unique_lock<mutex> m_lock(*thread_tasks[i].m);
                    thread_cv.wait(m_lock, [&] { 
                        return (current_time_step == i + 1); 
                    });

                    cout << i + 1 << " processing" << endl;
                    m_lock.unlock();
                })
            }
        );
    } 
}

void schedule_thread_tasks() {
    for(int time = 0; time < TIME_FRAME; time ++){
        current_time_step++;
        cout << current_time_step << "s" << endl;
        thread_cv.notify_all();
        sleep(1);
    }
}

void join_threads() { 
    for(size_t k = 0; k < THREAD_COUNT; ++k) {
        thread& t = *(thread_tasks[k].t);
        t.join();
    }
}

};


int main(){
    RMS();
    return 0;
}


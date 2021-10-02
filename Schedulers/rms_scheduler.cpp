#include <iostream>
#include <vector>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

#define THREAD_COUNT 4
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
    cout << "rank " << rank << ": ready!" << endl;
}

};


class RMS {

public:

struct ThreadTask{
    int period;
    condition_variable *cv;
    mutex *m;
    thread *t;
};

vector<ThreadTask> thread_tasks;

int current_time_step = 0;
mutex *main_m;
condition_variable *main_cv;

RMS() {
    main_m = new mutex;
    main_cv = new condition_variable;
    schedule_thread_tasks();
}

~RMS() {
    for(auto &task : thread_tasks) {
        delete task.m;
        delete task.cv;
        delete task.t;
        cout << "task thread deleted" << endl;
    }
    thread_tasks.resize(0);

    delete main_m;
    delete main_cv;
    cout << "main tools deleted" << endl;
}

void add_thread_tasks() {
    for(int i = 0; i < THREAD_COUNT; i++) {
        int period;
        cout << "enter period" << endl;
        cin >> period; 
        thread_tasks.push_back(
            {   
                period,
                new condition_variable,
                new mutex,
                new thread([i, period](){ 
                    Task t(i, period); 
                })
            }
        );
    } 
}

void schedule_thread_tasks() {
    for(int time = 0; time < TIME_FRAME; time ++){
        cout << "tick" << endl;
        usleep(1);
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


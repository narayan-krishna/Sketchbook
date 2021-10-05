#include <iostream>
#include <math.h>
#include <vector>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

using namespace std;

#define THREAD_COUNT 4 
#define TIME_FRAME 16

vector<vector<int>> work_array(10, vector<int> (10));

class Task {
private:
int work_array2[10][10];

void init_array(){
    for(int i = 0; i < 10; i ++) {
        for(int j = 0; j < 10; j ++) {
            work_array[i][j] = 1;
        }
    }
}

int do_work(int count) {
    int product = 1;
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
vector<vector<int>> work_array;

Task(int p, int r, vector<vector<int>> &in_vec) {
    period = p;
    rank = r;
    work_array = in_vec;
    do_work(period*100);
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
    int runs;
    int missed_deadlines;
    mutex *m;
    thread *t;
};

vector<ThreadTask> thread_tasks;

int current_time_step = 1;

condition_variable thread_cv;
condition_variable main_cv;

mutex *shared_lock;
mutex *main_m;

vector<int> task_signaler;
queue<int> task_queue;

int scheduler_signal = 1;

RMS() {
    main_m = new mutex;
    add_thread_tasks();
    schedule_thread_tasks2();
}

~RMS() {
    for(auto &task : thread_tasks) {
        delete task.m;
        delete task.t;
        cout << "task thread deleted" << endl;
    }
    thread_tasks.resize(0);

    delete main_m;
    delete shared_lock;
    cout << "main tools deleted" << endl;
}

// void clock() {
//     thread* clock_thread = new thread([]{
//     for(int time = 0; time <= 10; time ++) {
//         current_time_step ++;
//         cout << "--------" << current_time_step << "s" << "--------" <<  endl;
//         sleep(1);
//     });
//     delete clock_thread;
// }

/* the scheduler does the work */
void schedule_thread_tasks() {
    while(current_time_step < 16) {
        unique_lock<mutex> main_lock(*main_m);
        main_cv.wait(main_lock, [&]{ return (scheduler_signal == 1); });
        cout << "------------" << endl;
        for (int i = 0; i < task_signaler.size(); i ++) {
            if ((current_time_step % thread_tasks[i].period) == 0) {
                task_signaler[i] = 1;
                task_queue.push(i);
            }
        }
        scheduler_signal = 0;
        thread_cv.notify_all();
        main_lock.unlock();
        current_time_step++;
        // cout << "current step: " << current_time_step << endl;
    }
    cout << "main done" << endl;
    
    for(size_t k = 0; k < THREAD_COUNT; ++k) {
        thread& t = *(thread_tasks[k].t);
        t.join();
    }

}

//- - - - 
//1 0 <-- this doesn't get unlcoed until last one isok

void schedule_thread_tasks2() {
    while(current_time_step < 16) {
        cout << "---------------------" << endl;
        for (int i = 0; i < task_signaler.size(); i ++) {
            unique_lock<mutex> main_lock(*main_m);
            main_cv.wait(main_lock, [&]{
                return (i == 0 || task_signaler[i-1] == 0); 
            });
            if ((current_time_step % thread_tasks[i].period) == 0) {
                task_signaler[i] = 1;
            }
            thread_cv.notify_all();
            main_lock.unlock();
        }
        current_time_step++;
    }
    cout << "main done" << endl;
    
    for(size_t k = 0; k < THREAD_COUNT; ++k) {
        thread& t = *(thread_tasks[k].t);
        t.join();
    }

}


void add_thread_tasks() {
    for(int i = 0; i < THREAD_COUNT; i++) {
        int period = pow(2, i);
        thread_tasks.push_back(
            {   
                period, 0, 0,
                new mutex,
                new thread([&, i, period] { 
                    while(current_time_step < 10) {
                        unique_lock<mutex> m_lock(*thread_tasks[i].m);
                        thread_cv.wait(m_lock, [&] { 
                            return (task_signaler[i] == 1); 
                        });
                        
                        cout << i + 1 << " processing" << endl;
                        // sleep(1);
                        // Task t(period, i, work_array);

                        // thread_tasks.runs += 1;
                        task_signaler[i] = 0;
                        main_cv.notify_one();
                        m_lock.unlock();
                    }
                    // cout << i << "finished" << endl;
                })
            }
        );
        task_signaler.push_back(0);
    } 
}


};


int main(){
    // int work_array[10][10];

    for(int i = 0; i < 10; i ++) {
        for(int j = 0; j < 10; j ++) {
            work_array[i][j] = 1;
        }
    }


    RMS();
    return 0;
}


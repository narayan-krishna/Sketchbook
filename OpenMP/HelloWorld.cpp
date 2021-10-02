#include <iostream>
#include <thread>
#include <omp.h>
#include <vector>
#include "k_timers.h"

using namespace std;
using namespace k_timers; 

int sleep(){
    timer_ms t = timer_ms();
    t.start();
    std::this_thread::sleep_for(chrono::seconds(2));
    t.stop();
    t.elapsed();
    return 0;
}

void print_stuff() {
    #pragma omp parallel num_threads(4)
    {
        int rank = omp_get_thread_num();
        int threads = omp_get_num_threads();
        cout << "Hello world -" << rank << "of" << threads <<endl;
        #pragma omp for
        for(int i = 0; i < 3; i++) {
            cout << i << endl;
        }
    }
}

template <class my_type>
void print_vec(vector<my_type> &v) {
    for(auto &n : v) {
        cout << n << " ";
    }
    cout << endl;
}

int add_vectors(vector<int> &x, vector<int> &y, vector<int> &z) {
    for(int i = 0; i < x.size(); ++i) {
        z[i] = x[i] + y[i];
    }
    return 0;
}

int add_vectors_ll(vector<int> &x, vector<int> &y, vector<int> &z) {
    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < x.size(); ++i) {
            z[i] = x[i] + y[i];
        }
    }
    return 0;
}


int main(){
    int n = 10;
    timer_ms t = timer_ms();
    vector<vector<int>> collection(3);
    for(int i = 0; i < n; i ++) {
        collection[0].push_back(i);
        collection[1].push_back(n - i);
        collection[2].push_back(0);
    }

    // print_vec(collection[0]);
    // print_vec(collection[1]);
                    
    t.start();
    add_vectors_ll(collection[0],
                collection[1],
                collection[2]); 

    t.stop();
    t.elapsed();
    print_vec(collection[2]);
    
    return 0;
}
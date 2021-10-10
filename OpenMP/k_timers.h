#pragma once
#include <iostream>
#include <chrono>

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration;
using chrono::milliseconds;

namespace k_timers
{
    class timer_ms{

    high_resolution_clock::time_point t1, t2; 
    duration <double, milli>  t_elapsed;
    public:
        timer_ms(){};
        ~timer_ms(){ cout << "deleted" << endl; };

        void start() { t1 = high_resolution_clock::now(); }
        void stop() { t2 = high_resolution_clock::now(); }

        void elapsed() {
            t_elapsed = t2 - t1;   
            cout << t_elapsed.count() << " ms" << endl;  
        }
    };

    // class timer_s{
    
    // public:
        
    // };
}

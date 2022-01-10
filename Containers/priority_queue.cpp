#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct person {
    string name;
    int priority;
};

class PriorityQueue {
    private:
        vector<person>priority_queue;
        void push_up(int index);
        void push_down(int index);
        void swap(int i, int j);

    public:
        PriorityQueue();
        person extract_max();
        person get_max();
        void insert(person p);
        void print();
};

PriorityQueue::PriorityQueue() {
    priority_queue.push_back(person {"", -1});
}

void PriorityQueue::swap(int i, int j) { 
    person temp = priority_queue[i]; 
    priority_queue[i] = priority_queue[j];
    priority_queue[j] = temp;
}

void PriorityQueue::push_up(int i) {
    if (i == 1) {
        return;
    }

    int current_prio = priority_queue[i].priority;
    int above_prio = priority_queue[i/2].priority;
    if (above_prio != -1 && current_prio > above_prio) {
        swap(i, i/2);
        push_up(i/2);
    }

    return;
}

void PriorityQueue::push_down(int i) {
    if (i*2 >= priority_queue.size()) {
        return;
    }

    int current_prio = priority_queue[i].priority;
    int below_prio = priority_queue[i*2].priority > priority_queue[i*2 + 1].priority ? 
                        i*2 : i*2 + 1;

    if (priority_queue[below_prio].priority > current_prio) {
        swap(i, below_prio);
        push_down(below_prio);
    }

    return;
}

person PriorityQueue::extract_max() {
    person max = priority_queue[1];
    swap(1, priority_queue.size() - 1);
    priority_queue.resize(priority_queue.size() - 1);
    push_down(1);
    return max;
}

person PriorityQueue::get_max() {
    return priority_queue[1];
}

void PriorityQueue::insert(person p) {
    priority_queue.push_back(p);
    // cout << priority_queue.size() << endl;
    push_up(priority_queue.size() - 1);
}

void PriorityQueue::print() {
    for (int i = 1; i < priority_queue.size(); i ++) {
        cout << "priority: " << priority_queue[i].priority << endl;
    }
    cout << endl;
}

int main () {

    PriorityQueue p = PriorityQueue();
    p.insert(person {"bob", 3});
    p.insert(person {"bob", 3});
    p.insert(person {"bob", 4});
    p.insert(person {"bob", 5});
    p.insert(person {"bob", 3});
    p.insert(person {"bob", 7});
    p.insert(person {"bob", 2});
    p.insert(person {"bob", 4});

    cout << p.extract_max().priority << endl;
    p.print();

    p.insert(person {"bob", 6});
    p.insert(person {"bob", 2});
    p.insert(person {"bob", 4});

    cout << p.extract_max().priority << endl;
    p.print();

    return 0;
}
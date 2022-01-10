#include <iostream>
#include <vector>

using namespace std;

class HashMap {
    private:
        char *data;
        int M;
        int hash(int key);

    public:
        HashMap(int size);
        ~HashMap();
        void insert(int key, char value);
        void remove(int key);
        char get_value(int key);
        void print_values();
};

HashMap::HashMap(int size) {
    M = size;
    data = new char[M];    
}

HashMap::~HashMap() {
    delete data;
}

int HashMap::hash(int key) {
    return key%M;
}

void HashMap::insert(int key, char value) {
    data[hash(key)] = value;
}

char HashMap::get_value(int key) {
    return data[hash(key)];
}

void HashMap::print_values() {
    for (int  i = 0; i < M; i ++) {
        cout << data[i] << " ";
    } cout << endl;
}

int main () {
    HashMap h(19);
    vector<int> keys{23,21,91,32,7};

    h.insert(23, 'a');
    h.insert(21, 'e');
    h.insert(91, 'c');
    h.insert(32, 'b');
    h.insert(7, 'd');

    h.print_values();

    for (auto i : keys) {
        cout << h.get_value(i) << endl;
    }

    return 0;
}
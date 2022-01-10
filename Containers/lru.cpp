#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

/**
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
        Otherwise, add the key-value pair to the cache. 
        If the number of keys exceeds the capacity from this operation, evict the least recently used key.
*/

//check if something exists in the cache using a map
//constant deletion using a linked list -- we can use map to store positions in linked list

//the map holds the key and the location of the value in the list

class LRUCache {
    private:
        int capacity;
        unordered_map<int, list<int>::iterator> m;
        list<int> l;
        void evict_lru(int key);
        void update(int key);

    public:
        LRUCache(int capacity);
        int get(int key);
        void put(int key, int value);
        void print();
};

void LRUCache::evict_lru(int key) { 
    int value = l.back();
    l.pop_back();
    m.erase(key);
}

void LRUCache::update(int key) { 
    l.erase(m[key]);
    l.push_front(key);
    m[key] = l.begin();
}

LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
}

int LRUCache::get(int key) {
    auto i = m.find(key);
    if(i != m.end()) {
        update(key);
        return (*(i->second));
    }

    return -1;
}

void LRUCache::put(int key, int value) {
    if (m.size() == capacity) {
        evict_lru(key);
    }

    //insert into list
    //insert key + iterator here
    l.push_front(value);
    m.insert({key, l.begin()});
}

void LRUCache::print() {
    for(auto i : l) {
        cout << i << " ";
    }
    cout << endl;
}

int main () {
    LRUCache* cache = new LRUCache(2);
    cache->print();
    cache->put(3, 4);
    cache->put(4, 6);
    cache->get(3);
    cache->print();
    cache->put(8, 2);
    cache->print();
    cache->put(1, 9);
    cache->put(1, 9);
    return 0;
}

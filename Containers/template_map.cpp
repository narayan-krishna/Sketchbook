#include <iostream>
#include <vector>

using namespace std;

template <class K, class V>
class HashMap {
    private:
        vector<pair<K,V>> kv_pairs;
        int hash(K key);

    public:
        HashMap(int size);
        void insert(K key, V value);
        pair<K,V> find(K key);
        void remove(K key);
};

template <class K, class V>
HashMap<K, V>::HashMap(int size) {
    kv_pairs.resize(size);
}

template<class K, class V>
int HashMap<K,V>::hash(K key) {
    return key%kv_pairs.size();
}

template<class K, class V>
void HashMap<K,V>::insert(K key, V value) {
    kv_pairs[hash(key)].first = key;
    kv_pairs[hash(key)].second = value;
}

template<class K, class V>
pair<K,V> HashMap<K,V>::find(K key) {
    return kv_pairs[hash(key)];
}

template<class K, class V>
void HashMap<K,V>::remove(K key) {
    kv_pairs.erase(hash(key));
}

int main () {
    HashMap<int, char> h(19);
    h.insert(3, 'c');
    h.insert(93, 'a');

    cout << h.find(3).second << endl;

    return 0;
}
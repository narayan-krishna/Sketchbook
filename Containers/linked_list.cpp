#include <iostream>

using namespace std;

typedef int index;

struct sll_node {
    int data;
    sll_node* next = nullptr;
};

class SinglyLinkedList {
    private:
        sll_node *head;
        sll_node *tail;

    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        void push_front(int data);
        void insert(int data, index i);
        void remove(index i);
        int get(index i);
        void print();
};

SinglyLinkedList::SinglyLinkedList() {
    head = new sll_node;
    head->next = tail;
    tail = new sll_node;
}

SinglyLinkedList::~SinglyLinkedList() {
}


void SinglyLinkedList::enqueue(int data) {
    sll_node *n = new sll_node;
    n->data = data; 
    n->next = head->next;
    head->next = n;
}

void SinglyLinkedList::dequeue

// void SinglyLinkedList::insert(int data, index i) {

//     sll_node *curr = head;
//     index k = 0;
//     while(curr->next != nullptr || k == i) {
//         curr = curr->next;
//         k++;
//     }

//     sll_node *n;
//     n->data = data; 
//     n->next = curr->next;
//     curr->next = n;
// }

void SinglyLinkedList::print() {
    sll_node *curr = head->next;
    while(true) {
        cout << curr->data << " ";

        if (curr->next == nullptr) {
            break;
        }
        curr = curr->next;
    }
    cout << endl;
}

int main () {
    SinglyLinkedList* sll = new SinglyLinkedList();
    sll->push_front(10);
    sll->push_front(20);
    sll->push_front(30);
    sll->push_front(40);
    sll->print();
    return 0;
}
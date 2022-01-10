#include <iostream>

using namespace std;

typedef int index;

struct sll_node {
    int data;
    sll_node* next;
};

class SinglyLinkedList {
    private:
        sll_node *head;

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
    head->next = nullptr;
    head->data = 1;
}

SinglyLinkedList::~SinglyLinkedList() {

}


void SinglyLinkedList::push_front(int data) {
    sll_node *n = new sll_node;
    n->data = data; 
    n->next = head->next;
    head->next = n;
}

void SinglyLinkedList::insert(int data, index i) {

    sll_node *curr = head;
    index k = 0;
    while(curr->next != nullptr || k == i) {
        curr = curr->next;
        k++;
    }

    sll_node *n;
    n->data = data; 
    n->next = curr->next;
    curr->next = n;
}

void SinglyLinkedList::print() {
    sll_node *curr = head;
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
    sll->print();
    return 0;
}
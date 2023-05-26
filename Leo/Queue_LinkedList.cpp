#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class Queue {
    public:
        Queue();
        void push(int data);
        int pop();
        int display();
        int capacity;
    private:
        Node *head;
        Node *tail;
};


Queue::Queue(){
    head = NULL;
    tail = NULL;
    capacity = 100;
};

void Queue::push(int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    
    if (head == NULL) {
        new_node->prev = NULL;
    } else {
        new_node->prev = head;
    }
    head = new_node;
};

int Queue::pop() {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        int redata = head->data;
        head = head->prev;
        head->next = NULL;
        return redata;
    }
    return -1;
};

int Queue::display(){
    cout << "The top element is: ";
    return head->data;
};

int main(){
    Queue s = Queue();
    s.push(2);
    s.push(5);
    s.push(15);
    s.push(25);
    s.push(35);
    cout << s.display() << endl ;
    cout << s.pop() << endl;
    cout << s.display() << endl ;
    return 0;
}
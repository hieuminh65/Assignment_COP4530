#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
};

class Stack {
    public:
        Stack();
        void push(int data);
        int pop();
        int display();
        int capacity;
    private:
        Node *head;
};


Stack::Stack(){
    head = NULL;
};

void Stack::push(int data){
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

int Stack::pop() {
    if (head == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        int redata = head->data;
        head = head->prev;
        head->next = NULL;
        return redata;
    }
    return -1;
};

int Stack::display(){
    cout << "The top element is: ";
    return head->data;
};

int main(){
    Stack s = Stack();
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
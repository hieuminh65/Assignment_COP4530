#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
    public:
        char data;
        Node *next;
        Node *prev;
};

class Stack {
    public:
        Stack();
        void push(char data);
        char pop();
        char display();
        int capacity;
    private:
        Node *head;
};


Stack::Stack(){
    head = NULL;
    capacity = 100;
};

void Stack::push(char data){
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

char Stack::pop() {
    if (head == NULL) {
        cout << "Stack is empty" << endl;
        return '\0';
    } else {
        char redata = head->data;
        head = head->prev;
        if (head != NULL){
            head->next = NULL;
            return redata;
        } else {
            return '\0';
        }
    }
};

char Stack::display(){
    if (head == NULL) {
        return '\0';
    }
    return head->data;
};

int TestStack(string string_test){
    Stack s = Stack();
    for (int i = 0; i < string_test.length(); i++){
        if (string_test[i] == '(' || string_test[i] == '{' || string_test[i] == '[') {
            s.push(string_test[i]);
        } 
        else if (string_test[i] == ')' || string_test[i] == ']' || string_test[i] == '}'){
            if ((string_test[i] == ')') && s.display() != '(') {
                return -1;
            }
            else if ((string_test[i] == ']') && (s.display() != '[')) {
                return -1;
            }
            else if ((string_test[i] == '}') && (s.display() != '{')) {
                cout << "error here" << endl;
                return -1;
            }
            else {
                s.pop();
            }
        }
    }
    return 1;
}
    


int main(){
    // Stack s = Stack();
    // s.push(')');
    // s.push('(');
    // s.push(')');
    // s.push('{');
    // s.push('}');
    // cout << s.display() << endl ;
    // cout << s.pop() << endl;
    // cout << s.display() << endl ;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // 5 test cases
    string string_test1 = "12*3{2(()[])}2";    // * True
    string string_test2 = "1[s}3{2)}2)";  // * False
    string string_test3 = ""; // * True
    string string_test4 = "{[()]}(())"; // * True
    string string_test5 = "((([]{{{}}})))()()()(())({[[[]]]})"; // * True
    cout << TestStack(string_test3) << endl;
    return 0;
}
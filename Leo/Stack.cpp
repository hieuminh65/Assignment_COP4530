#include <iostream>
#include <cstdlib>
#include <chrono>
#include <memory>
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
    private:
        Node *head;
};


Stack::Stack(){
    head = NULL;
};

void Stack::push(char data){
    Node *new_node = new Node;
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

bool TestStack(string string_test){
    Stack s = Stack();
    for (int i = 0; i < string_test.length(); i++){
        if (string_test[i] == '(' || string_test[i] == '{' || string_test[i] == '[') {
            s.push(string_test[i]);
        } 
        else if (string_test[i] == ')' || string_test[i] == ']' || string_test[i] == '}'){
            if ((string_test[i] == ')') && s.display() != '(') {
                return false;
            }
            else if ((string_test[i] == ']') && (s.display() != '[')) {
                return false;
            }
            else if ((string_test[i] == '}') && (s.display() != '{')) {
                return false;
            }
            else {
                s.pop();
            }
        }
    }
    if (s.display() != '\0') {
        return false;
    }
    return true;
}
    


int main(){
    auto start = std::chrono::steady_clock::now();

    string test1 = "{{{{}}}[][]((())";    // * False
    string test2 = "(%TT{>><]]]%%%%%%)";  // * False
    string test3 = "(((((()))))){}{}{}[][][][[[]]]"; // * True
    string test4 = "{{{@23+6767}}}*<45>(a+b)[]"; // * True
    string test5 = "(a+b)"; // * True
    string test6 = "(((((a+b %%%%%####3422222222222)))))[]{}[]"; // * True
    string test7 = "[[[{{()}}]]]"; // * True
    string test8 = "((((((}}}}}}"; // * False
    string test9 = "Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$)"; // * True
    string test10 = "@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%% "; // * True
    string test11 = "<<<<<{{{{[@@@@((((%%%%%%............))))]]]*****######!!!!!!!}}}}>>>>>"; // * False
    string test12 = "(((()()()())[{}]))[[[]]]{[[()()][]]}"; // * True
    string test13 = "(((([[{{((()))}}]]]))))([{<>}])"; // * False
    string test14 = "((((({[((([])))][{(())}]})}))))"; // * False
    string test15 = "((((({[2312((123([2131])*))][{(())}]})}))))"; // * False
    string test16 = "((((({[2312((123([2131])*))][{(())}]}2312((123([2131"; // * False

    // change the test case here
    cout << "Result for test case 15: ";
    cout << TestStack(test14) << endl;

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " us (microsecond)" << std::endl;

    // get memory consumption
    std::unique_ptr<int[]> ptr(new int[1024 * 1024]);
    std::cout << "Memory usage: " << 1024 * 1024 * sizeof(int) << " bytes" << std::endl;
    return 0;
}
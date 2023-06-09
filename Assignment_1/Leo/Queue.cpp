#include <iostream>
#include <cstdlib>
#include <chrono>
#include <memory>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the circular array is 99

class Queue {
    private:
        int array[MAX_SIZE];
        int front;
        int back;

    public:
        Queue() {
            front = 0;
            back = 0; 
        }

        bool empty() {
            return front == back;
        }

        bool isFull() {
            return (back + 1) % MAX_SIZE == front;
        }

        void push(int element) {
            if (isFull()) {
                throw std::overflow_error("Queue is full");
            }

            back = (back + 1) % MAX_SIZE;
            array[back] = element;
        }

        int pop() {
            if (empty()) {
                throw std::underflow_error("Queue is empty");
            }
            front = (front + 1) % MAX_SIZE;
            return array[front];
        }

        int frontElement() {
            if (empty()) {
                throw std::underflow_error("Queue is empty");
            }
            return array[(front + 1) % MAX_SIZE];
        }

        int backElement() {
            if (empty()) {
                throw std::underflow_error("Queue is empty");
            }
            return array[back];
        }

        int size() {
            return (back - front + MAX_SIZE) % MAX_SIZE;
        }
};

int main(){
    auto start = std::chrono::steady_clock::now();

    Queue queue = Queue();
    queue.push(5);
    queue.push(8);
    queue.push(4);
    queue.push(2);
    cout << queue.frontElement() << endl;
    queue.pop();
    cout << queue.frontElement() << endl;
    queue.pop();
    cout << queue.frontElement() << endl;
    queue.pop();
    cout << queue.frontElement() << endl;
    cout << queue.backElement() << endl;
    cout <<queue.empty() << endl; // 0 means False
    queue.pop();
    cout <<queue.empty() << endl; // 1 means True
    cout << queue.size() << endl; // size = 0
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " us (microsecond)" << std::endl;

    // get memory consumption
    std::unique_ptr<int[]> ptr(new int[1024 * 1024]);
    std::cout << "Memory usage: " << 1024 * 1024 * sizeof(int) << " bytes" << std::endl;
    return 0;
}

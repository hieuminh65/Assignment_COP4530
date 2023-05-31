#include <iostream>
#include <cstdlib>

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

        void enqueue(int element) {
            if (isFull()) {
                throw std::overflow_error("Queue is full");
            }

            back = (back + 1) % MAX_SIZE;
            array[back] = element;
        }

        int dequeue() {
            if (empty()) {
                throw std::underflow_error("Queue is empty");
            }
            front = (front + 1) % MAX_SIZE;
            return array[front];
        }

        int front() {
            if (empty()) {
                throw std::underflow_error("Queue is empty");
            }
            return array[(front + 1) % MAX_SIZE];
        }

        int back() {
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
    Queue queue = Queue();
}

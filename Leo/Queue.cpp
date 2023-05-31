#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the circular array is 99

class CircularQueue {
    private:
        int array[MAX_SIZE];
        int front;
        int rear;

    public:
        CircularQueue() {
            front = 0;
            rear = 0; 
        }

        bool isEmpty() {
            return front == rear;
        }

        bool isFull() {
            return (rear + 1) % MAX_SIZE == front;
        }

        void enqueue(int element) {
            if (isFull()) {
                throw std::overflow_error("Queue is full");
            }

            rear = (rear + 1) % MAX_SIZE;
            array[rear] = element;
        }

        int dequeue() {
            if (isEmpty()) {
                throw std::underflow_error("Queue is empty");
            }
            front = (front + 1) % MAX_SIZE;
            return array[front];
        }

        int frontElement() {
            if (isEmpty()) {
                throw std::underflow_error("Queue is empty");
            }
            return array[(front + 1) % MAX_SIZE];
        }

        int rearElement() {
            if (isEmpty()) {
                throw std::underflow_error("Queue is empty");
            }
            return array[rear];
        }

        int size() {
            return (rear - front + MAX_SIZE) % MAX_SIZE;
        }
};

int main(){
    CircularQueue queue = CircularQueue();
}

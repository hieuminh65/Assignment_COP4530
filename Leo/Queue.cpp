#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 5; // Maximum size of the circular array is 4

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
            cout << "front is" << front << endl;
            return array[(front + 1) % MAX_SIZE];
        }

        int rearElement() {
            if (isEmpty()) {
                throw std::underflow_error("Queue is empty");
            }
            cout << "rear is" << rear << endl;
            return array[rear];
        }

        int size() {
            return (rear - front + MAX_SIZE) % MAX_SIZE;
        }
};

int main(){
    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    // queue.enqueue(6); // This will throw an exception
    // cout << queue.rearElement() << endl;
    // cout << queue.frontElement() << endl;
    // queue.enqueue(9);
    // cout << queue.dequeue() << endl;
    // cout << queue.dequeue() << endl;
    // cout << queue.dequeue() << endl;
    return 0;
}

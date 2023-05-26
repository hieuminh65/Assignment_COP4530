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


// When comparing the queue implementation using a circular array with a C++ queue, there are a few points to consider:

// Speed: The circular array implementation can be faster in terms of enqueuing and dequeuing elements compared to the linked list implementation. 
// This is because accessing elements in an array is more cache-friendly and doesn't involve dynamic memory allocation like the linked list.

// Similarity: Both the circular array implementation and the C++ queue provide the same functionality of enqueueing and dequeueing elements in a first-in-first-out (FIFO) manner. 
// They both maintain the order of elements and offer similar operations.

// Dissimilarity: The main difference lies in the underlying data structure. 
// The circular array implementation uses a fixed-size array, while the C++ queue typically uses a doubly linked list. 
// The circular array implementation requires explicit handling of wraparound and may have a maximum capacity, while the C++ queue can dynamically resize itself as elements are added or removed.

// Error handling: In the circular array implementation, we'll need to handle cases where the queue is full or empty separately. 
// If the array is full, we may choose to throw an error or implement some form of resizing strategy. If the array is empty, we may choose to throw an error or return a special value to indicate that the queue is empty. 
// In contrast, the C++ queue provides built-in error handling mechanisms such as exceptions or member functions that return status indicators.
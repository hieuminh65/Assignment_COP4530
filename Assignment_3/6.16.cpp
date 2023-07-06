#include <iostream>
#include <vector>

class BinaryHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

public:
    void insert(int num) {
        heap.push_back(num);
        heapifyUp(heap.size() - 1);
    }

    int getHeapSize() {
        return heap.size();
    }

    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index) {
        return (2 * index) + 1;
    }

    int getRightChildIndex(int index) {
        return (2 * index) + 2;
    }

    int getNodeAtIndex(int index) {
        if (index >= 0 && index < heap.size()) {
            return heap[index];
        }
        return -1; // Return -1 for invalid index
    }
};

int main() {
    BinaryHeap heap;

    // Get user input
    std::cout << "Enter elements (enter -1 to stop): ";
    int value;
    while (std::cin >> value && value != -1) {
        heap.insert(value);
    }

    // Print the heap
    std::cout << "Heap: ";
    for (int i = 0; i < heap.getHeapSize(); ++i) {
        std::cout << heap.getNodeAtIndex(i) << " ";
    }
    std::cout << std::endl;

    // Find a node at an implicit position
    int position;
    std::cout << "Enter position: ";
    std::cin >> position;

    int nodeIndex = position - 1;
    int nodeValue = heap.getNodeAtIndex(nodeIndex);

    if (nodeValue != -1) {
        std::cout << "Node at position " << position << ": " << nodeValue << std::endl;
    } else {
        std::cout << "Invalid position!" << std::endl;
    }

    return 0;
}


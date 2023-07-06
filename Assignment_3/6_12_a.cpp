#include <iostream>
#include <vector>

class BinaryHeap {
private:
    std::vector<int> array;
    int currentSize;

    void percolateUp(int hole) {
        int x = std::move(array[hole]);
        for (; hole > 1 && x < array[hole / 2]; hole /= 2) {
            array[hole] = std::move(array[hole / 2]);
        }
        array[hole] = std::move(x);
    }

public:
    BinaryHeap() : currentSize(0) {
        array.push_back(0); // Use index 0 as a placeholder
    }

    void insert(const int& x) {
        if (currentSize == array.size() - 1)
            array.resize(array.size() * 2);

        int hole = ++currentSize;
        array[hole] = x;
        percolateUp(hole);
    }

    void printHeap() {
        for (int i = 1; i <= currentSize; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    BinaryHeap heap;

    int N;
    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    std::cout << "Enter " << N << " elements:" << std::endl;
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        heap.insert(num);
    }

    std::cout << "Heap: ";
    heap.printHeap();

    return 0;
}

#include <iostream>
#include <vector>

class BinaryHeap {
private:
    std::vector<int> array;
    int currentSize;

    void percolateUp(int hole) {
        int x = std::move(array[hole]);
        for (; hole > 1 && x < array[hole / 2]; hole /= 2) {
            array[hole] = array[hole / 2];
        }
        array[0] = array[hole] = x;
    }

    void percolateDown(int hole) {
        int x = std::move(array[hole]);
        int child;

        for (; hole * 2 <= currentSize; hole = child) {
            child = hole * 2;
            if (child != currentSize && array[child + 1] < array[child])
                ++child;

            if (array[child] < x)
                array[hole] = std::move(array[child]);
            else
                break;
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
        int copy = x;
        array[0] = std::move(copy);
        percolateUp(hole);
    }

    void createHeap(const std::vector<int>& nums) {
        currentSize = nums.size();
        array.resize(nums.size() + 1);

        for (int i = 0; i < nums.size(); ++i) {
            array[i + 1] = nums[i];
        }

        for (int i = currentSize / 2; i > 0; --i) {
            percolateDown(i);
        }
    }

    void printHeap() {
        for (int i = 1; i <= currentSize; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main(int argc, char* argv[]) {
    BinaryHeap heap;

    // Check if the command line argument is provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
        return 1;
    }

    // Create a vector to store the numbers
    std::vector<int> nums;

    // Iterate over the command line arguments and convert them to integers
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        nums.push_back(num);
    }

    // Create the binary heap
    heap.createHeap(nums);

    // Print the heap
    std::cout << "Heap: ";
    heap.printHeap();

    return 0;
}

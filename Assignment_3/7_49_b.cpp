#include <iostream>
#include <vector>

template <typename Comparable>
const Comparable& median3(std::vector<Comparable>& a, int left, int right) {
    int center = (left + right) / 2;

    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    // Place pivot at position right - 1
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

template <typename Comparable>
void quicksort(std::vector<Comparable>& a, int left, int right, int cutoff) {
    if (left + cutoff <= right) {
        const Comparable& pivot = median3(a, left, right);

        int i = left, j = right - 1;
        for (;;) {
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}

            if (i < j)
                std::swap(a[i], a[j]);
            else
                break;
        }

        std::swap(a[i], a[right - 1]);

        quicksort(a, left, i - 1, cutoff);
        quicksort(a, i + 1, right, cutoff);
    } else {
        // Do an insertion sort on the subarray
        for (int i = left + 1; i <= right; ++i) {
            Comparable tmp = std::move(a[i]);
            int j = i;

            for (; j > left && tmp < a[j - 1]; --j) {
                a[j] = std::move(a[j - 1]);
            }

            a[j] = std::move(tmp);
        }
    }
}

template <typename Comparable>
void quicksort(std::vector<Comparable>& a, int cutoff) {
    quicksort(a, 0, a.size() - 1, cutoff);
}

int main(int argc, char* argv[]) {
    std::vector<int> nums;

    // Check if the command line argument is provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
        return 1;
    }

    // Iterate over the command line arguments and convert them to integers
    for (int i = 1; i < argc; ++i) {
        nums.push_back(std::stoi(argv[i]));
    }

    // Perform quicksort with different cutoff values
    for (int cutoff = 0; cutoff <= 20; ++cutoff) {
        std::vector<int> sorted = nums;  // Make a copy of the original vector
        quicksort(sorted, cutoff);
        
        std::cout << "Sorted numbers with cutoff " << cutoff << ": ";
        for (const auto& num : sorted) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


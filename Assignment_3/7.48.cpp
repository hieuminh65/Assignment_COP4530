#include <iostream>
#include <vector>
#include <chrono> // For measuring execution time

template <typename Comparable>
void shellsort(std::vector<Comparable> &a, const std::vector<int>& increments) {
    for (int k = 0; k < increments.size(); ++k) {
        int gap = increments[k];

        for (int i = gap; i < a.size(); ++i) {
            Comparable tmp = std::move(a[i]);
            int j = i;

            for (; j >= gap && tmp < a[j - gap]; j -= gap) {
                a[j] = std::move(a[j - gap]);
            }
            a[j] = std::move(tmp);
        }
    }
}

// Generate Hibbard's increments
std::vector<int> generateHibbardIncrements(int size) {
    std::vector<int> increments;
    int k = 1;
    while (true) {
        int gap = (1 << k) - 1;
        if (gap >= size)
            break;
        increments.push_back(gap);
        ++k;
    }
    std::reverse(increments.begin(), increments.end());
    return increments;
}

// Generate Knuth's increments
std::vector<int> generateKnuthIncrements(int size) {
    std::vector<int> increments;
    int gap = 1;
    while (gap < size) {
        increments.push_back(gap);
        gap = 3 * gap + 1;
    }
    std::reverse(increments.begin(), increments.end());
    return increments;
}

// Generate Gonnet's increments
std::vector<int> generateGonnetIncrements(int size) {
    std::vector<int> increments;
    int k = 0;
    while (true) {
        int gap = ((1 << k) - (1 << (k / 2))) + 1;
        if (gap >= size)
            break;
        increments.push_back(gap);
        ++k;
    }
    std::reverse(increments.begin(), increments.end());
    return increments;
}

// Generate Sedgewick's increments
std::vector<int> generateSedgewickIncrements(int size) {
    std::vector<int> increments;
    int k = 0;
    while (true) {
        int gap1 = (1 << k) * 9 - (1 << (k - 1)) * 4 + 1;
        int gap2 = (1 << (k + 2)) - 3 * (1 << k) + 1;
        if (gap1 >= size)
            break;
        increments.push_back(gap1);
        if (gap2 >= size)
            break;
        increments.push_back(gap2);
        ++k;
    }
    std::reverse(increments.begin(), increments.end());
    return increments;
}

// Function to measure execution time of shellsort
template <typename Comparable>
double measureExecutionTime(std::vector<Comparable>& a, const std::vector<int>& increments) {
    auto start = std::chrono::steady_clock::now();
    shellsort(a, increments);
    auto end =std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    return diff.count();
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

    std::cout << "Input size: " << nums.size() << std::endl;

    // Generate different increment sequences
    std::vector<int> hibbardIncrements = generateHibbardIncrements(nums.size());
    std::vector<int> knuthIncrements = generateKnuthIncrements(nums.size());
    std::vector<int> gonnetIncrements = generateGonnetIncrements(nums.size());
    std::vector<int> sedgewickIncrements = generateSedgewickIncrements(nums.size());

    // Measure execution time for each increment sequence
    double timeHibbard = measureExecutionTime(nums, hibbardIncrements);
    double timeKnuth = measureExecutionTime(nums, knuthIncrements);
    double timeGonnet = measureExecutionTime(nums, gonnetIncrements);
    double timeSedgewick = measureExecutionTime(nums, sedgewickIncrements);

    // Print the results
    std::cout << "Execution time using Hibbard's increments: " << timeHibbard << " seconds" << std::endl;
    std::cout << "Execution time using Knuth's increments: " << timeKnuth << " seconds" << std::endl;
    std::cout << "Execution time using Gonnet's increments: " << timeGonnet << " seconds" << std::endl;
    std::cout << "Execution time using Sedgewick's increments: " << timeSedgewick << " seconds" << std::endl;

    return 0;
}

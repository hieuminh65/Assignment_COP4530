#include <iostream>
#include <vector>

bool hasThreeNumbersSum(const std::vector<int>& nums, int target) {
    int n = nums.size();
    // Sort the array in non-decreasing order
    std::vector<int> sortedNums = nums;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sortedNums[j] > sortedNums[j + 1]) {
                int temp = sortedNums[j];
                sortedNums[j] = sortedNums[j + 1];
                sortedNums[j + 1] = temp;
            }
        }
    }

    // Fix the first number, then find the remaining two numbers using two pointers approach
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = sortedNums[i] + sortedNums[left] + sortedNums[right];
            if (sum == target)
                return true;
            else if (sum < target)
                ++left;
            else
                --right;
        }
    }

    return false;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int target;
    std::cout << "Enter the target sum: ";
    std::cin >> target;

    bool hasSum = hasThreeNumbersSum(nums, target);
    if (hasSum)
        std::cout << "Yes, there exist three numbers whose sum is " << target << std::endl;
    else
        std::cout << "No, there does not exist three numbers whose sum is " << target << std::endl;

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <queue>
#include <chrono>
#include <memory>
using namespace std;

int main(){
    auto start = std::chrono::steady_clock::now();

    queue<int> queue;
    queue.push(5);
    queue.push(8);
    queue.push(4);
    queue.push(2);
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    cout << queue.back() << endl;
    cout <<queue.empty() << endl; // 0 means False
    queue.pop();
    cout <<queue.empty() << endl; // 1 means True
    cout << queue.size() << endl; // size = 0

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " us (microsecond)" << std::endl;

    // get memory consumption
    std::unique_ptr<int[]> ptr(new int[1024 * 1024]);
    std::cout << "Memory usage: " << 1024 * 1024 * sizeof(int) << " bytes" << std::endl;
    return 0;
}
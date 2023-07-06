#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
template <typename Comparable>
int partition(std::vector<Comparable>& a, int low, int high) {
    Comparable pivot = a[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && a[i] <= pivot)
            ++i;
        while (j >= i && a[j] >= pivot)
            --j;
        if (i >= j)
            break;
        std::swap(a[i], a[j]);
    }

    std::swap(a[low], a[j]);
    return j;
}
template <typename Comparable>
int median3(std::vector<Comparable>& a, int low, int high) {
    int mid = low + (high - low) / 2;
    if (a[low] > a[mid])
        std::swap(a[low], a[mid]);
    if (a[mid] > a[high])
        std::swap(a[mid], a[high]);
    if (a[low] > a[mid])
        std::swap(a[low], a[mid]);
    return mid;
}

template <typename Comparable>
int median5(std::vector<Comparable>& a, int low, int high) {
    int mid = low + (high - low) / 2;
    if (a[low] > a[mid])
        std::swap(a[low], a[mid]);
    if (a[mid] > a[high])
        std::swap(a[mid], a[high]);
    if (a[low] > a[mid])
        std::swap(a[low], a[mid]);

    std::swap(a[mid], a[high - 1]);
    if (a[low] > a[mid])
        std::swap(a[low], a[mid]);
    if (a[mid] > a[high])
        std::swap(a[mid], a[high]);
    return high - 1;
}
template <typename Comparable>
int randomPivot(std::vector<Comparable>& a, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    std::swap(a[low], a[pivotIndex]);
    return low;
}
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    int value;
    std::cout << "Select a pivot by entering the number:\n";
    std::cout << "1- first element, 2- middle element, 3- last element, 4- median3, 5- median5\n";
    if((std::cin >> value) == 1)
        const Comparable & pivot = a[left];
        
    if((std::cin >> value) == 2){
        int mid;
        mid = (left + right)/2;
        const Comparable & pivot = a[mid];
    }
    if((std::cin >> value) == 3)
        const Comparable & pivot = randomPivot(a, left, right);
        
    if((std::cin >> value) == 4)
        const Comparable & pivot = median3( a, left, right );
        
    if((std::cin >> value) == 5)
        const Comparable & pivot = median5( a, left, right );
    else{
        const Comparable & pivot = a[left];
    }
    if( left + 10 <= right )
    {
        
            // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot

        quicksort( a, left, i - 1 );     // Sort small elements
        quicksort( a, i + 1, right );    // Sort large elements
    }
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a ){
    quicksort( a, 0, a.size( ) - 1 );
}

int main() {
    std::vector<int> values;

    std::cout << "Enter values (enter a non-integer to stop):\n";
    int value;
    while (std::cin >> value) {
        values.push_back(value);
    }

    quicksort(values);

    std::cout << "Sorted values:\n";
    for (const auto& val : values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}




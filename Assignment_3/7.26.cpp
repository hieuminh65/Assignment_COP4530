// In file '7.25parta.cpp,' enter {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0} as test case
    //in this test case, 10 is the largest element so the first recursive call 
    //processes all elements lesser than 10 (smaller sub-array) and the second 
    //recursive call processes the entire array including 10 (bigger)

#include <vector>
#include <functional>
#include <iostream>
using namespace std;

template <typename Comparable>
const Comparable& median3(vector<Comparable>& a, int left, int right) {
    int center = (left + right) / 2;

    if (a[center] < a[left])
        swap(a[left], a[center]);
    if (a[right] < a[left])
        swap(a[left], a[right]);
    if (a[right] < a[center])
        swap(a[center], a[right]);

    swap(a[center], a[right - 1]);
    return a[right - 1];
}

template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Comparable temp = std::move(a[i]);
        int j;
        for (j = i; j > left && temp < a[j - 1]; j--)
            a[j] = std::move(a[j - 1]);
        a[j] = std::move(temp);
    }
}

template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    while( left + 10 <= right ){
       // Do a quicksort on the subarray
        const Comparable & pivot = median3( a, left, right );

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

       if (i - left <= right - i - 1) {
            quicksort(a, left, i - 1);  // Sort small elements
            left = i + 1;               // Update left for the larger subarray
        } else {
            quicksort(a, i + 1, right); // Sort large elements
            right = i - 1;              // Update right for the smaller subarray
        }
    }
    insertionSort( a, left, right ); 
        
}


/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}

int main(int argc, char* argv[]) {
    vector<int> arr(argc - 1);
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    quicksort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
    


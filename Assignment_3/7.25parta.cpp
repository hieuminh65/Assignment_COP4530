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
    if( left + 10 > right ){
        insertionSort( a, left, right ); 
        return;
    } 
    else{
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

        quicksort( a, left, i - 1 );     // Sort small elements
        quicksort( a, i + 1, right );    // Sort large elements
    }
    
        
}


/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}


/**
 * Internal selection method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 * k is the desired rank (1 is minimum) in the entire array.
 */
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

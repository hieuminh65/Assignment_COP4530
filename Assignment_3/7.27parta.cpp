//in command line enter first vale as depth and next values as array of numbers
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

/**
 * Standard heapsort.
 */
/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild( int i )
{
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown( vector<Comparable> & a, int i, int n )
{
    int child;
    Comparable tmp;

    for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
    {
        child = leftChild( i );
        if( child != n - 1 && a[ child ] < a[ child + 1 ] )
            ++child;
        if( tmp < a[ child ] )
            a[ i ] = std::move( a[ child ] );
        else
            break;
    }
    a[ i ] = std::move( tmp );
}
/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */

template <typename Comparable>
void heapsort( vector<Comparable> & a )
{
    for( int i = a.size( ) / 2 - 1; i >= 0; --i )  /* buildHeap */
        percDown( a, i, a.size( ) );
    for( int j = a.size( ) - 1; j > 0; --j )
    {
        std::swap( a[ 0 ], a[ j ] );               /* deleteMax */
        percDown( a, 0, j );
    }
}


template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right, int depth )
{
    if( left + 10 <= right ){
        if(depth == 0){
            heapsort(a);
            return;
        }
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

        quicksort( a, left, i - 1, depth - 1 );     // Sort small elements
        quicksort( a, i + 1, right, depth - 1 );    // Sort large elements 
    } 
    else{
        insertionSort( a, left, right ); 
    }
          
}


/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a, int depth )
{
    quicksort( a, 0, a.size( ) - 1, depth );
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
    vector<int> arr(argc - 2);
    int depth = atoi(argv[1]);
    for (int i = 2; i < argc; i++) {
        arr[i - 2] = atoi(argv[i]);
    }

    quicksort(arr, depth);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <cstdlib>

using namespace std;

// The quicksort in the text uses two recursive calls. Remove one of the calls as follows:
// a. Rewrite the code so that the second recursive call is unconditionally the last
// line in quicksort. Do this by reversing the if/else and returning after the call to
// insertionSort.

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void heap(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]){
        largest = left;
    }
    if (right < n && a[right] > a[largest]){
        largest = right;
    }

    if (largest != i){
        swap(a, i, largest);
        heap(a, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heap(arr, n, i);
    }
}

void heapSort(int arr[], int n, int left, int right){
    buildMaxHeap(arr + left, right - left + 1);
    for (int i = right; i >= left; i--){
        swap(arr[left], arr[i]);
        heap(arr, i - left, left);
    }
}

void display(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertArray(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << "Enter the element " << i + 1 << ": ";
        cin >> a[i];
    }
    cout << "The array is: " << endl;
    display(a, n);
}

int median3(int a[], int lb, int ub){
    int mid = (lb + ub)/2;
    if (a[lb] > a[mid]){
        swap(a, lb, mid);
    }
    if (a[lb] > a[ub]){
        swap(a, lb, ub);
    }
    if (a[mid] > a[ub]){
        swap(a, mid, ub);
    }
    swap(a, mid, ub - 1);
    return a[ub - 1];
}

void quickSort(int a[], int left, int right, int depth){
    while (right - left >= 3 && depth > 0){
        int pivot = median3(a, left, right);
        int i = left;
        int j = right - 1;
        for ( ; ; ) {
            while (a[i] < pivot){ i++;}
            while (a[j] >= pivot){ j--;}
            if (i < j){
                swap(a, i, j);
            }
            else{
                break;
            }
        }
        swap(a, i, right - 1);
        quickSort(a, left, i - 1, depth - 1);
        left = i + 1;
        depth--;
    } 
    heapSort(a, right - left + 1, left, right);
}


int main(){
    cout << "Enter the number of elements you want: ";
    int n;
    cin >> n;
    int arr[n];
    insertArray(arr, n);
    cout << "Intial array: " << endl;
    display(arr, n);
    cout << "Sorted array: " << endl;
    quickSort(arr, 0, n, 2 * log(n));
    display(arr, n);
    
    return 0;
}
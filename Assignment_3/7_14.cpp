#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

void display(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " | ";
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
        swap(a[i], a[largest]);
        heap(a, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heap(arr, n, i);
    }
}

void heapSort(int arr[], int n, int low, int high){
    cout << "Initial array: " << endl;
    display(arr, n);
    buildMaxHeap(arr, n);
    for (int i = high; i >= low; i--){
        swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
    cout << "Sorted array: " << endl;
    display(arr, n);
}

int main(){
    cout << "Enter the number of elements you want: ";
    int n;
    cin >> n;
    int arr[n];
    insertArray(arr, n);
    cout << "Enter the lower bound you want: ";
    int low;
    cin >> low;
    while (low < 0 || low > n - 1){
        cout << "Enter the lower bound you want (between 0 and " << n - 1 << "): ";
        cin >> low;
    }
    cout << "Enter the upper bound you want: ";
    int high;
    cin >> high;
    while (high < 0 || high > n - 1 || high < low){
        cout << "Enter the upper bound you want (between 0 and " << n - 1 << " and larger than low): ";
        cin >> high;
    }
    heapSort(arr, n, low, high);
}
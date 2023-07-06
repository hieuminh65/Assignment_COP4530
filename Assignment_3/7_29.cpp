#include <iostream>
#include <cstdlib>
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

int locOfSmallest(int a[], int s, int e){
    int i = s;
    int j = i;
    while (i<=e){
        if (a[i] < a[j]){
            j = i;
        }
        i++;
    }
    return j;
}

void selectionSort(int a[], int n){
    int i = 0;
    while ( i < n - 1){
        int j = locOfSmallest(a, i, n-1);
        swap(a, i, j);
        i++;
    }
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
    selectionSort(arr, n);
    display(arr, n);
}
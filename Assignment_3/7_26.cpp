#include <iostream>
#include <cstdlib>

using namespace std;

// The quicksort in the text uses two recursive calls. Remove one of the calls as follows:
// b. Remove the tail recursion by writing a while loop and altering left.

void insertIth(int a[], int n, int i){
    int j = i;
    while (j>0 && a[j-1] > a[j]){
        int temp = a[j];
        a[j] = a[j-1];
        a[j-1] = temp;
        j--;
    }
}


void inSort(int a[], int n ){
    int i = 1;
    while (i<n){
        insertIth(a, n, i);
        i++;
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

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
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

void quickSort(int a[], int left, int right){
    while (right - left > 3){
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
        quickSort(a, left, i - 1);
        left = i + 1;
    } 
    inSort(a + left, right - left + 1);
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
    quickSort(arr, 0, n);
    display(arr, n);
    
    return 0;
}
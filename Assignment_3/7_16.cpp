#include <iostream>
#include <cstdlib>

using namespace std;

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

void merge(int a[], int s, int m, int e){
    int * tmp = new int[e + 1];
    int k = s;
    while (k<=e){
        tmp[k] = a[k];
        k++;
    }

    int i = s, j = m + 1;
    k = s;
    while (i <= m && j <= e){
        if (tmp[i] < tmp[j]){
            a[k] = tmp[i];
            i++;
        }
        else{
            a[k] = tmp[j];
            j++;
        }
        k++;
    }
    while (i <= m){
        a[k] = tmp[i];
        i++;
        k++;
    }
    while (j <= e){
        a[k] = tmp[j];
        j++;
        k++;
    }
    delete[] tmp;
}

void mSort(int a[], int n){
    int p, s, mid, e;
    for (p = 1; p < n; p *= 2*p){
        for (int s = 0; s < n - 1; s += 2*p){
            mid = min(s + p - 1, n - 1);
            e = min(s + 2 * p - 1, n - 1);
            merge(a, s, mid, e);
        }
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
    mSort(arr, n);
    display(arr, n);
    return 0;
}
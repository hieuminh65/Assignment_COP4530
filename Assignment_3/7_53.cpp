#include <iostream>
#include <cstdlib>
#include <chrono>


using namespace std;

void merge(int a[], int s, int m, int e);
void mSort(int a[], int s, int e);
void mSort(int a[], int n);

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

bool longAlgorithm(int a[], int n, int k){
    int i = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] + a[j] == k){
                return true;
            }
        }
    }
    return false;
}

bool shortAlgorithm(int a[], int n, int k){
    mSort(a, n);
    int i = 0;
    int j = n - 1;
    while (i < j){
        if (a[i] + a[j] == k){
            return true;
        }
        else if (a[i] + a[j] < k){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

int main(){
    cout << "Enter the number of elements you want: ";
    int n;
    cin >> n;
    int arr[n];
    insertArray(arr, n);
    cout << "Enter target number K: ";
    int k;
    cin >> k;
    cout << "1. Long Algorithm" << endl;
    cout << "2. Short Algorithm (using merge sort)" << endl;
    cout << "Choose the algorithm you want to use: ";
    int choice;
    cin >> choice;
    switch (choice){
        case 1:
            if (longAlgorithm(arr, n, k)){
                cout << "There are two elements in the array that add up to " << k << endl;
            }
            else{
                cout << "There are no two elements in the array that add up to " << k << endl;
            }
            break;
        case 2:
            if (shortAlgorithm(arr, n, k)){
                cout << "There are two elements in the array that add up to " << k << endl;
            }
            else{
                cout << "There are no two elements in the array that add up to " << k << endl;
            }
            break;
        default:
            cout << "Invalid choice" << endl;
    }
    cout << "What algorithm do you want to see the execution time?" << endl;
    cout << "1. Long Algorithm" << endl;
    cout << "2. Short Algorithm (using merge sort)" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;
    while (choice != 3 ){
        if (choice == 1){
            auto start = std::chrono::steady_clock::now();
            cout << "Long algorithm: " << endl;
            longAlgorithm(arr, n, k);
            auto end = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            std::cout << "Execution time: " << duration.count() << " us (microsecond)" << std::endl;
        }
        else if (choice == 2){
            auto start = std::chrono::steady_clock::now();
            cout << "Short algorithm: " << endl;
            shortAlgorithm(arr, n, k);
            auto end = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            std::cout << "Execution time: " << duration.count() << " us (microsecond)" << std::endl;
        }
        else{
            cout << "Invalid choice" << endl;
        }
        cout << "What algorithm do you want to see the execution time?" << endl;
        cout << "1. Long Algorithm" << endl;
        cout << "2. Short Algorithm (using merge sort)" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;
    }
    
    
    return 0;
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

void mSort(int a[], int s, int e){
    if (s == e) return;
    int m = (s + e) / 2;
    mSort(a, s, m);
    mSort(a, m + 1, e);
    merge(a, s, m, e);
}

void mSort(int a[], int n){
    mSort(a, 0, n - 1);
}
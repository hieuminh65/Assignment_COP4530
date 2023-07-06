#include <iostream>
#include <cstdlib>
#include <chrono>
#include <set>


using namespace std;

void display(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void display(vector<int>& a, int n){
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void insertArray(vector<int>& a, int n){
    int input;
    for (int i = 0; i < n; i++){
        cout << "Enter the element " << i + 1 << ": ";
        cin >> a[i];
    }
    cout << "The array is: " << endl;
    display(a, n);
}

bool binary_search(vector<int>& sums, int left, int right, int K) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(sums[mid] == K) return true;
        else if(sums[mid] < K) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

bool isPossible(vector<int>& nums, int K) {
    int N = nums.size();
    vector<int> sums;

    // Compute all possible sums
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            sums.push_back(nums[i] + nums[j]);
        }
    }

    // Sort the sums
    sort(sums.begin(), sums.end());

    // Perform binary search for K
    return binary_search(sums, 0, sums.size() - 1, K);
}

int main(){
    cout << "Enter the number of elements you want: ";
    int n;
    cin >> n;
    vector<int> a(n);
    insertArray(a, n);
    cout << "Enter target number K: ";
    int k;
    cin >> k;
    bool result = isPossible(a, k);
    if(result) cout << "Yes. There is 4 numbers that sum up to " << k << endl;
    else cout << "No. There is no such numbers that sum up to " << k << endl;
    
    return 0;
}



// the following explains the algorithm 
1. Choose a pivot element from the subarray. This pivot element can be selected randomly or deterministically based on your requirements.

2. Initialize three pointers: i, j, and low. Set i and j to the first and last indices of the subarray, and low to the first index.

3. Repeat the following steps while i is less than or equal to j:
    Compare the element at index i with the pivot element:
    If the element is smaller than the pivot:
    Swap the element at index i with the element at index low.
    Increment both i and low by 1.
    If the element is equal to the pivot:
    Increment i by 1.
    If the element is larger than the pivot:
    Swap the element at index i with the element at index j.
    Decrement j by 1.
    After the above steps, the subarray is partitioned into three parts: elements less than the pivot, elements equal to the pivot, and elements greater than the pivot.

4. Now, perform the following steps to move the equal elements to the middle:

5. Initialize two pointers, equalLow and equalHigh, both pointing to the first index of the equal elements section.
    Iterate from low to equalHigh and perform the following:
    If the element at the current index is equal to the pivot:
    Swap the element at the current index with the element at equalHigh.
    Increment equalHigh by 1.
    
At this point, all the equal elements are grouped together between equalLow and equalHigh.
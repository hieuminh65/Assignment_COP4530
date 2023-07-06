/*
a) To find the minimum and maximum elements in a min-max heap:
   - The minimum element is always the root of the min-max heap.
   - The maximum element can be found by comparing the values of the root's children and selecting the larger one.

b) Algorithm to insert a new node into a min-max heap:
   - Perform a standard insertion by adding the new node as the last leaf node in the heap.
   - Compare the new node with its parent and grandparent based on the depth of the new node:
     - If the depth is even:
       - If the new node is smaller than its parent, swap them.
       - If the new node is larger than its grandparent, swap them.
       - Repeat the comparison and swapping process with the new node's grandparent until the heap-order property is satisfied.
     - If the depth is odd:
       - If the new node is larger than its parent, swap them.
       - If the new node is smaller than its grandparent, swap them.
       - Repeat the comparison and swapping process with the new node's grandparent until the heap-order property is satisfied.

c) Algorithm to perform deleteMin and deleteMax operations in a min-max heap:
   - To perform deleteMin:
     - Swap the root with the last leaf node of the heap.
     - Delete the last leaf node.
     - Perform a down-heapify operation starting from the root to restore the heap property.
     - During the down-heapify operation, swap the node with the smallest child at even depth and the node with the largest child at odd depth.
   - To perform deleteMax:
     - Find the maximum element by comparing the values of the root's children.
     - Swap the maximum element with the last leaf node at an even depth in the heap.
     - Delete the last leaf node.
     - Perform a down-heapify operation starting from the node where the maximum element was located to restore the heap property.
     - During the down-heapify operation, swap the node with the smallest child at even depth and the node with the largest child at odd depth.

d) Building a min-max heap in linear time:
   - Yes, a min-max heap can be built in linear time using the following algorithm:
     - Create an empty min-max heap.
     - Insert each element into the heap one by one using the insertion algorithm mentioned above.
     - This process will result in a valid min-max heap in linear time complexity.

e) Data structure to support deleteMin, deleteMax, and merge operations in O(logN) time:
   - To support all three operations in O(logN) time, you can use a combination of a min-max heap and a binary search tree (BST).
   - The min-max heap will maintain the min-max heap-order property and support efficient deleteMin and deleteMax operations.
   - The BST will allow efficient merge operation, as it supports sorted insertions and deletions.
*/
#include<bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted with node i
void heapify(vector<int> &arr, int n, int i) {
  int largest = i;       // Initialize largest as root
  int left = 2 * i + 1;  // left child
  int right = 2 * i + 2; // right child

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child is larger than largest so far
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// Function to build a max-heap from the array
void buildHeap(vector<int> &arr) {
  int n = arr.size();

  // Index of the last non-leaf node
  int startIdx = (n / 2) - 1;

  // Perform reverse level order traversal from the last non-leaf node and
  // heapify each node
  for (int i = startIdx; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

// Utility function to print the array
void printArray(const vector<int> &arr) {
  for (int i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr = {4, 10, 3, 5, 1};

  cout << "Original array: ";
  printArray(arr);

  buildHeap(arr);

  cout << "Max-Heap array: ";
  printArray(arr);

  return 0;
}

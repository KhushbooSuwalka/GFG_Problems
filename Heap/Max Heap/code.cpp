#include <iostream>
using namespace std;

class Heap{
public:
    int *arr;
    int capacity;
    int size;

    // Constructor
    Heap(int capacity){
        // 1-based indexing
        this->arr = new int[capacity + 1];
        this->capacity = capacity;
        this->size = 0;
    }

    // 1. Insertion Operation of Heap Data Structure
    void insertion(int val){
        if (size == capacity){
            cout << "Heap Overflow" << endl;
            return;
        }

        // Increase size
        size++;

        // Insert value at last position
        int index = size;
        arr[index] = val;

        // Take the value to its correct position
        while (index > 1){
            int parentIndex = index / 2;

            if (arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // 2. Deletion Operation of Heap Data Structure
    int deleteFromHeap(){
        if (size == 0){
            cout << "Heap is Empty" << endl;
            return -1;
        }

        // Save root element
        int savedRoot = arr[1];

        // Step 1: Replace root with last element
        arr[1] = arr[size];

        // Delete last element
        size--;

        // Step 2: Put root element at its correct position
        int index = 1;

        while (index < size){
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largestIndex = index;

            // Check left index
            if (leftIndex <= size && arr[largestIndex] < arr[leftIndex]) {
                largestIndex = leftIndex;
            }

            // Check right index
            if (rightIndex <= size && arr[largestIndex] < arr[rightIndex]) {
                largestIndex = rightIndex;
            }

            // No changes needed
            if (index == largestIndex) {
                break;
            } else {
                swap(arr[largestIndex], arr[index]);
                index = largestIndex; // Move down
            }
        }

        return savedRoot;
    }

    // 3. Heapify using recursion
    void heapify(int arr[], int size, int index) {
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;
        int largestIndex = index;

        // Check left child
        if (leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
            largestIndex = leftIndex;
        }

        // Check right child
        if (rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
            largestIndex = rightIndex;
        }

        // If largest is not current index
        if (index != largestIndex){
            swap(arr[largestIndex], arr[index]);

            // Recursion
            index = largestIndex;
            heapify(arr, size, index);
        }
    }

    // 4. Printing Heap
    void printHeap(){
        for (int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int capacity = 5;
    Heap h(capacity);

    // Insertion of elements
    h.insertion(10);
    h.insertion(20);
    h.insertion(5);
    h.insertion(11);
    h.insertion(6);

    cout << "Printing Heap:" << endl;
    h.printHeap();

    // Deletion
    cout << "Deleted Element: " << h.deleteFromHeap() << endl;

    cout << "Heap after deletion:" << endl;
    h.printHeap();

    return 0;
}
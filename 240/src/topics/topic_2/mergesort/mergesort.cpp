#include <iostream>
#include <vector>

// merges two subarrays of array[].
void merge(std::vector<int> &arr, int start, int middle, int end) {

    std::vector<int> leftArray(middle - start + 1);
    std::vector<int> rightArray(end - middle);

    // fill in left array
    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[start + i];

    // fill in right array
    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[middle + 1 + i];

    /* Merge the temp arrays */

    // initial indexes of first and second subarrays
    int leftIndex = 0, rightIndex = 0;

    // the index we will start at when adding the subarrays back into the main array
    int currentIndex = start;

    // compare each index of the subarrays adding the lowest value to the currentIndex
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[currentIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[currentIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    // copy remaining elements of leftArray[] if any
    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    // copy remaining elements of rightArray[] if any
    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}

// main function that sorts array[start..end] using merge()
void mergeSort(std::vector<int> &arr, int start, int end) {
    // base case
    if (start < end) {
        // find the middle point
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle); // sort first half
        mergeSort(arr, middle + 1, end);  // sort second half

        // merge the sorted halves
        merge(arr, start, middle, end);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8};
    mergeSort(arr, 0, static_cast<int>(arr.size() - 1));
    for (int i; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
}
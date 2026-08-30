#include <vector>
#include <iostream>

void Swap(std::vector<int>& vec, int _item1, int _item2)
{
    if (_item1 == _item2) { return; }
    int temp = vec[_item1];
    vec[_item1] = vec[_item2];
    vec[_item2] = temp;
}

int partition(std::vector<int>& vec, int low, int high) {

    // Selecting the last element as the pivot
    int pivot = vec[high];

    // Index of the element smaller than the pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {

        // If the current element is smaller than
        // or equal to the pivot
        if (vec[j] <= pivot) {
            i++;
            Swap(vec, i, j);
        }
    }

    // Place the pivot in its correct position
    Swap(vec, i + 1, high);

    // Return the partition index
    return i + 1;
}

void quickSort(std::vector<int>& vec, int low, int high) {

    // Base case
    if (low < high) {

        // Partition the array
        int pi = partition(vec, low, high);

        // Sort elements before the pivot
        quickSort(vec, low, pi - 1);

        // Sort elements after the pivot
        quickSort(vec, pi + 1, high);
    }
}

int main() {

    std::vector<int> vec = { 4, 3, 1, 2, 5, 9, 7, 10, 6 };

    int n = vec.size();

    // Print the sorted array
    for (int i : vec) {
        std::cout << i << " ";
    }

    std::cout << "\n\n";

    // Calling Quick Sort
    quickSort(vec, 0, n - 1);

    // Print the sorted array
    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}
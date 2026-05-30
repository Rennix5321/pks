#include "InsertionSort.h"
#include <queue>

std::queue<SortStep> InsertionSort::generateSteps(std::vector<int>& array) {
    std::queue<SortStep> steps;
    std::vector<int> arr = array;
    int n = arr.size();
    
    steps.push(SortStep(arr, -1, -1, false));
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        steps.push(SortStep(arr, i, j, false));
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            steps.push(SortStep(arr, j + 1, j, false));
            j--;
        }
        
        arr[j + 1] = key;
        steps.push(SortStep(arr, j + 1, -1, false));
    }
    
    steps.push(SortStep(arr, -1, -1, true));
    return steps;
}

std::string InsertionSort::getName() const {
    return "Сортировка вставками";
}
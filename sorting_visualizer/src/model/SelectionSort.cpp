#include "SelectionSort.h"
#include <queue>

std::queue<SortStep> SelectionSort::generateSteps(std::vector<int>& array) {
    std::queue<SortStep> steps;
    std::vector<int> arr = array;
    int n = arr.size();
    
    steps.push(SortStep(arr, -1, -1, false));
    
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        
        for (int j = i + 1; j < n; j++) {
            steps.push(SortStep(arr, minIdx, j, false));
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
            steps.push(SortStep(arr, i, minIdx, false));
        }
    }
    
    steps.push(SortStep(arr, -1, -1, true));
    return steps;
}

std::string SelectionSort::getName() const {
    return "Сортировка выбором";
}
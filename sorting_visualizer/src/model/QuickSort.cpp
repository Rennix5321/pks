#include "QuickSort.h"
#include <queue>

std::queue<SortStep> QuickSort::generateSteps(std::vector<int>& array) {
    std::queue<SortStep> steps;
    std::vector<int> arr = array;
    
    steps.push(SortStep(arr, -1, -1, false));
    
    std::function<void(int, int)> quickSort = [&](int low, int high) {
        if (low < high) {
            int pivot = arr[high];
            int i = low - 1;
            
            for (int j = low; j < high; j++) {
                steps.push(SortStep(arr, j, high, false));
                
                if (arr[j] <= pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                    steps.push(SortStep(arr, i, j, false));
                }
            }
            
            std::swap(arr[i + 1], arr[high]);
            steps.push(SortStep(arr, i + 1, high, false));
            int pi = i + 1;
            
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    };
    
    quickSort(0, arr.size() - 1);
    steps.push(SortStep(arr, -1, -1, true));
    
    return steps;
}

std::string QuickSort::getName() const {
    return "Быстрая сортировка";
}
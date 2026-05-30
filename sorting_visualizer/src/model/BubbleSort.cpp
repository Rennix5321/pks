#include "BubbleSort.h"
#include <queue>

std::queue<SortStep> BubbleSort::generateSteps(std::vector<int>& array) {
    std::queue<SortStep> steps;
    std::vector<int> arr = array;
    int n = arr.size();
    
    steps.push(SortStep(arr, -1, -1, false));
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            steps.push(SortStep(arr, j, j + 1, false));
            
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                steps.push(SortStep(arr, j, j + 1, false));
            }
        }
    }
    
    steps.push(SortStep(arr, -1, -1, true));
    return steps;
}

std::string BubbleSort::getName() const {
    return "Пузырьковая сортировка";
}
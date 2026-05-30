#include "MergeSort.h"
#include <queue>
#include <functional>

std::queue<SortStep> MergeSort::generateSteps(std::vector<int>& array) {
    std::queue<SortStep> steps;
    std::vector<int> arr = array;
    
    steps.push(SortStep(arr, -1, -1, false));
    
    // Вспомогательная рекурсивная функция
    std::function<void(int, int)> mergeSort = [&](int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            
            std::vector<int> temp(right - left + 1);
            int i = left, j = mid + 1, k = 0;
            
            while (i <= mid && j <= right) {
                steps.push(SortStep(arr, i, j, false));
                if (arr[i] <= arr[j]) {
                    temp[k++] = arr[i++];
                } else {
                    temp[k++] = arr[j++];
                }
            }
            
            while (i <= mid) {
                temp[k++] = arr[i++];
            }
            
            while (j <= right) {
                temp[k++] = arr[j++];
            }
            
            for (i = left, k = 0; i <= right; i++, k++) {
                arr[i] = temp[k];
                steps.push(SortStep(arr, i, -1, false));
            }
        }
    };
    
    mergeSort(0, arr.size() - 1);
    steps.push(SortStep(arr, -1, -1, true));
    
    return steps;
}

std::string MergeSort::getName() const {
    return "Сортировка слиянием";
}
#ifndef SORTINGMANAGER_H
#define SORTINGMANAGER_H

#include <memory>
#include <queue>
#include <string>
#include "../model/SortingAlgorithm.h"
#include "../model/BubbleSort.h"
#include "../model/MergeSort.h"
#include "../model/QuickSort.h"
#include "../model/InsertionSort.h"
#include "../model/SelectionSort.h"

class SortingManager {
private:
    std::unique_ptr<SortingAlgorithm> algorithm;
    
public:
    SortingManager();
    
    void setAlgorithm(int index);
    std::queue<SortStep> generateSteps(std::vector<int>& array);
    std::string getAlgorithmName() const;
};

#endif
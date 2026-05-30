#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "SortingAlgorithm.h"
#include <string>
#include <queue>

class SelectionSort : public SortingAlgorithm {
public:
    std::queue<SortStep> generateSteps(std::vector<int>& array) override;
    std::string getName() const override;
};

#endif
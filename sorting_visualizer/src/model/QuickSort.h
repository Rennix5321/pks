#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortingAlgorithm.h"
#include <string>
#include <queue>

class QuickSort : public SortingAlgorithm {
public:
    std::queue<SortStep> generateSteps(std::vector<int>& array) override;
    std::string getName() const override;
};

#endif
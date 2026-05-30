#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortingAlgorithm.h"
#include <string>
#include <queue>

class MergeSort : public SortingAlgorithm {
public:
    std::queue<SortStep> generateSteps(std::vector<int>& array) override;
    std::string getName() const override;
};

#endif
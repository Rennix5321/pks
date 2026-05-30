#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "SortingAlgorithm.h"
#include <string>
#include <queue>

class InsertionSort : public SortingAlgorithm {
public:
    std::queue<SortStep> generateSteps(std::vector<int>& array) override;
    std::string getName() const override;
};

#endif
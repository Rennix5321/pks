#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlgorithm.h"
#include <string>
#include <queue>

class BubbleSort : public SortingAlgorithm {
public:
    std::queue<SortStep> generateSteps(std::vector<int>& array) override;
    std::string getName() const override;
};

#endif
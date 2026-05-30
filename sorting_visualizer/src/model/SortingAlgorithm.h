#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H

#include <vector>
#include <functional>
#include <string>
#include <queue>

struct SortStep {
    std::vector<int> array;
    int compareIdx1;
    int compareIdx2;
    bool isComplete;
    
    SortStep() : compareIdx1(-1), compareIdx2(-1), isComplete(false) {}
    SortStep(const std::vector<int>& arr, int idx1, int idx2, bool complete = false)
        : array(arr), compareIdx1(idx1), compareIdx2(idx2), isComplete(complete) {}
};

class SortingAlgorithm {
public:
    virtual ~SortingAlgorithm() = default;
    virtual std::queue<SortStep> generateSteps(std::vector<int>& array) = 0;
    virtual std::string getName() const = 0;
};

#endif
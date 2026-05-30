#include "SortingManager.h"
#include <memory>

SortingManager::SortingManager() {
    algorithm = std::make_unique<BubbleSort>();
}

void SortingManager::setAlgorithm(int index) {
    switch (index) {
        case 0:
            algorithm = std::make_unique<BubbleSort>();
            break;
        case 1:
            algorithm = std::make_unique<MergeSort>();
            break;
        case 2:
            algorithm = std::make_unique<QuickSort>();
            break;
        case 3:
            algorithm = std::make_unique<InsertionSort>();
            break;
        case 4:
            algorithm = std::make_unique<SelectionSort>();
            break;
        default:
            algorithm = std::make_unique<BubbleSort>();
            break;
    }
}

std::queue<SortStep> SortingManager::generateSteps(std::vector<int>& array) {
    if (algorithm) {
        return algorithm->generateSteps(array);
    }
    return std::queue<SortStep>();
}

std::string SortingManager::getAlgorithmName() const {
    if (algorithm) {
        return algorithm->getName();
    }
    return "Unknown";
}
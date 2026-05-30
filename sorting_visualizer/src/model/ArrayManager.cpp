#include "ArrayManager.h"
#include <random>
#include <algorithm>

ArrayManager::ArrayManager() 
    : size(50)
    , allowDuplicates(true) 
{
    generateArray();
}

void ArrayManager::generateArray() {
    array.clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    
    if (allowDuplicates) {
        std::uniform_int_distribution<> dis(1, size);
        for (int i = 0; i < size; i++) {
            array.push_back(dis(gen));
        }
    } else {
        for (int i = 1; i <= size; i++) {
            array.push_back(i);
        }
        std::shuffle(array.begin(), array.end(), gen);
    }
}

void ArrayManager::regenerateArray() {
    generateArray();
}

std::vector<int> ArrayManager::getArray() const {
    return array;
}

void ArrayManager::setArray(const std::vector<int>& newArray) {
    array = newArray;
    size = static_cast<int>(array.size());
}

void ArrayManager::setSize(int newSize) {
    if (newSize >= 10 && newSize <= 100) {
        size = newSize;
        generateArray();
    }
}

void ArrayManager::setDuplicates(bool flag) {
    allowDuplicates = flag;
    generateArray();
}

int ArrayManager::getSize() const {
    return size;
}

bool ArrayManager::getAllowDuplicates() const {
    return allowDuplicates;
}
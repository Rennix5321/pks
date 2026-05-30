#include <gtest/gtest.h>
#include "src/model/BubbleSort.h"
#include "src/model/QuickSort.h"
#include "src/model/MergeSort.h"
#include "src/model/InsertionSort.h"
#include "src/model/SelectionSort.h"
#include "src/model/ArrayManager.h"
#include <algorithm>

//BubbleSort Tests

class BubbleSortTest : public ::testing::Test {
protected:
    BubbleSort sorter;
    ArrayManager arrayManager;
};

TEST_F(BubbleSortTest, SortRandomArray) {
    arrayManager.setSize(50);
    arrayManager.generateArray();
    std::vector<int> arr = arrayManager.getArray();
    
    auto steps = sorter.generateSteps(arr);
    
    SortStep lastStep;
    while (!steps.empty()) {
        lastStep = steps.front();
        steps.pop();
    }
    
    EXPECT_TRUE(std::is_sorted(lastStep.array.begin(), lastStep.array.end()));
}

TEST_F(BubbleSortTest, GetName) {
    EXPECT_EQ(sorter.getName(), "Пузырьковая сортировка");
}

//QuickSort Tests

class QuickSortTest : public ::testing::Test {
protected:
    QuickSort sorter;
    ArrayManager arrayManager;
};

TEST_F(QuickSortTest, SortRandomArray) {
    arrayManager.setSize(50);
    arrayManager.generateArray();
    std::vector<int> arr = arrayManager.getArray();
    
    auto steps = sorter.generateSteps(arr);
    
    SortStep lastStep;
    while (!steps.empty()) {
        lastStep = steps.front();
        steps.pop();
    }
    
    EXPECT_TRUE(std::is_sorted(lastStep.array.begin(), lastStep.array.end()));
}

TEST_F(QuickSortTest, GetName) {
    EXPECT_EQ(sorter.getName(), "Быстрая сортировка");
}

//MergeSort Tests

class MergeSortTest : public ::testing::Test {
protected:
    MergeSort sorter;
    ArrayManager arrayManager;
};

TEST_F(MergeSortTest, SortRandomArray) {
    arrayManager.setSize(50);
    arrayManager.generateArray();
    std::vector<int> arr = arrayManager.getArray();
    
    auto steps = sorter.generateSteps(arr);
    
    SortStep lastStep;
    while (!steps.empty()) {
        lastStep = steps.front();
        steps.pop();
    }
    
    EXPECT_TRUE(std::is_sorted(lastStep.array.begin(), lastStep.array.end()));
}

TEST_F(MergeSortTest, GetName) {
    EXPECT_EQ(sorter.getName(), "Сортировка слиянием");
}

//InsertionSort Tests

class InsertionSortTest : public ::testing::Test {
protected:
    InsertionSort sorter;
    ArrayManager arrayManager;
};

TEST_F(InsertionSortTest, SortRandomArray) {
    arrayManager.setSize(50);
    arrayManager.generateArray();
    std::vector<int> arr = arrayManager.getArray();
    
    auto steps = sorter.generateSteps(arr);
    
    SortStep lastStep;
    while (!steps.empty()) {
        lastStep = steps.front();
        steps.pop();
    }
    
    EXPECT_TRUE(std::is_sorted(lastStep.array.begin(), lastStep.array.end()));
}

TEST_F(InsertionSortTest, GetName) {
    EXPECT_EQ(sorter.getName(), "Сортировка вставками");
}

//SelectionSort Tests

class SelectionSortTest : public ::testing::Test {
protected:
    SelectionSort sorter;
    ArrayManager arrayManager;
};

TEST_F(SelectionSortTest, SortRandomArray) {
    arrayManager.setSize(50);
    arrayManager.generateArray();
    std::vector<int> arr = arrayManager.getArray();
    
    auto steps = sorter.generateSteps(arr);
    
    SortStep lastStep;
    while (!steps.empty()) {
        lastStep = steps.front();
        steps.pop();
    }
    
    EXPECT_TRUE(std::is_sorted(lastStep.array.begin(), lastStep.array.end()));
}

TEST_F(SelectionSortTest, GetName) {
    EXPECT_EQ(sorter.getName(), "Сортировка выбором");
}
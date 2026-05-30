#include <gtest/gtest.h>
#include "src/model/ArrayManager.h"
#include "src/controller/SortingManager.h"
#include <set>
#include <algorithm>

// ============ Сценарий 1: Генерация массива и проверка размера ============
TEST(ScenarioTest, GenerateArrayAndCheckSize) {
    ArrayManager manager;
    
    for (int size = 10; size <= 100; size += 10) {
        manager.setSize(size);
        EXPECT_EQ(manager.getArray().size(), (size_t)size);
    }
}

// ============ Сценарий 2: Сортировка случайного массива ============
TEST(ScenarioTest, SortRandomArray) {
    ArrayManager arrayManager;
    SortingManager sorter;
    
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

// ============ Сценарий 3: Все алгоритмы сортируют массив правильно ============
TEST(ScenarioTest, AllAlgorithmsSortCorrectly) {
    SortingManager manager;
    ArrayManager arrayManager;
    
    arrayManager.setSize(50);
    arrayManager.generateArray();
    std::vector<int> original = arrayManager.getArray();
    
    for (int i = 0; i < 5; i++) {
        manager.setAlgorithm(i);
        std::vector<int> arr = original;
        auto steps = manager.generateSteps(arr);
        
        SortStep lastStep;
        while (!steps.empty()) {
            lastStep = steps.front();
            steps.pop();
        }
        
        EXPECT_TRUE(std::is_sorted(lastStep.array.begin(), lastStep.array.end()))
            << "Failed for algorithm: " << manager.getAlgorithmName();
    }
}

// ============ Сценарий 4: Работа с дубликатами ============
TEST(ScenarioTest, HandleDuplicatesCorrectly) {
    ArrayManager manager;
    manager.setDuplicates(true);
    manager.setSize(50);
    manager.generateArray();
    
    std::vector<int> arr = manager.getArray();
    
    for (int val : arr) {
        EXPECT_GE(val, 1);
        EXPECT_LE(val, 50);
    }
}

// ============ Сценарий 5: Работа без дубликатов ============
TEST(ScenarioTest, HandleNoDuplicatesCorrectly) {
    ArrayManager manager;
    manager.setDuplicates(false);
    manager.setSize(50);
    manager.generateArray();
    
    std::vector<int> arr = manager.getArray();
    std::set<int> uniqueSet(arr.begin(), arr.end());
    EXPECT_EQ(uniqueSet.size(), arr.size());
}

// ============ Сценарий 6: Сортировка больших массивов ============
TEST(ScenarioTest, SortLargeArray) {
    SortingManager manager;
    ArrayManager arrayManager;
    
    arrayManager.setSize(100);
    arrayManager.generateArray();
    
    std::vector<int> arr = arrayManager.getArray();
    auto steps = manager.generateSteps(arr);
    
    EXPECT_FALSE(steps.empty());
}

// ============ Сценарий 7: Сравнение результатов разных алгоритмов ============
TEST(ScenarioTest, CompareAlgorithmsResults) {
    ArrayManager arrayManager;
    arrayManager.setSize(50);
    arrayManager.generateArray();
    std::vector<int> original = arrayManager.getArray();
    
    std::vector<std::vector<int>> results;
    SortingManager manager;
    
    for (int i = 0; i < 5; i++) {
        manager.setAlgorithm(i);
        std::vector<int> arr = original;
        auto steps = manager.generateSteps(arr);
        
        SortStep lastStep;
        while (!steps.empty()) {
            lastStep = steps.front();
            steps.pop();
        }
        results.push_back(lastStep.array);
    }
    
    for (size_t i = 1; i < results.size(); i++) {
        EXPECT_EQ(results[0], results[i]);
    }
}

// ============ Сценарий 8: Полный цикл работы программы ============
TEST(ScenarioTest, FullProgramWorkflow) {
    // 1. Создание массива
    ArrayManager arrayManager;
    arrayManager.setSize(20);
    arrayManager.generateArray();
    
    // 2. Выбор алгоритма
    SortingManager sortingManager;
    sortingManager.setAlgorithm(2); // Быстрая сортировка
    
    // 3. Генерация шагов сортировки
    std::vector<int> arr = arrayManager.getArray();
    auto steps = sortingManager.generateSteps(arr);
    
    EXPECT_FALSE(steps.empty());
    
    // 4. Проверка последнего шага
    SortStep lastStep;
    while (!steps.empty()) {
        lastStep = steps.front();
        steps.pop();
    }
    
    EXPECT_TRUE(std::is_sorted(lastStep.array.begin(), lastStep.array.end()));
}
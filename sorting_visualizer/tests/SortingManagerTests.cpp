#include <gtest/gtest.h>
#include "src/controller/SortingManager.h"
#include "src/model/ArrayManager.h"

class SortingManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        manager = new SortingManager();
        arrayManager = new ArrayManager();
    }
    
    void TearDown() override {
        delete manager;
        delete arrayManager;
    }
    
    SortingManager* manager;
    ArrayManager* arrayManager;
};

// Тест 1: Алгоритм по умолчанию - пузырьковая сортировка
TEST_F(SortingManagerTest, DefaultAlgorithmIsBubbleSort) {
    EXPECT_EQ(manager->getAlgorithmName(), "Пузырьковая сортировка");
}

// Тест 2: Установка быстрой сортировки
TEST_F(SortingManagerTest, SetQuickSortAlgorithm) {
    manager->setAlgorithm(2);
    EXPECT_EQ(manager->getAlgorithmName(), "Быстрая сортировка");
}

// Тест 3: Установка сортировки слиянием
TEST_F(SortingManagerTest, SetMergeSortAlgorithm) {
    manager->setAlgorithm(1);
    EXPECT_EQ(manager->getAlgorithmName(), "Сортировка слиянием");
}

// Тест 4: Установка сортировки вставками
TEST_F(SortingManagerTest, SetInsertionSortAlgorithm) {
    manager->setAlgorithm(3);
    EXPECT_EQ(manager->getAlgorithmName(), "Сортировка вставками");
}

// Тест 5: Установка сортировки выбором
TEST_F(SortingManagerTest, SetSelectionSortAlgorithm) {
    manager->setAlgorithm(4);
    EXPECT_EQ(manager->getAlgorithmName(), "Сортировка выбором");
}

// Тест 6: Неверный индекс - возвращает пузырьковую сортировку
TEST_F(SortingManagerTest, InvalidIndexReturnsBubbleSort) {
    manager->setAlgorithm(99);
    EXPECT_EQ(manager->getAlgorithmName(), "Пузырьковая сортировка");
}

// Тест 7: Генерация шагов для массива минимального размера (10)
TEST_F(SortingManagerTest, GenerateStepsForMinimumSizeArray) {
    arrayManager->setSize(10);
    arrayManager->generateArray();
    std::vector<int> arr = arrayManager->getArray();
    
    auto steps = manager->generateSteps(arr);
    EXPECT_FALSE(steps.empty());
}

// Тест 8: Генерация шагов для массива максимального размера (100)
TEST_F(SortingManagerTest, GenerateStepsForMaximumSizeArray) {
    arrayManager->setSize(100);
    arrayManager->generateArray();
    std::vector<int> arr = arrayManager->getArray();
    
    auto steps = manager->generateSteps(arr);
    EXPECT_FALSE(steps.empty());
}

// Тест 9: Генерация шагов для массива среднего размера (50)
TEST_F(SortingManagerTest, GenerateStepsForMediumSizeArray) {
    arrayManager->setSize(50);
    arrayManager->generateArray();
    std::vector<int> arr = arrayManager->getArray();
    
    auto steps = manager->generateSteps(arr);
    EXPECT_FALSE(steps.empty());
}
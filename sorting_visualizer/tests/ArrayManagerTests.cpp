#include <gtest/gtest.h>
#include "src/model/ArrayManager.h"
#include <algorithm>
#include <set>

class ArrayManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        manager = new ArrayManager();
    }
    
    void TearDown() override {
        delete manager;
    }
    
    ArrayManager* manager;
};

TEST_F(ArrayManagerTest, DefaultSizeIsFifty) {
    EXPECT_EQ(manager->getSize(), 50);
}

TEST_F(ArrayManagerTest, GenerateArrayWithDuplicates) {
    manager->setDuplicates(true);
    manager->generateArray();
    std::vector<int> arr = manager->getArray();
    
    EXPECT_EQ(arr.size(), 50);
    for (int val : arr) {
        EXPECT_GE(val, 1);
        EXPECT_LE(val, 50);
    }
}

TEST_F(ArrayManagerTest, GenerateArrayWithoutDuplicates) {
    manager->setDuplicates(false);
    manager->generateArray();
    std::vector<int> arr = manager->getArray();
    
    EXPECT_EQ(arr.size(), 50);
    
    std::set<int> uniqueSet(arr.begin(), arr.end());
    EXPECT_EQ(uniqueSet.size(), 50);
}

TEST_F(ArrayManagerTest, SetSizeWorks) {
    manager->setSize(30);
    EXPECT_EQ(manager->getSize(), 30);
    
    std::vector<int> arr = manager->getArray();
    EXPECT_EQ(arr.size(), 30);
}

TEST_F(ArrayManagerTest, SetMinimumSize) {
    manager->setSize(10);
    EXPECT_EQ(manager->getSize(), 10);
    EXPECT_EQ(manager->getArray().size(), 10);
}

TEST_F(ArrayManagerTest, SetMaximumSize) {
    manager->setSize(100);
    EXPECT_EQ(manager->getSize(), 100);
    EXPECT_EQ(manager->getArray().size(), 100);
}

TEST_F(ArrayManagerTest, InvalidSizeIgnored) {
    manager->setSize(5);
    EXPECT_EQ(manager->getSize(), 50);
    
    manager->setSize(200);
    EXPECT_EQ(manager->getSize(), 50);
}

TEST_F(ArrayManagerTest, ToggleDuplicates) {
    manager->setDuplicates(true);
    EXPECT_TRUE(manager->getAllowDuplicates());
    
    manager->setDuplicates(false);
    EXPECT_FALSE(manager->getAllowDuplicates());
}

TEST_F(ArrayManagerTest, RegenerateArray) {
    std::vector<int> first = manager->getArray();
    manager->regenerateArray();
    std::vector<int> second = manager->getArray();
    
    EXPECT_EQ(first.size(), second.size());
}
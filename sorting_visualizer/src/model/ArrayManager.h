#ifndef ARRAYMANAGER_H
#define ARRAYMANAGER_H

#include <vector>

class ArrayManager {
private:
    std::vector<int> array;
    int size;
    bool allowDuplicates;

public:
    ArrayManager();
    
    void generateArray();
    void regenerateArray();
    std::vector<int> getArray() const;
    void setArray(const std::vector<int>& newArray);
    void setSize(int newSize);
    void setDuplicates(bool flag);
    int getSize() const;
    bool getAllowDuplicates() const;
};

#endif
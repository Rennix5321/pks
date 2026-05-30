#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "../model/ArrayManager.h"
#include "../view/VisualizationEngine.h"
#include "SortingManager.h"
#include "AnimationController.h"

class AppController {
private:
    SortingManager sortingManager;
    ArrayManager arrayManager;
    VisualizationEngine visualization;
    AnimationController animation;
    
    bool m_hasSteps;
    std::vector<int> m_currentArray;
    
    void prepareAndStartSorting();

public:
    AppController();
    
    void start();
    void pause();
    void reset();
    
    void generateArray();
    void setArraySize(int size);
    void setDuplicates(bool flag);
    void setAlgorithm(int index);
    void setAnimationSpeed(int speed);
    
    std::vector<int> getCurrentArray() const;
    VisualizationEngine* getVisualization() { return &visualization; }
};

#endif
#include "AppController.h"
#include <QMetaObject>

AppController::AppController()
    : m_hasSteps(false) {
    visualization.setArray(arrayManager.getArray());
    m_currentArray = arrayManager.getArray();
    
    animation.setOnStep([this](const SortStep& step) {
        QMetaObject::invokeMethod(&visualization, [this, step]() {
            visualization.setArray(step.array);
            visualization.highlight(step.compareIdx1, step.compareIdx2);
            m_currentArray = step.array;
        });
    });
    
    animation.setOnComplete([this]() {
        QMetaObject::invokeMethod(&visualization, [this]() {
            visualization.clearHighlight();
        });
        m_hasSteps = false;
    });
}

void AppController::prepareAndStartSorting() {
    std::vector<int> array = arrayManager.getArray();
    std::queue<SortStep> steps = sortingManager.generateSteps(array);
    animation.setSteps(steps);
    m_hasSteps = true;
    animation.play();
}

void AppController::start() {
    if (animation.isRunning()) return;
    
    // Если есть сохранённые шаги (после паузы) - продолжаем
    if (animation.hasSteps() && m_hasSteps) {
        animation.resume();
    } 
    // Иначе начинаем новую сортировку
    else {
        prepareAndStartSorting();
    }
}

void AppController::pause() {
    animation.pause();
}

void AppController::reset() {
    animation.stop();
    m_hasSteps = false;
    generateArray();
    QMetaObject::invokeMethod(&visualization, [this]() {
        visualization.setArray(arrayManager.getArray());
        visualization.clearHighlight();
    });
}

void AppController::generateArray() {
    animation.stop();
    m_hasSteps = false;
    arrayManager.generateArray();
    QMetaObject::invokeMethod(&visualization, [this]() {
        visualization.setArray(arrayManager.getArray());
        visualization.clearHighlight();
    });
    m_currentArray = arrayManager.getArray();
}

void AppController::setArraySize(int size) {
    animation.stop();
    m_hasSteps = false;
    arrayManager.setSize(size);
    QMetaObject::invokeMethod(&visualization, [this]() {
        visualization.setArray(arrayManager.getArray());
        visualization.clearHighlight();
    });
    m_currentArray = arrayManager.getArray();
}

void AppController::setDuplicates(bool flag) {
    animation.stop();
    m_hasSteps = false;
    arrayManager.setDuplicates(flag);
    QMetaObject::invokeMethod(&visualization, [this]() {
        visualization.setArray(arrayManager.getArray());
        visualization.clearHighlight();
    });
    m_currentArray = arrayManager.getArray();
}

void AppController::setAlgorithm(int index) {
    animation.stop();
    m_hasSteps = false;
    sortingManager.setAlgorithm(index);
}

void AppController::setAnimationSpeed(int speed) {
    animation.setSpeed(speed);
}

std::vector<int> AppController::getCurrentArray() const {
    return m_currentArray;
}
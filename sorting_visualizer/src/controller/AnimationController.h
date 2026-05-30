#ifndef ANIMATIONCONTROLLER_H
#define ANIMATIONCONTROLLER_H

#include <QObject>
#include <QTimer>
#include <functional>
#include <queue>
#include "../model/SortingAlgorithm.h"

class AnimationController : public QObject {
    Q_OBJECT

private:
    int m_speed;
    bool m_isRunning;
    bool m_isPaused;
    QTimer* m_timer;
    std::queue<SortStep> m_steps;
    std::queue<SortStep> m_remainingSteps;
    std::function<void(const SortStep&)> m_onStep;
    std::function<void()> m_onComplete;

private slots:
    void processNextStep();

public:
    explicit AnimationController(QObject* parent = nullptr);
    ~AnimationController();
    
    void setSpeed(int speed);
    void setSteps(std::queue<SortStep> steps);
    void play();
    void pause();
    void stop();
    void clearSteps();
    void resume();
    
    bool isRunning() const { return m_isRunning; }
    bool hasSteps() const { return !m_remainingSteps.empty(); }
    void setOnStep(std::function<void(const SortStep&)> callback);
    void setOnComplete(std::function<void()> callback);
};

#endif
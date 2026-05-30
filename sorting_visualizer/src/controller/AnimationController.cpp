#include "AnimationController.h"

AnimationController::AnimationController(QObject* parent)
    : QObject(parent)
    , m_speed(50)
    , m_isRunning(false)
    , m_isPaused(false) {
    m_timer = new QTimer(this);
    m_timer->setSingleShot(true);
    connect(m_timer, &QTimer::timeout, this, &AnimationController::processNextStep);
}

AnimationController::~AnimationController() {
    stop();
}

void AnimationController::setSpeed(int speed) {
    m_speed = speed;
}

void AnimationController::setSteps(std::queue<SortStep> steps) {
    m_steps = steps;
    m_remainingSteps = steps;
}

void AnimationController::play() {
    if (m_isRunning) return;
    
    if (m_remainingSteps.empty()) {
        return;
    }
    
    m_isRunning = true;
    m_isPaused = false;
    processNextStep();
}

void AnimationController::pause() {
    if (!m_isRunning) return;
    m_isPaused = true;
    m_isRunning = false;
    m_timer->stop();
}

void AnimationController::resume() {
    if (m_isRunning) return;
    if (m_remainingSteps.empty()) {
        if (m_onComplete) {
            m_onComplete();
        }
        return;
    }
    
    m_isRunning = true;
    m_isPaused = false;
    processNextStep();
}

void AnimationController::stop() {
    m_isRunning = false;
    m_isPaused = false;
    m_timer->stop();
    while (!m_steps.empty()) {
        m_steps.pop();
    }
    while (!m_remainingSteps.empty()) {
        m_remainingSteps.pop();
    }
}

void AnimationController::clearSteps() {
    while (!m_steps.empty()) {
        m_steps.pop();
    }
    while (!m_remainingSteps.empty()) {
        m_remainingSteps.pop();
    }
}

void AnimationController::processNextStep() {
    if (!m_isRunning || m_isPaused) return;
    
    if (m_remainingSteps.empty()) {
        m_isRunning = false;
        m_isPaused = false;
        if (m_onComplete) {
            m_onComplete();
        }
        return;
    }
    
    SortStep step = m_remainingSteps.front();
    m_remainingSteps.pop();
    
    if (m_onStep) {
        m_onStep(step);
    }
    
    if (m_isRunning && !m_isPaused && !m_remainingSteps.empty()) {
        m_timer->start(m_speed);
    }
}

void AnimationController::setOnStep(std::function<void(const SortStep&)> callback) {
    m_onStep = callback;
}

void AnimationController::setOnComplete(std::function<void()> callback) {
    m_onComplete = callback;
}
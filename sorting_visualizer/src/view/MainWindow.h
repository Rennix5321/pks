#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QSlider>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>


class AppController;
class VisualizationEngine;

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    AppController* controller;
    VisualizationEngine* visualizationWidget;
    QComboBox* algorithmSelector;
    QSlider* sizeSlider;
    QSlider* speedSlider;
    QPushButton* startButton;
    QPushButton* pauseButton;
    QPushButton* resetButton;
    QPushButton* generateButton;
    QCheckBox* duplicatesCheckBox;
    
    void setupUI();
    void connectSignals();

private slots:
    void onStartClicked();
    void onPauseClicked();
    void onResetClicked();
    void onGenerateClicked();
    void onAlgorithmChanged(int index);
    void onSizeChanged(int value);
    void onSpeedChanged(int value);
    void onDuplicatesToggled(bool checked);

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void setArraySize(int size);
    void setAlgorithm(int index);
    void setAnimationSpeed(int speed);
};

#endif
#include "MainWindow.h"
#include "VisualizationEngine.h"
#include "../controller/AppController.h"
#include <QLabel>
#include <QGroupBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    controller = new AppController();
    setupUI();
    connectSignals();
}

MainWindow::~MainWindow() {
    delete controller;
}

void MainWindow::setupUI() {
    setWindowTitle("Визуализатор алгоритмов сортировки");
    setMinimumSize(1000, 600);
    
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    
    visualizationWidget = controller->getVisualization();
    mainLayout->addWidget(visualizationWidget, 1);
    
    QGroupBox* controlsGroup = new QGroupBox("Управление");
    QVBoxLayout* controlsLayout = new QVBoxLayout(controlsGroup);

    QHBoxLayout* algorithmLayout = new QHBoxLayout();
    algorithmLayout->addWidget(new QLabel("Алгоритм сортировки:"));
    algorithmSelector = new QComboBox();
    algorithmSelector->addItem("Пузырьковая сортировка");
    algorithmSelector->addItem("Сортировка слиянием");
    algorithmSelector->addItem("Быстрая сортировка");
    algorithmSelector->addItem("Сортировка вставками");
    algorithmSelector->addItem("Сортировка выбором");
    algorithmLayout->addWidget(algorithmSelector);
    controlsLayout->addLayout(algorithmLayout);

    QHBoxLayout* sizeLayout = new QHBoxLayout();
    sizeLayout->addWidget(new QLabel("Размер массива (10-100):"));
    sizeSlider = new QSlider(Qt::Horizontal);
    sizeSlider->setMinimum(10);
    sizeSlider->setMaximum(100);
    sizeSlider->setValue(50);
    sizeLayout->addWidget(sizeSlider);
    
    QLabel* sizeValue = new QLabel("50");
    sizeValue->setMinimumWidth(40);
    sizeValue->setAlignment(Qt::AlignCenter);
    sizeLayout->addWidget(sizeValue);
    controlsLayout->addLayout(sizeLayout);

    QHBoxLayout* speedLayout = new QHBoxLayout();
    speedLayout->addWidget(new QLabel("Скорость анимации:"));
    speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setMinimum(1);
    speedSlider->setMaximum(200);
    speedSlider->setValue(50);
    speedLayout->addWidget(speedSlider);
    
    QLabel* speedValue = new QLabel("50");
    speedValue->setMinimumWidth(40);
    speedValue->setAlignment(Qt::AlignCenter);
    speedLayout->addWidget(speedValue);
    controlsLayout->addLayout(speedLayout);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    startButton = new QPushButton("Старт");
    startButton->setStyleSheet("background-color: #4CAF50; color: white; font-weight: bold; padding: 8px;");
    pauseButton = new QPushButton("Пауза");
    pauseButton->setStyleSheet("background-color: #FF9800; color: white; font-weight: bold; padding: 8px;");
    resetButton = new QPushButton("Сброс");
    resetButton->setStyleSheet("background-color: #f44336; color: white; font-weight: bold; padding: 8px;");
    generateButton = new QPushButton("Сгенерировать массив");
    generateButton->setStyleSheet("background-color: #2196F3; color: white; font-weight: bold; padding: 8px;");
    
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(pauseButton);
    buttonLayout->addWidget(resetButton);
    buttonLayout->addWidget(generateButton);
    controlsLayout->addLayout(buttonLayout);

    QHBoxLayout* optionLayout = new QHBoxLayout();
    duplicatesCheckBox = new QCheckBox("Разрешить повторяющиеся значения");
    duplicatesCheckBox->setChecked(true);
    optionLayout->addWidget(duplicatesCheckBox);
    controlsLayout->addLayout(optionLayout);
    
    mainLayout->addWidget(controlsGroup);

    connect(sizeSlider, &QSlider::valueChanged, this, [sizeValue](int val) {
        sizeValue->setText(QString::number(val));
    });
    connect(speedSlider, &QSlider::valueChanged, this, [speedValue](int val) {
        speedValue->setText(QString::number(val));
    });
}

void MainWindow::connectSignals() {
    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::onPauseClicked);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateClicked);
    connect(algorithmSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), 
            this, &MainWindow::onAlgorithmChanged);
    connect(sizeSlider, &QSlider::valueChanged, this, &MainWindow::onSizeChanged);
    connect(speedSlider, &QSlider::valueChanged, this, &MainWindow::onSpeedChanged);
    connect(duplicatesCheckBox, &QCheckBox::toggled, this, &MainWindow::onDuplicatesToggled);
}

void MainWindow::onStartClicked() {
    controller->start();
}

void MainWindow::onPauseClicked() {
    controller->pause();
}

void MainWindow::onResetClicked() {
    controller->reset();
}

void MainWindow::onGenerateClicked() {
    controller->generateArray();
}

void MainWindow::onAlgorithmChanged(int index) {
    controller->setAlgorithm(index);
}

void MainWindow::onSizeChanged(int value) {
    controller->setArraySize(value);
}

void MainWindow::onSpeedChanged(int value) {
    controller->setAnimationSpeed(201 - value);
}

void MainWindow::onDuplicatesToggled(bool checked) {
    controller->setDuplicates(checked);
}

void MainWindow::setArraySize(int size) {
    controller->setArraySize(size);
    visualizationWidget->update();
}

void MainWindow::setAlgorithm(int index) {
    controller->setAlgorithm(index);
    algorithmSelector->setCurrentIndex(index);
}

void MainWindow::setAnimationSpeed(int speed) {
    controller->setAnimationSpeed(101 - speed);
    speedSlider->setValue(101 - speed);
}
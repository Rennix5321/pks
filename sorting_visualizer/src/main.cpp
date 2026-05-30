// src/main.cpp
#include <QApplication>
#include "view/MainWindow.h"
#include <iostream>
#include <string>

void printHelp() {
    std::cout << "========================================" << std::endl;
    std::cout << "   Sorting Visualizer - Help           " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Usage: SortingVisualizer [OPTIONS]" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --help, -h          Show this help message" << std::endl;
    std::cout << "  --version, -v       Show version information" << std::endl;
    std::cout << "  --size <N>          Set initial array size (10-100)" << std::endl;
    std::cout << "  --algorithm <N>     Set sorting algorithm (0-4)" << std::endl;
    std::cout << "  --speed <ms>        Set animation speed in milliseconds" << std::endl;
    std::cout << "  --no-gui            Run in headless mode (for testing)" << std::endl;
    std::cout << std::endl;
    std::cout << "Algorithms:" << std::endl;
    std::cout << "  0 - Bubble Sort" << std::endl;
    std::cout << "  1 - Merge Sort" << std::endl;
    std::cout << "  2 - Quick Sort" << std::endl;
    std::cout << "  3 - Insertion Sort" << std::endl;
    std::cout << "  4 - Selection Sort" << std::endl;
    std::cout << std::endl;
    std::cout << "Examples:" << std::endl;
    std::cout << "  SortingVisualizer --size 30 --algorithm 2" << std::endl;
    std::cout << "  SortingVisualizer --size 50 --speed 10" << std::endl;
    std::cout << "  SortingVisualizer --no-gui" << std::endl;
}

void printVersion() {
    std::cout << "Sorting Visualizer v1.0.0" << std::endl;
    std::cout << "Built with Qt6 and C++17" << std::endl;
}

int main(int argc, char *argv[]) {
    // Парсинг аргументов командной строки
    bool noGui = false;
    bool showHelp = false;
    bool showVersion = false;
    int initialSize = -1;
    int initialAlgorithm = -1;
    int initialSpeed = -1;
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "--help" || arg == "-h") {
            showHelp = true;
        }
        else if (arg == "--version" || arg == "-v") {
            showVersion = true;
        }
        else if (arg == "--no-gui") {
            noGui = true;
        }
        else if (arg == "--size" && i + 1 < argc) {
            initialSize = std::stoi(argv[++i]);
        }
        else if (arg == "--algorithm" && i + 1 < argc) {
            initialAlgorithm = std::stoi(argv[++i]);
        }
        else if (arg == "--speed" && i + 1 < argc) {
            initialSpeed = std::stoi(argv[++i]);
        }
    }
    
    // Показываем help
    if (showHelp) {
        printHelp();
        return 0;
    }
    
    // Показываем version
    if (showVersion) {
        printVersion();
        return 0;
    }
    
    // Headless режим
    if (noGui) {
        std::cout << "Running in headless mode..." << std::endl;
        std::cout << "Array size: " << (initialSize > 0 ? initialSize : 50) << std::endl;
        std::cout << "Algorithm: " << (initialAlgorithm >= 0 ? initialAlgorithm : 0) << std::endl;
        std::cout << "Speed: " << (initialSpeed > 0 ? initialSpeed : 50) << "ms" << std::endl;
        std::cout << "Exiting headless mode." << std::endl;
        return 0;
    }
    
    // Нормальный запуск с GUI
    QApplication app(argc, argv);
    
    MainWindow window;
    
    // Применяем параметры из командной строки
    if (initialSize >= 10 && initialSize <= 100) {
        window.setArraySize(initialSize);
    }
    
    if (initialAlgorithm >= 0 && initialAlgorithm <= 4) {
        window.setAlgorithm(initialAlgorithm);
    }
    
    if (initialSpeed >= 1 && initialSpeed <= 200) {
        window.setAnimationSpeed(initialSpeed);
    }
    
    window.show();
    
    return app.exec();
}
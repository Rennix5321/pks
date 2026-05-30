cmake_minimum_required(VERSION 3.16)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(MSVC)
    add_compile_options(/Zc:__cplusplus /permissive-)
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Основная библиотека с исходниками - ДОБАВЛЯЕМ AnimationController
add_library(SortingVisualizerLib STATIC
    src/model/ArrayManager.cpp
    src/model/BubbleSort.cpp
    src/model/MergeSort.cpp
    src/model/QuickSort.cpp
    src/model/InsertionSort.cpp
    src/model/SelectionSort.cpp
    src/controller/SortingManager.cpp
    src/controller/AnimationController.cpp   # <--- ДОБАВИТЬ ЭТУ СТРОКУ
)

target_link_libraries(SortingVisualizerLib
    Qt6::Core
)

target_include_directories(SortingVisualizerLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/model
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controller
)

# Основное приложение
set(SOURCES
    src/main.cpp
    src/controller/AppController.cpp
    src/view/VisualizationEngine.cpp
    src/view/MainWindow.cpp
)

set(HEADERS
    src/controller/AppController.h
    src/controller/AnimationController.h
    src/view/VisualizationEngine.h
    src/view/MainWindow.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME}
    SortingVisualizerLib
    Qt6::Core
    Qt6::Widgets
)

# ================ ТЕСТЫ ================
enable_testing()
add_subdirectory(tests)
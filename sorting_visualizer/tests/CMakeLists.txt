# Автоматическая загрузка GoogleTest
include(FetchContent)

# Проверяем, не загружен ли уже googletest
if(NOT googletest_POPULATED)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

# Тесты для ArrayManager
add_executable(ArrayManagerTests
    ArrayManagerTests.cpp
)

target_link_libraries(ArrayManagerTests
    SortingVisualizerLib
    gtest
    gtest_main
    Qt6::Core
)

target_include_directories(ArrayManagerTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_test(NAME ArrayManagerTests COMMAND ArrayManagerTests)

# Тесты для алгоритмов сортировки
add_executable(SortingAlgorithmTests
    SortingAlgorithmTests.cpp
)

target_link_libraries(SortingAlgorithmTests
    SortingVisualizerLib
    gtest
    gtest_main
    Qt6::Core
)

target_include_directories(SortingAlgorithmTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_test(NAME SortingAlgorithmTests COMMAND SortingAlgorithmTests)

# Тесты для SortingManager
add_executable(SortingManagerTests
    SortingManagerTests.cpp
)

target_link_libraries(SortingManagerTests
    SortingVisualizerLib
    gtest
    gtest_main
    Qt6::Core
)

target_include_directories(SortingManagerTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_test(NAME SortingManagerTests COMMAND SortingManagerTests)

# Сценарии
add_executable(Scenarios
    Scenarios.cpp
)

target_link_libraries(Scenarios
    SortingVisualizerLib
    gtest
    gtest_main
    Qt6::Core
)

target_include_directories(Scenarios PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_test(NAME Scenarios COMMAND Scenarios)
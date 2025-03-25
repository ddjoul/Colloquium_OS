cmake_minimum_required(VERSION 3.10)
project(CppTasks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(factorial_generator src/factorial_generator.cpp)
add_library(duplicate_remover src/duplicate_remover.cpp)
add_library(list_reverser src/list_reverser.cpp)

add_executable(tasks_app src/main.cpp)
target_link_libraries(tasks_app factorial_generator duplicate_remover list_reverser)

# Тесты
enable_testing()
add_subdirectory(tests)
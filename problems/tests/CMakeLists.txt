cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)

# Тесты для генератора факториалов
add_executable(test_factorial test_factorial.cpp)
target_link_libraries(test_factorial
    factorial_generator
    GTest::GTest
    GTest::Main
)
target_include_directories(test_factorial PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Тесты для удаления дубликатов
add_executable(test_duplicate_remover test_duplicate_remover.cpp)
target_link_libraries(test_duplicate_remover
    duplicate_remover
    GTest::GTest
    GTest::Main
)
target_include_directories(test_duplicate_remover PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Тесты для разворота списка
add_executable(test_list_reverser test_list_reverser.cpp)
target_link_libraries(test_list_reverser
    list_reverser
    GTest::GTest
    GTest::Main
)
target_include_directories(test_list_reverser PRIVATE ${CMAKE_SOURCE_DIR}/include)

enable_testing()
add_test(NAME factorial_tests COMMAND test_factorial)
add_test(NAME duplicate_remover_tests COMMAND test_duplicate_remover)
add_test(NAME list_reverser_tests COMMAND test_list_reverser)
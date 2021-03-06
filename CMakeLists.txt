cmake_minimum_required(VERSION 3.0)
project(Othello_bot)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/othello_bot)
set(TEST_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${TEST_SRC_DIR})

add_executable(test_exec ${TEST_SRC_DIR}/test_main.cpp ${TEST_SRC_DIR}/test_AI.cpp ${SRC_DIR}/AI.cpp ${TEST_SRC_DIR}/test_game.cpp ${SRC_DIR}/game.cpp)
target_include_directories(test_exec PRIVATE ${SRC_DIR})
target_link_libraries(test_exec Catch)

add_executable(bench ${TEST_SRC_DIR}/benchmark_main.cpp ${SRC_DIR}/AI.cpp ${SRC_DIR}/game.cpp)
target_include_directories(bench PRIVATE ${SRC_DIR})

add_executable(play ${TEST_SRC_DIR}/play_main.cpp ${SRC_DIR}/AI.cpp ${SRC_DIR}/game.cpp)
target_include_directories(play PRIVATE ${SRC_DIR})

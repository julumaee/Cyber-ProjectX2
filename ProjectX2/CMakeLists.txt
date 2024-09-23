cmake_minimum_required(VERSION 3.16)
project(ProjectX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp ) #this executes main.cpp file present in the root project directory

## Enable fuzz testing
find_package(cifuzz NO_SYSTEM_ENVIRONMENT_PATH)
enable_fuzz_testing()

add_fuzz_test(fuzz_test_1 test/test.cpp)

target_link_libraries(fuzz_test_1 PRIVATE calculator)

#target_link_libraries(${PROJECT_NAME} PRIVATE calculator)


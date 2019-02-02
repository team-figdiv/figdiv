cmake_minimum_required(VERSION 3.5.2)
project(figdiv)
enable_testing()

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(test_executable test/main.cpp test/hello.cpp)
target_include_directories(test_executable PRIVATE "${Boost_INCLUDE_DIRS}")
target_link_libraries(test_executable Boost::unit_test_framework)
add_test(NAME unittests COMMAND test_executable)

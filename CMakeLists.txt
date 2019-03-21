cmake_minimum_required(VERSION 3.5.2)
project(figdiv)
enable_testing()
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
add_compile_definitions(_LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR) # boost still uses auto_ptr
set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

find_package(SDL2)
if(NOT SDL2_FOUND) # for some reason REQUIRED doesn't work properly, so we need this manual check
	message(SEND_ERROR "SDL2 not found")
endif()

add_executable(test_executable test/main.cpp test/hello.cpp)
target_include_directories(test_executable PRIVATE "${Boost_INCLUDE_DIRS}")
target_link_libraries(test_executable Boost::unit_test_framework)
add_test(NAME unittests COMMAND test_executable)

message("SDL2 libs=${SDL2_LIBRARIES} include=${SDL2_INCLUDE_DIRS}")
add_executable(figdiv src/main.cpp)
target_include_directories(figdiv PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(figdiv ${SDL2_LIBRARIES})

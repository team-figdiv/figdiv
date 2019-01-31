cmake_minimum_required(VERSION 2.8.7)
project(figdiv)
enable_testing()

if(MSVC)
	set(Boost_USE_STATIC_LIBS ON)
endif()
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(test_executable test/main.cpp test/hello.cpp)
target_include_directories(test_executable PRIVATE "${Boost_INCLUDE_DIRS}")
target_link_libraries(test_executable "${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}")
if(NOT MSVC)
	#Generate a main function
	target_compile_definitions(test_executable PRIVATE BOOST_TEST_DYN_LINK)
endif()
add_test(NAME unittests COMMAND test_executable)

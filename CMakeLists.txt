cmake_minimum_required(VERSION 3.12)
project(dt_runner VERSION 1.0)

# TODO make unrequired. using FetchContent module or something
find_package(doctest REQUIRED)

add_library(${PROJECT_NAME} OBJECT)

target_sources(${PROJECT_NAME}
PRIVATE
	src/dt_runner.cpp
	src/dt_impl.cpp
)
target_include_directories(${PROJECT_NAME}
PUBLIC
	include
)
target_link_libraries(${PROJECT_NAME}
PUBLIC
	doctest::doctest
)

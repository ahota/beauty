cmake_minimum_required(VERSION 2.8)

project(beauty
    DESCRIPTION "Built-in Entities for Automatic Unit-testing, Y'all"
    LANGUAGES CXX
)

add_subdirectory(beauties)
include_directories(beauties)

add_executable(main main.cpp beauties)

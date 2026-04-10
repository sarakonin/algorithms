cmake_minimum_required(VERSION 4.1)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")

foreach(source_file ${SOURCES})
    get_filename_component(exe_name ${source_file} NAME_WE)
    add_executable(${exe_name} ${source_file})
endforeach()
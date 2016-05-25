cmake_minimum_required (VERSION 2.6)
project(WordSearch)


#Bring the headers, such as Student.h into the project
include_directories(include)
file(GLOB SOURCES "src/*.c")


#add the executables
add_executable(WordSearch ${SOURCES})


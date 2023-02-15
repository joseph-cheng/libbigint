cmake_minimum_required(VERSION 3.15)


project(libbigint)

set(SOURCE_DIR "src")
set(INCLUDE_DIR "inc")

include_directories(${INCLUDE_DIR})
add_executable(bigint ${SOURCE_DIR}/main.cpp)


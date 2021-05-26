cmake_minimum_required( VERSION 2.8 )
project(chapter1)

set(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_INSTALL_PREFIX /usr/local/)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


include_directories(include)

add_library(hello SHARED src/hello.cpp)
add_library(hello_static STATIC src/hello.cpp)

add_executable(sayhello src/useHello.cpp)
target_link_libraries(sayhello hello)

install(TARGETS sayhello
RUNTIME DESTINATION bin)
install(TARGETS sayhello
LIBRARY DESTINATION lib)
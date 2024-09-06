# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TetrisGame VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# If conan toolchain is used, include it
if(EXISTS "${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake")
    include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)
endif()

# Specify the output directory for the compiled binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the source files
set(SOURCES src/main.cpp)

set(SOURCES_GAME
    src/game/block.cpp
    src/game/game.cpp
    src/game/grid.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES_GAME} )#${HEADERS})

# Include raylib and other Conan dependencies
find_package(raylib REQUIRED)
find_package(GTest REQUIRED)

# Link libraries provided by Conan, including raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Copy assets (if any) to the binary directory after build
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#     ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
# )

# Add the test executable
add_executable(${PROJECT_NAME}_tests
    ${SOURCES_GAME}
    tests/test_main.cpp
    tests/test_block.cpp
    tests/test_grid.cpp
    tests/test_game.cpp
)

# Link gtest libraries to the test executable
target_link_libraries(${PROJECT_NAME}_tests PRIVATE gtest GTest::gtest_main raylib)

# Include directories for tests
target_include_directories(${PROJECT_NAME}_tests PRIVATE include)

# Enable CTest
enable_testing()
add_test(NAME TetrisTests COMMAND ${PROJECT_NAME}_tests)

# add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     ${CONAN_LIBS_DIR}/gtest.dll $<TARGET_FILE_DIR:${PROJECT_NAME}_tests>
# )

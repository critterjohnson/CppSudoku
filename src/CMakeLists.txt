add_subdirectory("sudoku")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(sudoku.exe main.cpp)

target_link_libraries(sudoku.exe sudoku)

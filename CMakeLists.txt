cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 17)

add_library(chess_engine_library
    src/bitboard.cc
    src/position.cc
    src/bitboard_utils.cc
)

# Main executable
add_executable(ChessEngine src/main.cc)
target_link_libraries(ChessEngine PRIVATE chess_engine_library)

# Add the test executable
add_executable(test_position tests/test_position.cc)

# Link the test executable with the chess engine library
target_link_libraries(test_position PRIVATE chess_engine_library)

# Enable testing
enable_testing()

# Add the test to CTest
add_test(NAME TestPosition COMMAND test_position)
cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 17)

# Add sources
add_executable(ChessEngine src/main.cc src/bitboard.cc)
#ifndef BITBOARD_UTILS_H
#define BITBOARD_UTILS_H

#include <cstdint>

// Masks for file boundaries
const uint64_t notAFile = 0xFEFEFEFEFEFEFEFEULL;  // Mask to exclude A file
const uint64_t notHFile = 0x7F7F7F7F7F7F7F7FULL;  // Mask to exclude H file
const uint64_t notABFile = 0xFCFCFCFCFCFCFCFCULL; // Mask to exclude A and B files
const uint64_t notGHFile = 0x3F3F3F3F3F3F3F3FULL; // Mask to exclude G and H files

// Helper functions for knight moves
uint64_t noNoEa(uint64_t b);
uint64_t noEaEa(uint64_t b);
uint64_t soEaEa(uint64_t b);
uint64_t soSoEa(uint64_t b);
uint64_t noNoWe(uint64_t b);
uint64_t noWeWe(uint64_t b);
uint64_t soWeWe(uint64_t b);
uint64_t soSoWe(uint64_t b);

#endif // BITBOARD_UTILS_H
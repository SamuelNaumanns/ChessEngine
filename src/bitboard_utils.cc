#include "bitboard_utils.h"

// Helper functions for knight moves
uint64_t noNoEa(uint64_t b) { return (b & notHFile) << 17; }
uint64_t noEaEa(uint64_t b) { return (b & notGHFile) << 10; }
uint64_t soEaEa(uint64_t b) { return (b & notGHFile) >> 6; }
uint64_t soSoEa(uint64_t b) { return (b & notHFile) >> 15; }
uint64_t noNoWe(uint64_t b) { return (b & notAFile) << 15; }
uint64_t noWeWe(uint64_t b) { return (b & notABFile) << 6; }
uint64_t soWeWe(uint64_t b) { return (b & notABFile) >> 10; }
uint64_t soSoWe(uint64_t b) { return (b & notAFile) >> 17; }
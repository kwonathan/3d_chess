#include "cube.h"

void Cube::set_rank(int const rank) {
    this->rank = rank;
}

void Cube::set_file(char const file) {
    this->file = file;
}

void Cube::set_level(char const level) {
    this->level = level;
}

void Cube::set_piece(Piece* const piece) {
    this->piece = piece;
}

Piece* Cube::get_piece() const {
    return this->piece;
}

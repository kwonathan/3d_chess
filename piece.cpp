#include "piece.h"

int Piece::get_rank() const {
    return rank;
}

int Piece::get_file() const {
    return file;
}

int Piece::get_level() const {
    return level;
}

Colour Piece::get_colour() const {
    return colour;
}

void Piece::set_rank(int const rank) {
    this->rank = rank;
}

void Piece::set_file(int const file) {
    this->file = file;
}

void Piece::set_level(int const level) {
    this->level = level;
}

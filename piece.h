#pragma once

#include "cube.h"

#include <iostream>
#include <cmath>

enum Colour { white, black };
enum Name { bishop, king, knight, pawn, queen, rook, unicorn };

class Piece {
protected:
    int rank;
    int file;
    int level;
    Colour const colour;

public:
    virtual char print() const = 0;
    virtual Name get_name() const = 0;
    virtual bool check_move(Cube chessboard[5][5][5], int const dst_rank, int const dst_file, int const dst_level) const = 0;

    int get_rank() const;
    int get_file() const;
    int get_level() const;
    Colour get_colour() const;
    void set_rank(int const rank);
    void set_file(int const file);
    void set_level(int const level);

    Piece(int const rank, int const file, int const level, Colour const colour) : rank(rank), file(file), level(level), colour(colour) {};
    virtual ~Piece() {};
};

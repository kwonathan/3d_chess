#pragma once

#include "piece.h"

class Bishop : virtual public Piece {
    char print() const override;
    Name get_name() const override;

protected:
    bool check_move(Cube chessboard[5][5][5], int const dst_rank, int const dst_file, int const dst_level) const override;

public:
    Bishop(int const rank, int const file, int const level, Colour const colour) : Piece(rank, file, level, colour) {};
};

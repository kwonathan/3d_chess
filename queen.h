#include "piece.h"

#include "bishop.h"
#include "rook.h"
#include "unicorn.h"

class Queen : public Bishop, public Rook, public Unicorn {
    char print() const override;
    Name get_name() const override;
    bool check_move(Cube chessboard[5][5][5], int const dst_rank, int const dst_file, int const dst_level) const override;

public:
    Queen(int const rank, int const file, int const level, Colour const colour) :
        Piece(rank, file, level, colour),
        Bishop(rank, file, level, colour),
        Rook(rank, file, level, colour),
        Unicorn(rank, file, level, colour) {};
};

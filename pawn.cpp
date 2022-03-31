#include "pawn.h"

char Pawn::print() const {
    if (this->colour == white) {
        return 'P';
    } else if (this->colour == black) {
        return 'p';
    } else {
        return '?';
    }
}

Name Pawn::get_name() const {
    return pawn;
}

bool Pawn::check_move(Cube chessboard[5][5][5], int const dst_rank, int const dst_file, int const dst_level) const {

    // move to empty cube
    if (!chessboard[dst_rank][dst_file][dst_level].get_piece()) {
        if (colour == white) {
            if (dst_rank - rank == 1 && dst_file - file == 0 && dst_level - level == 0) {
                return true;
            }
            if (dst_level - level == 1 && dst_rank - rank == 0 && dst_file - file == 0) {
                return true;
            }
        } else if (colour == black) {
            if (rank - dst_rank == 1 && dst_file - file == 0 && dst_level - level == 0) {
                return true;
            }
            if (level - dst_level == 1 && dst_rank - rank == 0 && dst_file - file == 0) {
                return true;
            }
        }
    }
    
    // diagonal capture
    if (chessboard[dst_rank][dst_file][dst_level].get_piece()) {
        if (colour == white && chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour() == black) {
            if (dst_rank - rank == 1 && (dst_file - file == 1 || file - dst_file == 1) && dst_level - level == 0) {
                return true;
            }
            if (dst_level - level == 1 && (dst_file - file == 1 || file - dst_file == 1) && dst_rank - rank == 0) {
                return true;
            }
            if (dst_level - level == 1 && dst_rank - rank == 1 && dst_file - file == 0) {
                return true;
            }
        } else if (colour == black && chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour() == white) {
            if (rank - dst_rank == 1 && (dst_file - file == 1 || file - dst_file == 1) && dst_level - level == 0) {
                return true;
            }
            if (level - dst_level == 1 && (dst_file - file == 1 || file - dst_file == 1) && dst_rank - rank == 0) {
                return true;
            }
            if (level - dst_level == 1 && rank - dst_rank == 1 && dst_file - file == 0) {
                return true;
            }
        }
    }
    
    return false;
}

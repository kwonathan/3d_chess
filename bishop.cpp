#include "bishop.h"

char Bishop::print() const {
    if (this->colour == white) {
        return 'B';
    } else if (this->colour == black) {
        return 'b';
    } else {
        return '?';
    }
}

Name Bishop::get_name() const {
    return bishop;
}

bool Bishop::check_move(Cube chessboard[5][5][5], int const dst_rank, int const dst_file, int const dst_level) const {

    if (chessboard[dst_rank][dst_file][dst_level].get_piece() && colour == chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour()) {
        return false;
    }

    if (dst_rank == rank && dst_file == file && dst_level == level) {
        return false;
    }

    if (abs(dst_rank - rank) == abs(dst_file - file) && dst_level == level) {
        for (int i = 1; i < abs(dst_rank - rank); i++) {
            int rank_dir = (dst_rank - rank < 0) ? -1 : 1;
            int file_dir = (dst_file - file < 0) ? -1 : 1;
            if (chessboard[rank + rank_dir * i][file + file_dir * i][level].get_piece()) {
                return false;
            }
        }
        
        return true;
    }
    
    if (abs(dst_rank - rank) == abs(dst_level - level) && dst_file == file) {
        for (int i = 1; i < abs(dst_rank - rank); i++) {
            int rank_dir = (dst_rank - rank < 0) ? -1 : 1;
            int level_dir = (dst_level - level < 0) ? -1 : 1;
            if (chessboard[rank + rank_dir * i][file][level + level_dir * i].get_piece()) {
                return false;
            }
        }

        return true;
    }

    if (abs(dst_file - file) == abs(dst_level - level) && dst_rank == rank) {
        for (int i = 1; i < abs(dst_file - file); i++) {
            int file_dir = (dst_file - file < 0) ? -1 : 1;
            int level_dir = (dst_level - level < 0) ? -1 : 1;
            if (chessboard[rank][file + file_dir * i][level + level_dir * i].get_piece()) {
                return false;
            }
        }

        return true;
    }

    return false;
}

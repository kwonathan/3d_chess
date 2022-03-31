#include "king.h"

char King::print() const {
    if (this->colour == white) {
        return 'K';
    } else if (this->colour == black) {
        return 'k';
    } else {
        return '?';
    }
}

Name King::get_name() const {
    return king;
}

bool King::check_move(Cube chessboard[5][5][5], int const dst_rank, int const dst_file, int const dst_level) const {

    if (abs(dst_rank - rank) > 1 || abs(dst_file - file) > 1 || abs(dst_level - level) > 1) {
        return false;
    }

    if (Bishop::check_move(chessboard, dst_rank, dst_file, dst_level)) {
        return true;
    }
    
    if (Rook::check_move(chessboard, dst_rank, dst_file, dst_level)) {
        return true;
    }

    if (Unicorn::check_move(chessboard, dst_rank, dst_file, dst_level)) {
        return true;
    }

    return false;
}

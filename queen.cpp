#include "queen.h"

char Queen::print() const {
    if (this->colour == white) {
        return 'Q';
    } else if (this->colour == black) {
        return 'q';
    } else {
        return '?';
    }
}

Name Queen::get_name() const {
    return queen;
}

bool Queen::check_move(Cube chessboard[5][5][5], int const dst_rank, int const dst_file, int const dst_level) const {

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

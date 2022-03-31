#include "knight.h"

char Knight::print() const {
    if (this->colour == white) {
        return 'N';
    } else if (this->colour == black) {
        return 'n';
    } else {
        return '?';
    }
}

Name Knight::get_name() const {
    return knight;
}

bool Knight::check_move(Cube chessboard[5][5][5], int const dst_rank, int const dst_file, int const dst_level) const {

    if (chessboard[dst_rank][dst_file][dst_level].get_piece() && colour == chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour()) {
        return false;
    }

    if (dst_rank == rank && dst_file == file && dst_level == level) {
        return false;
    }

    if ((dst_rank == rank - 2 && dst_file == file - 1 && dst_level == level) ||
        (dst_rank == rank - 2 && dst_file == file + 1 && dst_level == level) ||
        (dst_rank == rank + 2 && dst_file == file - 1 && dst_level == level) ||
        (dst_rank == rank + 2 && dst_file == file + 1 && dst_level == level) ||
        (dst_rank == rank - 1 && dst_file == file - 2 && dst_level == level) ||
        (dst_rank == rank - 1 && dst_file == file + 2 && dst_level == level) ||
        (dst_rank == rank + 1 && dst_file == file - 2 && dst_level == level) ||
        (dst_rank == rank + 1 && dst_file == file + 2 && dst_level == level) ||
        (dst_level == level - 2 && dst_rank == rank - 1 && dst_file == file) ||
        (dst_level == level - 2 && dst_rank == rank + 1 && dst_file == file) ||
        (dst_level == level + 2 && dst_rank == rank - 1 && dst_file == file) ||
        (dst_level == level + 2 && dst_rank == rank + 1 && dst_file == file) ||
        (dst_level == level - 1 && dst_rank == rank - 2 && dst_file == file) ||
        (dst_level == level - 1 && dst_rank == rank + 2 && dst_file == file) ||
        (dst_level == level + 1 && dst_rank == rank - 2 && dst_file == file) ||
        (dst_level == level + 1 && dst_rank == rank + 2 && dst_file == file) ||
        (dst_file == file - 2 && dst_level == level - 1 && dst_rank == rank) ||
        (dst_file == file - 2 && dst_level == level + 1 && dst_rank == rank) ||
        (dst_file == file + 2 && dst_level == level - 1 && dst_rank == rank) ||
        (dst_file == file + 2 && dst_level == level + 1 && dst_rank == rank) ||
        (dst_file == file - 1 && dst_level == level - 2 && dst_rank == rank) ||
        (dst_file == file - 1 && dst_level == level + 2 && dst_rank == rank) ||
        (dst_file == file + 1 && dst_level == level - 2 && dst_rank == rank) ||
        (dst_file == file + 1 && dst_level == level + 2 && dst_rank == rank)) {
        
        return true;
    }

    return false;
}

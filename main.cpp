#include "helper.cpp"

#include <iostream>
#include <string>
#include <cctype>

int main() {

    const int TO_INT_RANK = 49;
    const int TO_INT_FILE = 97;
    const int TO_INT_LEVEL = 65;

    bool first_game = true;
    bool new_game = false;

    while (true) {

        if (!new_game) {
            opening_outputs(first_game);
        }

        Cube chessboard[5][5][5];
        init_board(chessboard);
        print_board_horizontal(chessboard);

        Colour turn = white;
        bool game_over = false;

        while (true && !game_over) {
            std::string src_cube;
            std::string dst_cube;
            std::string to_move = (turn == white) ? "White" : "Black";

            int src_level, src_file, src_rank;
            int dst_level, dst_file, dst_rank;

            // input in the format level-file-rank
            bool valid_input = false;
            do {
                std::cout << std::endl;
                std::cout << to_move << "'s turn to move: ";
                std::cin >> src_cube >> dst_cube;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                src_level = src_cube[0] - TO_INT_LEVEL;
                src_file = src_cube[1] - TO_INT_FILE;
                src_rank = src_cube[2] - TO_INT_RANK;
                dst_level = dst_cube[0] - TO_INT_LEVEL;
                dst_file = dst_cube[1] - TO_INT_FILE;
                dst_rank = dst_cube[2] - TO_INT_RANK;

                if (// inputs of valid length
                    src_cube.length() == 3 && dst_cube.length() == 3
                    &&
                    // inputs valid within the bounds of the board
                    src_level >= 0 && src_level < 5 &&
                    src_file >= 0 && src_file < 5 &&
                    src_rank >= 0 && src_rank < 5 &&
                    dst_level >= 0 && dst_level < 5 &&
                    dst_file >= 0 && dst_file < 5 &&
                    dst_rank >= 0 && dst_rank < 5) {

                    valid_input = true;
                }

                if (!valid_input) {
                    std::cout << "Invalid input!" << std::endl;
                }
            } while (!valid_input);

            if (!chessboard[src_rank][src_file][src_level].get_piece()) {
                std::cout << "No piece at " << src_cube << "!" << std::endl;
            } else if (chessboard[src_rank][src_file][src_level].get_piece()->get_colour() != turn) {
                std::cout << "It is " << to_move << "'s turn to move!" << std::endl;
            } else if (!chessboard[src_rank][src_file][src_level].get_piece()->check_move(chessboard, dst_rank, dst_file, dst_level)) {
                std::cout << "Invalid move!" << std::endl;
            } else {
                Piece* dst_piece = chessboard[dst_rank][dst_file][dst_level].get_piece();
                chessboard[src_rank][src_file][src_level].get_piece()->set_rank(dst_rank);
                chessboard[src_rank][src_file][src_level].get_piece()->set_file(dst_file);
                chessboard[src_rank][src_file][src_level].get_piece()->set_level(dst_level);
                chessboard[dst_rank][dst_file][dst_level].set_piece(chessboard[src_rank][src_file][src_level].get_piece());
                chessboard[src_rank][src_file][src_level].set_piece(nullptr);
                
                if (is_in_check(chessboard, turn)) {
                    std::cout << "Invalid move!" << std::endl;
                    chessboard[dst_rank][dst_file][dst_level].get_piece()->set_rank(src_rank);
                    chessboard[dst_rank][dst_file][dst_level].get_piece()->set_file(src_file);
                    chessboard[dst_rank][dst_file][dst_level].get_piece()->set_level(src_level);
                    chessboard[src_rank][src_file][src_level].set_piece(chessboard[dst_rank][dst_file][dst_level].get_piece());
                    chessboard[dst_rank][dst_file][dst_level].set_piece(dst_piece);
                    dst_piece = nullptr;
                } else {
                    delete dst_piece;
                    dst_piece = nullptr;

                    if (chessboard[dst_rank][dst_file][dst_level].get_piece()->get_name() == pawn) {
                        if ((chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour() == white && dst_level == 4 && dst_rank == 4) ||
                            (chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour() == black && dst_level == 0 && dst_rank == 0)) {

                            std::string promotion;
                            bool promoted = false;
                            do {
                                std::cout << "Enter promotion piece: ";
                                std::cin >> promotion;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                if (promotion == "Q" || promotion == "q" || promotion == "Queen" || promotion == "queen") {
                                    Queen* promotion_piece = new Queen(dst_rank, dst_file, dst_level, chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour());
                                    delete chessboard[dst_rank][dst_file][dst_level].get_piece();
                                    chessboard[dst_rank][dst_file][dst_level].set_piece(promotion_piece);
                                    promoted = true;
                                } else if (promotion == "N" || promotion == "n" || promotion == "Knight" || promotion == "knight") {
                                    Knight* promotion_piece = new Knight(dst_rank, dst_file, dst_level, chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour());
                                    delete chessboard[dst_rank][dst_file][dst_level].get_piece();
                                    chessboard[dst_rank][dst_file][dst_level].set_piece(promotion_piece);
                                    promoted = true;
                                } else if (promotion == "R" || promotion == "r" || promotion == "Rook" || promotion == "rook") {
                                    Rook* promotion_piece = new Rook(dst_rank, dst_file, dst_level, chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour());
                                    delete chessboard[dst_rank][dst_file][dst_level].get_piece();
                                    chessboard[dst_rank][dst_file][dst_level].set_piece(promotion_piece);
                                    promoted = true;
                                } else if (promotion == "B" || promotion == "b" || promotion == "Bishop" || promotion == "bishop") {
                                    Bishop* promotion_piece = new Bishop(dst_rank, dst_file, dst_level, chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour());
                                    delete chessboard[dst_rank][dst_file][dst_level].get_piece();
                                    chessboard[dst_rank][dst_file][dst_level].set_piece(promotion_piece);
                                    promoted = true;
                                } else if (promotion == "U" || promotion == "u" || promotion == "Unicorn" || promotion == "unicorn") {
                                    Unicorn* promotion_piece = new Unicorn(dst_rank, dst_file, dst_level, chessboard[dst_rank][dst_file][dst_level].get_piece()->get_colour());
                                    delete chessboard[dst_rank][dst_file][dst_level].get_piece();
                                    chessboard[dst_rank][dst_file][dst_level].set_piece(promotion_piece);
                                    promoted = true;
                                }

                                if (!promoted) {
                                    std::cout << "Invalid promotion piece!" << std::endl;
                                }
                            } while (!promoted);
                        }
                    }

                    Colour opponent = (turn == white) ? black : white;
                    bool opponent_is_in_check = is_in_check(chessboard, opponent);
                    bool opponent_is_in_checkmate = true;

                    // for all the cubes in the chessboard
                    for (int i = 0; i < 5 && opponent_is_in_checkmate; i++) {
                        for (int j = 0; j < 5 && opponent_is_in_checkmate; j++) {
                            for (int k = 0; k < 5 && opponent_is_in_checkmate; k++) {
                                // if there is an opponent piece
                                if (chessboard[k][j][i].get_piece() &&
                                    chessboard[k][j][i].get_piece()->get_colour() == opponent) {
                                    // for all the cubes in the chessboard
                                    for (int l = 0; l < 5 && opponent_is_in_checkmate; l++) {
                                        for (int m = 0; m < 5 && opponent_is_in_checkmate; m++) {
                                            for (int n = 0; n < 5 && opponent_is_in_checkmate; n++) {
                                                // if there is a possible move for the opponent piece
                                                if (chessboard[k][j][i].get_piece()->check_move(chessboard, n, m, l)) {
                                                    // update and see if the opponent is still in check
                                                    Piece* checkmate_piece = chessboard[n][m][l].get_piece();
                                                    chessboard[k][j][i].get_piece()->set_rank(n);
                                                    chessboard[k][j][i].get_piece()->set_file(m);
                                                    chessboard[k][j][i].get_piece()->set_level(l);
                                                    chessboard[n][m][l].set_piece(chessboard[k][j][i].get_piece());
                                                    chessboard[k][j][i].set_piece(nullptr);
                                                    if (!is_in_check(chessboard, opponent)) {
                                                        opponent_is_in_checkmate = false;
                                                    }
                                                    // undo the update
                                                    chessboard[n][m][l].get_piece()->set_rank(k);
                                                    chessboard[n][m][l].get_piece()->set_file(j);
                                                    chessboard[n][m][l].get_piece()->set_level(i);
                                                    chessboard[k][j][i].set_piece(chessboard[n][m][l].get_piece());
                                                    chessboard[n][m][l].set_piece(checkmate_piece);
                                                    checkmate_piece = nullptr;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if (opponent_is_in_checkmate) {
                        game_over = true;
                    }

                    turn = (turn == white) ? black : white;
                    print_board_horizontal(chessboard);

                    // output
                    std::string colour_in_check = (opponent == white) ? "White" : "Black";

                    if (opponent_is_in_check && !opponent_is_in_checkmate) {
                        std::cout << std::endl << colour_in_check << " is in check!" << std::endl;
                    } else if (opponent_is_in_check && opponent_is_in_checkmate) {
                        std::cout << std::endl << colour_in_check << " is in checkmate!" << std::endl;
                    } else if (!opponent_is_in_check && opponent_is_in_checkmate) {
                        std::cout << std::endl << colour_in_check << " is in stalemate!" << std::endl;
                    }
                }
            }
        }

        if (game_over) {

            // delete heap
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 5; k++) {
                        delete chessboard[i][j][k].get_piece();
                    }
                }
            }

            first_game = false;
            std::string restart;
            bool valid_restart = false;
            do {
                std::cout << std::endl << "Would you like to start a new game? Y/N: ";
                std::cin >> restart;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (restart == "Y" || restart == "y") {
                    new_game = true;
                    valid_restart = true;
                    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
                    std::cout << "                                            A new 3D Chess game has started!" << std::endl;
                    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
                } else if (restart == "N" || restart == "n") {
                    new_game = false;
                    valid_restart = true;
                } else {
                    std::cout << "Please enter either Y or N." << std::endl;
                    valid_restart = false;
                }
            } while (!valid_restart);
        }
    }

    return 0;
}

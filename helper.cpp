#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "unicorn.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

#include <iostream>
#include <limits>

int main_menu() {

    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << "                              ██████╗ ██████╗      ██████╗██╗  ██╗███████╗███████╗███████╗" << std::endl;
    std::cout << "                              ╚════██╗██╔══██╗    ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝" << std::endl;
    std::cout << "                               █████╔╝██║  ██║    ██║     ███████║█████╗  ███████╗███████╗" << std::endl;
    std::cout << "                               ╚═══██╗██║  ██║    ██║     ██╔══██║██╔══╝  ╚════██║╚════██║" << std::endl;
    std::cout << "                              ██████╔╝██████╔╝    ╚██████╗██║  ██║███████╗███████║███████║" << std::endl;
    std::cout << "                              ╚═════╝ ╚═════╝      ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "                                                1 NEW GAME" << std::endl;
    std::cout << "                                                2 HOW TO PLAY" << std::endl;
    std::cout << "                                                3 DEVELOPER INFORMATION" << std::endl;
    std::cout << "                                                4 QUIT" << std::endl;
    std::cout << std::endl << std::endl << std::endl << std::endl;

    int option;
    std::cout << "Select an option: ";
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (option)
    {
    case 1:
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        std::cout << "                                            A new 3D Chess game has started!" << std::endl;
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        break;
    case 2:
        std::cout << std::endl << std::endl;
        std::cout << "                                                     [HOW TO PLAY]" << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "This game is an implementation of Raumschach (German for Space Chess) developed by Ferdinand Maack (1861-1930)." << std::endl;
        std::cout << "The board can be thought of as a 5x5x5 cube, with 5 levels stacked on top of each other. These levels are denoted by" << std::endl;
        std::cout << "capital letters A through E. Ranks and files of each level are denoted using algebraic notation (a through e for files," << std::endl;
        std::cout << "and 1 through 5 for ranks). White starts on the A and B levels and Black starts on levels E and D. Moves must be entered" << std::endl;
        std::cout << "in the format [Source Cube] [Destination Cube]. For example, a possible opening move may be Bb2 Bb3. White moves first." << std::endl;
        std::cout << std::endl;
        std::cout << "Each player begins with the same set of pieces as in standard chess, but with two additional pawns and two special" << std::endl;
        std::cout << "pieces named unicorn. The rules of each piece are as follows:" << std::endl;
        std::cout << std::endl;
        std::cout << "1.  A rook (R/r) moves through the six faces of a cube in any level, rank, or file." << std::endl;
        std::cout << "2.  A bishop (B/b) moves through the twelve edges of a cube." << std::endl;
        std::cout << "3.  A knight (N/n) makes a (0,1,2) leap (the same effect as one step as a rook followed by one step as a bishop in the" << std::endl;
        std::cout << "    same outward direction) enabling it to control 24 different cells from the board's centre." << std::endl;
        std::cout << "4.  A unicorn (U/u) moves in a manner special to a 3D space (i.e. triagonal movement) through the corners of a cube, any" << std::endl;
        std::cout << "    number of steps in a straight line." << std::endl;
        std::cout << "5.  The queen (Q/q) combines the moves of a rook, bishop, and unicorn." << std::endl;
        std::cout << "6.  The king (K/k) moves the same as the queen but one step at a time." << std::endl;
        std::cout << "7.  A pawn (P/p), as in standard chess, moves and captures always forward toward the promotion rank (White pawns promote" << std::endl;
        std::cout << "    on rank E5 and Black on rank A1). This includes moving one step directly upward (for White) or downward (for Black)," << std::endl;
        std::cout << "    and capturing one step diagonally upward (White) or diagonally downward (Black), through a front or side cube edge." << std::endl;
        std::cout << "    There is no pawn initial two-step move (and consequently no capturing en passant), and no castling." << std::endl;
        std::cout << std::endl;
        std::cout << "[Source: https://en.wikipedia.org/wiki/Three-dimensional_chess]" << std::endl;
        std::cout << std::endl;
        std::cout << "Press [ENTER] to go back: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    case 3:
        std::cout << std::endl << std::endl;
        std::cout << "                                                [DEVELOPER INFORMATION]" << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "This game was written by John Kwon (@kwonathan)." << std::endl;
        std::cout << std::endl;
        std::cout << "If you notice any bugs or errors, or would like to request a feature, please create an issue at" << std::endl;
        std::cout << "https://github.com/kwonathan/3d_chess/issues." << std::endl;
        std::cout << std::endl;
        std::cout << "Thanks for playing!" << std::endl;
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        std::cout << "Press [ENTER] to go back: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    case 4:
        std::cout << "Quitting 3D Chess..." << std::endl;
        break;
    default:
        break;
    }

    return option;
}

void opening_outputs(bool first_game) {

    if (first_game) {
        std::cout << "Starting 3D Chess..." << std::endl << std::endl;
        std::cout << "Please ensure that your window size is 120x30." << std::endl << std::endl;
        std::cout << "Press [ENTER] to continue: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        std::cout << "                              ██████╗ ██████╗      ██████╗██╗  ██╗███████╗███████╗███████╗" << std::endl;
        std::cout << "                              ╚════██╗██╔══██╗    ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝" << std::endl;
        std::cout << "                               █████╔╝██║  ██║    ██║     ███████║█████╗  ███████╗███████╗" << std::endl;
        std::cout << "                               ╚═══██╗██║  ██║    ██║     ██╔══██║██╔══╝  ╚════██║╚════██║" << std::endl;
        std::cout << "                              ██████╔╝██████╔╝    ╚██████╗██║  ██║███████╗███████║███████║" << std::endl;
        std::cout << "                              ╚═════╝ ╚═════╝      ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝" << std::endl;
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "                                                     Press [ENTER]";
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int option = 0;

    while (option != 1) {
        option = main_menu();
        if (option == 4) {
            exit(EXIT_SUCCESS);
        }
    }

    return;
}

void init_board(Cube chessboard[5][5][5]) {

    // initialise the ranks, files, levels
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                int rank = k + 1;
                chessboard[k][j][i].set_rank(rank);
                char file = j + 'a';
                chessboard[k][j][i].set_file(file);
                char level = i + 'A';
                chessboard[k][j][i].set_level(level);
            }
        }
    }

    // create and initialise the pieces
    Rook* rook_w1 = new Rook(0, 0, 0, white);
    Rook* rook_w2 = new Rook(0, 4, 0, white);
    Rook* rook_b1 = new Rook(4, 0, 4, black);
    Rook* rook_b2 = new Rook(4, 4, 4, black);

    Bishop* bishop_w1 = new Bishop(0, 0, 1, white);
    Bishop* bishop_w2 = new Bishop(0, 3, 1, white);
    Bishop* bishop_b1 = new Bishop(4, 1, 3, black);
    Bishop* bishop_b2 = new Bishop(4, 4, 3, black);

    Knight* knight_w1 = new Knight(0, 1, 0, white);
    Knight* knight_w2 = new Knight(0, 3, 0, white);
    Knight* knight_b1 = new Knight(4, 1, 4, black);
    Knight* knight_b2 = new Knight(4, 3, 4, black);

    Unicorn* unicorn_w1 = new Unicorn(0, 1, 1, white);
    Unicorn* unicorn_w2 = new Unicorn(0, 4, 1, white);
    Unicorn* unicorn_b1 = new Unicorn(4, 0, 3, black);
    Unicorn* unicorn_b2 = new Unicorn(4, 3, 3, black);

    Queen* queen_w = new Queen(0, 2, 1, white);
    Queen* queen_b = new Queen(4, 2, 3, black);

    King* king_w = new King(0, 2, 0, white);
    King* king_b = new King(4, 2, 4, black);

    Pawn* pawn_w1 = new Pawn(1, 0, 0, white);
    Pawn* pawn_w2 = new Pawn(1, 1, 0, white);
    Pawn* pawn_w3 = new Pawn(1, 2, 0, white);
    Pawn* pawn_w4 = new Pawn(1, 3, 0, white);
    Pawn* pawn_w5 = new Pawn(1, 4, 0, white);
    Pawn* pawn_w6 = new Pawn(1, 0, 1, white);
    Pawn* pawn_w7 = new Pawn(1, 1, 1, white);
    Pawn* pawn_w8 = new Pawn(1, 2, 1, white);
    Pawn* pawn_w9 = new Pawn(1, 3, 1, white);
    Pawn* pawn_w10 = new Pawn(1, 4, 1, white);
    
    Pawn* pawn_b1 = new Pawn(3, 0, 3, black);
    Pawn* pawn_b2 = new Pawn(3, 1, 3, black);
    Pawn* pawn_b3 = new Pawn(3, 2, 3, black);
    Pawn* pawn_b4 = new Pawn(3, 3, 3, black);
    Pawn* pawn_b5 = new Pawn(3, 4, 3, black);
    Pawn* pawn_b6 = new Pawn(3, 0, 4, black);
    Pawn* pawn_b7 = new Pawn(3, 1, 4, black);
    Pawn* pawn_b8 = new Pawn(3, 2, 4, black);
    Pawn* pawn_b9 = new Pawn(3, 3, 4, black);
    Pawn* pawn_b10 = new Pawn(3, 4, 4, black);

    chessboard[0][0][0].set_piece(rook_w1);
    chessboard[0][4][0].set_piece(rook_w2);
    chessboard[4][0][4].set_piece(rook_b1);
    chessboard[4][4][4].set_piece(rook_b2);

    chessboard[0][0][1].set_piece(bishop_w1);
    chessboard[0][3][1].set_piece(bishop_w2);
    chessboard[4][1][3].set_piece(bishop_b1);
    chessboard[4][4][3].set_piece(bishop_b2);

    chessboard[0][1][0].set_piece(knight_w1);
    chessboard[0][3][0].set_piece(knight_w2);
    chessboard[4][1][4].set_piece(knight_b1);
    chessboard[4][3][4].set_piece(knight_b2);

    chessboard[0][1][1].set_piece(unicorn_w1);
    chessboard[0][4][1].set_piece(unicorn_w2);
    chessboard[4][0][3].set_piece(unicorn_b1);
    chessboard[4][3][3].set_piece(unicorn_b2);

    chessboard[0][2][1].set_piece(queen_w);
    chessboard[4][2][3].set_piece(queen_b);

    chessboard[0][2][0].set_piece(king_w);
    chessboard[4][2][4].set_piece(king_b);

    chessboard[1][0][0].set_piece(pawn_w1);
    chessboard[1][1][0].set_piece(pawn_w2);
    chessboard[1][2][0].set_piece(pawn_w3);
    chessboard[1][3][0].set_piece(pawn_w4);
    chessboard[1][4][0].set_piece(pawn_w5);
    chessboard[1][0][1].set_piece(pawn_w6);
    chessboard[1][1][1].set_piece(pawn_w7);
    chessboard[1][2][1].set_piece(pawn_w8);
    chessboard[1][3][1].set_piece(pawn_w9);
    chessboard[1][4][1].set_piece(pawn_w10);

    chessboard[3][0][3].set_piece(pawn_b1);
    chessboard[3][1][3].set_piece(pawn_b2);
    chessboard[3][2][3].set_piece(pawn_b3);
    chessboard[3][3][3].set_piece(pawn_b4);
    chessboard[3][4][3].set_piece(pawn_b5);
    chessboard[3][0][4].set_piece(pawn_b6);
    chessboard[3][1][4].set_piece(pawn_b7);
    chessboard[3][2][4].set_piece(pawn_b8);
    chessboard[3][3][4].set_piece(pawn_b9);
    chessboard[3][4][4].set_piece(pawn_b10);
}

void print_board_vertical(Cube chessboard[5][5][5]) {

    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "            " << static_cast<char>('E' - i) << std::endl;
        std::cout << "  +---+---+---+---+---+" << std::endl;
        for (int j = 0; j < 5; j++) {
            std::cout << 5 - j << " |";
            for (int k = 0; k < 5; k++) {
                if (chessboard[4 - j][k][4 - i].get_piece()) {
                    std::cout << " " << chessboard[4 - j][k][4 - i].get_piece()->print() << " |";
                } else {
                    std::cout << "   |";
                }
            }
            std::cout << std::endl << "  +---+---+---+---+---+" << std::endl;
        }
        std::cout << "    a   b   c   d   e" << std::endl;
        std::cout << std::endl;
    }
}

void print_board_horizontal(Cube chessboard[5][5][5]) {

    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "             " << static_cast<char>('A' + i) << "          ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "   +---+---+---+---+---+";
    }
    std::cout << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << " " << 5 - i << " |";
            for (int k = 0; k < 5; k++) {
                if (chessboard[4 - i][k][j].get_piece()) {
                    std::cout << " " << chessboard[4 - i][k][j].get_piece()->print() << " |";
                } else {
                    std::cout << "   |";
                }
            }
        }
        std::cout << std::endl;
        for (int j = 0; j < 5; j++) {
            std::cout << "   +---+---+---+---+---+";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << "     a   b   c   d   e  ";
    }
    std::cout << std::endl;
}

bool is_in_check(Cube chessboard[5][5][5], Colour colour) {
    
    // find king
    int king_rank;
    int king_file;
    int king_level;
    bool king_found = false;

    for (int i = 0; i < 5 && !king_found; i++) {
        for (int j = 0; j < 5 && !king_found; j++) {
            for (int k = 0; k < 5 && !king_found; k++) {
                if (chessboard[k][j][i].get_piece() && chessboard[k][j][i].get_piece()->get_name() == king && chessboard[k][j][i].get_piece()->get_colour() == colour) {
                    king_rank = k;
                    king_file = j;
                    king_level = i;
                    king_found = true;
                }
            }
        }
    }

    // see if king is in check
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (chessboard[k][j][i].get_piece() &&
                    chessboard[k][j][i].get_piece()->get_colour() != colour &&
                    chessboard[k][j][i].get_piece()->check_move(chessboard, king_rank, king_file, king_level)) {
                    
                    return true;
                }
            }
        }
    }

    return false;
}

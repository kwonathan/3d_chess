class Piece;

class Cube {
    int rank;
    char file;
    char level;
    Piece* piece = nullptr;

public:
    void set_rank(int const rank);
    void set_file(char const file);
    void set_level(char const level);
    void set_piece(Piece* const piece);
    Piece* get_piece() const;
};

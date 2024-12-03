#ifndef BOARD_HH__
#define BOARD_HH__

#include "Piece.hh"

class Board {
private:
    int board[64];  // An array representing the 64 squares of the chessboard

    // Initialize the board to the starting setup
    void initBoard() {
        // White pieces
        board[0] = Piece::ROOK | Piece::WHITE;      // A1
        board[1] = Piece::KNIGHT | Piece::WHITE;    // B1
        board[2] = Piece::BISHOP | Piece::WHITE;    // C1
        board[3] = Piece::QUEEN | Piece::WHITE;     // D1
        board[4] = Piece::KING | Piece::WHITE;      // E1
        board[5] = Piece::BISHOP | Piece::WHITE;    // F1
        board[6] = Piece::KNIGHT | Piece::WHITE;    // G1
        board[7] = Piece::ROOK | Piece::WHITE;      // H1
        for (int i = 8; i < 16; ++i) board[i] = Piece::PAWN | Piece::WHITE;  // White pawns

        // Black pieces
        board[56] = Piece::ROOK | Piece::BLACK;     // A8
        board[57] = Piece::KNIGHT | Piece::BLACK;   // B8
        board[58] = Piece::BISHOP | Piece::BLACK;   // C8
        board[59] = Piece::QUEEN | Piece::BLACK;    // D8
        board[60] = Piece::KING | Piece::BLACK;     // E8
        board[61] = Piece::BISHOP | Piece::BLACK;   // F8
        board[62] = Piece::KNIGHT | Piece::BLACK;   // G8
        board[63] = Piece::ROOK | Piece::BLACK;     // H8
        for (int i = 48; i < 56; ++i) board[i] = Piece::PAWN | Piece::BLACK;  // Black pawns
    }

public:
    Board() {
        initBoard();  // Initialize the board with the starting setup
    }

    // Function that checks if a square is occupied by a piece
    bool isOccupied(int square) {
        return board[square] != Piece::NONE;
    }

    // Function that returns a 64-bit array representing available moves for a piece
    unsigned long long getAvailableMoves(int square) {
        int piece = board[square];
        unsigned long long availableMoves = 0;

        if (piece == Piece::NONE) return availableMoves;

        // Check for movement possibilities for the piece at the square
        // Here you can define the logic for each piece type (pawn, knight, etc.)
        switch (Piece::PieceType(piece)) {
            case Piece::PAWN:
                // Example: Pawns move forward (for simplicity, just checking 1 square ahead)
                if (Piece::isColor(piece, Piece::WHITE)) {
                    if (square - 8 >= 0 && !isOccupied(square - 8)) {
                        availableMoves |= (1ULL << (square - 8)); // Move forward one square
                    }
                } else {
                    if (square + 8 < 64 && !isOccupied(square + 8)) {
                        availableMoves |= (1ULL << (square + 8)); // Move forward one square
                    }
                }
                break;

            case Piece::KNIGHT:
                // Knights have an "L" shape move (8 possible squares)
                // Add logic for the knight's movement here
                break;

            case Piece::BISHOP:
                // Bishops move diagonally
                // Add logic for the bishop's movement here
                break;

            case Piece::ROOK:
                // Rooks move horizontally or vertically
                // Add logic for the rook's movement here
                break;

            case Piece::QUEEN:
                // Queens move both like rooks and bishops
                // Add logic for the queen's movement here
                break;

            case Piece::KING:
                // Kings move one square in any direction
                // Add logic for the king's movement here
                break;

            default:
                break;
        }

        return availableMoves;
    }

    // Function to print the board (for debugging)
    void printBoard() {
        for (int i = 0; i < 64; ++i) {
            std::cout << board[i] << " ";
            if ((i + 1) % 8 == 0) std::cout << std::endl;
        }
    }
};

#endif

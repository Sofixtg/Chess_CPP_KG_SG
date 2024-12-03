#include <iostream>
#include <vector>
#include <string>
#include "BoardWindow.hh" // Assuming BoardWindow is the UI class you mentioned

class ChessGame {
public:
    // Representing the board as an 8x8 grid with pieces
    // Each cell holds a character, with 'P' for Pawn, 'R' for Rook, etc.
    // Uppercase for White pieces, lowercase for Black pieces
    char board[8][8];

    ChessGame() {
        // Initialize the chessboard with the standard starting positions
        resetBoard();
    }

    // Reset the board to the starting position
    void resetBoard() {
        const std::string initialBoard[8] = {
            "RNBQKBNR", // Black pieces
            "PPPPPPPP", // Black pawns
            "        ",  // Empty row
            "        ",  // Empty row
            "        ",  // Empty row
            "        ",  // Empty row
            "pppppppp",  // White pawns
            "rnbqkbnr"   // White pieces
        };

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = initialBoard[i][j];
            }
        }
    }

    // Print the current state of the board
    void printBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Move a piece from one square to another (e.g., "e2" to "e4")
    bool movePiece(const std::string& from, const std::string& to) {
        int fromRow = 8 - (from[1] - '0'); // Convert from chess notation to array index
        int fromCol = from[0] - 'a';
        int toRow = 8 - (to[1] - '0');
        int toCol = to[0] - 'a';

        // Check if the move is within bounds and if the starting square has a piece
        if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
            toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8 || board[fromRow][fromCol] == ' ') {
            std::cout << "Invalid move!" << std::endl;
            return false;
        }

        // Move the piece
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' '; // Empty the starting square
        return true;
    }

    // Check if a move is valid (simplified version)
    bool isValidMove(const std::string& from, const std::string& to) {
        // For simplicity, this function can be expanded based on chess rules
        // Currently, it only checks if the move is within bounds
        int fromRow = 8 - (from[1] - '0');
        int fromCol = from[0] - 'a';
        int toRow = 8 - (to[1] - '0');
        int toCol = to[0] - 'a';
        return fromRow >= 0 && fromRow < 8 && fromCol >= 0 && fromCol < 8 &&
               toRow >= 0 && toRow < 8 && toCol >= 0 && toCol < 8;
    }
};

int main() {
    ChessGame game;

    // Create and display the game window
    BoardWindow window({100, 100}, "Chess");
    window.show();

    game.printBoard(); // Print the initial board state

    std::string from, to;
    while (true) {
        std::cout << "Enter move (e.g., 'e2 e4'): ";
        std::cin >> from >> to;

        if (game.isValidMove(from, to)) {
            if (game.movePiece(from, to)) {
                game.printBoard();
            } else {
                std::cout << "Move failed!" << std::endl;
            }
        } else {
            std::cout << "Invalid move!" << std::endl;
        }

        // Update the window with the new board state
        // You would need to update the board window here based on the `game.board`
    }

    return 0;
}

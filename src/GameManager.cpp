#include <iostream>
#include "ChessGame.cpp" // Assuming ChessGame logic is in ChessGame.cpp
#include "BoardWindow.hh" // Assuming BoardWindow is the UI class

class GameManager {
public:
    enum Player { WHITE, BLACK };

    GameManager()
        : currentPlayer(WHITE), game(new ChessGame()) {}

    ~GameManager() {
        delete game;
    }

    void startGame() {
        // Initialize the game and window
        std::cout << "Starting a new chess game...\n";
        game->resetBoard();
        boardWindow.show();

        while (true) {
            boardWindow.redraw();
            handlePlayerMove();
            checkGameStatus();
            switchPlayer();
        }
    }

private:
    ChessGame* game; // Chess game logic
    Player currentPlayer; // Current player's turn
    BoardWindow boardWindow = BoardWindow({100, 100}, "Chess Game");

    void handlePlayerMove() {
        std::string from, to;
        std::cout << (currentPlayer == WHITE ? "White" : "Black") << "'s turn\n";
        std::cout << "Enter move (e.g., 'e2 e4'): ";
        std::cin >> from >> to;

        if (game->isValidMove(from, to)) {
            if (game->movePiece(from, to)) {
                std::cout << "Move successful!\n";
                boardWindow.updateBoard(game->board); // Update the board window with new position
            } else {
                std::cout << "Move failed!\n";
            }
        } else {
            std::cout << "Invalid move!\n";
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE;
    }

    void checkGameStatus() {
        // Placeholder: You could add checks for checkmate, stalemate, or draw conditions here
        // For example:
        // if (game->isCheckmate()) {
        //     std::cout << "Checkmate! ";
        //     std::cout << (currentPlayer == WHITE ? "Black" : "White") << " wins!\n";
        //     exit(0);
        // }
    }
};

int main() {
    GameManager gameManager;
    gameManager.startGame();
    return 0;
}

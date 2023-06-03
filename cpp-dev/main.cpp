
#include <iostream>
#include <functional>
#include <vector>

#include "chess/Grid.cpp"
#include "dataStructures/HashTable.cpp"
#include "dataStructures/List.cpp"


int main() {
    // Grid grid;
    // auto myGrid = grid.getGrid();
    // grid.printBoard();

    List<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    list.display();

    list.erase(4);
    list.erase(1);
    list.erase(5);
    list.erase(3);
    list.display();

    List<std::string> lists;
    lists.insert("A");
    lists.insert("B");
    lists.insert("C");
    lists.insert("D");
    lists.insert("E");

    lists.display();

    lists.erase("D");
    lists.erase("A");
    lists.erase("E");
    lists.erase("C");
    lists.display();
    
    return 0;
}




/////////////////////////////////////////


// const int BOARD_SIZE = 3;
// const char EMPTY = ' ';
// const char PLAYER_X = 'X';
// const char PLAYER_O = 'O';

// std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, EMPTY));

// bool isBoardFull() {
//     for (int i = 0; i < BOARD_SIZE; ++i) {
//         for (int j = 0; j < BOARD_SIZE; ++j) {
//             if (board[i][j] == EMPTY) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// bool checkWin(char player) {
//     // Check rows
//     for (int i = 0; i < BOARD_SIZE; ++i) {
//         if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
//             return true;
//         }
//     }

//     // Check columns
//     for (int j = 0; j < BOARD_SIZE; ++j) {
//         if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
//             return true;
//         }
//     }

//     // Check diagonals
//     if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
//         (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
//         return true;
//     }

//     return false;
// }

// void printBoard() {
//     std::cout << "-------------\n";
//     for (int i = 0; i < BOARD_SIZE; ++i) {
//         for (int j = 0; j < BOARD_SIZE; ++j) {
//             std::cout << "| " << board[i][j] << " ";
//         }
//         std::cout << "|\n-------------\n";
//     }
// }

// bool isValidMove(int row, int col) {
//     if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY) {
//         return true;
//     }
//     return false;
// }

// void makeMove(char player, int row, int col) {
//     board[row][col] = player;
// }

// int main() {
//     char currentPlayer = PLAYER_X;
//     int row, col;

//     std::cout << "Tic Tac Toe\n";
//     std::cout << "Player X vs Player O\n\n";

//     while (true) {
//         std::cout << "Current board:\n";
//         printBoard();
//         std::cout << "Player " << currentPlayer << "'s turn. Enter your move (row column): ";
//         std::cin >> row >> col;

//         if (isValidMove(row, col)) {
//             makeMove(currentPlayer, row, col);

//             if (checkWin(currentPlayer)) {
//                 std::cout << "Player " << currentPlayer << " wins!\n";
//                 break;
//             }

//             if (isBoardFull()) {
//                 std::cout << "It's a tie!\n";
//                 break;
//             }

//             currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
//         } else {
//             std::cout << "Invalid move! Try again.\n";
//         }
//     }

//     std::cout << "Final board:\n";
//     printBoard();
//     std::cout << "Game Over.\n";

//     return 0;
// }

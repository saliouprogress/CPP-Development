#include <iostream>
#include <algorithm>
#include "Point.cpp"
#include "Square.cpp"

const int BOARD_SIZE = 9;
// const char EMPTY = ' ';
// const char PLAYER_X = 'X';
// const char PLAYER_O = 'O';

class Grid { 
    public:
        Grid() : gridPoints() {
            for (int i = 0; i < BOARD_SIZE; i++) {
                std::vector<Point> row;
                for (int j = 0; j < BOARD_SIZE; j++) {
                    row.push_back(Point(i,j));
                }
                this->gridPoints.push_back(row);
            }
            this->buildSquares();
        }

        std::vector<std::vector<Point>> getGrid() {
            return this->gridPoints;
        }

        void buildSquares() {
            for (int i = 0; i < BOARD_SIZE - 1; i++) {
                std::vector<Square> square_row;
                for (int j = 0; j < BOARD_SIZE - 1 ; j++) {
                    Square square( Point(i,j));
                    square_row.push_back(square);
                }
                this->squares.push_back(square_row);
            }
        }

        std::vector<std::vector<Square>> getSquares() {
            return squares;
        }

        void printBoard() {
            for ( int i = this->squares.size() - 1; i >= 0; i--) {
                
                for(int j = 0; j < this->squares.size(); j++) {
                    Square square = this->squares[j][i];
                    std::cout <<  ")" << square.top_left_point.getY() << "--------" << square.top_right_point.getY() << "(";
                }
                std::cout << "\n";
                for(int j = 0; j < this->squares.size(); j++) {
                    std::cout <<  "|"                          << "          " << "|";
                }
                std::cout << "\n";
                for(int j = 0; j < this->squares.size(); j++) {
                    std::cout <<  "*"                          << "          " << "*";
                }
                std::cout << "\n";
                for(int j = 0; j < this->squares.size(); j++) {
                    std::cout <<  "|"                          << "          " << "|";
                }
                std::cout << "\n";
                for(int j = 0; j < this->squares.size(); j++) {
                    Square square = this->squares[j][i];
                    std::cout <<  ")" << square.bottom_left_point.getX() << "--------" << square.bottom_right_point.getX() << "(";
                }
                std::cout << "\n";
            }
        }

    private:
        std::vector<std::vector<Point>> gridPoints;
        std::vector<std::vector<Square>> squares;
};

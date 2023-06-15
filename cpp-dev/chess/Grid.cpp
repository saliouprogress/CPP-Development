#include <iostream>
#include <algorithm>
#include "Point.cpp"
#include "Square.cpp"
#include "Piece.cpp"


const int BOARD_SIZE = 9;
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
            this->setPositions();
            this->setPieces();
            this->placePieces();
            this->buildSquares();
        }

        std::vector<std::vector<Point>> getGrid() {
            return this->gridPoints;
        }

        void buildSquares() {
            bool color_square = true;
            for (int i = 0; i < BOARD_SIZE - 1; i++) {
                std::vector<Square> square_row;
                for (int j = 0; j < BOARD_SIZE - 1 ; j++) {
                    
                    Square square( Point(i,j));
                    (color_square == true) ? (square.getAttributes().color = "White") : (square.getAttributes().color = "Black");
                    std::string key = std::to_string(i) + std::to_string(j);
                    square.getAttributes().position  = this->positions[key];
                    if(this->pieces.find(this->positions[key]) != this->pieces.end()) {
                        square.setCurrentPieceName( this->pieces[this->positions[key]].getName());
                    }
                    color_square == true ? color_square = false : color_square = true;
                    square_row.push_back(square);
                }
                color_square == true ? color_square = false : color_square = true;
                this->squares.push_back(square_row);
            }
        }

        std::vector<std::vector<Square>>& getSquares() {
            return squares;
        }
        
        void printBoard() {
            for ( int i = this->squares.size() - 1; i >= 0; i--) {
                for(int j = 0; j < this->squares.size(); j++) {
                    Square& square = this->squares[j][i];
                    std::cout <<  ")------------(";
                }
                std::cout << "\n";
                for(int j = 0; j < this->squares.size(); j++) {
                    Attributes attr = squares[i][j].getAttributes();
                    std::cout <<  "|"                          << "     " <<  attr.position << "     " << "|";
                }
                std::cout << "\n";
                for(int j = 0; j < this->squares.size(); j++) {
                    std::cout <<  "|"                          << "   " <<  squares[i][j].getAttributes().color << "    " << "|";
                }
                std::cout << "\n";
                for(int j = 0; j < this->squares.size(); j++) {
                    Attributes attr = squares[i][j].getAttributes();
                    if(attr.current_piece_name.size() == 0) {
                        std::cout <<  "|"                          << "     -      " << "|";
                    } else if(attr.current_piece_name.size() == 6) {
                         std::cout <<  "|"                          << "   " <<  attr.current_piece_name << "   " << "|";
                    } else if(attr.current_piece_name.size() == 7) {
                        std::cout <<  "|"                          << "  " <<  attr.current_piece_name << "   " << "|";
                    } else {
                        std::cout <<  "|"                          << "  " <<  attr.current_piece_name << "  " << "|";
                    }
                }
                std::cout << "\n";
                for(int j = 0; j < this->squares.size(); j++) {
                    Square& square = this->squares[j][i];
                    std::cout <<  ")------------(";
                }
                std::cout << "\n";
            }
        }

        void movePiece(std::string init_position, std::string final_position) {
            this->pieces[final_position] = this->pieces[init_position];
            this->pieces.erase(init_position);
            for (int i = 0; i <  this->squares.size(); i++) {
                for(int j = 0; j < this->squares.size(); j++) {
                    if(squares[i][j].getAttributes().position == final_position) {
                        squares[i][j].setCurrentPieceName(this->pieces[final_position].getName());
                    } else if(squares[i][j].getAttributes().position == init_position) {
                        squares[i][j].setCurrentPieceName("");
                    }
                }
            }
        }

        bool verifyInput(const std::string input) {
            if(input.size() == 2 && (static_cast<char>(input[0]) >= 65 && static_cast<char>(input[0]) <= 90) && 
                (static_cast<char>(input[1]) >= 48 && static_cast<char>(input[1]) <= 57)) {
                    return true;
            }
            return false;
        }

        bool isValidOrigin(const std::string origin) {
            if(pieces.find(origin) == pieces.end()) { 
                std::cout << "There is no piece there." << std::endl;
                return false;
            }
            return true;
        }

        void getMoveInput() {
            std::string origin;

            // Read input from the terminal
            while(true) {

                std::cout << "Enter original: ";
                std::getline(std::cin, origin);
                for (char& c : origin) {
                    c = std::toupper(c);
                }
                if(verifyInput(origin) && isValidOrigin(origin)) { break;}
            }
            std::string destination;

            // Read input from the terminal
            while (true) 
            {
                std::cout << "Enter destinaltion: ";
                std::getline(std::cin, destination);
                for (char& c : destination) {
                    c = std::toupper(c);
                }
                if(verifyInput(destination)) { break;}
            }
            // if(isValidMove(origin, destination)) {
                this->movePiece(origin, destination);
                this->printBoard();
            // }
        }
        void play();
        void setPieces();
        void placePieces();
        void setPositions();

    private:
         //// set all the pieces
        // Kings
        Piece red_king;
        Piece blue_king;

        // Queens
        Piece red_queen;
        Piece blue_queen;

        // Bishops
        Piece red_bishop1;
        Piece red_bishop2;
        Piece blue_bishop1;
        Piece blue_bishop2;

        // Knights
        Piece red_knight1;
        Piece red_knight2;
        Piece blue_knight1;
        Piece blue_knight2;

        // Rooks
        Piece red_rook1;
        Piece red_rook2;
        Piece blue_rook1;
        Piece blue_rook2;

        // Pawn
        Piece red_pawn1;
        Piece red_pawn2;
        Piece red_pawn3;
        Piece red_pawn4;
        Piece red_pawn5;
        Piece red_pawn6;
        Piece red_pawn7;
        Piece red_pawn8;

        Piece blue_pawn1;
        Piece blue_pawn2;
        Piece blue_pawn3;
        Piece blue_pawn4;
        Piece blue_pawn5;
        Piece blue_pawn6;
        Piece blue_pawn7;
        Piece blue_pawn8;
        std::vector<std::vector<Point>> gridPoints;
        std::vector<std::vector<Square>> squares;
        std::unordered_map<std::string, std::string> positions; 
        std::unordered_map<std::string, Piece> pieces;

};


void Grid::setPieces() {

    // set bishops
    this->blue_bishop1.setName("B Bishop");
    this->blue_bishop1.setColor("Blue");
    this->blue_bishop1.setId(1);

    this->blue_bishop2.setName("B Bishop");
    this->blue_bishop2.setColor("Blue");
    this->blue_bishop2.setId(2);

    this->red_bishop1.setName("R Bishop");
    this->red_bishop1.setColor("Red");
    this->red_bishop1.setId(1);

    this->red_bishop2.setName("R Bishop");
    this->red_bishop2.setColor("Red");
    this->red_bishop2.setId(2);
    
    // set knights
    this->blue_knight1.setName("B Knight");
    this->blue_knight1.setColor("Blue");
    this->blue_knight1.setId(1);

    this->blue_knight2.setName("B Knight");
    this->blue_knight2.setColor("Blue");
    this->blue_knight2.setId(2);

    this->red_knight1.setName("R Knight");
    this->red_knight1.setColor("Red");
    this->red_knight1.setId(1);

    this->red_knight2.setName("R Knight");
    this->red_knight2.setColor("Red");
    this->red_knight2.setId(2);

    // set rooks
    this->blue_rook1.setName("B Rook");
    this->blue_rook1.setColor("Blue");
    this->blue_rook1.setId(1);

    this->blue_rook2.setName("B Rook");
    this->blue_rook2.setColor("Blue");
    this->blue_rook2.setId(2);

    this->red_rook1.setName("R Rook");
    this->red_rook1.setColor("Red");
    this->red_rook1.setId(1);

    this->red_rook2.setName("R Rook");
    this->red_rook2.setColor("Red");
    this->red_rook2.setId(2);

    // set queens
    this->blue_queen.setName("B Queen");
    this->blue_queen.setColor("Blue");
    this->blue_queen.setId(1);

    this->red_queen.setName("R Queen");
    this->red_queen.setColor("Red");
    this->red_queen.setId(1);

    // set kings
    this->blue_king.setName("B King");
    this->blue_king.setColor("Blue");
    this->blue_king.setId(1);

    this->red_king.setName("R King");
    this->red_king.setColor("Red");
    this->red_king.setId(1);

    // set pawns
    this->blue_pawn1.setName("B Pawn");
    this->blue_pawn1.setColor("Blue");
    this->blue_pawn1.setId(1);

    this->blue_pawn2.setName("B Pawn");
    this->blue_pawn2.setColor("Blue");
    this->blue_pawn2.setId(2);

    this->blue_pawn3.setName("B Pawn");
    this->blue_pawn3.setColor("Blue");
    this->blue_pawn3.setId(3);

    this->blue_pawn4.setName("B Pawn");
    this->blue_pawn4.setColor("Blue");
    this->blue_pawn4.setId(4);

    this->blue_pawn5.setName("B Pawn");
    this->blue_pawn5.setColor("Blue");
    this->blue_pawn5.setId(5);

    this->blue_pawn6.setName("B Pawn");
    this->blue_pawn6.setColor("Blue");
    this->blue_pawn6.setId(6);

    this->blue_pawn7.setName("B Pawn");
    this->blue_pawn7.setColor("Blue");
    this->blue_pawn7.setId(7);

    this->blue_pawn8.setName("B Pawn");
    this->blue_pawn8.setColor("Blue");
    this->blue_pawn8.setId(8);

    this->red_pawn1.setName("R Pawn");
    this->red_pawn1.setColor("Red");
    this->red_pawn1.setId(1);

    this->red_pawn2.setName("R Pawn");
    this->red_pawn2.setColor("Red");
    this->red_pawn2.setId(2);

    this->red_pawn3.setName("R Pawn");
    this->red_pawn3.setColor("Red");
    this->red_pawn3.setId(3);

    this->red_pawn4.setName("R Pawn");
    this->red_pawn4.setColor("Red");
    this->red_pawn4.setId(4);

    this->red_pawn5.setName("R Pawn");
    this->red_pawn5.setColor("Red");
    this->red_pawn5.setId(5);

    this->red_pawn6.setName("R Pawn");
    this->red_pawn6.setColor("Red");
    this->red_pawn6.setId(6);

    this->red_pawn7.setName("R Pawn");
    this->red_pawn7.setColor("Red");
    this->red_pawn7.setId(7);

    this->red_pawn8.setName("R Pawn");
    this->red_pawn8.setColor("Red");
    this->red_pawn8.setId(8);
}

void Grid::placePieces() {
    // palce red pieces
    this->pieces["A1"] = this->red_rook1;
    this->pieces["B1"] = this->red_knight1;
    this->pieces["C1"] = this->red_bishop1;
    this->pieces["D1"] = this->red_queen;
    this->pieces["E1"] = this->red_king;
    this->pieces["F1"] = this->red_bishop2;
    this->pieces["G1"] = this->red_knight2;
    this->pieces["H1"] = this->red_rook2;
    this->pieces["A2"] = this->red_pawn1;
    this->pieces["B2"] = this->red_pawn2;
    this->pieces["C2"] = this->red_pawn3;
    this->pieces["D2"] = this->red_pawn4;
    this->pieces["E2"] = this->red_pawn5;
    this->pieces["F2"] = this->red_pawn6;
    this->pieces["G2"] = this->red_pawn7;
    this->pieces["H2"] = this->red_pawn8;

    // place blue pieces
    this->pieces["A8"] = this->blue_rook1;
    this->pieces["B8"] = this->blue_knight1;
    this->pieces["C8"] = this->blue_bishop1;
    this->pieces["D8"] = this->blue_queen;
    this->pieces["E8"] = this->blue_king;
    this->pieces["F8"] = this->blue_bishop2;
    this->pieces["G8"] = this->blue_knight2;
    this->pieces["H8"] = this->blue_rook2;
    this->pieces["A7"] = this->blue_pawn1;
    this->pieces["B7"] = this->blue_pawn2;
    this->pieces["C7"] = this->blue_pawn3;
    this->pieces["D7"] = this->blue_pawn4;
    this->pieces["E7"] = this->blue_pawn5;
    this->pieces["F7"] = this->blue_pawn6;
    this->pieces["G7"] = this->blue_pawn7;
    this->pieces["H7"] = this->blue_pawn8;
}

void Grid::setPositions() {
    std::vector<std::string> vecLetters = {"A", "B", "C", "D", "E", "F", "G", "H"};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::string key = std::to_string(i ) + std::to_string(j);
            positions[key] = vecLetters[j] + std::to_string(i + 1);
        }
    } 
}

void Grid::play() {

    this->getMoveInput();
}
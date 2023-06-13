
#include <iostream>
#include <functional>
#include <vector>
#include <unistd.h>
#include <string>

#include "chess/Point.cpp"
#include "chess/Square.cpp"
#include "chess/Grid.cpp"
#include "dataStructures/HashTable.cpp"
#include "dataStructures/List.cpp"
#include "dataStructures/Array.cpp"
#include "dataStructures/HashMap.cpp"


void echoInput() {
    std::string input;

    // Read input from the terminal
    std::cout << "Enter some input: ";
    std::getline(std::cin, input);

    // Output the input back to the terminal
    std::cout << "You entered: " << input << std::endl;
}

int main() {
    // Grid grid;
    // grid.movePiece("D8", "D5");
    // grid.movePiece("H2", "H3");
    // grid.movePiece("E2", "E3");
    // // sleep(5);
    // grid.printBoard();

    // Call the echoInput function
    echoInput();
    return 0;
}
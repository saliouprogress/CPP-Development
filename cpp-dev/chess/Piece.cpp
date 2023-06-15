#ifndef PIECE_CPP_GUARD
#define PIECE_CPP_GUARD

#include <iostream>


class Piece {
public:
    Piece() : name(""), color(""), player_id(""), id(0), position("") {}
    Piece(std::string name, std::string color) : name(name), color(color), 
        player_id("") , id(0), position("") {}
    Piece(std::string name, std::string color, std::string player_id) : 
        name(name), color(color), player_id(player_id), id(0), position("") {}

    void setName(std::string name) {
        this->name = name;
    }

    const std::string& getName() {
        return this->name;
    }

    void setColor(std::string color) {
        this->color = color;
    }

    const std::string& getColor() {
        return this->color;
    }

    void setPlayerId(const std::string& player_id) {
        this->player_id = player_id;
    }

    const std::string& getPlayerId() {
        return this->player_id;
    }

    void setId(const int& id) {
        this->id = id;
    }

    const int& getId() {
        return this->id;
    }

    void setPosition(const std::string position) {
        this->position = position;
    }

    const std::string& getPosition() {
        return this->position;
    }

private:
    int id;
    std::string name;
    std::string color;
    std::string player_id;
    std::string position;
    int numberOfMoves;
};

#endif
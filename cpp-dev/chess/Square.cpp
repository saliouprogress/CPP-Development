#include <iostream>

#include "Point.cpp"

class Square {
    public:
        Square(Point point) : bottom_left_point(point), square() {

            // bottom left point 
            this->bottom_left_point.setX(point.getX());
            this->bottom_left_point.setY(point.getY());

            // set bottom right point
            this->bottom_right_point.setX(point.getX() + 1);
            this->bottom_right_point.setY(point.getY());

            // set top left point;
            this->top_left_point.setX(point.getX());
            this->top_left_point.setY(point.getY() + 1);

            // set top right point
            this->top_right_point.setX(point.getX() + 1);
            this->top_right_point.setY(point.getY() + 1);
            this->setSquare();
        }
        void setSquare() {
            this->square.push_back(this->bottom_left_point);
            this->square.push_back(this->bottom_right_point);
            this->square.push_back(this->top_left_point);
            this->square.push_back(this->top_right_point);
        }

        std::vector<Point> getSquare() {
            return this->square;
        }

        void printSquare() {
            std::cout <<  ")" << this->top_left_point.y << "--------" << this->top_right_point.y << "(";
            std::cout <<  "|"                          << "          " << "|";
            std::cout <<  "*"                          << "          " << "*";
            std::cout <<  "|"                          << "          " << "|";
            std::cout <<  ")" << this->bottom_left_point.x << "--------" << this->bottom_right_point.x << "(";
        }

        Point bottom_left_point;
        Point bottom_right_point;
        Point top_left_point;
        Point top_right_point;

    private:
        std::vector<Point> square;
};
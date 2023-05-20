// point.h
#include <iostream>

class Point {
    public:
    int x;
    int y;
    int z;

    Point() {}

    Point(int x, int y) : x(x), y(y) {}

    Point(int x, int y, int z) : x(x), y(y), z(z) {}

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setZ(int z) {
        this->z = z;
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    int getZ() {
        return this->z;
    }

    void printPoint() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

};
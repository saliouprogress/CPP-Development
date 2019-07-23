#ifndef POINT_H             ///////////////  http://www.cplusplus.com/forum/general/124555/
#define POINT_H
#include <iostream>

using namespace std;

class Point
{
public:
    //Default constructor
    Point();
    Point(double new_x, double new_y);
    /*******Member Fucntions*******/
    //Accessors
    double GetX();
    double GetY();
    //Mutators
    void SetX(double x);
    void SetY(double Y);
private:
    double xCOORD, yCOORD;
};

#endif // POINT_H 

//////////////////////////////////////////////////////////////////////////

#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <sstream>
#include <string>
//#include "point.h"

using namespace std;

class Line
{
public:
    Line();
    Line(Point P1, Point P2);
    double GetA();
    double GetB();
    string ToString(double A, double B);
private:
    Point p1, p2;
    double A,B;
};

#endif // LINE_H 

/////////////////////////////////////////////////////////////////////////////

//#include "line.h"
//#include "point.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

//using namespace std;

//Default constructor
Line::Line():A(0),B(0)
{
    //left blank intentionally
}
//Point1_Object & Point2_Object were suppose to get
//Passed into here
Line::Line(Point P1, Point P2)
{
    p1 = P1;
    p2 = P2;
    double x1,x2,y1,y2;
    x1 = P1.GetX();
    x2 = P2.GetX();
    y1 = P1.GetY();
    y2 = P2.GetY();

    //derived from slope(m) intercept(b) form
    double m,b;
    
    m = (y2 - y1)/(x2-x1);
    b = y1 - m*x1;

    //B = -1/b;
    //A = -B*m;
    A = m;
    B = b;
    //cout << A << " " << B << endl;
}

//ACCESSORS
double Line::GetA()
{
    return A;
}
double Line::GetB()
{
    return B;
}

std::string Line::ToString(double A, double B)
{
    cout << "works" << endl;
    std::string out_string;
    std:stringstream buffer;
    
    cout << "Resulting line: " << "y = " << A << "x" << " + " << B << endl;
    out_string = buffer.str();
    cout << out_string;
    return out_string;
}
///////////////////////////////////////////////////////////////////////////////////

//#include "point.h"
//#include <iostream>

using namespace std;
              //INITIALIZES
Point::Point():xCOORD(0), yCOORD(0)
{
   //default constructor
   //does nothing
}

//Constructor acts as a mutator
//to get values

Point::Point(double new_x, double new_y)
{
    xCOORD = new_x;
    yCOORD = new_y;
}

//MUTATOR FUNCTIONS
void Point::SetX(double x)
{
    xCOORD = x;
}
void Point::SetY(double y)
{
    yCOORD = y;
}


//ACCESSOR FUNCTIONS
//This is how it is done
//In order to return a Private variable's value.
//In order to access a private variable's value.
double Point::GetX()
{
    return xCOORD;
}
double Point::GetY()
{
    return yCOORD;
}

////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <string>
//#include "point.h"
//#include "line.h"

using namespace std;

int main()
{

    Point Point1_Object(5,5);
    cout << "Point1 (x,y) is: (" << Point1_Object.GetX() << "," << Point1_Object.GetY() << ")" << endl;
    cout<<endl;
    Point Point2_Object(6,4);
    cout<<"Point2 (x,y) is: (" << Point2_Object.GetX() << "," << Point2_Object.GetY() << ")" << endl;
    cout<<endl;

    Line THE_Line(Point1_Object, Point2_Object);
    //cout<< "Resulting line: " << "y = " << THE_Line.GetA() << "x" << " + " << THE_Line.GetB() << endl;
    THE_Line.ToString(5,6);


    cout << endl << endl << endl << "END!!!" << endl;
    return 0;
}
//Edit & Run

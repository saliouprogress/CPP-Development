#include <iostream>

using namespace std;
/*
class Shape

{
public:
    
    double ID()
    { 
        double x = 5;
        //m_id = x;
        cout << x << endl;
        //return x;
    }
    std::string String()
    {
        cout << "Inheritence Working" << endl;
    }
private:
    double m_id;

};*/


class Point //: public Shape
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
    //friend ostream& operator<<(ostream& os, const Point& dt);
private:
    double xCOORD, yCOORD;
};

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
//ostream& operator<<(ostream& os, const Point& dt)
//{
    //os << dt.GetX() << '/' << dt.GetY() << '/' << endl;
//    return os;
//}

//ACCESSOR FUNCTIONS

double Point::GetX()
{   return xCOORD;  }
double Point::GetY()
{    return yCOORD; }


int main()
{
    
    Point Point1_Object(5,5);
    cout << "Point1 (x,y) is: (" << Point1_Object.GetX() << "," << Point1_Object.GetY() << ")" << endl;
    cout<<endl;
    Point Point2_Object(6,4);
    cout<<"Point2 (x,y) is: (" << Point2_Object.GetX() << "," << Point2_Object.GetY() << ")" << endl;
   
    
}

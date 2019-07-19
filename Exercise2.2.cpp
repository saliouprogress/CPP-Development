// Program to illustrate the working of objects and class in C++ Programming
#include <iostream>
#include <string> // For string class
// #include "Point.h"
using std::cout;
using std::cin;
using namespace std;

/////////////////////////////////// Header File //////////////////////////////////////

// #ifndef POINT_H
// #define POINT_H
// #include <string>
class Point
{
    private:
        double m_x;
        double m_y;
    public:
        Point(std::string); // This is the constructor declaration
        ~Point(); // This is the destructor declaration
        double GetX();
        double GetY(); 
        double SetX(double x);
        double SetY(double y);
        std::string ToString(double x, double y);     
};

// #endif

///////////////////////// Point.cpp File ///////////////////////////////////


// Member functions definitions including constructor and destructor
// Constructor
Point::Point(void) 
{
cout << "Object is being created" << endl;
}
// Destructor
Point::~Point(void) {
cout << "Object is being deleted" << endl;
}
double Point::GetX()
{
cout << "Enter the Value of x: " << endl;      
cin >> m_x;
return m_x;        
}
double Point::GetY()
{
  cout << "Enter the Value of y: " << endl;
  cin >> m_y;
  return m_y;
}
double Point::SetX(double x)
{
  m_x = x;
  cout << "The Value of x is: " << m_x << endl;
  return m_x;
}
double Point::SetY(double y)
{
  m_y = y;
  cout << "The Value of y is: " << m_y << endl; 
  return m_y;
}
std::string Point::ToString(double x,double y)
{ 
  cout << "Point(" << x << "," << y << ")" << endl;
}

/////////////////////////// Main.cpp File ////////////////////////
int main()
{
  
  Point Object;
  double badx,bady; char bads;
  badx = Object.SetX(Object.GetX());
  bady = Object.SetY(Object.GetY());
  Object.ToString(badx,bady);
 
  cout << "You entered x = " << badx << " & y = " << bady << bads << endl;
  return 0;
}


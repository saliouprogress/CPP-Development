// Program to illustrate the working of objects and class in C++ Programming
#include <iostream>
#include <string> // For string class
using namespace std;
class Point
{
    private:
        double m_x;
        double m_y;
    public:
        Point();   // This is the constructor declaration
        ~Point();  // This is the destructor declaration
        double GetX();
        double GetY(); 
        double SetX(double x);
        double SetY(double y);
        std::string ToString();     
};
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
std::string Point::ToString()
{ 
  //string str[7] = "String";
  //cout << str << endl;
  //return str;
}

int main()
{
  Point Object;
  double badx,bady; char bads;
  badx = Object.SetX(Object.GetX());
  bady = Object.SetY(Object.GetY());
  //bads = Object.ToString();
  //Object.ToString();
  cout << "You entered x = " << badx << " & y = " << bady << bads << endl;
  return 0;
}


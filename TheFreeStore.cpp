//////////////////////////////////////// Point Class /////////////////////////////////////

#ifndef POINT_H             ///////////////  http://www.cplusplus.com/forum/general/124555/
#define POINT_H
#include <iostream>
#include "cmath"

using namespace std;
class Point
{
public:
    //Default constructor
    Point();
    
    
    Point(double new_x, double new_y);
    Point(const Point& pp);
    /*******Member Fucntions*******/
    //Accessors
    double GetX();
    double GetY();
    //Mutators
    void SetX(double x);
    void SetY(double Y);
    double Distance(const Point& pp);
private:
    double xCOORD, yCOORD;
};

#endif // POINT_H 

using namespace std;
              //INITIALIZES
Point::Point():xCOORD(0), yCOORD(0)
{
   cout << "Default constructor" << endl;
   //does nothing
}

//Constructor acts as a mutator
//to get values

Point::Point(const Point& pp)
{
    xCOORD = pp.xCOORD;
    yCOORD = pp.yCOORD;
    cout << xCOORD << " Copy Constructor " << yCOORD << endl;
}

Point::Point(double new_x, double new_y)
{
    xCOORD = new_x;
    yCOORD = new_y;
    
    cout << xCOORD << " Constructor with coordinates " << yCOORD << endl;
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
double Point::Distance(const Point& pp)
{
    double distance, dx , dy;
    distance = sqrt(pow((xCOORD - pp.xCOORD),2) + pow((yCOORD - pp.yCOORD),2));
    
    cout << "Distance is: " << distance << endl;
    return distance;
}

 class MyClass
 {
 public:
     MyClass() { 
        itsAge = 1; 
        itsWeight=5; 
     } 
     ~MyClass() {}                          
     int GetAge() const { return itsAge; }
     int GetWeight() const { return itsWeight; }
     void SetAge(int age) { itsAge = age; }
 
 private:
     int itsAge;
     int itsWeight;
 };
 


#include <iostream>
#include <sstream>
#include <string>
//#include "Point.h"

using namespace std;

int main()
{
    
    Point Point1_Object(5,5);  
    cout << "Point1 (x,y) is: (" << Point1_Object.GetX() << "," << Point1_Object.GetY() << ")" << endl;
    cout<<endl;
    Point Point2_Object(6,4);
    cout<<"Point2 (x,y) is: (" << Point2_Object.GetX() << "," << Point2_Object.GetY() << ")" << endl;
    cout<<endl;
    
    Point* pp;
    //pp = new Point; // Default constructor is called
    pp= new Point(Point1_Object); //Copy Constructor
    pp = new Point(Point2_Object);
    pp = new Point(7,8);
    //delete pp; // Destructor gets called
    
    Point* p2 = new Point(*pp);
     cout << (*p2).GetX() << endl;
    Point1_Object.Distance(*pp); 
    
    delete p2; // Destructor gets called
    cout << (*pp).GetX() << endl;
    //delete pp; // Destructor gets called
    /*
    int ArrSize = 4;
    cin >> ArrSize;
    Point* pArr;
    pArr = new Point[ArrSize];
    delete[] pArr;  */
    
    //               Exercise 2: Creating Array of Pointers
    
    int ArrSize = 3, i;
    //cin >> ArrSize;
    Point* Arr[ArrSize];
    Point * ArrPointer;
    
     for (i = 0; i < ArrSize; i++)
     {
         ArrPointer = new Point(i, i+1);
         //ArrPointer-> Point(2*i , 1);
         Arr[i] = ArrPointer;
         //cout << "Point" << i+1 << ": " << endl;
     }
    
    for (i = 0; i < ArrSize; i++){
         cout << "Point" << i+1 << ": (" << Arr[i] -> GetX() << ", " << Arr[i] -> GetY()<< ")" << endl;}
    
    //delete[] Arr;
    for (i = 0; i < ArrSize; i++)
    {
        cout << "Point" << i + 1  << ":  deleted" << endl;
        delete Arr[i];
    }
    cout << "Point" << "1" << ": (" << Arr[0] -> GetX() << ", " << Arr[0] -> GetY()<< ")" << endl;
    delete[] Arr;
    //Arr = new Point(*pp);
    //Point[1] = new Point(2,3);
    //*(P_Arr + 2) = new Point();
    //cout << ((Arr[0]).GetX()) << " and " << ((*Arr).GetY()) << endl;
    
    //delete[] Arr;
    //elete[] Arr;
    cout << endl << endl <<  "              END!!!";
    //////////////////////////////////////////////////
    /*
    MyClass * myObject[50];
     int i;
     MyClass * objectPointer;
     for (i = 0; i < 50; i++)
     {
         objectPointer = new MyClass;
         objectPointer->SetAge(2*i +1);
         myObject[i] = objectPointer;
     }
 
     for (i = 0; i < 50; i++)
         std::cout << "#" << i+1 << ": " << myObject[i]->GetAge() << std::endl;

 
     for (i = 0; i < 50; i++)
     {
         delete myObject[i];
         myObject[i] = NULL;
     }
    */
    
 }
   

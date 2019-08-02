// C++ program to demonstrate implementation 
// of Inheritance 
#include <iostream>
using namespace std; 

//Base class 
class Parent 
{ 
	public: 
	int id_p;
	void print () 
    	{ cout<< "print parent class" <<endl; } 
   
    	void show () 
    	{ cout<< "show parent class" <<endl; }
}; 
/////////////////////////////////////////////////////////////////
// Sub class inheriting from Base Class(Parent) 
class Child : public Parent 
{ 
	public: 
	int id_c; 
	void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly 
    	{ /*cout<< "print child class" <<endl; */} 
   
    	void show () 
    	{ cout<< "show child class" <<endl; } 
}; 
// base class 
class Vehicle  : public Child 
{ 
  public: 
    Vehicle() 
    { 
      cout << "This is a Vehicle" << endl; 
    } 
}; 

///////////////////////////////////////////////////////////////////
class fourWheeler: public Vehicle 
{  public: 
    
    fourWheeler() 
    { 
      cout<<"Objects with 4 wheels are vehicles"<<endl; 
    } 
}; 
// sub class derived from two base classes 

class Car: public fourWheeler{ 
   
  public: 
     Car() 
     { 
       cout<<"Car has 4 Wheels"<<endl; 
     } 
}; 
///////////////////////////////////////////////////////////////////
class Shape
{
public:
    
    double ID()
    { 
        double x = 5;
        m_id = x;
        //cout << m_id << endl;
        return m_id;
    }
    std::string ToString()
    {
      	string s = { "Inheritence Working"};
        //cout << "Inheritence Working" << endl;
      	return s;
    }
//private:
    double m_id;
};

class Point : public Shape
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
{   	return xCOORD;  }
double Point::GetY()
{    	return yCOORD; }


int main()
{
    
    	Point Point1_Object(5,5);
    	cout << "Point1 (x,y) is: (" << Point1_Object.GetX() << "," << Point1_Object.GetY() << ")" << endl;
    	cout<<endl;
    	Point Point2_Object(6,4);
  	//Point2_Object.m_id = 7;
    	cout<<"Point2 (x,y) is: (" << Point2_Object.GetX() << "," << Point2_Object.GetY() << ")" << endl << 
      	Point2_Object.ID() << endl << Point2_Object.ToString() << endl << Point2_Object.m_id << endl;
  	
  	Car obj1; 
		
	// An object of class child has all data members 
	// and member functions of class parent 
	obj1.id_c = 7; 
	obj1.id_p = 91; 
	cout << "Child id is " << obj1.id_c << endl; 
	cout << "Parent id is " << obj1.id_p << endl; 
	//Car obj; 
	
	Parent *bptr; 
    	//Child d; 
    	//bptr = &d; 
       
    	//virtual function, binded at runtime (Runtime polymorphism) 
    	bptr->print();  
       
    	// Non-virtual function, binded at compile time 
    	bptr->show();  
  
	return 0; 
    
}

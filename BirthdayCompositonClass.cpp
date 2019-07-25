#include <iostream>
#include <string>

using namespace std;
class Point1{

public:
    Point1() {
      m_x1 = 0;   m_y1 = 0;
      cout << "Point1 Default Constructor." << endl; 
    }
    
    Point1(int x1, int y1) {
      m_x1 = x1;   m_y1 = y1;
      cout << "Point1 Start Point Constructor." << endl; 
    }
    
    Point1(const Point1& old) {
      m_x1 = old.m_x1;   m_y1 = old.m_y1;
      cout << "Point1 Copy Constructor." << endl;
    }
    
    ~Point1() {  //cout << "Birtthday Destructor." << endl; 
                }
    
    void X(int x1) { m_x1 = x1; }
    
    void Y(int y1) { m_y1 = y1; }
      
    int X() {  return m_x1; }
    
    int Y() { return m_y1; }
    
    
    void Distance1()
    {
        int distance =  m_x1 - m_y1;
        cout << distance << endl;
    }
    void ToString1() { cout<< m_x1 <<"/" <<m_y1 << endl; }
    
private:
    int m_x1; int m_y1;
    
};
class Birthday{

public:
    Birthday() {
      month = 0;   day = 0;   year = 0;
      cout << "Birthday Default Constructor." << endl; 
    }
    
    Birthday(int xmonth, int yday, int zyear) {
      month = xmonth;   day = yday;   year = zyear;
      //cout << "Birthday constructor with Start and End Point." << endl; 
    }
    
    Birthday(const Birthday& old) {
      month = old.month;   day = old.day;    year = old.year;
      //cout << "Birtthday Copy Constructor." << endl;
    }
    
    ~Birthday() {  //cout << "Birtthday Destructor." << endl; 
                }
    
    void X(int x) { month = x; }
    
    void Y(int y) { day = y; }
    
    void Z(int z){ year = z; }
    
    int X() {  return month; }
    
    int Y() { return day; }
    
    int Z() { return year; }
    
    void Distance2()
    {
        int distance =  month - day + year;
        cout << distance << endl;
        //return distance;
    }
    void ToString2(){ cout<< month <<"/" <<day <<"/" << year <<endl; }
    
private:
    int month; int day; int year;
    
};

class People{
public:
    People() { cout << "People Default Constructor." << endl;}
    
    People(string cname, Birthday cdateOfBirth) :name(cname), dateOfBirth(cdateOfBirth)
    { cout << "People Constructor with End Point." << endl; }
    
    People(string cname, Point1 cObject) :name(cname), Object(cObject)
    { cout << "People Constructor with Start Point." << endl; }
   
    ~People() { cout << "People Destructor." << endl; }
    
    void Length()
    {  
        cout<< name << " The distance is: "; dateOfBirth.Distance2(); 
        cout<< name << " The distance is: "; Object.Distance1(); 
    }
    
    void ToString() { 
        cout<<name <<" was born on: "; dateOfBirth.ToString2();
        cout<<name <<" was born on: "; Object.ToString1(); }
    
private:
    string name; Point1 Object; Birthday dateOfBirth; 
};

int main() 
{
    int x,y;
    cin >> x; cin >> y;
    
    int a,b,c;
    cin >> a; cin >> b; cin >> c;
    
    Point1 StartPoint(x,y);
    Birthday EndPoint(a,b,c);
    cout << endl << endl;
    
    People infoObject("Start Point Information is: ",StartPoint);
    infoObject.ToString();
    infoObject.Length();
    
    cout << endl << endl;
    
    
    People IObject("End Point Information is: ", EndPoint);
    IObject.ToString();
    IObject.Length();
}

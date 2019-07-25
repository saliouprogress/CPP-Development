#include <iostream>
#include <string>

using namespace std;

class Birthday{

public:
    Birthday() {
      month = 0;   day = 0;   year = 0;
      cout << "Birthday Default Constructor." << endl; }
    
    Birthday(int xmonth, int yday, int zyear) {
      month = xmonth;   day = yday;   year = zyear;
      cout << "Birthday constructor with Start and End Point." << endl; }
    
    Birthday(const Birthday& old) {
      month = old.month;   day = old.day;    year = old.year;
      cout << "Birtthday Copy Constructor." << endl;}
    
    ~Birthday() {  cout << "Birtthday Destructor." << endl; }
    
    void X(int x) { month = x; }
    
    void Y(int y) { day = y; }
    
    void Z(int z){ year = z; }
    
    int X() {  return month; }
    
    int Y() { return day; }
    
    int Z() { return year; }
    
    void ToString(){ cout<< month <<"/" <<day <<"/" << year <<endl; }
    
private:
    int month; int day; int year;
};

class People{
public:
    People(string cname, Birthday cdateOfBirth) :name(cname), dateOfBirth(cdateOfBirth)
    { cout << "People Constructor with Start Point." << endl; }
    
    ~People() { cout << "People Destructor." << endl; }
    
    void ToString() { cout<<name <<" was born on: "; dateOfBirth.ToString(); }
    
private:
    string name;   Birthday dateOfBirth;
};

int main() {
    int x,y,z;
    cin >> x; cin >> y; cin >> z;
    
    Birthday Object;
    Object.X(x); Object.Y(y); Object.Z(z);
    
    Birthday birthObject(8,9,97);
    
    People infoObject("Lenny the Cowboy", birthObject);
    infoObject.ToString();
  
    People IObject("Lenny the Cowboy", Object);
    IObject.ToString();
}

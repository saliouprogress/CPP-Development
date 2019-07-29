#include <iostream>
#include <ostream>
using namespace std;
 
class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
      
   public:
      // required constructors
      Distance() {
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i) {
         feet = f;
         inches = i;
      }
      
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet << " I: " << inches <<endl;
      }
      
      /*// method to display distance
      void displayDistance(const Distance& d) 
      {
          //Distance box;
          box.feet = d.feet;
          box.inches = d.inches;
   
         cout << "F: " << box.feet << " I: " << box.inches <<endl;
      }*/
      
      // overloaded minus (-) operator
      Distance operator- () {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
      }
      // Overload + operator to add two Distance objects.
      Distance operator + (const Distance& b) 
      {
          Distance box;
          box.feet = this->feet + b.feet;
          box.inches = this->inches + b.inches;
        return box;
       }
        // Overload * operator to Myltiply two Distance objects.
        Distance operator * (const Distance& b) 
        {
            Distance box;
            box.feet = this->feet * b.feet;
            box.inches = this->inches * b.inches;
          return box;
         }
         bool operator == (const Distance& d) {
           
          if(feet == d.feet && inches == d.inches) {
              return true;
           }
           return false;
        }
        
        Distance& operator = (const Distance& d) // Assignment operator.
        {
            //Distance box;
            feet = d.feet + 5;
            inches = d.inches + 5;
            
            return *this;
        }
        Distance& operator *= (int factor) // Scale the coordinates & assign.
        {
            feet *= factor;
            inches *= factor;
            //return ;
        }
};

ostream& operator << (ostream& os, const Distance& p) // Send to ostream.
{
 
}

int main() 
{
    Distance D1(11, 10), D2(11, 11), D3, D4, D5;
    int factor = 5;
   
    if( D1 == D2 ) 
    {
      cout << "D1 is equal to D2 " << endl;
    } 
    else 
    {
      cout << "D1 is not equal to D2 " << endl;
    }
   
     D3 = D1 + D2;
     cout << "D3: " ; D3.displayDistance();    // display 3

     D4 = D1 * D2;
     cout << "D4: " ; D4.displayDistance();     // display 4

     -D1;                     // apply negation
     cout << "-D1: " ; D1.displayDistance();    // display D1

     -D2;                     // apply negation
     cout << "-D2: " ; D2.displayDistance() ;     // display D2
 
     D3 = D1 + D2;
     cout << "D3: " ; D3.displayDistance();     // display 3
     
     D1 = D2;
     cout << "D5: " ; D1.displayDistance();    // display 5
 
     D1 *= factor;
     cout << "D6: " ; D1.displayDistance();    // display 5
 
     return 0;
}

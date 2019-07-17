#include <iostream>

using namespace std;

class Box {
   public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box
      double weight;   // Weight of box
};

int main() {

   Box Box1;        // Declare Box1 of type Box
   Box Box2;        // Declare Box2 of type Box
   Box Box3;        // Declare Box3 of type Box
   
   double volume = 0.0;     // Store the volume of a box here
   double density = 0.0;    // Store the density of a box here
 
   // box 1 specification
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;
   Box1.weight = 120.0;

   // box 2 specification
   Box2.height = 10.0;
   Box2.length = 12.0;
   Box2.breadth = 13.0;
   Box2.weight = 120.0;
   
   // box 3 specification
   Box3.height = 10.0;
   Box3.length = 10.0;
   Box3.breadth = 10.0;
   Box3.weight = 120.0;
   
   // volume of box 1
   volume = Box1.height * Box1.length * Box1.breadth;
   density = Box1.weight / volume;
   cout << "Volume of Box1 : " << volume << " Density : " << density << endl;
   

   // volume of box 2
   volume = Box2.height * Box2.length * Box2.breadth;
   density = Box2.weight / volume;
   cout << "Volume of Box2 : " << volume << " Density : " << density << endl;
   
   // volume of box 3
   volume = Box3.height * Box3.length * Box3.breadth;
   density = Box3.weight / volume;
   cout << "Volume of Box3 : " << volume << " Density : " << density << endl;
   
   return 0;
}

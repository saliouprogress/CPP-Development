
namespace MamadouDiallo 
{
  namespace CAD { int a = 5; void display(); }
  namespace Containers {int a = 5; void display();}
}

// A C++ code to demonstrate that we can define 
// methods outside namespace. 
#include <iostream> 
using namespace std; 

// Creating a namespace 
namespace ns 
{ 
	void display(); 
	class geek 
	{ 
	public: 
	void display(); 
	}; 
} 

// Defining methods of namespace 
void ns::geek::display() 
{ 
	cout << "ns::geek::display()\n"; 
} 
void ns::display() 
{ 
	cout << "ns::display()\n"; 
} 
void MamadouDiallo::CAD::display() 
{ 
	cout << "MamadouDiallo::CAD::display()\n"; 
} 

void MamadouDiallo::Containers::display() 
{ 
	cout << "MamadouDiallo::Containers::display()\n"; 
} 

// Driver code 
int main() 
{ 
	ns::geek obj; 
	ns::display(); 
	obj.display(); 
  MamadouDiallo::CAD::display();
  MamadouDiallo :: Containers :: display();
	return 0; 
} 

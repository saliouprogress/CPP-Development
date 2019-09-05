#include<iostream> 
//#include <stringstream>
#include<tuple> // for tuple 
#include<string>
#include <sstream>
using namespace std; 

string Print(const tuple <string, int, float>& tuple_print)
{
	cout << get<0>(tuple_print) << " " << get<1>(tuple_print); 
	std::stringstream ss;
  	ss.str << "Name: "<< get<0>(tuple_print) << ",Age: " << get<1>(tuple_print) << ",Height: " << get<2>(tuple_print) << endl;
  	std::string s = ss.str();
	return s;
}
int main() 
{ 
	// Declaring tuple 
	tuple <string, int, float> geek; 

	// Assigning values to tuple using make_tuple() 
	geek = make_tuple("Mamadou Diallo", 31, 5.5); 

	// Printing initial tuple values using get() 
	cout << "The initial values of tuple are : "; 
	cout << get<0>(geek) << " " << get<1>(geek); 
	cout << " " << get<2>(geek) << endl; 

	// Use of get() to change values of tuple 
	get<0>(geek) = "cde"; 
	get<2>(geek) = 20.5; 

	// Printing modified tuple values 
	cout << "The modified values of tuple are : "; 
	cout << get<0>(geek) << " " << get<1>(geek); 
	cout << " " << get<2>(geek) << endl; 
	cout << Print(geek);
	return 0; 
} 

#include <iostream> 
using namespace std; 
  
// A Functor 
class isSmaller 
{ 
private: 
    double num; 
public: 
    isSmaller(dbouble n) : num(n) {  } 
  
    // This operator overloading enables calling 
    // operator function () on objects of increment 
    double operator () (double arr_num) const { 
        return num + arr_num; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int to_add = 5; 
  
    transform(arr, arr+n, arr, isSmaller(to_add)); 
  
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
} 

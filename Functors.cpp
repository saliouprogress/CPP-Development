#include <iostream>     // std::cout
#include <algorithm>    // std::count_if
#include <vector>  
using namespace std; 
  
// A Functor 
template <typename T>
class isSmaller 
{ 
private: 
    T num; 
public: 
    isSmaller(T n) : num(n) {  } 
    bool operator () (T arr_num) const { 
        return num >= arr_num ? true : false;
    } 
}; 
  
// Driver code 
int main() 
{ 
   std::vector<double> myvector;
  for (int i=1; i<10; i++) myvector.push_back(i*1.5); // myvector: 1 2 3 4 5 6 7 8 9
  double cutoff = 6;
  double mycount = count_if(myvector.begin(), myvector.end(), isSmaller<double>(cutoff));
  std::cout << "myvector contains " << mycount  << " odd values.\n";
  
  for (int i=0; i<myvector.size(); i++) 
    cout << myvector[i] << " "; 
} 

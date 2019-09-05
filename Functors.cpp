#include <iostream>     // std::cout
#include <algorithm>    // std::count_if
#include <vector>  
#include <iterator>
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
        return (arr_num <= num) ? true : false;
    } 
}; 

template <typename T>
double sum(T iterStart, T iterEnd)
{
    double sum = 0.0;
    for(iterStart; iterStart != iterEnd; iterStart++)
        sum += (*iterStart);
    return sum;
}
  
// Driver code 
int main() 
{ 
  std::vector<double> myvector;
  for (int i=0; i<20; i++) myvector.push_back(-.5*i); // myvector: 1 2 3 4 5 6 7 8 9
  for (int i=0; i<myvector.size(); i++) cout << myvector[i] << " " << endl; 
  double cutoff = -2;
  double mycount = count_if(myvector.begin(), myvector.end(), isSmaller<double>(cutoff));
  std::cout << "myvector contains " << mycount  << " values less than or equal to " << cutoff << ".\n";
  
  cout << sum(myvector.begin(), myvector.end()) << endl;
} 

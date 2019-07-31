#include <iostream>

using namespace std;

class data
{
private:

    int numbers[16]; // integer array
    

public:
   int& operator[] (int index)  { return numbers[index]; }
    // returns reference to an integer (not the value of integer)
};

int main()
{
    data dat;
    dat[3] = 23;
    cout << dat[3] << endl;
}

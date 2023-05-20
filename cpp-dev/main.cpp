// Online C++ compiler to run C++ program online
#include <iostream>
#include <functional>


#include "./array.cpp"

int main() {
 
   int size = 5;
    Array<std::string, 5> data;

    data[0] = "Cherno";
    data[1] = "C++";

    for (size_t i = 0; i < data.Size(); i++) {
        std::cout << data[i] << std::endl;
    }

    constexpr int x = 10; // A constexpr variable initialized with a constant expression.

    std::cout << 56 << data.factorial(5) << std::endl;

    return 0; 
    
}
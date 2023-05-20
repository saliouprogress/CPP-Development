#include <iostream>

#include <array>


template<typename T, size_t S>
class Array
{
public:
    constexpr size_t Size() const { return S;  }
    
    T& operator[](size_t index) {  return m_Data[index];   }
    const T& operator[](size_t index) const {  return m_Data[index];   }

    T* Data() { return m_Data;  }
    const T* Data() const { return m_Data;  }

    constexpr int factorial(int n) { // A constexpr function that can be evaluated at compile time.
        if (n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        };
    };
private:
    T m_Data[S];
};


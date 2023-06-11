#include <iostream>


template <typename T>
class Array {
public:
    Array(int size);
    ~Array();
    int getSize() const;
    int& operator[](int index);
    void display();
private:
    int * data; // Pointer to dynamically allocate array
    int size; // Size of the array
};

template <typename T>
Array<T>::Array(int size) { // Constructor
    this->size = size;
    this->data = new int[size]();
}

template <typename T>
Array<T>::~Array() { // Destructor
    delete[] data;
}

template <typename T>
int Array<T>::getSize() const { // Getter for size
    return this->size;
}

template <typename T>
int& Array<T>::operator[](int index) { // Accessor and modifier for individual elements
    return data[index];
}

template <typename T>
void Array<T>::display() {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
// Online C++ compiler to run C++ program online
#include <iostream>

#include "./leetcodeQuestions/lrucache.cpp"

int main() {
 
    int capacity = 5;
    LRUCache* obj = new LRUCache(capacity);

    obj->put(1,1);
    obj->put(2,2);
    int param_1 = obj->get(1);
    obj->put(4,3);
    int param_2 = obj->get(2);
    obj->put(4,4);
    int param_3 = obj->get(1);

    int param_4 = obj->get(4);
    std::cout << param_1 << param_2 << param_1 << param_4 << "\n";

    return 0;
    
}
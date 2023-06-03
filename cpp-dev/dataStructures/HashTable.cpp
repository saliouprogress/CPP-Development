#include <iostream>
#include <vector>
#include <list>

template <typename T>
class HashTable {
private:
    static const int tableSize = 10; // size of the hash table
    std::vector<std::list<std::pair<int, T>>> table; // Vector of lists to store key-value pairs

    public:
    HashTable();
    void insert( int key, const T& value);
    void remove(int key);
    T get(int key);
    int hashFunction(int key);
};

template <typename T>
HashTable<T>::HashTable() {
    table.resize(tableSize); // Initialize the list with the specified size
}

template <typename T>
int HashTable<T>::hashFunction(int key) {
    return key % tableSize; // A simple hash function that returns the remainder after division by table size
}

template <typename T>
void HashTable<T>::insert(int key, const T& value) {
    int index = hashFunction(key);
    table[index].push_back(std::make_pair(key, value));
}

template <typename T>
void HashTable<T>::remove(int key) {
    int index = hashFunction(key);
    std::list<std::pair<int, T>>& bucket = table[index];
    for( auto it = bucket.begin(); it != bucket.end(); ++it) {
        if(it->first == key) {
            bucket.erase(it);
            break;
        }
    }
}
template <typename T>
T HashTable<T>::get(int key) {
    int index = hashFunction(key);
    std::list<std::pair<int, std::string>>& butcket = table[index];
    for(const auto& pair : butcket) {
        if( pair.first == key) {
            return pair.second;
        }
    }
    return ""; // If the key is not found return an empty string
}



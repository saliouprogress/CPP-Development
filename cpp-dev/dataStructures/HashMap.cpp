#include <iostream>
#include <vector>
#include <list>


// Hash Entry
template<typename K, typename V>
struct HashEntry
{
    K key;
    V value;
};


template < typename K, typename V, typename Hash = std::hash<K>>
class HashMap {
private:
    std::vector<std::list<HashEntry<K, V>>> buckets;
    size_t numBuckets;
    Hash hashFunction;

    size_t getBucketIndex(const K& key ) const {
        return hashFunction(key) % numBuckets;
    }

public:
    HashMap(size_t size) : numBuckets(size), buckets(size){}

    void insert( const K& key, const V& value ) {
        size_t index = getBucketIndex(key);
        for (auto& entry : buckets[index]) {
            if(entry.key == key) {
                entry.value = value;
                return;
            }
        }
        buckets[index].push_back({key, value});
    }

    bool contains(const K& key) {
        size_t index = getBucketIndex(key);
        for (auto& entry : buckets[index]) {
            if(entry.key == key) {
                return true;
            }
        }
        return false;
    }

    const V& get(const K& key) {
        size_t index = getBucketIndex(key);
        for (auto& entry : buckets[index]) {
            if(entry.key == key) {
                return entry.value;
            }
        }
        throw std::out_of_range("Key not found in range.");
    }

    void remove(const K& key) {
        size_t index = getBucketIndex(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                return;
            }
        }
        throw std::out_of_range("Key not found in range.");
    }
};
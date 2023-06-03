#include <iostream>

template <typename T>
struct  Node 
{
    T value;
    Node * prev;
    Node * next;
    Node(): prev(nullptr), next(nullptr){} 
    Node(T value): value(value), prev(nullptr), next(nullptr){} 
};

template <typename T>
class List
{
private:
    Node<T> * head;
    Node<T> * tail;
    int size;
public:
    List();

    void insert(T value);
    void erase( T value);
    void display();
    T   front();
    T   back();
};

template <typename T>
List<T>::List(): head(nullptr), tail(nullptr), size(0){
}

template <typename T>
void List<T>::insert( T value) {
    Node<T> * newNode = new Node<T>(value);
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size += 1;
}

template <typename T>
void List<T>::erase(T value) {
    Node<T> * newNode = head;
    while(newNode != nullptr) {
        if(newNode->value == value) {
            if(newNode == head) {
                head = newNode->next;
                if(head != nullptr) {
                    head->prev = nullptr;
                }
            } else if(newNode == tail) {
                tail = newNode->prev;
                if(tail != nullptr) {
                    tail->next = nullptr;
                }
            } else {
                newNode->prev->next = newNode->next;
                newNode->next->prev = newNode->prev;
            }
            newNode = nullptr;
            delete newNode;
            size -= 1;
            return;
        }
        newNode = newNode->next;
    }
}

template <typename T>
void List<T>::display() {
    Node<T> * newNode = head;
    while(newNode) {
        std::cout << newNode->value << " ";
        newNode = newNode->next;
    }
    delete newNode;
    std::cout << "\n";
}

template <typename T>
T List<T>::front() {
    return head->value;
}

template <typename T>
T List<T>::back() {
    return tail->value;
}




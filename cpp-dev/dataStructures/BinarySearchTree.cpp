#include <iostream>


template<typename T>
struct Node {
    T value;
    Node * left;
    Node * right;
    Node(): left(nullptr), right(nullptr){}
    Node(T value) : value(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    Node<T> * root;
    int size;

public:
    BinaryTree() : size(0), root(nullptr) {}
    BinaryTree(const T& value) {
        root->value = value;
        size += 1;
    }

    void insert(const T& value) {
        Node curr = root;
        if(curr == nullptr) {
            curr->value = value;
            return;
        }
        while (curr != nullptr)
        {
            if(curr->value > value) {
                curr = curr->left;
            } else if(curr->value < value) {
                curr = curr->right;
            }
        }
        curr = new Node<T>(value);
        size += 1;
    }

    void remove(T& value) {
        Node curr = root;
        if(curr == nullptr) {
            return;
        }
        while (curr != nullptr)
        {
            if(curr->value == value) { break;}
            else if(curr->left != nullptr && curr->left->value >= value) {
                root = curr->left;
            } else if(curr->right != nullptr && curr->right->value <= value) {
                curr = curr->right;
            } else {
                break;
            }
        }

        if(curr == nullptr) {
            return;
        }
        
    }

    const T& find(const T& value) {

    }

    void display() {

    }
};
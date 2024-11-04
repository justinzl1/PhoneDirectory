//
// Created by Justin Lee on 11/3/24.
//

#ifndef DICT_HPP
#define DICT_HPP
#include <string>
#include <vector>

using namespace std;

template <typename T>
int comp(const T& a, const T& b) {
    if(a < b) return -1;
    if(a > b) return 1;
    return 0;
}


template <typename T, typename Y>
class Node
{
public:
    Node(T k, Y d, Node* n = NULL) : key(k), data(d), left(n), right(n) {}
    T key;
    Y data;
    Node* left;
    Node* right;
};


template <typename T, typename Y>
class Dict {
public:
    Dict() : head(nullptr) {}
    Dict(T k, Y d) : head(new Node<T, Y>(k, d)) {}
    void add(T key, Y data);
    Y& operator[](const T& key);

private:
    Node<T, Y>* head;
    Node<T, Y>* search(const T& key);
};

template <typename T, typename Y>
void
Dict<T,Y>:: add(T key, Y data) {
    if (head == NULL) {
        head = new Node<T,Y>(key,data);
        return;
    }
    auto* newNode = new Node<T,Y>(key,data);
    Node<T,Y>* curr = head;
    while(curr->left || curr->right) {
        if(comp(curr->key,key) < 0) {
            if (curr->left == nullptr) break;
            curr = curr->left;
        } else {
            if (curr->right == nullptr) break;
            curr = curr->right;
        }
    }
    if(comp(curr->key,key) < 0) {
        curr->left = newNode;
    } else {
        curr->right = newNode;
    }
};

template <typename T, typename Y>
Node<T, Y>* Dict<T, Y>::search(const T& key) {
    Node<T, Y>* curr = head;
    Node<T, Y>* parent = nullptr;

    while (curr != nullptr) {
        int comparison = comp(curr->key, key);
        if (comparison == 0) {
            return curr;  // Key found
        }
        parent = curr;
        if (comparison < 0) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

template <typename T, typename Y>
Y& Dict<T, Y>::operator[](const T& key) {
    return search(key)->data;
}

#endif //DICT_HPP

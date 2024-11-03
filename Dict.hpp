//
// Created by Justin Lee on 11/3/24.
//

#ifndef DICT_HPP
#define DICT_HPP
#include <string>

template <typename T>
class Node
{
public:
    Node(T d, Node* n = NULL) : data(d), left(n), right(n) {}
    T data;
    Node* left;
    Node* right;
};


template <typename T, typename Y>
class Dict {
public:
    Dict(): node(NULL), data(NULL){};
    Dict(T n, Y d): node(n), data(d){};
    void add(T root, Y val) {
        Node temp = new Node<T>(root, val);
        if (root == NULL) {
            return temp;
        }
        Node curr = root;
        while(curr != NULL) {
            if(curr->data > val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if(val < curr->data) {
            curr->left = temp;
        } else {
            curr->right = temp;
        }
    };
private:
    Node<T>* node;
    Node<Y>* data;

};

#endif //DICT_HPP

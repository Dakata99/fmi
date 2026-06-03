#pragma once

struct Node {
    int value;
    Node *left, *right;
    Node(Node * = nullptr, const int = -1, Node * = nullptr);
};

#include "BTree.cpp"

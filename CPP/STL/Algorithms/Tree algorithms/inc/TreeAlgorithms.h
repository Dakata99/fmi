#ifndef _TREE_ALGS_H_
#define _TREE_ALGS_H_

#include "Binary/Linked/BTree.h"
#include "BST/BST.h"
#include "AVL/AVL.h"

template<class T>
class TreeAlgorithm {

public:
    void pre_order(const BTree<T>&);

    void in_order(const BTree<T>&);

    void post_order(const BTree<T>&);

    bool search(const BTree<T>&, const T&);

    void print2D(const BTree<T>&);

    void print2D_v2(const BTree<T>&);

    int height(const BTree<T>&);
};

#include "TreeAlgorithms.cpp"

#endif

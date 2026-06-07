#ifndef _TREE_ALGS_H_
#define _TREE_ALGS_H_

#include "../../Containers/Other/Graph/Trees/AVL/AVL.h"
#include "../../Containers/Other/Graph/Trees/BST/BST.h"
#include "../../Containers/Other/Graph/Trees/Binary/Linked/BTree.h"

template <class T>
void pre_order(const BTree<T>&);

template <class T>
void in_order(const BTree<T>&);

template <class T>
void post_order(const BTree<T>&);

template <class T>
bool search(const BTree<T>&, const T&);

template <class T>
void print2D(const BTree<T>&);

template <class T>
void print2D_v2(const BTree<T>&);

template <class T>
int height(const BTree<T>&);

#include "TreeAlgorithms.cpp"

#endif

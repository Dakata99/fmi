#ifndef _BST_H_
#define _BST_H_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>

#include "../../Binary/Linked/src/BTree.hpp"

template <class T>
class BST : public BTree<T> {
private:
    friend Position<T>;

    typedef typename BTree<T>::Node BTNode;

private: /* other helper functions */
    void create_rec(BTNode*&, std::vector<T>, int, int);
    BTNode* insert_rec(BTNode*, const T&);
    BTNode* remove_rec(BTNode*, const T&);

private:
    BTNode* find_min(BTNode*);
    BTNode* in_pre(BTNode* root);
    BTNode* in_succ(BTNode* root);

public:
    BST();
    BST(const BST&);

    BST& operator=(const BST&);

    void create(const std::vector<T>&) override;

    void insert_rec(const T&);
    void insert_iter(const T&);

    bool search_rec(const T&) const;
    bool search_iter(const T&) const;

    void remove(const T&);
};

#endif

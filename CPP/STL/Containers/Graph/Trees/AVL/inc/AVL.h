#ifndef _AVL_H_
#define _AVL_H_

#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>

#include "BST/src/BST.hpp"

template <class T>
class Position;

template <class T>
class Iterator;

template <class T>
class AVL : public BST<T> {
private:
    friend Position<T>;
    typedef typename BST<T>::Node BTNode;

private: /* other helper functions */
    BTNode* insert_rec(BTNode*, const T&);
    BTNode* remove_rec(BTNode*, const T&);
    BTNode* find_min(BTNode*);

private:
    int balance_factor(BTNode*);
    BTNode* LL_rotation(BTNode*);
    BTNode* RR_rotation(BTNode*);
    BTNode* LR_rotation(BTNode*);
    BTNode* RL_rotation(BTNode*);

public:
    AVL();
    AVL(const AVL&);

    AVL& operator=(const AVL&);

    void insert_rec(const T&);
    void insert_iter(const T&);

    bool search_rec(const T&) const;
    bool search_iter(const T&) const;

    void remove(const T&);
};

#endif

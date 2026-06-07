#ifndef _BTREE_H_
#define _BTREE_H_

#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>

template <class T>
class Position;

template <class T>
class Iterator;

template <class T>
class BTree {
protected:
    struct Node {
        int height;
        T value;
        Node *left, *right;
        Node(Node* = nullptr, const T& = T(), Node* = nullptr);
    };

    Node* root;
    friend Position<T>;

private:
    void copy_rec(Node*&, const Node*);
    void dealloc(Node*);

private: /* print order traversals */
    void print_pre_order(const Node*) const;
    void print_in_order(const Node*) const;
    void print_post_order(const Node*) const;

protected: /* other helper functions */
    void print(Node*, int) const;
    void print_v2(Node*, int) const;

    virtual void create_rec(Node*&, const std::vector<T>&, int, int);
    bool search_element(Node*, const T&) const;
    int calc_height(const Node*) const;

public:
    BTree();
    BTree(const BTree&);
    ~BTree();

    BTree& operator=(const BTree&);

    Position<T> root_position(void);

    Iterator<T> begin(void);
    Iterator<T> end(void);

    void create(void);
    virtual void create(const std::vector<T>&);
    bool search(const T&) const;

    void print2D(void) const;
    void print2D_v2(void) const;

    void pre_order(void) const;
    void in_order(void) const;
    void post_order(void) const;

    int height(void) const;
};

#endif

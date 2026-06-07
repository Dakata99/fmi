#ifndef _TREE_H_
#define _TREE_H_

#include <queue>

#define COUNT 5

template <class T>
class Tree {
protected:
    struct Node {
        int height;
        T value;
        Node *left, *right;
        Node(Node* = nullptr, const T& = T(), Node* = nullptr);
    };

    Node* root;

private:
    Node* copy(Node*, Node*);
    void copy(const Tree&);
    void dealloc(Node*);

    void create_rec(Node*&, std::vector<T>, int, int);
    bool search_element(Node*, const T&) const;
    int calc_height(const Node*) const;

    /* print order traversals */
    void print_pre_order(const Node*) const;
    void print_in_order(const Node*) const;
    void print_post_order(const Node*) const;

    /* print 2D tree */
    void print(Node*, int) const;
    void print_v2(Node*, int) const;

public:
    Tree();
    Tree(const Tree&);
    ~Tree();

    Tree& operator=(const Tree&);

    void create(void);

    void create(std::vector<T>);
    bool search(const T&) const;

    int height(void) const;

    void pre_order(void) const;
    void in_order(void) const;
    void post_order(void) const;

    void print2D(void) const;
    void print2D_v2(void) const;
};

#endif

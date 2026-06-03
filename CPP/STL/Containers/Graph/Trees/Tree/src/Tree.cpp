#include "Tree.h"

#include <iostream>

template <class T>
Tree<T>::Node::Node(Node* _left, const T& val, Node* _right)
    : left(_left), value(val), right(_right) {}

template <class T>
typename Tree<T>::Node* Tree<T>::copy(Node* root1, Node* root2) {
    if (root2 == nullptr) {
        return nullptr;
    }

    root1 = new typename Tree<T>::Node(nullptr, root2->value, nullptr);
    root1->left = copy(root1->left, root2->left);
    root1->right = copy(root1->right, root2->right);

    return root1;
}

template <class T>
void Tree<T>::copy(const Tree<T>& other) {
    root = copy(root, other.root);
}

template <class T>
void Tree<T>::dealloc(Node* root) {
    if (root == nullptr) {
        return;
    }

    dealloc(root->left);
    dealloc(root->right);
    delete root;
}

template <class T>
Tree<T>::~Tree() {
    dealloc(root);
}

template <class T>
Tree<T>& Tree<T>::operator=(const Tree& other) {
    if (this != &other) {
        dealloc(*this);
        copy(other);
    }
    return *this;
}

template <class T>
Tree<T>::Tree(const Tree& other) {}

template <class T>
Tree<T>::Tree() : root(nullptr) {}

template <class T>
void Tree<T>::create(void) {
    Node* curr_node;
    Node* new_node;
    std::queue<Node*> nodes;

    T value;
    std::cout << "Enter root value: " << std::flush;
    std::cin >> value;

    root = new Node(nullptr, value, nullptr);
    nodes.push(root);

    while (!nodes.empty()) {
        curr_node = nodes.front();
        nodes.pop();

        std::cout << "Enter left child value of " << curr_node->value << ": "
                  << std::flush;
        std::cin >> value;
        if (value != -1) {
            new_node = new Node(nullptr, value, nullptr);
            curr_node->left = new_node;
            nodes.push(new_node);
        }

        std::cout << "Enter right child value of " << curr_node->value << ": "
                  << std::flush;
        std::cin >> value;
        if (value != -1) {
            new_node = new Node(nullptr, value, nullptr);
            curr_node->right = new_node;
            nodes.push(new_node);
        }
    }
    std::cout << std::endl;
}

template <class T>
void Tree<T>::print_pre_order(const Node* root) const {
    if (root == nullptr) {
        return;
    }

    std::cout << root->value << ' ';
    print_pre_order(root->left);
    print_pre_order(root->right);
}

template <class T>
void Tree<T>::pre_order(void) const {
    std::cout << "Pre order traversal: ";
    print_pre_order(root);
    std::cout << std::endl;
}

template <class T>
void Tree<T>::print_in_order(const Node* root) const {
    if (root == nullptr) {
        return;
    }

    print_in_order(root->left);
    std::cout << root->value << ' ';
    print_in_order(root->right);
}

template <class T>
void Tree<T>::in_order(void) const {
    std::cout << "In order traversal: ";
    print_in_order(root);
    std::cout << std::endl;
}

template <class T>
void Tree<T>::print_post_order(const Node* root) const {
    if (root == nullptr) {
        return;
    }

    print_post_order(root->left);
    print_post_order(root->right);
    std::cout << root->value << ' ';
}

template <class T>
void Tree<T>::post_order(void) const {
    std::cout << "Post order traversal: ";
    print_post_order(root);
    std::cout << std::endl;
}

template <class T>
void Tree<T>::print(Node* root, int tabs) const {
    if (root == nullptr) {
        return;
    }

    tabs += COUNT;

    print(root->right, tabs);

    for (int i = COUNT; i < tabs; i++) {
        std::cout << ' ';
    }
    std::cout << root->value << std::endl;

    print(root->left, tabs);
}

template <class T>
void Tree<T>::print2D(void) const {
    if (root == nullptr) {
        return;
    }

    std::cout << "------------------- 2D Tree -------------------\n";
    print(root, 0);
    std::cout << "-----------------------------------------------\n";
}

template <class T>
void Tree<T>::print_v2(Node* root, int tabs) const {
    if (root == nullptr) {
        return;
    }

    tabs += COUNT;

    std::cout << std::endl;
    for (int i = COUNT; i < tabs; i++) {
        std::cout << ' ';
    }
    std::cout << root->value << std::endl;

    print_v2(root->left, tabs);
    print_v2(root->right, tabs);
}

template <class T>
void Tree<T>::print2D_v2(void) const {
    if (root == nullptr) {
        return;
    }

    std::cout << "------------------- 2D Tree -------------------\n";
    print_v2(root, 0);
    std::cout << "-----------------------------------------------\n";
}

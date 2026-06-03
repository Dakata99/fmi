#include "BTree.h"

#define COUNT 5

template <class T>
BTree<T>::Node::Node(Node* l, const T& val, Node* r)
    : left(l), value(val), right(r) {}

template <class T>
void BTree<T>::copy_rec(Node*& root, const Node* other_root) {
    if (other_root == nullptr) {
        return;
    }

    root = new Node(nullptr, other_root->value, nullptr);
    copy_rec(root->left, other_root->left);
    copy_rec(root->right, other_root->right);
}

template <class T>
bool BTree<T>::search_element(Node* root, const T& element) const {
    if (root == nullptr) {
        return false;
    } else if (root->value == element) {
        return true;
    } else if (root->left == nullptr && root->right == nullptr) {
        return false;
    }

    return search_element(root->left, element) ||
           search_element(root->right, element);
}

template <class T>
bool BTree<T>::search(const T& element) const {
    return search_element(root, element);
}

template <class T>
void BTree<T>::print(Node* root, int tabs) const {
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
void BTree<T>::print2D(void) const {
    if (root == nullptr) {
        return;
    }

    std::cout << "------------------- 2D Tree -------------------\n";
    print(root, 0);
    std::cout << "-----------------------------------------------\n";
}

template <class T>
void BTree<T>::dealloc(Node* root) {
    if (root == nullptr) {
        return;
    }

    dealloc(root->left);
    dealloc(root->right);
    delete root;
}

template <class T>
BTree<T>::BTree() : root(nullptr) {}

template <class T>
BTree<T>::BTree(const BTree& other) {
    copy_rec(root, other.root);
}

template <class T>
BTree<T>::~BTree() {
    dealloc(root);
}

template <class T>
BTree<T>& BTree<T>::operator=(const BTree& other) {
    if (this != &other) {
        dealloc(*this);
        copy(other);
    }
    return *this;
}

template <class T>
Position<T> BTree<T>::root_position(void) {
    return Position<T>(root);
}

template <class T>
void BTree<T>::create(void) {
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
void BTree<T>::create_rec(Node*& root, const std::vector<T>& vec, int start,
                          int end) {
    if (start > end) {
        root = nullptr;
        return;
    }

    size_t mid = (start + end) / 2;
    root = new Node(nullptr, vec[mid], nullptr);

    create_rec(root->left, vec, start, mid - 1);
    create_rec(root->right, vec, mid + 1, end);
}

template <class T>
void BTree<T>::create(const std::vector<T>& vec) {
    create_rec(root, vec, 0, vec.size() - 1);
}

template <class T>
void BTree<T>::print_pre_order(const Node* root) const {
    if (root == nullptr) {
        return;
    }

    std::cout << root->value << ' ';
    print_pre_order(root->left);
    print_pre_order(root->right);
}

template <class T>
void BTree<T>::print_in_order(const Node* root) const {
    if (root == nullptr) {
        return;
    }

    print_in_order(root->left);
    std::cout << root->value << ' ';
    print_in_order(root->right);
}

template <class T>
void BTree<T>::print_post_order(const Node* root) const {
    if (root == nullptr) {
        return;
    }

    print_post_order(root->left);
    print_post_order(root->right);
    std::cout << root->value << ' ';
}

template <class T>
void BTree<T>::pre_order(void) const {
    std::cout << "Pre order traversal: ";
    print_pre_order(root);
    std::cout << std::endl;
}

template <class T>
void BTree<T>::in_order(void) const {
    std::cout << "In order traversal: ";
    print_in_order(root);
    std::cout << std::endl;
}

template <class T>
void BTree<T>::post_order(void) const {
    std::cout << "Post order traversal: ";
    print_post_order(root);
    std::cout << std::endl;
}

template <class T>
int BTree<T>::calc_height(const Node* root) const {
    if (root == nullptr) {
        return -1;
    }

    return 1 + std::max(calc_height(root->left), calc_height(root->right));
}

template <class T>
int BTree<T>::height(void) const {
    return calc_height(root);
}

template <class T>
void BTree<T>::print_v2(Node* root, int tabs) const {
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
void BTree<T>::print2D_v2(void) const {
    if (root == nullptr) {
        return;
    }

    std::cout << "------------------- 2D Tree -------------------\n";
    print_v2(root, 0);
    std::cout << "-----------------------------------------------\n";
}

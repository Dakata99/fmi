#include "BST.h"

template <class T>
bool BST<T>::search_rec(const T& element) const {
    return this->search(element);
}

template <class T>
bool BST<T>::search_iter(const T& element) const {
    if (this->root == nullptr) {
        return false;
    }

    BTNode* curr = this->root;
    while (curr != nullptr) {
        if (curr->value == element) {
            return true;
        } else if (curr->value > element) {
            curr = curr->left;
        } else if (curr->value < element) {
            curr = curr->right;
        }
    }

    return false;
}

template <class T>
typename BST<T>::BTNode* BST<T>::in_pre(BTNode* root) {
    while (root && root->right != nullptr) {
        root = root->right;
    }

    return root;
}

template <class T>
typename BST<T>::BTNode* BST<T>::in_succ(BTNode* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }

    return root;
}

template <class T>
typename BST<T>::BTNode* BST<T>::find_min(BTNode* root) {
    BTNode* current = root;
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current;
}

template <class T>
typename BST<T>::BTNode* BST<T>::remove_rec(BTNode* root, const T& element) {
    if (root == nullptr) {
        return root;
    }

    if (root->value > element) {
        root->left = remove_rec(root->left, element);
    } else if (root->value < element) {
        root->right = remove_rec(root->right, element);
    } else {
        if (root->left == nullptr) {
            BTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BTNode* temp = root->left;
            delete root;
            return temp;
        }

        BTNode* temp = find_min(root->right);
        root->value = temp->value;
        root->right = remove_rec(root->right, temp->value);
    }
    return root;
}

template <class T>
void BST<T>::remove(const T& element) {
    if (!this->search(element)) {
        return;
    }
    this->root = remove_rec(this->root, element);
}

template <class T>
BST<T>::BST() : BTree<T>() {}

template <class T>
BST<T>::BST(const BST& other) : BTree<T>(other) {}

template <class T>
BST<T>& BST<T>::operator=(const BST& other) {
    if (this != &other) {
        BTree<T>::operator=(other);
    }
    return *this;
}

template <class T>
void BST<T>::create(const std::vector<T>& vec) {
    std::vector<T> tmp(vec);
    std::sort(tmp.begin(), tmp.end());

    typename std::vector<T>::iterator it = std::unique(tmp.begin(), tmp.end());
    tmp.resize(std::distance(tmp.begin(), it));

    create_rec(this->root, tmp, 0, tmp.size() - 1);
}

template <class T>
void BST<T>::create_rec(BTNode*& root, std::vector<T> vec, int start, int end) {
    if (start > end) {
        root = nullptr;
        return;
    }

    size_t mid = (start + end) / 2;
    root = new BTNode(nullptr, vec[mid], nullptr);

    create_rec(root->left, vec, start, mid - 1);
    create_rec(root->right, vec, mid + 1, end);
}

template <class T>
typename BST<T>::BTNode* BST<T>::insert_rec(BTNode* root, const T& element) {
    if (root == nullptr) {
        return (new BTNode(nullptr, element, nullptr));
    } else if (root->value > element) {
        root->left = insert_rec(root->left, element);
    } else if (root->value < element) {
        root->right = insert_rec(root->right, element);
    }

    return root;
}

template <class T>
void BST<T>::insert_rec(const T& element) {
    if (!this->search(element)) {
        this->root = insert_rec(this->root, element);
    }
}

template <class T>
void BST<T>::insert_iter(const T& element) {
    BTNode* curr = this->root;
    BTNode* p;
    BTNode* r;

    if (this->root == nullptr) {
        this->root = new BTNode(nullptr, element, nullptr);
        return;
    }

    while (curr != nullptr) {
        r = curr;
        if (element < curr->value) {
            curr = curr->left;
        } else if (element > curr->value) {
            curr = curr->right;
        } else {
            return;
        }
    }

    p = new BTNode(nullptr, element, nullptr);

    if (element < r->value) {
        r->left = p;
    } else {
        r->right = p;
    }
}

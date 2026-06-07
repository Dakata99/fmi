#include "AVL.h"

template <class T>
AVL<T>::AVL() : BST<T>() {}

template <class T>
AVL<T>::AVL(const AVL& other) : BST<T>(other) {}

template <class T>
AVL<T>& AVL<T>::operator=(const AVL& other) {
    if (this != &other) {
        BST<T>::operator=(other);
    }
    return *this;
}

template <class T>
bool AVL<T>::search_iter(const T& element) const {
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
typename BST<T>::Node* AVL<T>::remove_rec(BTNode* root, const T& element) {
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
void AVL<T>::remove(const T& element) {
    if (!this->search_element(this->root, element)) {
        return;
    }
    this->root = remove_rec(this->root, element);
}

template <class T>
typename BST<T>::Node* AVL<T>::LL_rotation(BTNode* root) {
    BTNode* pl = root->left;
    BTNode* plr = pl->right;

    pl->right = root;
    root->left = plr;
    root->height = this->calc_height(root);
    pl->height = this->calc_height(pl);

    return pl;
}

template <class T>
typename BST<T>::Node* AVL<T>::RR_rotation(BTNode* root) {
    BTNode* pr = root->right;
    BTNode* prl = pr->left;

    pr->left = root;
    root->right = prl;
    root->height = this->calc_height(root);
    pr->height = this->calc_height(pr);

    return pr;
}

template <class T>
typename BST<T>::Node* AVL<T>::LR_rotation(BTNode* root) {
    BTNode* cl = root->left;
    BTNode* clr = cl->right;

    cl->right = clr->left;
    root->left = clr->right;

    clr->left = cl;
    clr->right = root;

    cl->height = this->calc_height(cl);
    root->height = this->calc_height(root);
    clr->height = this->calc_height(clr);

    return clr;
}

template <class T>
typename BST<T>::Node* AVL<T>::RL_rotation(BTNode* root) {
    BTNode* cr = root->right;
    BTNode* crl = cr->left;

    cr->left = crl->right;
    root->right = crl->left;

    crl->left = root;
    crl->right = cr;

    cr->height = this->calc_height(cr);
    root->height = this->calc_height(root);
    crl->height = this->calc_height(crl);

    return crl;
}

template <class T>
typename BST<T>::Node* AVL<T>::insert_rec(BTNode* root, const T& element) {
    if (root == nullptr) {
        root = new BTNode(nullptr, element, nullptr);
        return root;
    }
    if (root->value > element) {
        root->left = insert_rec(root->left, element);
    } else if (root->value < element) {
        root->right = insert_rec(root->right, element);
    }

    root->height = this->calc_height(root);

    if (balance_factor(root) == 2 && balance_factor(root->left) == 1) {
        return LL_rotation(root);
    } else if (balance_factor(root) == 2 && balance_factor(root->left) == -1) {
        return LR_rotation(root);
    } else if (balance_factor(root) == -2 &&
               balance_factor(root->right) == -1) {
        return RR_rotation(root);
    } else if (balance_factor(root) == -2 && balance_factor(root->right) == 1) {
        return RL_rotation(root);
    }

    return root;
}

template <class T>
void AVL<T>::insert_rec(const T& element) {
    if (!this->search_element(this->root, element)) {
        this->root = insert_rec(this->root, element);
    }
}

template <class T>
typename BST<T>::Node* AVL<T>::find_min(BTNode* root) {
    BTNode* current = root;
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current;
}

template <class T>
int AVL<T>::balance_factor(BTNode* root) {
    int lh = root != nullptr && root->left != nullptr ? root->left->height : -1;
    int rh =
        root != nullptr && root->right != nullptr ? root->right->height : -1;

    return lh - rh;
}

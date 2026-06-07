#include <iostream>

struct Node {
    int data;
    Node *left, *right;
    Node(Node *l = nullptr, const int d = 0, Node *r = nullptr)
        : left(l), data(d), right(r) {}
};

void inorder(Node *root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    std::cout << root->data << ' ';
    inorder(root->right);
}

void create_tree(int *values, int *l_childs, int *r_childs, int left, int right,
                 Node **root) {
    if (left == -1 && right == -1) {
        return;
    }

    if (left != -1) {
        (*root)->left = new Node(nullptr, values[left], nullptr);
        create_tree(values, l_childs, r_childs, l_childs[left], r_childs[left],
                    &(*root)->left);
    }

    if (right != -1) {
        (*root)->right = new Node(nullptr, values[right], nullptr);
        create_tree(values, l_childs, r_childs, l_childs[right],
                    r_childs[right], &(*root)->right);
    }
}

int main() {
    Node *root = new Node(nullptr, 99, nullptr); /* root */
    int a[] = {10, 11, 12, 13, 17};              /* root values */
    int b[] = {3, -1, -1, -1, -1};               /* left childs */
    int c[] = {2, 4, -1, -1, -1};                /* right childs */
    create_tree(a, b, c, 0, 1, &root);
    inorder(root);
    std::cout << std::endl;

    Node *root2 = new Node(nullptr, 999, nullptr);
    int a2[] = {10, 101};
    int b2[] = {-1, -1};
    int c2[] = {-1, -1};
    create_tree(a2, b2, c2, 0, 1, &root2);
    inorder(root2);
    std::cout << std::endl;

    return 0;
}

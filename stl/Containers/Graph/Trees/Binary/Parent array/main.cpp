#include <iostream>

struct Node {
    int value;
    Node *left, *right;
    Node(Node *l, const int val, Node *r) : left(l), value(val), right(r) {}
};

void inorder(const Node *root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    std::cout << root->value << ' ';
    inorder(root->right);
}

void create_node(int *parent, int i, Node **created, Node **root) {
    if (created[i] != NULL) {
        return;
    }

    created[i] = new Node(nullptr, i, nullptr);

    if (parent[i] == -1) {
        *root = created[i];
        return;
    }

    if (created[parent[i]] == NULL) {
        create_node(parent, parent[i], created, root);
    }

    Node *p = created[parent[i]];

    if (p->left == NULL) {
        p->left = created[i];
    } else {
        p->right = created[i];
    }
}

Node *create_tree(int *parent, int n) {
    Node *created[n];
    for (size_t i = 0; i < n; i++) {
        created[i] = NULL;
    }

    Node *root = NULL;
    for (size_t i = 0; i < n; i++) {
        create_node(parent, i, created, &root);
    }

    return root;
}

int main() {
    int parent[] = {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof(parent) / sizeof(parent[0]);
    Node *root = create_tree(parent, n);
    inorder(root);
    std::cout << std::endl;

    return 0;
}

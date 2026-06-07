
template <class T>
void pre_order(const BTree<T>& tree) {
    tree.pre_order();
}

template <class T>
void in_order(const BTree<T>& tree) {
    tree.in_order();
}

template <class T>
void post_order(const BTree<T>& tree) {
    tree.post_order();
}

template <class T>
bool search(const BTree<T>& tree, const T& element) {
    return tree.search(element);
}

template <class T>
void print2D(const BTree<T>& tree) {
    tree.print2D();
}

template <class T>
void print2D_v2(const BTree<T>& tree) {
    tree.print2D_v2();
}

template <class T>
int height(const BTree<T>& tree) {
    return tree.height();
}

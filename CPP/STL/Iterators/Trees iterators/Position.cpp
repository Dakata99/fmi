template <class T>
Position<T>::Position(typename BTree<T>::Node*& root) : current(root) {}

template <class T>
Position<T> Position<T>::left(void) const {
    assert(current != nullptr);
    return Position<T>(current->left);
}

template <class T>
Position<T> Position<T>::right(void) const {
    assert(current != nullptr);
    return Position<T>(current->right);
}

template <class T>
const T& Position<T>::operator*(void) const {
    assert(current != nullptr);
    return current->value;
}

template <class T>
bool Position<T>::empty(void) const {
    return current == nullptr;
}

template <class T>
const T& Position<T>::get(void) const {
    assert(current != nullptr);
    return current->value;
}

template <class T>
void Position<T>::set(const T& x) {
    if (current == nullptr) {
        current = new typename BTree<T>::Node(nullptr, x, nullptr);
    } else {
        current->value = x;
    }
}

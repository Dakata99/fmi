#include <cassert>

template <class T>
Iterator<T>::Iterator(Position<T> start, bool is_end) {
    if (!is_end && !start.empty()) {
        st.push(start);

        while (!st.top().left().empty()) {
            st.push(st.top().left());
        }
    }
}

template <class T>
T Iterator<T>::operator*(void) const {
    assert(!st.empty());
    return st.top().get();
}

template <class T>
Iterator<T>& Iterator<T>::operator++(void) {}

template <class T>
bool Iterator<T>::operator!=(const Iterator&) const {
    return false;
}

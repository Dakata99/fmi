#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include <vector>

#include "Binary/Linked/inc/BTree.h"

template <class T>
void pre_order_convert(Position<T> root, std::vector<T>& vec) {
    if (root.empty()) {
        return;
    }

    vec.push_back(root.get());
    pre_order_convert(root.left(), vec);
    pre_order_convert(root.right(), vec);
}

template <class T>
std::vector<T> tovector_pre_order(BTree<T> tree) {
    std::vector<T> vec;

    pre_order_convert(tree.root_position(), vec);

    return vec;
}

template <class T>
void in_order_convert(Position<T> root, std::vector<T>& vec) {
    if (root.empty()) {
        return;
    }

    in_order_convert(root.left(), vec);
    vec.push_back(root.get());
    in_order_convert(root.right(), vec);
}

template <class T>
std::vector<T> tovector_in_order(BTree<T> tree) {
    std::vector<T> vec;

    in_order_convert(tree.root_position(), vec);

    return vec;
}

template <class T>
void post_order_convert(Position<T> root, std::vector<T>& vec) {
    if (root.empty()) {
        return;
    }

    post_order_convert(root.left(), vec);
    post_order_convert(root.right(), vec);
    vec.push_back(root.get());
}

template <class T>
std::vector<T> tovector_post_order(BTree<T> tree) {
    std::vector<T> vec;

    post_order_convert(tree.root_position(), vec);

    return vec;
}

#endif

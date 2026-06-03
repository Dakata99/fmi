#pragma once

template <class InputIterator, class UnaryPredicate>
bool all_of(InputIterator, InputIterator, UnaryPredicate);

template <class InputIterator, class UnaryPredicate>
bool any_of(InputIterator, InputIterator, UnaryPredicate);

#include "Array_algs.cpp"

#include "Node.h"

template<typename T>
Node<T>::Node(const T& value)
{
    data = value;
    next = nullptr;
}

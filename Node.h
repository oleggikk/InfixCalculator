#ifndef LINKED_LIST_HEADER_H
#define LINKED_LIST_HEADER_H

template<typename T>
class Node
{
public:
    T data;
    Node* next;

    Node(const T& value);
};

#endif //LINKED_LIST_HEADER_H

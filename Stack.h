#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template<typename T>
class Stack
{
private:
    LinkedList<T> list;

public:
    Stack();
    ~Stack();

    void push(const T& data);
    T pop();
    T top() const;
    bool isEmpty() const;
    int size() const;
};

#include "Stack.cpp"

#endif  // STACK_H


template<typename T>
Stack<T>::Stack()
= default;

template<typename T>
Stack<T>::~Stack()
= default;

template<typename T>
void Stack<T>::push(const T& data)
{
    list.add_front(data);
}

template<typename T>
T Stack<T>::pop()
{
    T data = list.find_at(0);
    list.remove_front();
    return data;
}

template<typename T>
T Stack<T>::top() const
{
    return list.find_at(0);
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return list.get_size() == 0;
}

template<typename T>
int Stack<T>::size() const
{
    return list.get_size();
}

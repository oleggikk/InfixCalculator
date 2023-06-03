#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

template<typename T>
class LinkedList
{
private:
    template<typename U>
    struct Node
    {
        U data;
        Node<U>* next;

        Node(const U& value) : data(value), next(nullptr) {}
    };

    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void add_front(const T& value);
    void add_back(const T& value);
    void add_at(int index, const T& value);
    void remove_front();
    void remove_back();
    void remove_at(int index);
    int find(const T& value);
    T find_at(int index) const;
    void print();
    int get_size() const;
};


#endif  // LINKEDLIST_H


template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0)
{
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void LinkedList<T>::add_front(const T& value)
{
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr)
    {
        tail = newNode;
    }
    else
    {
        newNode->next = head;
    }

    head = newNode;
    size++;
}

template<typename T>
void LinkedList<T>::add_back(const T& value)
{
    Node<T>* newNode = new Node<T>(value);

    if (tail == nullptr)
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }

    tail = newNode;
    size++;
}

template<typename T>
void LinkedList<T>::add_at(int index, const T& value)
{
    if (index < 0 || index > size)
    {
        throw std::runtime_error("Error: Invalid index");
        return;
    }

    if (index == 0)
    {
        add_front(value);
        return;
    }

    if (index == size)
    {
        add_back(value);
        return;
    }

    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = head;
    Node<T>* previous = nullptr;

    for (int i = 0; i < index; i++)
    {
        previous = current;
        current = current->next;
    }

    previous->next = newNode;
    newNode->next = current;
    size++;
}

template<typename T>
void LinkedList<T>::remove_front()
{
    if (head == nullptr)
    {
        throw std::runtime_error("Error: List is empty");
        return;
    }

    Node<T>* current = head;
    head = head->next;
    delete current;
    size--;

    if (size == 0)
    {
        tail = nullptr;
    }
}

template<typename T>
void LinkedList<T>::remove_back()
{
    if (tail == nullptr)
    {
        throw std::runtime_error("Error: List is empty");
        return;
    }

    if (size == 1)
    {
        remove_front();
        return;
    }

    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current != tail)
    {
        previous = current;
        current = current->next;
    }

    delete tail;
    tail = previous;
    tail->next = nullptr;
    size--;
}

template<typename T>
void LinkedList<T>::remove_at(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::runtime_error("Error: Invalid index");
        return;
    }

    if (index == 0)
    {
        remove_front();
        return;
    }

    if (index == size - 1)
    {
        remove_back();
        return;
    }

    Node<T>* current = head;
    Node<T>* previous = nullptr;

    for (int i = 0; i < index; i++)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    delete current;
    size--;
}

template<typename T>
int LinkedList<T>::find(const T& value)
{
    Node<T>* current = head;
    int index = 0;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}

template<typename T>
T LinkedList<T>::find_at(int index) const
{
    if (index < 0 || index >= size)
    {
        throw std::runtime_error("Error: Invalid index");
        return T();
    }

    Node<T>* current = head;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

template<typename T>
void LinkedList<T>::print()
{
    Node<T>* current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

template<typename T>
int LinkedList<T>::get_size() const
{
    return size;
}

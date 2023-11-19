#ifndef COLA_H
#define COLA_H
#include <cstdlib>
#include <iostream>
template <class T> struct Node {
    T data;
    Node<T> *previous, *next;
};

template <class T> class Queue {
private:
    Node<T> *header, *z;
    int size;

public:
    Queue();
    int Size() { return size; };
    void Enqueue(T data);
    T Dequeue();
    T getDato(int pos);
    T Front();
    bool IsEmpty() { return header->next == z; }
};

template <class T> Queue<T>::Queue() {
    header = new Node<T>;
    z = new Node<T>;

    header->data = T();

    header->next = z;
    z->previous = header;

    z->next = z;
    z->data = T();
    size = 0;
}

template <class T> void Queue<T>::Enqueue(T data) {
    Node<T> *newNode, *temp, *aux;
    newNode = new Node<T>;
    newNode->data = data;

    aux = z->previous;

    z->previous = newNode;
    newNode->next = z;

    newNode->previous = aux;
    aux->next = newNode;
    size++;
}

template <class T> T Queue<T>::getDato(int pos) {
    if (pos < 1 || pos > size) {

    } else {
        Node<T> *aux = header->next;
        for (int i = 1; i < pos; i++) {
            aux = aux->next;
        }

        return aux->data;
    }
}

template <class T> T Queue<T>::Dequeue() {
    Node<T> *temp, *aux;
    T data;
    if (header->next != z) {
        temp = header->next;
        aux = temp->next;
        data = temp->data;

        aux->previous = header;
        header->next = aux;

        delete temp;
        size--;
    }
    return data;
}

template <class T> T Queue<T>::Front() {
    Node<T> *temp, *aux;
    T data;
    temp = header->next;
    return temp->data;
}
#endif
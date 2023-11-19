#include <iostream>
#include <queue>
#include "Pila.h"
#include "Cola.h"

enum Color
{
    BLACK = 0,
    RED = 1
};

template <class T, class S>
struct Nodo
{
    T dato;
    S otroDato;  // Nuevo tipo de dato
    bool color;
    Nodo<T, S> *left;
    Nodo<T, S> *right;
    Nodo<T, S> *parent;
};

template <class T, class S>
class RBTree
{
private:
    Nodo<T, S> *root;
    Nodo<T, S> *nullNode;

public:
    RBTree()
    {
        nullNode = new Nodo<T, S>{T(), S(), 0, NULL, NULL, NULL};
        root = nullNode;
    }

    void Insert(RBTree *&tree, Nodo<T, S> *z);
    void Delete(RBTree *&tree, Nodo<T, S> *z);
    Nodo<T, S> *getNullNode() { return nullNode; }
    Nodo<T, S> *getRoot() { return root; }
    void setRoot(Nodo<T, S> *Root) { this->root = Root; }
    Nodo<T, S> *createNodo(T Data, S OtroDato);
    Nodo<T, S> *findNodo(T Data);
    Queue<Nodo<T, S> *> recorridoNiveles();
    Queue<Nodo<T, S> *> preorden();
    Queue<Nodo<T, S> *> inorden();
    Queue<Nodo<T, S> *> posorden();

private:
    void FixInsertion(RBTree *&tree, Nodo<T, S> *z);
    void FixDeletion(RBTree *&tree, Nodo<T, S> *x);
    void Transplant(RBTree *&tree, Nodo<T, S> *u, Nodo<T, S> *v);
    void RotateLeft(RBTree *&tree, Nodo<T, S> *x);
    void RotateRight(RBTree *&tree, Nodo<T, S> *x);
    Nodo<T, S> *Minimum(Nodo<T, S> *x);
};

template <class T, class S>
Nodo<T, S> *RBTree<T, S>::createNodo(T Data, S OtroDato)
{
    Nodo<T, S> *nuevo = new Nodo<T, S>;

    nuevo->dato = Data;
    nuevo->otroDato = OtroDato;
    nuevo->left = NULL;
    nuevo->right = NULL;
    nuevo->parent = NULL;
    nuevo->color = 1; // RED
    return nuevo;
}

template <class T, class S>
Nodo<T, S> *RBTree<T, S>::Minimum(Nodo<T, S> *x)
{
    while (x->left != getNullNode())
    {
        x = x->left;
    }
    return x;
}

template <class T, class S>
void RBTree<T, S>::Transplant(RBTree *&tree, Nodo<T, S> *u, Nodo<T, S> *v)
{
    if (u->parent == tree->getNullNode())
    {
        tree->setRoot(v);
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template <class T, class S>
void RBTree<T, S>::RotateRight(RBTree *&tree, Nodo<T, S> *x)
{
    Nodo<T, S> *y = x->left;
    x->left = y->right;

    if (y->right != tree->getNullNode())
    {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == tree->getNullNode())
    {
        tree->setRoot(y);
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

template <class T, class S>
void RBTree<T, S>::RotateLeft(RBTree *&tree, Nodo<T, S> *x)
{
    Nodo<T, S> *y = x->right;
    x->right = y->left;

    if (y->left != tree->getNullNode())
    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == tree->getNullNode())
    {
        tree->setRoot(y);
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

template <class T, class S>
void RBTree<T, S>::Insert(RBTree *&tree, Nodo<T, S> *z)
{
    Nodo<T, S> *x = tree->getRoot();
    Nodo<T, S> *y = tree->getNullNode();

    while (x != tree->getNullNode())
    {
        y = x;
        if (z->dato < x->dato)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == tree->getNullNode())
    {
        tree->setRoot(z);
    }
    else if (z->dato < y->dato)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    z->left = tree->getNullNode();
    z->right = tree->getNullNode();
    z->color = 1; // RED
    FixInsertion(tree, z);
}

template <class T, class S>
Nodo<T, S> *RBTree<T, S>::findNodo(T Data)
{
    Nodo<T, S> *temp = root;
    while (temp != NULL && Data != temp->dato)
    {
        if (Data < temp->dato)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return temp;
}

template <class T, class S>
void RBTree<T, S>::FixInsertion(RBTree *&tree, Nodo<T, S> *z)
{
    Nodo<T, S> *tio;
    while (z->parent->color == 1) // RED
    {
        if (z->parent == z->parent->parent->left)
        {
            tio = z->parent->parent->right;
            if (tio->color == 1) // RED
            {
                z->parent->color = 0; // BLACK
                tio->color = 0; // BLACK
                z->parent->parent->color = 1; // RED
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    RotateLeft(tree, z);
                }
                z->parent->color = 0; // BLACK
                z->parent->parent->color = 1; // RED
                RotateRight(tree, z->parent->parent);
            }
        }
        else
        {
            tio = z->parent->parent->left;
            if (tio->color == 1) // RED
            {
                z->parent->color = 0; // BLACK
                tio->color = 0; // BLACK
                z->parent->parent->color = 1; // RED
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    RotateRight(tree, z);
                }
                z->parent->color = 0; // BLACK
                z->parent->parent->color = 1; // RED
                RotateLeft(tree, z->parent->parent);
            }
        }
    }
    tree->getRoot()->color = 0; // BLACK
}

template <class T, class S>
void RBTree<T, S>::Delete(RBTree<T, S> *&tree, Nodo<T, S> *z)
{
    Nodo<T, S> *x;
    Nodo<T, S> *y = z;
    bool originalColor = y->color;

    if (z->left == tree->getNullNode())
    {
        x = z->right;
        Transplant(tree, z, z->right);
    }
    else if (z->right == tree->getNullNode())
    {
        x = z->left;
        Transplant(tree, z, z->left);
    }
    else
    {
        y = Minimum(z->right);
        originalColor = y->color;
        x = y->right;
        if (y != z->right)
        {
            Transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        else
        {
            x->parent = y;
        }
        Transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = originalColor;
    }
    if (originalColor == 0) // BLACK
    {
        FixDeletion(tree, x);
    }
}

template <class T, class S>
void RBTree<T, S>::FixDeletion(RBTree<T, S> *&tree, Nodo<T, S> *x)
{
    Nodo<T, S> *w;
    while (x != tree->getRoot() && x->color == 0) // BLACK
    {
        if (x == x->parent->left)
        {
            w = x->parent->right;
            if (w->color == 1) // RED
            {
                w->color = 0; // BLACK
                x->parent->color = 1; // RED
                RotateLeft(tree, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 0 && w->right->color == 0) // BLACK
            {
                w->color = 1; // RED
                x = x->parent;
            }
            else
            {
                if (w->right->color == 0) // BLACK
                {
                    w->left->color = 0; // BLACK
                    w->color = 1;      // RED
                    RotateRight(tree, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 0; // BLACK
                w->right->color = 0; // BLACK
                RotateLeft(tree, x->parent);
                x = tree->getRoot();
            }
        }
        else
        {
            w = x->parent->left;
            if (w->color == 1) // RED
            {
                w->color = 0; // BLACK
                x->parent->color = 1; // RED
                RotateRight(tree, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 0 && w->left->color == 0) // BLACK
            {
                w->color = 1; // RED
                x = x->parent;
            }
            else
            {
                if (w->left->color == 0) // BLACK
                {
                    w->right->color = 0; // BLACK
                    w->color = 1;       // RED
                    RotateLeft(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 0; // BLACK
                w->left->color = 0;  // BLACK
                RotateRight(tree, x->parent);
                x = tree->getRoot();
            }
        }
    }
    x->color = 0; // BLACK
}

template <class T, class S>
Queue<Nodo<T, S>*> RBTree<T, S>::recorridoNiveles() {
    Queue<Nodo<T, S>*> resultado;
    if (root == NULL) {
        return resultado;
    }
    Queue<Nodo<T, S>*> cola;
    cola.Enqueue(root);
    while (!cola.IsEmpty()) {
        Nodo<T, S>* nodo = cola.Front();
        cola.Dequeue();
        resultado.Enqueue(nodo);
        if (nodo->left && nodo->left->dato != T()) {
            cola.Enqueue(nodo->left);
        }
        if (nodo->right && nodo->right->dato != T()) {
            cola.Enqueue(nodo->right);
        }
    }
    return resultado;
}

template <class T, class S>
Queue<Nodo<T, S>*> RBTree<T, S>::inorden() {
    Pila<Nodo<T, S>*> pila;
    Queue<Nodo<T, S>*> info;
    if (root == NULL) {
        return info;
    }
    Nodo<T, S>* temp = root;

    while (temp != NULL || !pila.vacia()) {
        while (temp != NULL) {
            pila.meter(temp);
            temp = temp->left;
        }

        temp = pila.Sacar();
        if (temp->dato != T()) {
            info.Enqueue(temp);
        }
        temp = temp->right;
    }
    return info;
}

template <class T, class S>
Queue<Nodo<T, S>*> RBTree<T, S>::preorden() {
    Pila<Nodo<T, S>*> pila;
    Queue<Nodo<T, S>*> info;
    if (root == NULL) {
        return info;
    }
    Nodo<T, S>* temp = root;

    while (temp != NULL || !pila.vacia()) {
        while (temp != NULL) {
            pila.meter(temp);
            info.Enqueue(temp);
            temp = temp->left;
        }
        temp = pila.Sacar();
        temp = temp->right;
    }
    return info;
}

template <class T, class S>
Queue<Nodo<T, S>*> RBTree<T, S>::posorden() {
    Pila<Nodo<T, S>*> pila;
    Queue<Nodo<T, S>*> info;
    if (root == NULL) {
        return info;
    }
    Nodo<T, S>* temp = root;
    Nodo<T, S>* prev = NULL;
    while (temp != NULL || !pila.vacia()) {
        while (temp != NULL) {
            pila.meter(temp);
            temp = temp->left;
        }
        temp = pila.Cima();
        if (temp->right != NULL && temp->right != prev) {
            temp = temp->right;
        } else {
            temp = pila.Sacar();
            prev = temp;
            info.Enqueue(temp);
            temp = NULL;
        }
    }
    return info;
}

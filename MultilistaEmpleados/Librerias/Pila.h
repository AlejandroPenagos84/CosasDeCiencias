#ifndef PILA_H
#define PILA_H

template <class T> class Pila {
public:
    Pila();
    //~Pila();
    void meter(T v);
    T Sacar();
    T Cima();
    int vacia();

private:
    struct Nodo {
        T clave;
        Nodo *siguiente;
    };
    Nodo *cabeza;
    Nodo *z;
};

template <class T> Pila<T>::Pila() {
    cabeza = new Nodo;
    z = new Nodo;

    cabeza->siguiente = z;
    z->siguiente = z;
}
/*
template <class T> Pila<T>::~Pila() {
    Nodo *t = cabeza;
    while (t != z) {
        cabeza = t;
        t = t->siguiente;
        delete cabeza;
    }
    delete z;
}
*/
template <class T> void Pila<T>::meter(T v) {
    Nodo *t = new Nodo;
    t->clave = v;
    t->siguiente = cabeza->siguiente;
    cabeza->siguiente = t;
}

template <class T> T Pila<T>::Sacar() {
    T x;
    Nodo *t = cabeza->siguiente;
    cabeza->siguiente = t->siguiente;
    x = t->clave;
    delete t;
    return x;
}

template <class T> T Pila<T>::Cima() {
    Nodo *t = cabeza->siguiente;
    return t->clave;
}

template <class T> int Pila<T>::vacia() { return cabeza->siguiente == z; }


#endif //ARBOLBINARIO_PILA_H

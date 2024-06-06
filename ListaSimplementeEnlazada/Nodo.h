#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo
{
public:
    T dat;
    Nodo<T>* sig;

    Nodo(T dato) : dat(dato), sig(nullptr) {}
};


#endif


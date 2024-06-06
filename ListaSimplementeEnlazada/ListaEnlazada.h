#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
#include "Nodo.h"

using namespace std;
template <typename T>
class ListaEnlazada
{
private:
    Nodo<T>* lista;
    Nodo<T>* aux;
    Nodo<T>* aux2;

public:
    ListaEnlazada() : lista(nullptr), aux(nullptr), aux2(nullptr) {}
    ~ListaEnlazada()
    {
        limpiar();
    }

    void inicializa()
    {
        lista = nullptr;
    }

    bool vacia()
    {
        return lista == nullptr ? true : false;
    }

    void agrega(T x)
    {
        if (vacia())
        {
            lista = new Nodo<T>(x);
        }
        else
        {
            aux = new Nodo<T>(x);
            if (aux->dat < lista->dat)
            {
                aux->sig = lista;
                lista = aux;
            }
            else
            {
                aux2 = lista;
                while ((aux2->sig != nullptr) && (aux->dat > aux2->sig->dat))
                {
                    aux2 = aux2->sig;
                }
                aux->sig = aux2->sig;
                aux2->sig = aux;
            }
        }
    }

    bool buscar(T x)
    {
        aux = lista;
        while (aux != nullptr)
        {
            if (aux->dat == x)
                return true;
            aux = aux->sig;
        }
        return false;
    }

    void elimina(T e)
    {
        if (vacia())
        {
            std::cout << "La lista esta vacia, no se pueden eliminar datos" << std::endl;
        }
        else
        {
            if (buscar(e))
            {
                if (lista->sig == nullptr)
                {
                    delete lista;
                    inicializa();
                }
                else
                {
                    aux = lista;
                    if (lista->dat == e)
                    {
                        lista = lista->sig;
                        delete aux;
                    }
                    else
                    {
                        while (aux->sig->dat != e)
                        {
                            aux = aux->sig;
                        }
                        aux2 = aux->sig;
                        aux->sig = aux2->sig;
                        delete aux2;
                    }
                }
                cout << "El dato ha sido eliminado" << endl;
            }
            else
            {
                cout << "Dato no existente. Eliminando el último nodo de la lista." << endl;
                elimina();
            }
        }
    }

    void elimina()
    {
        if (vacia())
        {
            std::cout << "La lista esta vacia, no se pueden eliminar datos" << std::endl;
        }
        else
        {
            if (lista->sig == nullptr)
            {
                delete lista;
                inicializa();
            }
            else
            {
                aux = lista;
                while (aux->sig->sig != nullptr)
                {
                    aux = aux->sig;
                }
                aux2 = aux->sig;
                aux->sig = nullptr;
                delete aux2;
                cout << "El último nodo ha sido eliminado" << endl;
            }
        }
    }

    void imprimir()
    {
        if (vacia())
            cout << "La lista esta vacia, no hay datos a imprimir" << endl;
        else
        {
            cout << "DATOS:" << endl;
            aux = lista;
            while (aux != nullptr)
            {
                cout << aux->dat << endl;
                aux = aux->sig;
            }
        }
    }

    void limpiar()
    {
        if (vacia())
            cout << "La lista esta vacia, no hay nada que limpiar" << endl;
        else
        {
            while (lista != nullptr)
            {
                aux = lista;
                lista = lista->sig;
                delete aux;
            }
        }
        inicializa();
    }
};




#endif

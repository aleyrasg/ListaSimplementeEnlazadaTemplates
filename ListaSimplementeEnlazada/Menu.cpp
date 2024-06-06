#include "Menu.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Menu::mostrarMenu()
{
    int ans, x, e;
    ListaEnlazada<int> lista;
    do
    {
        cout << "						MENU					" << endl
            << "Elija una opcion del menu" << endl
            << "1.-AGREGA(agrega un dato)" << endl
            << "2.-ELIMINA(elimina un dato)" << endl
            << "3.-IMPRIMIR(imprime la lista)" << endl
            << "4.-LIMPIAR(limpia la lista)" << endl
            << "5.-Salir" << endl;
        cout << "Ingrese solo numero por favor" << endl;
        cin >> ans;
        switch (ans)
        {
        case 1:
            system("cls");
            cout << "Ingrese un dato" << endl;
            cin >> x;
            lista.agrega(x);
            system("cls");
            break;

        case 2:
            system("cls");
            cout << "Ingrese un dato a eliminar" << endl;
            cin >> e;
            lista.elimina(e);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            lista.imprimir();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            lista.limpiar();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "Hasta pronto" << endl;
            system("pause");
            break;
        default:
            cout << "Numero invalido, digite otro numero" << endl;
            system("pause");
            system("cls");
            break;
        }
    } while (ans != 5);
}

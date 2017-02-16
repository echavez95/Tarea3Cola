#include <iostream>
#include <stdlib.h>

using namespace std;
class Elemento
{
    public:
        int Value;
        Elemento *NextElement;

    Elemento(int val)
    {
        Value=val;
        NextElement = 0;
    }

    ~Elemento(){}
};

class Cola
{
    public :
		Elemento *Peak;
		Elemento *Tail;

	Cola ()
	{
        Peak=Tail=0;
	}

    bool Vacia()
    {
        if(Peak==0 && Tail==0)
        {
            return true;
        }
        return false;
    }

    void Agregar(int valor)
    {
        Elemento* nodo = new Elemento(valor);
        if(Vacia())
        {
            Peak=Tail=nodo;
        }
        else
            {
                Tail->NextElement = nodo;
                Tail=nodo;
            }
    }

    int Sacar()
    {
        if(Vacia())
        {
            cout<<"Cola Vacia"<<endl;
            return 0;
        }
        else
            {
                Elemento* nodoTemp;
                int valor = Peak->Value;
                nodoTemp = Peak;
                Peak=Peak->NextElement;
                delete nodoTemp;
                return valor;
            }
    }

    void ImprimirCola()
    {
        if(!Vacia())
        {
            Elemento* nodoTemp=Peak;
            do
            {
                cout<<nodoTemp->Value<<endl;
                nodoTemp=nodoTemp->NextElement;
            }while(nodoTemp!=0);
        }
        else
            {
                cout<<"Cola Vacia"<<endl;
            }
    }

    void Anular()
    {
        if(!Vacia())
        {
            Elemento* nodoTemp=Peak;
            Elemento* nodoBorrar;
            do
            {
                nodoBorrar=nodoTemp;
                nodoTemp=nodoTemp->NextElement;
                delete nodoBorrar;
            }while(nodoTemp!=0);
            Peak=Tail=0;
        }else
            {
                cout<<"Cola Vacia"<<endl;
            }
    }

};


int main()
{
    Cola colaEnteros;
    int res;
    int entero;
    int posicion;
    do{
        system("cls");
        cout << "EJEMPLO COLA" << endl;
        cout << "1. Agregar" << endl;
        cout << "2. Sacar" << endl;
        cout << "3. Peak / Tail" << endl;
        cout << "4. Vacia" << endl;
        cout << "5. Ver Cola" << endl;
        cout << "6. Anula" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion" << endl;
        cin>>res;
        system("cls");
        switch(res)
        {
            case 1:
                cout << "Escriba un Numero: " << endl;
                cin>>entero;
                colaEnteros.Agregar(entero);

                break;
            case 2:
                cout << "Enter para sacar de la cola" << endl;
                system("pause");
                cout << colaEnteros.Sacar() <<endl;
                system("pause");
                break;
            case 3:
                if(!colaEnteros.Vacia())
                {
                    cout << "Primero: "<< colaEnteros.Peak->Value<< endl;
                    cout << "Ultimo: "<< colaEnteros.Tail->Value<< endl;
                }
                else
                    {
                        cout << "La cola esta vacia" << endl;
                    }
                system("pause");
                break;
            case 4:
                if(colaEnteros.Vacia())
                {
                    cout << "La cola esta vacia" << endl;
                }
                else
                {
                    cout << "La cola no esta vacia" << endl;
                }
                system("pause");
                break;
            case 5:
                cout << "Ver Cola" << endl;
                colaEnteros.ImprimirCola();
                system("pause");
                break;
            case 6:
                cout << "Cola Eliminada" << endl;
                colaEnteros.Anular();
                system("pause");
                break;
        }
    }while(res!=0);
    return 0;
}

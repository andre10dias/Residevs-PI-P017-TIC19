#include <iostream>
#include <vector>

using namespace std;

class ItemSet
{
    private:
        vector<string> itens;

        int localizar(string _str)
        {
            for (unsigned int i = 0; i < itens.size(); i++) {
                if (itens[i] == _str) {
                    return i;
                }
            }

            return -1;
        }

    public:
        ItemSet() {};

        void inserir(string _str) {
            int indice_str = localizar(_str);

            if (indice_str == -1) {
                itens.push_back(_str);
            }
        }

        void excluir(string _str) {
            int indice_str = localizar(_str);

            if (indice_str != -1) {
                vector<string>::iterator it = itens.begin() + indice_str;

                itens.erase(it);
            }
        }

        void exibir() 
        {
            cout << "---------------------" << endl;

            for (string str: itens) {
                cout << str << " ";
            }

            cout << endl;
        }
};

int main (void)
{
    ItemSet lista_objetos;

    lista_objetos.inserir("Cadeira");
    lista_objetos.inserir("Mesa");
    lista_objetos.inserir("Ventilador");

    lista_objetos.exibir();

    lista_objetos.excluir("Escrivaninha");

    lista_objetos.exibir();

    lista_objetos.inserir("Travesseiro");
    lista_objetos.excluir("Mesa");

    lista_objetos.exibir();
}
#include <iostream>
#include <vector>

using namespace std;

class ItemSet
{
private:
    vector<string> itens;

public:
    ItemSet() {}

    int localizaItem(string item_a_buscar)
    {
        for (int i = 0; i < itens.size(); i++)
        {
            if (itens[i] == item_a_buscar)
            {
                return i;
            }
        }
        return -1;
    }

    bool inserir(string s)
    {
        int consultar_existencia_item = localizaItem(s);

        if (consultar_existencia_item != -1)
        {
            return false;
        }
        else
        {
            itens.push_back(s);
            return true;
        }
    }

    bool excluir(string s)
    {
        int consultar_existencia_item = localizaItem(s);
        if (consultar_existencia_item != -1)
        {
            itens.erase(itens.begin() + consultar_existencia_item);
            return true;
        }
        else
        {
            return false;
        }
    }

    void listar()
    {
        for (const string &item : itens)
        {
            cout << item << endl;
        }
    }
};

int main()
{
    ItemSet A;
    A.inserir("bola");
    A.inserir("carrinho");
    A.inserir("caneta");
    A.inserir("caderno");
  
    
    cout << "Itens na lista:" << endl;
    A.listar();
    return 0;
}

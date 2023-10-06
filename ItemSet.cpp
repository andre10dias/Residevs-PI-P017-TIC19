#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ItemSet
{
    private:
        vector<string> listaItens;
        bool itemCadastrado(string s);

    public:
        ItemSet(/* args */);
        ~ItemSet();
        vector<string> getListaItens();
        void setListaItens(vector<string> _listaItens);
        void inserir(string s);
        void excluir(string s);
};

ItemSet::ItemSet(/* args */)
{
}

ItemSet::~ItemSet()
{
}

vector<string> ItemSet::getListaItens() 
{
    return listaItens;
}

void ItemSet::setListaItens(vector<string> _listaItens)
{
    listaItens = _listaItens;
}

bool ItemSet::itemCadastrado(string _s) {
    for (string s : listaItens)
    {
        if (s == _s)
        {
            return true;
        }
    }

    return false;
}

void ItemSet::inserir(string s)
{
    int tam = listaItens.size();

    if (tam == 0 || !itemCadastrado(s))
    {
        listaItens.push_back(s);
    }
}

void ItemSet::excluir(string s)
{
    int tam = listaItens.size();

    if (tam >= 0 && itemCadastrado(s))
    {
        for (int i = 0; i < tam; i++)
        {
            if (listaItens[i] == s)
            {
                listaItens.erase(listaItens.begin() + i);
                break;
            }
        }
    }
}

int main(void) {
    ItemSet itemSet;

    cout << "\nInserindo itens" << endl;
    itemSet.inserir("item1");
    itemSet.inserir("item2");
    itemSet.inserir("item3");
    itemSet.inserir("item4");
    itemSet.inserir("item5");

    for (string s : itemSet.getListaItens())
    {
        cout << s << "\t";
    }

    cout << "\n\nTentando inserir item4 novamente" << endl;
    itemSet.inserir("item4");

    for (string s : itemSet.getListaItens())
    {
        cout << s << "\t";
    }

    cout << "\n\nExcluindo itens 3 e 5" << endl;
    itemSet.excluir("item5");
    itemSet.excluir("item3");

    for (string s : itemSet.getListaItens())
    {
        cout << s << "\t";
    }
    
    cout << endl << endl;
    return 0;
}
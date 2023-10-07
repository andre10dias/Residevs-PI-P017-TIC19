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
        ItemSet operator+(ItemSet c);
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

ItemSet ItemSet::operator+(ItemSet c) {
    ItemSet a, b;
    bool inserir;
    a.setListaItens(listaItens);

    for (string itemC : c.getListaItens())
    {
        inserir = true;

        for (string itemB : listaItens)
        {
            if (itemC == itemB)
            {
                inserir = false;
                break;
            }
        }

        if (inserir)
        {
            a.inserir(itemC);
        }
    }
    
    return a;
}

int main(void) {
    ItemSet itemA, itemB, itemC;

    vector<string> listaItensB = {"1", "2", "3", "4", "5"};
    vector<string> listaItensC = {"8", "7", "6", "5", "4", "3"};

    itemB.setListaItens(listaItensB);
    itemC.setListaItens(listaItensC);

    //'A' recebe todos os itens de 'B' e os itens de 'C' que não se repetem em 'B'.
    itemA = itemB + itemC;

    cout << "\nB =\t";
    for (string s : itemB.getListaItens())
    {
        cout << s << "\t";
    }

    cout << "\n\nC =\t";
    for (string s : itemC.getListaItens())
    {
        cout << s << "\t";
    }

    cout << "\n\nA = B + c =>\t";
    for (string s : itemA.getListaItens())
    {
        cout << s << "\t";
    }

    cout << endl << endl;
    return 0;
}
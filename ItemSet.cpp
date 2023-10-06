#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ItemSet
{
    private:
        vector<string> listaItens;

    public:
        ItemSet(/* args */);
        ~ItemSet();
        vector<string> getListaItens();
        void setListaItens(vector<string> _listaItens);
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

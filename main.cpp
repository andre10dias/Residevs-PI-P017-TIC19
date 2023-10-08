#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ItemSet
{
private:
    vector<string> itens;
public:
    void inserirS(string _item);
    void excluirS(string _item);
    void listarItens();
    ~ItemSet();
};


void ItemSet::inserirS(string _item)
{
    for(int i = 0; i <itens.size(); i++){
        if (_item == itens[i] ){
            cout << "O produto já existe!";
            return;
        } 
    }

    itens.push_back(_item);
    cout << "Item inserido com sucesso!" << endl;
}

void ItemSet::excluirS(string _item)
{
    bool achou = false;

    for(int i = 0; i < itens.size(); ++i){
        if (itens[i] == _item ){
            itens.erase(itens.begin() + i);
            cout << "Produto encontrado e removido com sucesso!" << endl;
            achou = true;
            break;
        }

    }

if (achou == false)
{
cout << "Produto não encontrado." << endl;
}

}

void ItemSet::listarItens(){
    for (int i = 0; i < itens.size(); ++i)
    cout << itens[i] << endl;
}

ItemSet::~ItemSet()
{
}


int main(){

//TESTE DE FUNÇÕES

    ItemSet itemset;
    string item;
    char escolha;
    bool decisao = true;

    do
    {
    cout << "Insira um item: ";
    cin >> item;
    itemset.inserirS(item);
    itemset.listarItens();
    
        cout << "Deseja inserir outro item? (s/n): ";
        cin >> escolha;
        if(escolha == 's' || escolha == 'S'){
            decisao = true;
        } else {
            decisao = false;
        }
        
    } while (decisao == true);
    
    do
    {
    cout << "Digite o item quer deseja excluir: ";
    cin >> item;
    itemset.excluirS(item);
    itemset.listarItens();

        cout << "Deseja excluir outro item? (s/n): ";
        cin >> escolha;
        if(escolha == 's' || escolha == 'S'){
            decisao = true;
        } else {
            decisao = false;
        }
        
    } while (decisao == true);

    itemset.listarItens();

    return 0;
}

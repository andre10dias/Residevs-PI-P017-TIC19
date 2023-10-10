#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class ItemSet{
    private:
        vector<string> itens;

    public:
        ~ItemSet();
        ItemSet();
        string inserir(string _item);
        string excluir(string _item);
        void imprimir();

};
    ItemSet :: ~ItemSet(){

     };
    ItemSet :: ItemSet(){

    };

    string ItemSet :: inserir(string _item){
        for (const string& str: itens) {
            if(str == _item)
                return "Item :" + _item + " já existe.";
        }

        itens.push_back(_item);

        return "";
    };

    string ItemSet :: excluir(string _item){
        
        for (int i = 0; i < itens.size(); i++) {
            if (itens[i] == _item) {
                itens.erase(itens.begin() + i);
                
                return "";
            }
        }

        return "-1";
    };
    void ItemSet :: imprimir(){
        for (const string& str: itens) {
            cout << "Item: " << str << endl;
        }

    };

    int main(){

        ItemSet conjunto;

        conjunto.inserir("ItemSet 1");
        conjunto.inserir("ItemSet 2");
        conjunto.inserir("ItemSet 3");
        conjunto.inserir("ItemSet 1"); // Tentando inserir um item repetido
        conjunto.imprimir();

        conjunto.excluir("ItemSet 2");
        conjunto.excluir("ItemSet"); // Tentando excluir um item que não existe
        cout << endl << "Depois de excluir" << endl;        
        conjunto.imprimir();
        return 0;
    }
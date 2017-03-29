#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validaEmail(string email){
    int aux = 0;
    for(int i = 0; i < email.size(); i++){
        if(email[i] == '@')
            aux++;
        else if(email[i] == '.' && aux == 1)
            return true;
    }
    return false;
}

bool verificaTelefone(string numero){
    int i = 0;
    while(numero[i] != '\0'){
        if(numero[i] < '0' || numero[i] > '9')
            return false;
        i++;
    }
    return true;
}

bool verificaDuplicidade(vector<string> &telefones, string numero){
    for(auto valor : telefones)
        if(valor == numero)
            return false;
    return true;
}

class Contato{
private:
    string nome;
    string email;
    vector<string> telefones;

public:
    //Inicializa contato a partir do nome
    Contato(string nome){
        this->nome = nome;
    }

    //Muda o nome do contato
    void setNome(string nome){
        this->nome = nome;
    }

    //Retorna o nome
    string getNome(){
        return this->nome;
    }

    //Altera o email
    //Retorne se houve sucesso na alteração
    //Opcional 1:
    //	Valide verificando se o email possui um @ e depois um .
    bool setEmail(string email){
        if(validaEmail(email)){
            this->email = email;
            return true;
        }
        return false;
    }

    //Retorna o email do usuario
    string getEmail(){
        return this->email;
    }

    //Adiciona um novo telefone ao contato
    //Retorne se a operação foi realizada com sucesso.
    //  Opcional 1: Verifique se o telefone é composto apenas por dígitos
    //  Opcional 2: Nao permita adicionar duas vezes o mesmo numero
    bool addTelefone(string numero){
        if(verificaTelefone(numero) && verificaDuplicidade(telefones, numero)){
            telefones.push_back(numero);
            return true;
        }
        return false;
    }

    //Remova o telefone pelo número
    //Informe se houve sucesso
    bool rmTelefone(string numero){

        auto iterador = std::find(telefones.begin(), telefones.end(), numero);
        if(iterador == telefones.end())
            return false;
        telefones.erase(iterador);
        return true;
    }

    //Retorna a qtd de telefones do contato
    int qtdTelefones(){
        return this->telefones.size();

    }

    //Retorna a lista de telefones
    vector<string> getTelefones(){
        return telefones;
    }
};

int main(){

    Contato mateus("Mateus");
    if(mateus.addTelefone("21212121212") == true)
        cout << "Telefone adicionado" << endl;
    if(mateus.addTelefone("21212121211") == true)
        cout << "Telefone adicionado" << endl;
    if(mateus.rmTelefone("21212121211") == true)
        cout << "Telefone removido" << endl;
}


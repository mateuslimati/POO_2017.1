#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "header.h"

using namespace std;

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
        return ((int) this->telefones.size());

    }

    //Retorna a lista de telefones
    vector<string> getTelefones(){
        return telefones;
    }

    bool verificaSubString(string sub){
        if(this->nome.find(sub) != std::string::npos)
            return true;
        else if(this->email.find(sub) != std::string::npos)
            return true;
        else
            for(auto contato: this->telefones)
                if(contato.find(sub) != std::string::npos)
                    return true;
        return false;
    }
};

class Agenda{
private:
    vector<Contato> contatos;

public:
    bool adicionarContato(string nome){
        for(auto contato: this->contatos){
            if(contato.getNome() == nome){
                return false;
            }
        }
        contatos.push_back(Contato(nome));
        return true;
    }

    bool removerContato(string nome){
        int i = 0;
        for(auto contato: this->contatos){
            if(contato.getNome() == nome){
                contatos.erase(contatos.begin() + i);
                return true;
            }
            i++;
        }
        return false;
    }
    Contato* procurarContato(string nome){
        int i = 0;
        for(auto contato: this->contatos){
            if(contato.getNome() == nome)
                return &contatos[i];
            i++;
        }
        return NULL;
    }
    vector<Contato> procurarPorSubstring(string sub){
        vector<Contato> contatosEncontrados;
        for(auto contato: this->contatos){
            if(contato.verificaSubString(sub))
                contatosEncontrados.push_back(contato);
        }
        return contatosEncontrados;
    }
    vector<Contato> getContatos(){
        return this->contatos;
    }
};

#endif // CLASSES_H

#include<iostream>
#include<vector>

using namespace std;

bool validaEmail(string email){

    int aux = 0;
    int pos_arr = 0;
    for(int i = 0; (unsigned)i < email.size(); i++){
        if(email[i] == '@'){
            aux++;
            pos_arr = i;
        }
        else if(email[i] == '.' && aux == 1 && (pos_arr + 1) < i &&
                email[i + 1] != NULL){
                return true;
        }
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

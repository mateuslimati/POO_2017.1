#include <iostream>
#include <vector>
#include "classes.h"

using namespace std;

int main(){

    Agenda agenda;
    agenda.adicionarContato("Mateus Lima");
    agenda.adicionarContato("Matheus");

    Contato *mateus = agenda.procurarContato("Mateus Lima");

    mateus->addTelefone("997253230");
    mateus->addTelefone("986366515");
    mateus->addTelefone("987532905");
    mateus->setEmail("mateuslima.ti@outlook.com.br");

    vector<int> x;

    x.push_back(1);
    x.push_back(2);

    vector<Contato> y = agenda.getContatos();
    cout << y[0].getEmail() << endl;
    vector<string> numMateus = y[0].getTelefones();

    for(auto numero: numMateus)
        cout << numero << endl;

}


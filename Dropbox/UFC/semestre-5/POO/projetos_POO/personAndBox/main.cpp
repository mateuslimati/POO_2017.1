#include <iostream>
#include <vector>
#define left  0
#define rigth 1
int posBox = 2;

using namespace std;

class Cenario{
protected:
    int posicao;
public:
    Cenario(){
        this->posicao = 0;
    }

    int getPosicao(){
        return this->posicao;
    }
};

class Caixa: public Cenario{
private:
    int num;

public:
    Caixa(int num){
        this->num = num;
        this->posicao = posBox;
        posBox += 2;
    }
    void setPosicao(int posicao){
        this->posicao = posicao;
    }
};

vector<Caixa> caixas;

class Pessoa : public Cenario{
private:
    string nome;

public:
    Pessoa(string nome, int posicao){
        this->nome = nome;
        this->posicao = posicao;
    }

    string getNome(){
        return this->nome;
    }

    int verificaPosicao(int posicao){
        for(Caixa c : caixas) {
            if(c.getPosicao() == posicao)
                return 0;
        }
        return 1;
    }

    int empurraCaixa(int posicao, int direcao){
        int tam = caixas.size();
        int i;
        for(i = 0; i < tam; i++) {
            if(caixas[i].getPosicao() == posicao && verificaPosicao(posicao + direcao)){
                caixas[i].setPosicao(posicao + direcao);
                return 1;
            }
        }
        return 0;
    }

    int anda(unsigned int direcao){
        if(direcao < 2){
            if(verificaPosicao(this->posicao + 1) == 1 && direcao == 1)
                (this->posicao)++;
            else if(verificaPosicao(this->posicao - 1) == 1 && direcao == 0)
                (this->posicao)--;
            return 1;
        }
        return 0;
    }

    int empurra(unsigned int direcao){
        if(verificaPosicao(this->posicao + 1) == 0 && direcao < 2){
            if(direcao == 1){
                if(empurraCaixa((this->posicao + 1), 1))
                    (this->posicao)++;
            }
            else{
                if(empurraCaixa((this->posicao + 1), -1))
                    (this->posicao)--;
            }
            return 1;
        }
        return 0;
    }
};

int main()
{
    Pessoa mateus("Mateus", 0);
    Pessoa rodrigo("Digo", 1);

    mateus.anda(rigth);
    cout << mateus.getPosicao() << endl;

    Caixa caixa1(1);
    caixas.push_back(caixa1);

    Caixa caixa2(2);
    caixas.push_back(caixa2);

    mateus.anda(rigth);
    cout << mateus.getPosicao() << endl;

    mateus.anda(left);
    cout << mateus.getPosicao() << endl;

    mateus.anda(rigth);
    cout << rodrigo.getPosicao() << endl;

    mateus.empurra(rigth);
    cout << mateus.getPosicao() << endl;

    mateus.anda(left);
    cout << mateus.getPosicao() << endl;

}


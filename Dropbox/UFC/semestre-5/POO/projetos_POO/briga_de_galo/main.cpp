#include <iostream>

using namespace std;

struct galo{
    string name;
    int hp;
    int force;
    void cacarejar(){
        if(this->hp > 0) cout << this->name  << " - cócóricó!!! " << endl;
        else cout << this->name << " - I'm lose! " << endl;
    }
};

int main()
{
   galo eustacio = {"eustácio", 100, 15};
   eustacio.cacarejar();

}


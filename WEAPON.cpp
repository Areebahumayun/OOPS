#include<iostream>
using namespace std;

class Weapons {
public:
    void weaponsDescription(){
        cout << "Weapons are used for defense or attack." << endl;
    }
};

class HotWeapons : public Weapons {
public:
    void hotWeaponsDescription(){
        cout << "Hot weapons use gunpowder or explosion." << endl;
    }
};

class Bombs : public HotWeapons {
public:
    void bombsDescription(){
        cout << "Bombs explode and cause destruction." << endl;
    }
};

class NuclearBombs : public Bombs {
public:
    void nuclearBombsDescription(){
        cout << "Nuclear bombs use nuclear fission and fusion." << endl;
    }
};

int main(){
    NuclearBombs n;
    n.weaponsDescription();
    n.hotWeaponsDescription();
    n.bombsDescription();
    n.nuclearBombsDescription();


}
#include<iostream>
using namespace std;

class Item {
public:
    string name;
    int quantity;
};

class BakedGoods : public Item {
public:
    float discount = 0.10;
};

class Cakes : public BakedGoods {
public:
    int price = 600;

    float calculate(){
        float total = price * quantity;
        return total - (total * discount);
    }
};

class Bread : public BakedGoods {
public:
    int price = 200;

    float calculate(){
        float total = price * quantity;
        return total - (total * discount);
    }
};

class Drinks : public Item {
public:
    int price = 100;
    float discount = 0.05;

    float calculate(){
        float total = price * quantity;
        return total - (total * discount);
    }
};

int main(){
    Cakes c;
    Bread b;
    Drinks d;

    cout << "Enter quantity of Cakes: ";
    cin >> c.quantity;

    cout << "Enter quantity of Bread: ";
    cin >> b.quantity;

    cout << "Enter quantity of Drinks: ";
    cin >> d.quantity;

    float totalBill = c.calculate() + b.calculate() + d.calculate();

    cout << "Total Bill: " << totalBill << endl;

    return 0;
}
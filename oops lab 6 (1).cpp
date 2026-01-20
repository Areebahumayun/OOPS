#include <iostream>
using namespace std;

int main() {
    char type;
    float amount, balance = 200000, deduction = 0;

    cout << "Enter account type (S for Saving, C for Current): ";
    cin >> type;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    if (amount > 100000) {
        cout << "Cannot withdraw more than 100000." << endl;
        return 0;
    }

    if (type == 'S' || type == 's') {
        deduction = amount * 0.02;
        if (amount > 50000)
            deduction += amount * 0.05;
    }
    else if (type == 'C' || type == 'c') {
        deduction = 100;
        if (amount > 50000)
            deduction += amount * 0.05;
    }
    else {
        cout << "Invalid account type." << endl;
        return 0;
    }

    balance = balance - amount - deduction;

    cout << "Total Deduction: " << deduction << endl;
    cout << "Remaining Balance: " << balance << endl;

    return 0;
}

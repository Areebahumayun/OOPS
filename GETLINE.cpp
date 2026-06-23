#include <iostream>
#include <fstream>
#include <string> // getline aur string ke liye ZAROORI hai
using namespace std;

int main() {
    ifstream fil("story.txt");
    
    if(!fil) {
        cout << "File nahi khuli!";
    }
    else {
        string text_line; // Poori line store karne ke liye string variable

        // KAISE USE KARNA HAI:
        // Yeh loop tab tak chalega jab tak file mein lines baaki hain
        while (getline(fil, text_line)) {
            cout << text_line << endl; // Jo line read hui, usay screen par print kiya
        }
        
        fil.close();
    }
    return 0;
}
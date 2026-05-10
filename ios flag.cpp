#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string newContent;
    
    // Open the file in append mode using ios::app
    // If the file doesn't exist, it will be created
    ofstream outFile("marks.txt", ios::app);

    // Check if the file opened successfully
    if (!outFile) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    cout << "Enter text to append to the file: ";
    getline(cin, newContent);

    // Write the new content followed by a newline
    outFile << newContent << endl;

    // Close the file stream to save changes
    outFile.close();

    cout << "Data appended successfully!" << endl;

    return 0;
}

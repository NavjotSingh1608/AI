#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); 

    cout << "\nProcessing characters with AND and XOR with 127:\n";

    for (char ch : str) {
        int ascii = int(ch);
        cout << "Character: " << ch << " | AND 127: " << (ascii & 127) << " | XOR 127: " << (ascii ^ 127)  << endl;
    }

    return 0;
}

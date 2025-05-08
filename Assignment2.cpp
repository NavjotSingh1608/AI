#include<bits/stdc++.h>
using namespace std;

vector<int> getOrder(string& key) {
    vector<pair<char, int>> keyWithIndex;
    for (int i = 0; i < key.length(); i++)
        keyWithIndex.push_back({key[i], i});

    sort(keyWithIndex.begin(), keyWithIndex.end());

    vector<int> order(key.length());
    for (int i = 0; i < key.length(); i++)
        order[keyWithIndex[i].second] = i;

    return order;
}

string encrypt(string plaintext,  string& key) {
    int col = key.length();
    int row = (plaintext.length() + col - 1) / col;
    vector<vector<char>> matrix(row, vector<char>(col, 'X')); 

    int k = 0;
    for (int i = 0; i < row && k < plaintext.length(); i++) {
        for (int j = 0; j < col && k < plaintext.length(); j++) {
            matrix[i][j] = plaintext[k++];
        }
    }

    vector<int> order = getOrder(key);

    string ciphertext;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            if (order[j] == i) {
                for (int r = 0; r < row; r++) {
                    ciphertext += matrix[r][j];
                }
            }
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext,  string& key) {
    int col = key.length();
    int row = (ciphertext.length() + col - 1) / col;

    vector<vector<char>> matrix(row, vector<char>(col, ' '));
    vector<int> order = getOrder(key);

    int k = 0;
    for (int i = 0; i < col; i++) {
        int colIndex = find(order.begin(), order.end(), i) - order.begin();
        for (int r = 0; r < row; r++) {
            matrix[r][colIndex] = ciphertext[k++];
        }
    }


    string plaintext;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            plaintext += matrix[i][j];

    return plaintext;
}

int main() {
    string key = "ZEBRAS";
    string plaintext = "WEAREDISCOVEREDFLEEATONCE";

    string encrypted = encrypt(plaintext, key);
    cout << "Plaintext:  " << plaintext << endl;
    cout << "Encrypted:  " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted:  " << decrypted << endl;

    return 0;
}

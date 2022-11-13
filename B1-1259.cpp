#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word;

    while (1) {
        cin >> word;
        if (word == "0") {
            break;
        }
        
        string tmp = word;
        reverse(word.begin(), word.end());
        if (tmp == word) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
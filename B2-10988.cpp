#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word, tmp;
    
    cin >> word;
    tmp = word;
    reverse(word.begin(), word.end());
    if (tmp == word) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int alp[26];

    fill_n(alp, 26, -1);
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (alp[str[i] - 'a'] == -1) {
            alp[str[i] - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << alp[i] << ' ';
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
string str;
int mp[26][26];

void Set() {
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (mp[i][j] > mp[i][k] + mp[k][j]) {
                    mp[i][j] = mp[i][k] + mp[k][j];
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) {
                mp[i][j] = 0;
            }
            else {
                mp[i][j] = 9999999;
            }
        }
    }

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, str);

        int pre = str[0] - 'a';
        int nxt = str[str.length() - 1] - 'a';
        mp[pre][nxt] = 1;
    }

    Set();

    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++) {
        getline(cin, str);

        int pre = str[0] - 'a';
        int nxt = str[str.length() - 1] - 'a';

        if (mp[pre][nxt] != 9999999) {
            cout << "T\n";
        }
        else {
            cout << "F\n";
        }
    }

    return 0;
}
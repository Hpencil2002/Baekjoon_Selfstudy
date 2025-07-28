#include <iostream>
#include <string>
using namespace std;

string str;
string origin[1001];

int main() {
    int n;
    int index = 0;

    while (true) {
        cin >> n;
        string dobi = "zzzzzzzzzzzzzzzzzzzzzzzzzzzz";

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> str;
            origin[i] = str;

            for (int j = 0; j < str.size(); j++) {
                str[j] = toupper(str[j]);
            }
            for (int j = 0; j < dobi.size(); j++) {
                dobi[j] = toupper(dobi[j]);
            }

            if (dobi > str) {
                dobi = origin[i];
                index = i;
            }
        }

        cout << origin[index] << '\n';
    }

    return 0;
}
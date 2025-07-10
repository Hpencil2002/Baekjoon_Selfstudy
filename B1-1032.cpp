#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    string str[50];
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    char c;
    for (int i = 0; i < str[0].size(); i++) {
        c = str[0][i];

        for (int j = 0; j < N; j++) {
            if (c != str[j][i]) {
                c = '?';
                break;
            }
        }

        cout << c;
    }

    return 0;
}
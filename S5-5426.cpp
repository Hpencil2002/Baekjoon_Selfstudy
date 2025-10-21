#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    int len;
    char arr[100][100];
    while (T--) {
        string str;
        cin >> str;

        len = sqrt(str.length());
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                arr[i][j] = str[len * i + j];
            }
        }

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << arr[j][len - i - 1];
            }
        }

        cout << "\n";
    }

    return 0;
}
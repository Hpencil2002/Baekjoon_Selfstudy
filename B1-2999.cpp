#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string mes;
    cin >> mes;

    int R = 0, C = 0;
    for (int i = 1; i <= mes.length(); i++) {
        if (mes.length() % i == 0 && mes.length() / i >= i) {
            if (mes.length() / i > R) {
                R = i;
                C = mes.length() / i;
            }
        }
    }

    int t = 0;
    char arr[50][50];
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            arr[j][i] = mes[t++];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j];
        }
    }

    return 0;
}
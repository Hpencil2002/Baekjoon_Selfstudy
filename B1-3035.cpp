#include <iostream>
#include <string>
using namespace std;

char arr[51][51];
string str[51];

int main() {
    int R, C, ZR, ZC;
    cin >> R >> C >> ZR >> ZC;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int t = 0; t < ZC; t++) {
                str[i] += arr[i][j];
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < ZR; j++) {
            cout << str[i] << "\n";
        }
    }

    return 0;
}
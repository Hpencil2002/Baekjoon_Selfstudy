#include <iostream>
using namespace std;

int num[5];

void solve() {
    if (num[0] > num[1]) {
        int tmp = num[0];
        num[0] = num[1];
        num[1] = tmp;

        for (int i = 0; i < 5; i++) {
            cout << num[i] << ' ';
        }
        cout << "\n";
    }
    if (num[1] > num[2]) {
        int tmp = num[1];
        num[1] = num[2];
        num[2] = tmp;

        for (int i = 0; i < 5; i++) {
            cout << num[i] << ' ';
        }
        cout << "\n";
    }
    if (num[2] > num[3]) {
        int tmp = num[2];
        num[2] = num[3];
        num[3] = tmp;

        for (int i = 0; i < 5; i++) {
            cout << num[i] << ' ';
        }
        cout << "\n";
    }
    if (num[3] > num[4]) {
        int tmp = num[3];
        num[3] = num[4];
        num[4] = tmp;

        for (int i = 0; i < 5; i++) {
            cout << num[i] << ' ';
        }
        cout << "\n";
    }

    if (num[0] != 1 || num[1] != 2 || num[2] != 3 || num[3] != 4 || num[4] != 5) {
        solve();
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> num[i];
    }

    solve();

    return 0;
}
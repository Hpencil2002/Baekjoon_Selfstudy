#include <iostream>
using namespace std;

char mp[500][500];

void draw(int depth, int index) {
    if (depth == 1) {
        mp[index][index] = '*';
        mp[index + 1][index] = '*';
        mp[index + 2][index] = '*';

        return;
    }

    int len = 4 * (depth - 1) + 1;

    for (int i = index; i < len + index; i++) {
        mp[index][i] = '*';
        mp[index + len + 1][i] = '*';
    }
    for (int i = index; i < len + index + 2; i++) {
        mp[i][index] = '*';
        mp[i][index + len - 1] = '*';
    }

    mp[index + 1][index + len - 1] = ' ';
    mp[index + 2][index + len - 2] = '*';

    draw(depth - 1, index + 2);

    return;
}

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << "*\n";

        return 0;
    }

    int len = 4 * (N - 1) + 1;

    for (int i = 0; i < len + 2; i++) {
        for (int j = 0; j < len; j++) {
            mp[i][j] = ' ';
        }
    }

    draw(N, 0);

    for (int i = 0; i < len + 2; i++) {
        if (i == 1) {
            cout << "*\n";

            continue;
        }

        for (int j = 0; j < len; j++) {
            cout << mp[i][j];
        }
        cout << "\n";
    }

    return 0;
}
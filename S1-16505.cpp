#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
char arr[1024][1024];

void solve(int y, int x, int size) {
    int st = x + size / 2 - 1;

    for (int i = y + 1; i < y + size / 2; i++) {
        for (int j = st; j < x + size / 2; j++) {
            arr[i][j] = ' ';
        }

        st -= 1;
    }

    if (size == 4) {
        return;
    }

    solve(y, x, size / 2);
    solve(y, x + size / 2, size / 2);
    solve(y + size / 2, x, size / 2);

    return;
}

int main() {
    cin >> N;
    if (N == 0) {
        cout << '*';

        return 0;
    }
    else if (N == 1) {
        cout << "**\n";
        cout << '*';

        return 0;
    }

    N = pow(2, N);

    int en = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < en; j++) {
            arr[i][j] = '*';
        }

        en -= 1;
    }

    solve(0, 0, N);

    en = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < en; j++) {
            cout << arr[i][j];
        }
        cout << "\n";

        en -= 1;
    }

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int N;
int zero;
int m_one;
int one;
int mp[2200][2200];

void solve(int x, int y, int size) {
    bool same = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (mp[i][j] != mp[y][x]) {
                same = false;
                break;
            }
        }

        if (!same) {
            break;
        }
    }

    if (!same) {
        solve(x, y, size / 3);
        solve(x + size / 3, y, size / 3);
        solve(x + size / 3 + size / 3, y, size / 3);
        solve(x, y + size / 3, size / 3);
        solve(x, y + size / 3 + size / 3, size / 3);
        solve(x + size / 3, y + size / 3, size / 3);
        solve(x + size / 3 + size / 3, y + size / 3 + size / 3, size / 3);
        solve(x + size /3, y + size / 3 + size / 3, size / 3);
        solve(x + size / 3 + size / 3, y + size / 3, size / 3);
    }
    else {
        if (mp[y][x] == 1) {
            one += 1;
        }
        else if (mp[y][x] == -1) {
            m_one += 1;
        }
        else {
            zero += 1;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }

    solve(0, 0, N);

    cout << m_one << "\n";
    cout << zero << "\n";
    cout << one << "\n";

    return 0;
}
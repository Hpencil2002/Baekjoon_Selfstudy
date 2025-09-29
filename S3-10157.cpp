#include <iostream>
using namespace std;

int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { 1, 0, -1, 0 };
bool check[1001][1001];

int main() {
    int C, R, K;
    cin >> R >> C >> K;

    if (C * R < K) {
        cout << 0;
    }
    else if (K == 1) {
        cout << 1 << ' ' << 1;
    }
    else {
        int x = 1, y = 1;
        int d = 0;
        int num = 1;

        check[x][y] = true;
        while (true) {
            int dx = x + x_move[d];
            int dy = y + y_move[d];

            if (dx > R || dx <= 0 || dy > C || dy <= 0 || check[dx][dy]) {
                d = (d + 1) % 4;
            }

            x += x_move[d];
            y += y_move[d];
            check[x][y] = true;
            num += 1;

            if (num == K) {
                break;
            }
        }

        cout << x << ' ' << y;
    }

    return 0;
}
#include <iostream>
using namespace std;

int R, C;
char mp[13][13];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, 1, -1 };
int minY = 987654321;
int maxY = 0;
int minX = 987654321;
int maxX = 0;

bool check(int y, int x) {
    if (y < 0 || y >= R || x < 0 || x >= C) {
        return false;
    }

    return true;
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mp[i][j];
        }
    }

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (mp[y][x] == 'X') {
                int cnt = 0;

                for (int d = 0; d < 4; d++) {
                    int x_next = x + x_move[d];
                    int y_next = y + y_move[d];

                    if (!check(y_next, x_next)) {
                        cnt += 1;
                        continue;
                    }
                    if (mp[y_next][x_next] == '.') {
                        cnt += 1;
                    }
                }

                if (cnt >= 3) {
                    mp[y][x] = 'a';
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mp[i][j] == 'a') {
                mp[i][j] = '.';
            }

            if (mp[i][j] == 'X') {
                if (i <= minY) {
                    minY = i;
                }
                if (j <= minX) {
                    minX = j;
                }
                if (i >= maxY) {
                    maxY = i;
                }
                if (j >= maxX) {
                    maxX = j;
                }
            }
        }
    }

    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {
            cout << mp[i][j];
        }

        cout << "\n";
    }

    return 0;
}
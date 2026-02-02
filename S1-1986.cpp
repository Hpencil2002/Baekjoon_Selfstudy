#include <iostream>
using namespace std;

int n, m;
int queen, knight, pawn;
int ans;
int arr[1001][1001];
bool check[1001][1001];
int qx_move[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int qy_move[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int kx_move[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int ky_move[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void make_state(int x, int y, char c) {
    if (c == 'Q') {
        for (int d = 0; d < 8; d++) {
            int x_next = x + qx_move[d];
            int y_next = y + qy_move[d];

            while (true) {
                if (x_next < 1 || x_next > n || y_next < 1 || y_next > m) {
                    break;
                }
                if (arr[x_next][y_next] != 0) {
                    break;
                }

                check[x_next][y_next] = true;
                x_next += qx_move[d];
                y_next += qy_move[d];
            }
        }
    }
    else if (c == 'K') {
        for (int d = 0; d < 8; d++) {
            int x_next = x + kx_move[d];
            int y_next = y + ky_move[d];

            if (x_next >= 1 && x_next <= n && y_next >= 1 && y_next <= m) {
                if (arr[x_next][y_next] == 0) {
                    check[x_next][y_next] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    cin >> queen;
    for (int i = 0; i < queen; i++) {
        int x, y;
        cin >> x >> y;

        arr[x][y] = 1;
    }

    cin >> knight;
    for (int i = 0; i < knight; i++) {
        int x, y;
        cin >> x >> y;

        arr[x][y] = 2;
    }

    cin >> pawn;
    for (int i = 0; i < pawn; i++) {
        int x, y;
        cin >> x >> y;

        arr[x][y] = 3;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0) {
                continue;
            }

            if (arr[i][j] == 1) {
                check[i][j] = true;
                make_state(i, j, 'Q');
            }
            else if (arr[i][j] == 2) {
                check[i][j] = true;
                make_state(i, j, 'K');
            }
            else if (arr[i][j] == 3) {
                check[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0 && !check[i][j]) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}
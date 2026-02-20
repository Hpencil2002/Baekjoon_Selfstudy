#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int R, C;
int ans = -1;
int arr[50][50];
int visit[50][50];
queue<pair<int, int>> qu;
int x_move[4] = { 0, 0, 1, - 1};
int y_move[4] = { 1, -1, 0, 0 };

void bfs() {
    while (!qu.empty()) {
        int x = qu.front().second;
        int y = qu.front().first;
        qu.pop();

        for (int d = 0; d < 4; d++) {
            int x_next = x + x_move[d];
            int y_next = y + y_move[d];

            if (x_next < 0 || x_next >= C || y_next < 0 || y_next >= R) {
                continue;
            }
            if (arr[y_next][x_next] == 0 || visit[y_next][x_next]) {
                continue;
            }

            visit[y_next][x_next] = visit[y][x] + 1;
            ans = max(ans, visit[y_next][x_next]);
            qu.push({ y_next, x_next });
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < C; j++) {
            if (str[j] == 'W') {
                arr[i][j] = 0;
            }
            else {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 1) {
                visit[i][j] = 1;
                qu.push({ i, j });
                bfs();

                for (int k = 0; k < R; k++) {
                    for (int l = 0; l < C; l++) {
                        visit[k][l] = 0;
                    }
                }
            }
        }
    }

    cout << ans - 1;

    return 0;
}
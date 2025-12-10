#include <iostream>
#include <queue>
using namespace std;

int R, C;
int all_lamb, all_wolf;
char arr[251][251];
bool visit[251][251];
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
    int lamb = 0, wolf = 0;
    queue<pair<int, int>> qu;
    qu.push({ x, y });
    visit[x][y] = true;

    while (!qu.empty()) {
        int x_cur = qu.front().first;
        int y_cur = qu.front().second;
        qu.pop();

        if (arr[x_cur][y_cur] == 'v') {
            wolf += 1;
        }
        if (arr[x_cur][y_cur] == 'o') {
            lamb += 1;
        }

        for (int d = 0; d < 4; d++) {
            int x_next = x_cur + x_move[d];
            int y_next = y_cur + y_move[d];

            if (x_next >= 0 && x_next < R && y_next >= 0 && y_next < C) {
                if (arr[x_next][y_next] != '#' && !visit[x_next][y_next]) {
                    visit[x_next][y_next] = true;
                    qu.push({ x_next, y_next });
                }
            }
        }
    }

    if (lamb > wolf) {
        all_lamb += lamb;
    }
    else {
        all_wolf += wolf;
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visit[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << all_lamb << ' ' << all_wolf;

    return 0;
}
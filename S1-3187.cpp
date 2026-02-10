#include <iostream>
#include <queue>
using namespace std;

int R, C;
int ansK, ansV;
char arr[251][251];
bool visit[251][251];
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
    int sheep = 0;
    int wolf = 0;
    queue<pair<int, int>> qu;
    qu.push({ x, y });
    visit[x][y] = true;

    if (arr[x][y] == 'k') {
        sheep += 1;
    }
    if (arr[x][y] == 'v') {
        wolf += 1;
    }

    while (!qu.empty()) {
        int x_cur = qu.front().first;
        int y_cur = qu.front().second;
        qu.pop();

        for (int d = 0; d < 4; d++) {
            int x_next = x_cur + x_move[d];
            int y_next = y_cur + y_move[d];

            if (x_next >= 0 && x_next < R && y_next >= 0 && y_next < C) {
                if (!visit[x_next][y_next]) {
                    if (arr[x_next][y_next] == '.') {
                        visit[x_next][y_next] = true;
                        qu.push({ x_next, y_next });
                    }
                    else if (arr[x_next][y_next] == 'v') {
                        visit[x_next][y_next] = true;
                        qu.push({ x_next, y_next });

                        wolf += 1;
                    }
                    else if (arr[x_next][y_next] == 'k') {
                        visit[x_next][y_next] = true;
                        qu.push({ x_next, y_next });

                        sheep += 1;
                    }
                }
            }
        }
    }

    if (sheep > wolf) {
        ansK += sheep;
    }
    else {
        ansV += wolf;
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
            if (arr[i][j] == '#') {
                continue;
            }

            if (!visit[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << ansK << ' ' << ansV;

    return 0;
}
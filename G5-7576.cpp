#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001

int N, M;
int ans = 0;
int tomato[MAX][MAX];
int x_move[4] = {0, 0, 1, -1};
int y_move[4] = {1, -1, 0, 0};
queue<pair<int, int>> qu;

void bfs() {
    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;

        qu.pop();
        for (int i = 0; i < 4; i++) {
            int x_next = x + x_move[i];
            int y_next = y + y_move[i];

            if (y_next >= 0 && x_next >= 0 && x_next < N && y_next < M && tomato[x_next][y_next] == 0) {
                tomato[x_next][y_next] = tomato[x][y] + 1;
                qu.push({x_next, y_next});
            }
        }
    }
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];

            if (tomato[i][j] == 1) {
                qu.push({i, j});
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) {
                cout << -1;
                return 0;
            }
            else {
                ans = max(tomato[i][j], ans);
            }
        }
    }

    cout << ans - 1;

    return 0;
}
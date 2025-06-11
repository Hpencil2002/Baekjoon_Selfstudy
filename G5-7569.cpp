#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 101

int M, N, H;
int ans = 0;
int tomato[MAX][MAX][MAX];
int x_move[6] = {0, 0, 1, -1, 0, 0};
int y_move[6] = {1, -1, 0, 0, 0, 0};
int z_move[6] = {0, 0, 0, 0, 1, -1};
queue<pair<pair<int, int>, int>> qu;

void bfs() {
    while (!qu.empty()) {
        int x = qu.front().first.first;
        int y = qu.front().first.second;
        int z = qu.front().second;

        qu.pop();
        for (int i = 0; i < 6; i++) {
            int x_next = x + x_move[i];
            int y_next = y + y_move[i];
            int z_next = z + z_move[i];

            if (x_next >= 0 && y_next >= 0 && z_next >= 0 && x_next < N && y_next < M && z_next < H && tomato[x_next][y_next][z_next] == 0) {
                tomato[x_next][y_next][z_next] = tomato[x][y][z] + 1;
                qu.push({{x_next, y_next}, z_next});
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> tomato[i][j][k];

                if (tomato[i][j][k] == 1) {
                    qu.push({{i, j}, k});
                }
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < H; k++) {
                if (tomato[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                else {
                    ans = max(tomato[i][j][k], ans);
                }
            }
        }
    }

    cout << ans - 1;

    return 0;
}
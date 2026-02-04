#include <iostream>
#include <queue>
using namespace std;

int N, M;
int X, Y;
int ans[501][501];
bool visit[501][501];
queue<pair<int, int>> qu;
int x_move[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int y_move[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

void bfs(int y, int x) {
    ans[y][x] = 0;
    visit[y][x] = true;
    qu.push({ y, x });

    while (!qu.empty()) {
        int x_cur = qu.front().second;
        int y_cur = qu.front().first;
        qu.pop();

        for (int d = 0; d < 8; d++) {
            int x_next = x_cur + x_move[d];
            int y_next = y_cur + y_move[d];

            if (x_next <= 0 || x_next > N || y_next <= 0 || y_next > N) {
                continue;
            }
            if (visit[y_next][x_next]) {
                continue;
            }

            visit[y_next][x_next] = true;
            ans[y_next][x_next] = ans[y_cur][x_cur] + 1;
            qu.push({ y_next, x_next });
        }
    }
}

int main() {
    cin >> N >> M >> X >> Y;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        bfs(X, Y);

        cout << ans[a][b] << ' ';
    }

    return 0;
}
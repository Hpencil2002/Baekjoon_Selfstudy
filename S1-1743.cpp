#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K, r, c;
int ans;
int arr[101][101];
bool visit[101][101];
int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { 1, 0, -1, 0 };

int bfs(int n, int m) {
    queue<pair<int, int>> qu;
    int res = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 1 && !visit[i][j]) {
                cnt = 0;
                qu.push({ i, j });
                visit[i][j] = true;

                while (!qu.empty()) {
                    int x = qu.front().first;
                    int y = qu.front().second;
                    qu.pop();

                    cnt += 1;
                    for (int d = 0; d < 4; d++) {
                        int x_next = x + x_move[d];
                        int y_next = y + y_move[d];

                        if (x_next < 1 || x_next > n || y_next < 1 || y_next > m) {
                            continue;
                        }
                        if (arr[x_next][y_next] == 0 || visit[x_next][y_next]) {
                            continue;
                        }

                        qu.push({ x_next, y_next });
                        visit[x_next][y_next] = true;
                    }
                }

                res = max(cnt, res);
            }
        }
    }

    return res;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        arr[r][c] = 1;
    }

    ans = bfs(N, M);

    cout << ans;

    return 0;
}
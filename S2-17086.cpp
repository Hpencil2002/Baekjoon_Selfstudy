#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
int ans = -1;
int arr[50][50];
int x_move[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int y_move[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int bfs(int x, int y) {
    bool visit[50][50] = { false, };
    queue<tuple<int, int, int>> qu;

    qu.push({ x, y, 0 });
    visit[y][x] = true;

    while (!qu.empty()) {
        int oriX = get<0>(qu.front());
        int oriY = get<1>(qu.front());
        int dist = get<2>(qu.front());
        qu.pop();

        if (arr[oriY][oriX] == 1) {
            return dist;
        }

        for (int i = 0; i < 8; i++) {
            int x_next = oriX + x_move[i];
            int y_next = oriY + y_move[i];

            if (x_next < 0 || x_next >= M) {
                continue;
            }
            if (y_next < 0 || y_next >= N) {
                continue;
            }
            if (visit[y_next][x_next]) {
                continue;
            }

            visit[y_next][x_next] = true;
            qu.push({ x_next, y_next, dist + 1 });
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (arr[y][x] != 1) {
                ans = max(ans, bfs(x, y));
            }
        }
    }

    cout << ans;

    return 0;
}
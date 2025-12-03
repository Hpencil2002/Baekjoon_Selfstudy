#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, K;
int arr[100][100];
int x_move[4] = { 1, 0, -1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> qu;

int bfs() {
    int cnt = 0;

    while (!qu.empty()) {
        int x = qu.front().second;
        int y = qu.front().first;
        qu.pop();

        for (int d = 0; d < 4; d++) {
            int x_next = x + x_move[d];
            int y_next = y + y_move[d];

            if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= M) {
                continue;
            }

            if (!arr[y_next][x_next]) {
                cnt += 1;
                arr[y_next][x_next] = 1;
                qu.push({ y_next, x_next });
            }
        }
    }

    return cnt;
}

int main() {
    int x1, x2, y1, y2;
    int cnt = 0;
    int area[100];

    cin >> M >> N >> K;
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!arr[i][j]) {
                qu.push({ i, j });
                area[cnt++] = bfs();

                if (!area[cnt - 1]) {
                    area[cnt - 1] = 1;
                }
            }
        }
    }

    sort(area, area + cnt);

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << area[i] << ' ';
    }

    return 0;
}
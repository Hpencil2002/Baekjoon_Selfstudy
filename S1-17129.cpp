#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
char arr[3001][3001];
int dist[3001][3001];
int ans;
int x_start, y_start;
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };

int bfs() {
    dist[x_start][y_start] = 0;
    queue<pair<int, int>> qu;
    qu.push({ x_start, y_start });

    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        if (arr[x][y] > '2') {
            return dist[x][y];
        }

        for (int d = 0; d < 4; d++) {
            int x_next = x + x_move[d];
            int y_next = y + y_move[d];

            if (x_next < 0 || x_next >= n || y_next < 0 || y_next >= m) {
                continue;
            }
            if (arr[x_next][y_next] == '1' || dist[x_next][y_next] >= 0) {
                continue;
            }

            dist[x_next][y_next] = dist[x][y] + 1;
            qu.push({ x_next, y_next });
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '2') {
                x_start = i;
                y_start = j;
            }
        }
    }

    memset(dist, -1, sizeof(dist));

    ans = bfs();

    if (ans == -1) {
        cout << "NIE";
    }
    else {
        cout << "TAK\n" << ans;
    }

    return 0;
}
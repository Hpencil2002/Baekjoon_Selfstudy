#include <iostream>
#include <queue>
using namespace std;

int L;
int x_start, y_start, x_end, y_end;
int arr[301][301];
bool visit[301][301];
int x_move[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int y_move[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
queue<pair<int, int>> qu;

void reset() {
    while (!qu.empty()) {
        qu.pop();
    }

    for (int i = 0; i < 301; i++) {
        for (int j = 0; j < 301; j++) {
            visit[i][j] = false;
            arr[i][j] = 0;
        }
    }
}

void bfs(int x, int y) {
    qu.push({ x, y });
    visit[x][y] = true;

    while (!qu.empty()) {
        int x_cur = qu.front().first;
        int y_cur = qu.front().second;
        qu.pop();

        if (x_cur == x_end && y_cur == y_end) {
            cout << arr[x_cur][y_cur] << "\n";

            while (!qu.empty()) {
                qu.pop();
            }

            break;
        }

        for (int d = 0; d < 8; d++) {
            int x_next = x_cur + x_move[d];
            int y_next = y_cur + y_move[d];

            if (x_next >= 0 && x_next < L && y_next >= 0 && y_next < L && !visit[x_next][y_next]) {
                qu.push({ x_next, y_next });
                visit[x_next][y_next] = true;
                arr[x_next][y_next] = arr[x_cur][y_cur] + 1;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> L >> x_start >> y_start >> x_end >> y_end;

        bfs(x_start, y_start);

        reset();
    }

    return 0;
}
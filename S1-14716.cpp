#include <iostream>
#include <queue>
using namespace std;

int M, N;
int ans;
int arr[251][251];
bool visit[251][251];
int x_move[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int y_move[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };

void bfs(int x, int y) {
    ans += 1;

    queue<pair<int, int>> qu;
    qu.push({ x, y });
    visit[x][y] = true;

    while (!qu.empty()) {
        int x_cur = qu.front().first;
        int y_cur = qu.front().second;
        qu.pop();

        for (int d = 0; d < 8; d++) {
            int x_next = x_cur + x_move[d];
            int y_next = y_cur + y_move[d];

            if (x_next >= 0 && x_next < M && y_next >= 0 && y_next < N) {
                if (arr[x_next][y_next] == 1 && !visit[x_next][y_next]) {
                    visit[x_next][y_next] = true;
                    qu.push({ x_next, y_next });
                }
            }
        }
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1 && !visit[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, T;
int ans;
int arr[3002][3002];
int visit[3002][3002];
queue<pair<int, int>> qu;
int x_move[4] = { 1, 0, -1, 0 };
int y_move[4] = { 0, 1, 0, -1 };

int main() {
    cin >> N >> M;
    M *= 3;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> T;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j += 3) {
            int avg = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2]) / 3;

            if (avg >= T) {
                arr[i][j] = 255;
                arr[i][j + 1] = 255;
                arr[i][j + 2] = 255;
            }
            else {
                arr[i][j] = 0;
                arr[i][j + 1] = 0;
                arr[i][j + 2] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 || visit[i][j] > 0) {
                continue;
            }

            visit[i][j] = 1;
            qu.push({ i, j });
            ans += 1;

            while (!qu.empty()) {
                pair<int, int> cur = qu.front();
                qu.pop();

                for (int d = 0; d < 4; d++) {
                    int x_next = cur.first + x_move[d];
                    int y_next = cur.second + y_move[d];

                    if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= M) {
                        continue;
                    }
                    if (visit[x_next][y_next] > 0 || arr[x_next][y_next] == 0) {
                        continue;
                    }

                    visit[x_next][y_next] = 1;
                    qu.push({ x_next, y_next });
                }
            }
        }
    }

    cout << ans;

    return 0;
}
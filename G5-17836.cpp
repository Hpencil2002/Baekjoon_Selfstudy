#include <iostream>
#include <queue>
using namespace std;

int N, M, T;
int arr[101][101];
int visit[101][101][2];
int x_move[4] = { 1, 0, -1, 0 };
int y_move[4] = { 0, 1, 0, -1 };

int main() {
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<pair<int, int>, int>> qu;
    qu.push({ { 0, 0 }, 0 });
    visit[0][0][0] = 0;

    while (!qu.empty()) {
        auto cur = qu.front();
        qu.pop();

        if (visit[cur.first.first][cur.first.second][cur.second] > T) {
            continue;
        }

        if (cur.first.first == N - 1 && cur.first.second == M - 1) {
            cout << visit[N - 1][M - 1][cur.second];

            return 0;
        }

        if (arr[cur.first.first][cur.first.second] == 2) {
            cur.second = 1;
        }

        for (int d = 0; d < 4; d++) {
            int x_next = cur.first.first + x_move[d];
            int y_next = cur.first.second + y_move[d];

            if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= M) {
                continue;
            }

            if (cur.second == 1) {
                if (visit[x_next][y_next][1] > 0) {
                    continue;
                }

                qu.push({ { x_next, y_next }, 1 });

                if (visit[cur.first.first][cur.first.second][1] == 0) {
                    visit[x_next][y_next][1] = visit[cur.first.first][cur.first.second][0] + 1;
                }
                else {
                    visit[x_next][y_next][1] = visit[cur.first.first][cur.first.second][1] + 1;
                }
            }
            else {
                if (arr[x_next][y_next] == 1) {
                    continue;
                }
                if (visit[x_next][y_next][0] > 0) {
                    continue;
                }

                qu.push({ { x_next, y_next }, 0 });
                visit[x_next][y_next][0] = visit[cur.first.first][cur.first.second][0] + 1;
            }
        }
    }

    cout << "Fail";

    return 0;
}
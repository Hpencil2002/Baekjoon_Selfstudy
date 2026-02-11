#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[300][300];
bool visit[300][300];
int x_move[2] = { 0, 1 };
int y_move[2] = { 1, 0 };

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<pair<int, int>, int>> qu;
    qu.push({ { 0, 0 }, 0 });
    visit[0][0] = true;

    while (!qu.empty()) {
        int x = qu.front().first.first;
        int y = qu.front().first.second;
        int cnt = qu.front().second;
        qu.pop();

        if (x == N - 1 && y == M - 1) {
            cout << cnt;

            return 0;
        }

        for (int d = 0; d < 2; d++) {
            for (int i = 1; i <= arr[x][y]; i++) {
                int x_next = x + x_move[d] * i;
                int y_next = y + y_move[d] * i;

                if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < M) {
                    if (!visit[x_next][y_next]) {
                        visit[x_next][y_next] = true;
                        qu.push({ { x_next, y_next}, cnt + 1 });
                    }
                }
            }
        }
    }
}
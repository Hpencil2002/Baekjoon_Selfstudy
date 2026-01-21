#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int arr[301][301];
bool visit[301][301];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> qu;
    qu.push({ 0, 0 });
    visit[0][0] = true;

    while (!qu.empty()) {
        int x = qu.front().second;
        int y = qu.front().first;
        qu.pop();

        for (int curY = 1; curY >= 0; curY--) {
            int curX = 1 - curY;

            int x_next = x + curX;
            int y_next = y + curY;

            if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= M) {
                continue;
            }
            if (arr[y_next][x_next] == 0 || visit[y_next][x_next]) {
                continue;
            }

            qu.push({ y_next, x_next });
            visit[y_next][x_next] = true;
        }
    }

    cout << (visit[M - 1][N - 1] ? "Yes" : "No");

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int N;
int r1, c1, r2, c2;
bool visit[201][201];
int x_move[6] = { -2, -2, 0, 0, 2, 2 };
int y_move[6] = { -1, 1, -2, 2, -1, 1 };

void bfs(int a, int b) {
    queue<pair<pair<int, int>, int>> qu;
    qu.push({ { a, b }, 0 });
    visit[a][b] = true;

    while (!qu.empty()) {
        int x = qu.front().first.first;
        int y = qu.front().first.second;
        int cnt = qu.front().second;
        qu.pop();

        if (x == r2 && y == c2) {
            cout << cnt;

            return;
        }

        for (int d = 0; d < 6; d++) {
            int x_next = x + x_move[d];
            int y_next = y + y_move[d];

            if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < N) {
                if (!visit[x_next][y_next]) {
                    visit[x_next][y_next] = true;
                    qu.push({ { x_next, y_next }, cnt + 1 });
                }
            }
        }
    }

    cout << -1;
}

int main() {
    cin >> N >> r1 >> c1 >> r2 >> c2;

    bfs(r1, c1);

    return 0;
}
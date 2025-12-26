#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[65][65];
bool visit[65][65];
pair<int, int> mv[2] = { { 1, 0 }, { 0, 1 } };

bool bfs(int x, int y) {
    queue<pair<int, int>> qu;
    visit[x][y] = true;
    qu.push({ x, y });

    while (!qu.empty()) {
        int x_cur = qu.front().first;
        int y_cur = qu.front().second;
        qu.pop();

        if (arr[x_cur][y_cur] == -1) {
            return true;
        }

        for (int d = 0; d < 2; d++) {
            int x_next = x_cur + mv[d].first * arr[x_cur][y_cur];
            int y_next = y_cur + mv[d].second * arr[x_cur][y_cur];

            if (x_next >= 1 && x_next <= N && y_next >= 1 && y_next <= N) {
                if (visit[x_next][y_next]) {
                    continue;
                }

                visit[x_next][y_next] = true;
                qu.push({ x_next, y_next });
            }
        }
    }

    return false;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    if (bfs(1, 1)) {
        cout << "HaruHaru";
    }
    else {
        cout << "Hing";
    }

    return 0;
}
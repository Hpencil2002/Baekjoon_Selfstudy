#include <iostream>
#include <queue>
using namespace std;

int map[102] = {0, };
bool visited[102] = {false, };

void bfs(int x, int c) {
    queue<pair<int, int>> qu;
    qu.push({x, c});

    while (!qu.empty()) {
        int now = qu.front().first;
        int cnt = qu.front().second;
        qu.pop();

        for (int i = 1; i <= 6; i++) {
            int next = now + i;
            if (next == 100) {
                cout << cnt + 1;
                return;
            }
            else if (next < 100) {
                while (map[next] != 0) {
                    next = map[next];
                }
                if (!visited[next]) {
                    qu.push({next, cnt + 1});
                    visited[next] = true;
                }
            }
        }
    }
}

int main() {
    int N, M, x, y, u, v;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        map[x] = y;
    }
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        map[u] = v;
    }

    bfs(1, 0);

    return 0;
}
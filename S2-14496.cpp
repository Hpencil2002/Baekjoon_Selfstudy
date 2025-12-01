#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int a, b, N, M;
int ans = INT32_MAX;
vector<int> vc[1001];
bool visit[1001];

void bfs(int start, int dep) {
    queue<pair<int, int>> qu;

    qu.push({ start, dep });
    visit[start] = true;

    while (!qu.empty()) {
        int from = qu.front().first;
        int to = qu.front().second;
        qu.pop();

        if (from == b) {
            ans = min(ans, to);
        }

        for (int i = 0; i < vc[from].size(); i++) {
            if (!visit[vc[from][i]]) {
                qu.push({ vc[from][i], to + 1 });
                visit[vc[from][i]] = true;
            }
        }
    }
}

int main() {
    cin >> a >> b >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        vc[from].push_back(to);
        vc[to].push_back(from);
    }

    bfs(a, 0);

    if (ans == INT32_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
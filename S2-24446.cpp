#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, R;
vector<int> vc[100001];
int depth[100001];

void bfs() {
    queue<int> qu;

    qu.push(R);
    depth[R] = 1;

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for (auto& next : vc[cur]) {
            if (depth[next]) {
                continue;
            }

            depth[next] = depth[cur] + 1;
            qu.push(next);
        }
    }
}

int main() {
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    bfs();

    for (int i = 1; i <= N; i++) {
        cout << depth[i] - 1 << "\n";
    }

    return 0;
}
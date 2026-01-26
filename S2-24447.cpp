#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> vc[100001];
long long visit[100001];
long long seq[100001];
int cnt = 1;
long long ans;

void bfs() {
    queue<int> qu;

    qu.push(R);
    visit[R] = 0;
    seq[R] = 1;

    while (!qu.empty()) {
        int cur = qu.front();
        seq[cur] = cnt;

        cnt += 1;
        qu.pop();

        for (int i = 0; i < vc[cur].size(); i++) {
            int next = vc[cur][i];

            if (visit[next] != -1) {
                continue;
            }

            visit[next] = visit[cur] + 1;
            qu.push(next);
        }
    }
}

int main() {
    cin >> N >> M >> R;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(vc[i].begin(), vc[i].end());
    }

    memset(visit, -1, sizeof(visit));
    bfs();

    for (int i = 1; i <= N; i++) {
        ans += visit[i] * seq[i];
    }

    cout << ans;

    return 0;
}
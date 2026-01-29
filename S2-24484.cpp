#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R, t;
vector<vector<int>> vc;
vector<bool> visit;
long long ans;

void dfs(int cur, long long dep) {
    visit[cur] = true;
    ans += dep * ++t;

    for (int next : vc[cur]) {
        if (visit[next]) {
            continue;
        }

        dfs(next, dep + 1);
    }
}

int main() {
    cin >> N >> M >> R;

    visit = vector<bool>(N + 1);
    vc = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        sort(vc[i].begin(), vc[i].end(), greater<int>());
    }

    dfs(R, 0);

    cout << ans;

    return 0;
}
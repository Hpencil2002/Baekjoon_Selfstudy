#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> vc;
vector<int> dep;

void dfs(int depth, int cur) {
    if (dep[cur] != -1) {
        return;
    }

    dep[cur] = depth;

    sort(vc[cur].begin(), vc[cur].end());

    for (int i = 0; i < vc[cur].size(); i++) {
        dfs(depth + 1, vc[cur][i]);
    }
}

int main() {
    cin >> N >> M >> R;

    dep = vector<int>(N + 1, -1);
    vc = vector<vector<int>>(N + 1, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    dfs(0, R);

    for (int i = 1; i <= N; i++) {
        cout << dep[i] << "\n";
    }

    return 0;
}
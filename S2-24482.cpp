#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, R;
vector<int> vc[100001];
int visit[100001];

void dfs(int cur, int dep) {
    visit[cur] = dep;

    for (int i = 0; i < vc[cur].size(); i++) {
        int next = vc[cur][i];

        if (visit[next] != -1) {
            continue;
        }

        dfs(next, dep + 1);
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

    for (int i = 1; i <= N; i++) {
        sort(vc[i].begin(), vc[i].end(), greater<>());
    }
    memset(visit, -1, sizeof(visit));

    dfs(R, 0);

    for (int i = 1; i <= N; i++) {
        cout << visit[i] << "\n";
    }

    return 0;
}
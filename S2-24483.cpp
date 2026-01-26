#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> vc[100001];
long long visit[100001];
long long seq[100001];
int cnt = 1;
long long ans;

void dfs(int cur, int count) {
    seq[cur] = count;
    visit[cur] = cnt;
    cnt += 1;

    for (int i = 0; i < vc[cur].size(); i++) {
        int next = vc[cur][i];

        if (visit[next] != 0) {
            continue;
        }

        dfs(next, count + 1);
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

    memset(seq, -1, sizeof(seq));
    dfs(R, 0);

    for (int i = 1; i <= N; i++) {
        ans += visit[i] * seq[i];
    }

    cout << ans;

    return 0;
}
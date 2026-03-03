#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
int dp[100001];
vector<int> vc[100001];
bool visit[100001];
bool isLeaf;

void dfs(int node, int parent) {
    visit[node] = true;

    for (int i = 0; i < vc[node].size(); i++) {
        int next = vc[node][i];
        if (visit[next]) {
            continue;
        }

        dfs(next, node);
    }

    if (parent != -1) {
        dp[parent] += dp[node];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill_n(dp, 100001, 1);

    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    dfs(R, -1);

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;

        cout << dp[q] << "\n";
    }

    return 0;
}
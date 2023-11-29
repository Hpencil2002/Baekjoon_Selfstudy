#include <iostream>
#include <vector>
using namespace std;

int visit[200];
vector<int> vc[200];
int n, m;
int cnt = 0;

void dfs(int x);

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    dfs(1);

    cout << cnt << "\n";

    return 0;
}

void dfs(int x) {
    if (x > n) {
        return;
    }

    visit[x] = 1;
    for (auto e : vc[x]) {
        if (!visit[e]) {
            cnt += 1;
            dfs(e);
        }
    }

    return;
}
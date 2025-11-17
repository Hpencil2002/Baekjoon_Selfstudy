#include <iostream>
#include <vector>
using namespace std;

vector<int> vc[501];
int visit[501] = { false, };

void dfs(int cur, int depth) {
    if (depth == 2) {
        return;
    }

    for (int i = 0; i < vc[cur].size(); i++) {
        int next = vc[cur][i];
        visit[next] = true;
        dfs(next, depth + 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        vc[a].push_back(b);
        vc[b].push_back(a);
    }

    visit[1] = true;
    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i]) {
            ans += 1;
        }
    }

    cout << ans - 1;

    return 0;
}
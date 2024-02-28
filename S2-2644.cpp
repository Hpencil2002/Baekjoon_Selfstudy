#include <iostream>
#include <vector>
using namespace std;

vector<int> vc[101];
int visited[101];
int ans = -1;

void dfs(int now, int end, int num);

int main() {
    int n, m, x, y;
    cin >> n >> x >> y >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    dfs(x, y, 0);
    
    cout << ans;

    return 0;
}

void dfs(int now, int end, int num) {
    visited[now] = 1;
    if (now == end) {
        ans = num;
    }

    for (int i = 0; i < vc[now].size(); i++) {
        int next = vc[now][i];
        if (!visited[next]) {
            dfs(next, end, num + 1);
        }
    }
}
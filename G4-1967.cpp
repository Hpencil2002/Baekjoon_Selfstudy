#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<bool> vc;
vector<pair<int, int>> node[10001];
int ans=-1;
int maxNode=0;

void dfs(int now, int val) {
    vc[now] = true;

    if (ans < val) {
        ans = val;
        maxNode = now;
    }

    for (int i = 0; i < node[now].size(); i++) {
        if (vc[node[now][i].first]) {
            continue;
        }

        dfs(node[now][i].first, val + node[now][i].second);
    }
}

int main() {
    cin >> n;
    vc.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int s, e, w;
        cin >> s >> e >> w;

        node[s].push_back({ e, w });
        node[e].push_back({ s, w });
    }

    dfs(1, 0);

    vc.assign(n + 1, false);
    ans = -1;
    dfs(maxNode, 0);

    cout << ans;

    return 0;
}
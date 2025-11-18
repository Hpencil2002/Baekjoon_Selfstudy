#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vc[100001];
bool visit[100001] = { false, };
int result[100001] = { 0, };
int cnt;

void dfs(int R) {
    if (visit[R]) {
        return;
    }

    visit[R] = true;
    cnt += 1;
    result[R] = cnt;

    for (int i = 0; i < vc[R].size(); i++) {
        dfs(vc[R][i]);
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(vc[i].begin(), vc[i].end(), greater<int>());
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> vc[100001];
int visit[100001] = { 0, };
int result[100001] = { 0, };
int cnt;

void bfs(int R) {
    queue<int> qu;

    visit[R] = 1;
    qu.push(R);
    cnt += 1;
    result[R] = cnt;

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for (int i = 0; i < vc[cur].size(); i++) {
            int tmp = vc[cur][i];
            if (!visit[tmp]) {
                cnt += 1;
                result[tmp] = cnt;
                qu.push(tmp);
                visit[tmp] = 1;
            }
        }
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
        sort(vc[i].begin(), vc[i].end(), greater<int>());
    }

    bfs(R);

    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
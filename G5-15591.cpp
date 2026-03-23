#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, Q;
vector<vector<pair<int, long long>>> vc;

void bfs(long long k, int v) {
    vector<bool> visit = vector<bool>(N + 1, false);
    queue<pair<int, long long>> qu;
    int cnt = 0;

    visit[v] = true;
    qu.push({ v, k });

    while (!qu.empty()) {
        int cur = qu.front().first;
        int costCur = qu.front().second;
        qu.pop();

        for (int i = 0; i < vc[cur].size(); i++) {
            int next = vc[cur][i].first;
            int costNext = vc[cur][i].second;

            if (!visit[next] && costNext >= k) {
                visit[next] = true;
                cnt += 1;
                qu.push({ next, costNext });
            }
        }
    }

    cout << cnt << "\n";

    return;
}

int main() {
    cin >> N >> Q;

    vc.assign(N + 1, vector<pair<int, long long>>(0, { 0, 0 }));
    for (int i = 0; i < N - 1; i++) {
        int p, q;
        long long r;
        cin >> p >> q >> r;

        vc[p].emplace_back(make_pair(q, r));
        vc[q].emplace_back(make_pair(p, r));
    }

    for (int i = 0; i < Q; i++) {
        long long k;
        int v;
        cin >> k >> v;

        bfs(k, v);
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int ans;
vector<pair<int, int>> vc[1001];
bool visit[1001];

int bfs(int cur, int dest) {
    queue<pair<int, int>> qu;

    visit[cur] = true;
    qu.push({ cur, 0 });

    while (!qu.empty()) {
        int node = qu.front().first;
        int dist = qu.front().second;
        qu.pop();

        if (node == dest) {
            return dist;
        }

        for (int i = 0; i < vc[node].size(); i++) {
            int next = vc[node][i].first;
            int nextDist = vc[node][i].second;

            if (!visit[next]) {
                visit[next] = true;
                qu.push({ next, dist + nextDist });
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;

        vc[u].push_back({ v, dist });
        vc[v].push_back({ u, dist });
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        memset(visit, false, sizeof(visit));
        cout << bfs(u, v) << "\n";
    }

    return 0;
}
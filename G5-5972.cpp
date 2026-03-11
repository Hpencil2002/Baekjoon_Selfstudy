#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> vc[50002];
int dist[50002];

void solve(int start) {
    for (int i = 1; i <= N; i++) {
        dist[i] = 1e9;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < vc[cur].size(); i++) {
            int next = vc[cur][i].first;
            int newCost = vc[cur][i].second + cost;

            if (dist[next] > newCost) {
                dist[next] = newCost;
                pq.push({ -dist[next], next });
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        vc[a].push_back({ b, c });
        vc[b].push_back({ a, c });
    }

    solve(1);

    cout << dist[N];

    return 0;
}
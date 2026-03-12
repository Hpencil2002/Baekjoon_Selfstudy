#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
vector<pair<int, int>> vc[30001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int val[20005];

int main() {
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        vc[u].push_back({ v, w });
    }

    for (int i = 1; i <= V; i++) {
        val[i] = 987654321;
    }
    val[K] = 0;

    pq.push({ 0, K });

    while (!pq.empty()) {
        int x = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < vc[u].size(); i++) {
            int v = vc[u][i].first;
            int w = vc[u][i].second;

            if (x + w < val[v]) {
                val[v] = x + w;
                pq.push({ x + w, v });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (val[i] == 987654321) {
            cout << "INF\n";
        }
        else {
            cout << val[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int visit[1003];
vector<pair<int, int>> vec[1003];

void solve(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    visit[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (visit[now] < cost) {
            continue;
        }

        for (int i = 0; i < vec[now].size(); i++) {
            int next = vec[now][i].first;
            int cost_next = cost + vec[now][i].second;

            if (visit[next] > cost_next) {
                pq.push({cost_next, next});
                visit[next] = cost_next;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    vec[0].push_back({0, 0});
    memset(visit, 98765432, sizeof(visit));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }

    int start, dest;
    cin >> start >> dest;

    solve(start);

    cout << visit[dest];

    return 0;
}
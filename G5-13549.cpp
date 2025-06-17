#include <iostream>
#include <queue>
using namespace std;

int N, K;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visit[100005];

int main() {
    cin >> N >> K;
    pq.push({0, N});

    while (!pq.empty()) {
        int time = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        visit[now] = 1;

        if (now ==K) {
            cout << time;
            break;
        }

        if (now - 1 >= 0 && !visit[now - 1]) {
            pq.push({time + 1, now - 1});
        }
        if (now + 1 <= 100000 && !visit[now + 1]) {
            pq.push({time + 1, now + 1});
        }
        if (now * 2 <= 100000 && !visit[now * 2]) {
            pq.push({time, now * 2});
        }
    }

    return 0;
}
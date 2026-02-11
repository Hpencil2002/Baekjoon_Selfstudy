#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
vector<int> vc[101];
int dist[101];

bool check() {
    for (int i = 1; i <= N; i++) {
        if (dist[i] == -1 || dist[i] >= 7) {
            return false;
        }
    }

    return true;
}

void bfs(int cur) {
    queue<int> qu;
    qu.push(cur);
    dist[cur] = 0;

    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();

        for (int next : vc[now]) {
            if (dist[next] == -1) {
                qu.push(next);
                dist[next] = dist[now] + 1;
            }
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B;

        vc[A].push_back(B);
        vc[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        memset(dist, -1, sizeof(dist));

        bfs(i);

        if (!check()) {
            cout << "Big World!";

            return 0;
        }
    }

    cout << "Small World!";

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, X;
int d[300001];
vector<int> vc[300001];

void solve(int start) {
    d[start] = 0;
    queue<int> qu;
    qu.push(start);

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for (int i = 0; i < vc[cur].size(); i++) {
            int next = vc[cur][i];

            if (d[next] > d[cur] + 1) {
                d[next] = d[cur] + 1;
                qu.push(next);
            }
        }
    }
}

int main() {
    cin >> N >> M >> K >> X;
    for (int i = 1; i <= N; i++) {
        d[i] = 987654321;
    }

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        vc[start].push_back(end);
    }

    solve(X);

    bool check = false;
    for (int i = 1; i <= N; i++) {
        if (d[i] == K) {
            check = true;
            cout << i << "\n";
        }
    }

    if (!check) {
        cout << -1;
    }

    return 0;
}
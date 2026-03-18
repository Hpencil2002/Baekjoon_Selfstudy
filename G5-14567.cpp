#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
int arr[1001];
int ans[1001];
vector<int> vc[1001];
queue<int> qu;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        vc[a].push_back(b);
        arr[b] += 1;
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) {
            qu.push(i);
        }

        ans[i] = 1;
    }

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for (int i = 0; i < vc[cur].size(); i++) {
            int next = vc[cur][i];
            arr[next] -= 1;

            if (arr[next] == 0) {
                qu.push(next);
                ans[next] = max(ans[next], ans[cur] + 1);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
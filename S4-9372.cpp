#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vc[1001];
bool check[1001];

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, a, b;

        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            vc[i].clear();
            check[i] = false;
        }
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            vc[a].push_back(b);
            vc[b].push_back(a);
        }

        int ans = 0;
        queue<int> qu;

        qu.push(1);
        check[1] = true;
        while (!qu.empty()) {
            int index = qu.front();
            qu.pop();

            for (int i = 0; i < vc[index].size(); i++) {
                int next = vc[index][i];
                if (!check[next]) {
                    check[next] = true;
                    ans += 1;
                    qu.push(next);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
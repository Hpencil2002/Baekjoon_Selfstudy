#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, E;
bool flag;
vector<int> vc[300001];
int visit[300001];

int main() {
    cin >> N >> M >> S >> E;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        vc[x].push_back(y);
        vc[y].push_back(x);
    }

    queue<pair<int, int>> qu;
    qu.push({ S, 0 });
    visit[S] = 1;

    while (!qu.empty()) {
        int next = qu.front().first;
        int cnt = qu.front().second;
        qu.pop();

        if (next == E) {
            flag = true;
            cout << cnt;

            return 0;
        }

        if (next - 1 > 0 && visit[next - 1] == 0) {
            visit[next - 1] = 1;
            qu.push({ next - 1, cnt + 1 });
        }
        if (next + 1 <= N && visit[next + 1] == 0) {
            visit[next + 1] = 1;
            qu.push({ next + 1,  cnt + 1 });
        }

        for (int i = 0; i < vc[next].size(); i++) {
            if (visit[vc[next][i]] == 0) {
                visit[vc[next][i]] = 1;
                qu.push({ vc[next][i], cnt + 1 });
            }
        }
    }

    if (!flag) {
        cout << -1;
    }

    return 0;
}
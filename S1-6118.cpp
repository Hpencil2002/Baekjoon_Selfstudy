#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int ans_num = 1, ans_dist = 0, ans_cnt = 0;
vector<int> vc[50001];
vector<bool> visit(50001);

void bfs() {
    queue<pair<int, int>> qu;
    qu.push({ 1, 0 });

    while (!qu.empty()) {
        int cur = qu.front().first;
        int dist = qu.front().second;
        visit[cur] = true;
        qu.pop();

        if (dist > ans_dist) {
            ans_dist = dist;
            ans_num = cur;
            ans_cnt = 1;
        }
        else if (dist == ans_dist) {
            ans_num = min(ans_num, cur);
            ans_cnt += 1;
        }

        for (int i = 0; i < vc[cur].size(); i++) {
            int next = vc[cur][i];

            if (!visit[next]) {
                visit[next] = true;
                qu.push({ next, dist + 1 });
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        vc[a].push_back(b);
        vc[b].push_back(a);
    }

    bfs();

    cout << ans_num << ' ' << ans_dist << ' ' << ans_cnt;

    return 0;
}
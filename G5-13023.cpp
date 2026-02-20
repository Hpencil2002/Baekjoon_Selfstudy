#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vc[2001];
bool visit[2001];
bool flag = false;

void dfs(int cur, int cnt) {
    if (cnt == 4) {
        flag = true;

        return;
    }

    visit[cur] = true;
    for (int i = 0; i < vc[cur].size(); i++) {
        int next = vc[cur][i];

        if (!visit[next]) {
            dfs(next, cnt + 1);
            visit[next] = false;
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

    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            dfs(i, 0);
            visit[i] = false;
        }

        if (flag) {
            cout << 1;

            return 0;
        }
    }

    cout << 0;

    return 0;
}
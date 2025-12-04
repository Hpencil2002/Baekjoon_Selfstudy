#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[10001];
vector<int> vc[10001];
vector<int> ans;

int dfs(int num) {
    int cnt = 1;
    visit[num] = true;

    for (int i : vc[num]) {
        if (!visit[i]) {
            cnt += dfs(i);
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        vc[b].push_back(a);
    }

    int maxCnt = 0;
    for (int i = 0; i <= N; i++) {
        if (vc[i].empty()) {
            continue;
        }

        fill(visit, visit + 10001, false);

        int cnt = dfs(i);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans.clear();
            ans.push_back(i);
        }
        else if (cnt == maxCnt) {
            ans.push_back(i);
        }
    }

    for (int i : ans) {
        cout << i << ' ';
    }

    return 0;
}
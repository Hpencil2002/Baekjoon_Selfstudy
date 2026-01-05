#include <iostream>
#include <vector>
using namespace std;

int N;
long long ans;
vector<int> vc[5001];
bool visit[5001];
int mp[5001][5001];

void dfs(int start, long long sum) {
    if (sum > ans) {
        ans = sum;
    }

    visit[start] = true;

    for (int i = 0; i < vc[start].size(); i++) {
        int cur = vc[start][i];

        if (!visit[cur]) {
            visit[cur] = true;
            dfs(cur, sum + mp[start][cur]);
            visit[cur] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        vc[a].push_back(b);
        vc[b].push_back(a);

        mp[a][b] = c;
        mp[b][a] = c;
    }

    dfs(1, 0);

    cout << ans;

    return 0;
}
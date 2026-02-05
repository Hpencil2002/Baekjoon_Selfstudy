#include <iostream>
#include <vector>
using namespace std;

int N, M, X;
int ans;
vector<int> vc[100001];
bool visit[100001];

int dfs(int x) {
    int res = 1;
    visit[x] = true;

    for (int next : vc[x]) {
        if (!visit[next]) {
            res += dfs(next);
        }
    }

    return res;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        vc[b].push_back(a);
    }
    cin >> X;

    cout << dfs(X) - 1;

    return 0;
}
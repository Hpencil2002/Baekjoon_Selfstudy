#include <iostream>
using namespace std;

int N, ans;
int rome[] = { 1, 5, 10, 50 };
bool visit[1001];

void dfs(int cnt, int d, int total) {
    if (cnt == N) {
        if (!visit[total]) {
            visit[total] = true;
            ans += 1;
        }

        return;
    }

    for (int i = d; i < 4; i++) {
        dfs(cnt + 1, i, total + rome[i]);
    }
}

int main() {
    cin >> N;

    dfs(0, 0, 0);

    cout << ans;

    return 0;
}
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
int ans;
char relationship[50][50] = { 'N' };
int visit[50] = { 0, };

void bfs(int v) {
    memset(visit, 0, sizeof(visit));

    queue<pair<int, int>> qu;
    qu.push({ v, 0 });
    visit[v] = 1;

    int friends = 0;
    while (!qu.empty()) {
        int curV = qu.front().first;
        int depth = qu.front().second;
        qu.pop();

        if (depth > 1) {
            continue;
        }

        for (int i = 0; i < N; i++) {
            if (relationship[curV][i] == 'Y' && visit[i] == 0) {
                visit[i] = 1;
                friends += 1;
                qu.push({ i, depth + 1 });
            }
        }
    }

    if (friends > ans) {
        ans = friends;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> relationship[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        bfs(i);
    }

    cout << ans;

    return 0;
}
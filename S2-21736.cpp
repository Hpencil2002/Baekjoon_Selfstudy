#include <iostream>
#include <queue>
using namespace std;

char mp[601][601];
int visit[601][601];
int n, m, res;
pair<int, int> pos;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void bfs();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> mp[y][x];

            if (mp[y][x] == 'I') {
                pos.first = y;
                pos.second = x;
            }
        }
    }

    bfs();
    
    if (res == 0) {
        cout << "TT";
    }
    else {
        cout << res;
    }

    return 0;
}

void bfs() {
    queue<pair<int, int>> qu;
    qu.push(pos);
    visit[pos.first][pos.second] = 1;

    while (!qu.empty()) {
        pair<int, int> cur = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) {
                continue;
            }
            if (mp[next.first][next.second] == 'X') {
                continue;
            }
            if (visit[next.first][next.second] == 1) {
                continue;
            }

            if (mp[next.first][next.second] == 'P') {
                res += 1;
            }
            qu.push(next);
            visit[next.first][next.second] = 1;
        }
    }
}
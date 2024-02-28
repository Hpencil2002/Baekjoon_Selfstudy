#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 501

int n, m;
int map[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {0, };
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
vector<int> vc;
int s = 1;

void dfs(int y, int x);
bool compare(int i, int j);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                dfs(i, j);
                vc.push_back(s);
                cnt += 1;
                s = 1;
            }
        }
    }

    sort(vc.begin(), vc.end(), compare);
    cout << cnt << "\n";

    if (cnt == 0) {
        cout << 0 << "\n";
    }
    else {
        cout << vc[0] << "\n";
    }

    return 0;
}

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny > n || nx > m) {
            continue;
        }
        if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
            visited[ny][nx] = 1;
            s += 1;
            dfs(ny, nx);
        }
    }
}

bool compare(int i, int j) {
    return i > j;
}
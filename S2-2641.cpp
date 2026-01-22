#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int N, M;
string origin;
vector<string> ans;
set<string> path;
bool visit[101][101];
int x_move[4] = { 1, 0, -1, 0 };
int y_move[4] = { 0, -1, 0, 1 };

void dfs(int y, int x, int cnt, string route) {
    if (cnt == N) {
        path.insert(route);

        return;
    }

    for (int d = 0; d < 4; d++) {
        int x_next = x + x_move[d];
        int y_next = y + y_move[d];

        if (!visit[y_next][x_next]) {
            continue;
        }

        visit[y_next][x_next] = false;
        dfs(y_next, x_next, cnt + 1, route + to_string(d + 1));
        visit[y_next][x_next] = true;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;

        origin += c;
    }

    cin >> M;

    int x = 50, y = 50;
    for (int i = 0; i < N; i++) {
        int dir = origin[i] - '0' - 1;

        x += x_move[dir];
        y += y_move[dir];
        visit[y][x] = true;
    }

    for (y = 0; y < 100; y++) {
        for (x = 0; x < 100; x++) {
            if (visit[y][x]) {
                dfs(y, x, 0, "");
            }
        }
    }

    for (int i = 0; i < M; i++) {
        string str;

        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;

            str += c;
        }

        if (path.find(str) != path.end()) {
            ans.push_back(str);
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }

        cout << "\n";
    }

    return 0;
}
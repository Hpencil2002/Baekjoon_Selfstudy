#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int a, b;
bool visited[10000];

void bfs() {
    queue<pair<int, string>> qu;

    qu.push({a, ""});
    visited[a] = true;

    while (!qu.empty()) {
        int cur_int = qu.front().first;
        string cur_oper = qu.front().second;
        qu.pop();

        if (cur_int == b) {
            cout << cur_oper << "\n";
            return;
        }

        int D, S, L, R;

        D = (cur_int * 2) % 10000;
        if (!visited[D]) {
            visited[D] = true;
            qu.push({D, cur_oper + "D"});
        }

        S = cur_int - 1 < 0 ? 9999 : cur_int - 1;
        if (!visited[S]) {
            visited[S] = true;
            qu.push({S, cur_oper + "S"});
        }

        L = (cur_int % 1000) * 10 + (cur_int / 1000);
        if (!visited[L]) {
            visited[L] = true;
            qu.push({L, cur_oper + "L"});
        }

        R = cur_int / 10 + (cur_int % 10) * 1000;
        if (!visited[R]) {
            visited[R] = true;
            qu.push({R, cur_oper + "R"});
        }
    }
}

int main() {
    int T;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        memset(visited, false, sizeof(visited));
        bfs();
    }

    return 0;
}
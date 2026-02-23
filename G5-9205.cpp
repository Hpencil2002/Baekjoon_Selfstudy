#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

Point store[100];
Point festival;
Point home;
bool visit[100];

bool bfs(int n) {
    queue<pair<int, int>> qu;
    qu.push({ home.x, home.y });

    while (!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        if (abs(festival.x - x) + abs(festival.y - y) <= 1000) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (visit[i]) {
                continue;
            }

            if (abs(store[i].x - x) + abs(store[i].y - y) <= 1000) {
                visit[i] = true;
                qu.push({ store[i].x, store[i].y });
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cin >> home.x >> home.y;
        for (int i = 0; i < n; i++) {
            cin >> store[i].x >> store[i].y;
        }
        cin >> festival.x >> festival.y;

        if (bfs(n)) {
            cout << "happy\n";
        }
        else {
            cout << "sad\n";
        }

        fill(visit, visit + 100, false);
    }

    return 0;
}
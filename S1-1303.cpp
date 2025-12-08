#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int y;
    int x;
};

int axisX, axisY;
vector<string> vc;
queue<node> qu;
int ansW, ansB;
int dt[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

void bfs(int y, int x, char tar) {
    int cnt = 0;
    qu.push({ y, x });
    vc[y][x] = 'X';
    cnt += 1;

    node cur;
    while (!qu.empty()) {
        cur = qu.front();
        qu.pop();

        for (int d = 0; d < 4; d++) {
            int x_next = cur.x + dt[d][1];
            int y_next = cur.y + dt[d][0];

            if (x_next < 0 || x_next >= axisX || y_next < 0 || y_next >= axisY) {
                continue;
            }
            if (vc[y_next][x_next] != tar) {
                continue;
            }

            cnt += 1;
            vc[y_next][x_next] = 'X';
            qu.push({ y_next, x_next });
        }
    }

    if (tar == 'W') {
        ansW += cnt * cnt;
    }
    else {
        ansB += cnt * cnt;
    }
}

int main() {
    cin >> axisX >> axisY;
    vc.assign(axisY, "");

    for (int i = 0; i < axisY; i++) {
        cin >> vc[i];
    }

    for (int y = 0; y < axisY; y++) {
        for (int x = 0; x < axisX; x++) {
            if (vc[y][x] == 'W') {
                bfs(y, x, 'W');
            }
            if (vc[y][x] == 'B') {
                bfs(y, x, 'B');
            }
        }
    }

    cout << ansW << ' ' << ansB;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int R, C, k;
pair<int, int> start;
int arr[1001][1001];
bool visit[1001][1001];
vector<int> vc;
int x_move[5] = { 0, -1, 1, 0, 0 };
int y_move[5] = { 0, 0, 0, -1, 1 };

bool check(int x, int y) {
    for (int i = 1; i <= 4; i++) {
        int x_next = x + x_move[i];
        int y_next = y + y_move[i];

        if (x_next >= 0 && x_next < R && y_next >= 0 && y_next < C) {
            if (arr[x_next][y_next] == 0 && !visit[x_next][y_next]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> R >> C;

    cin >> k;
    for (int i = 0; i < k; i++) {
        int br, bc;
        cin >> br >> bc;

        arr[br][bc] = 1;
    }

    cin >> start.first >> start.second;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;

        vc.push_back(a);
    }

    int x = start.first;
    int y = start.second;
    int dir = 0;

    visit[x][y] = true;
    while (true) {
        if (!check(x, y)) {
            break;
        }

        while (true) {
            x += x_move[vc[dir]];
            y += y_move[vc[dir]];

            if (x < 0 || x >= R || y < 0 || y >= C) {
                break;
            }
            if (arr[x][y] == 1) {
                break;
            }
            if (visit[x][y]) {
                break;
            }

            visit[x][y] = true;
        }

        x -= x_move[vc[dir]];
        y -= y_move[vc[dir]];

        dir += 1;
        if (dir == 5) {
            dir = 0;
        }
    }

    cout << x << ' ' << y;

    return 0;
}
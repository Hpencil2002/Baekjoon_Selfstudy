#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int ans = INT32_MAX;
vector<vector<int>> vc(3, vector<int>(3));
vector<vector<int>> arr(3, vector<int>(3));
vector<bool> visit(10, false);

bool check() {
    for (int i = 0; i < 3; i++) {
        int total = 0;

        for (int j = 0; j < 3; j++) {
            total += arr[i][j];
        }

        if (total != 15) {
            return false;
        }
    }

    for (int i = 0; i < 3; i++) {
        int total = 0;

        for (int j = 0; j < 3; j++) {
            total += arr[j][i];
        }

        if (total != 15) {
            return false;
        }
    }

    if (arr[0][0] + arr[1][1] + arr[2][2] != 15) {
        return false;
    }
    if (arr[0][2] + arr[1][1] + arr[2][0] != 15) {
        return false;
    }

    return true;
}

void solve(int x, int y, int price) {
    if (y == 3) {
        x += 1;
        y = 0;
    }
    if (x == 3) {
        if (!check()) {
            return;
        }

        ans = min(ans, price);

        return;
    }

    for (int i = 1; i < 10; i++) {
        if (visit[i]) {
            continue;
        }

        visit[i] = true;
        arr[x][y] = i;
        solve(x, y + 1, price + abs(vc[x][y] - i));
        visit[i] = false;
    }
}

int main() {
    for (auto& ele : vc) {
        for (int& e : ele) {
            cin >> e;
        }
    }

    solve(0, 0, 0);

    cout << ans;

    return 0;
}
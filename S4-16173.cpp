#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string solve(int n, vector<vector<int>> vc) {
    queue<pair<int, int>> qu;
    qu.push({0, 0});

    while (!qu.empty()) {
        auto now = qu.front();
        qu.pop();

        int x = now.first;
        int y = now.second;
        int step = vc[x][y];

        if (step == -1) {
            return "HaruHaru";
        }
        if (step == 0) {
            continue;
        }

        if (x + step < n) {
            qu.push({x + step, y});
        }
        if (y + step < n) {
            qu.push({x, y + step});
        }
    }

    return "Hing";
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> vc(N);
    for (auto &now : vc) {
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            now.push_back(tmp);
        }
    }

    cout << solve(N, vc);

    return 0;
}
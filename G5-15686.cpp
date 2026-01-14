#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, chickenCnt;
int ans = 99999999;
int arr[51][51];
bool visit[13];
vector<pair<int, int>> house, chicken, vc;

int calc() {
    int res = 0;

    for (int i = 0; i < house.size(); i++) {
        int x = house[i].first;
        int y = house[i].second;
        int d = 99999999;

        for (int j = 0; j < vc.size(); j++) {
            int xx = vc[j].first;
            int yy = vc[j].second;
            int dist = abs(xx - x) + abs(yy - y);

            d = min(d, dist);
        }

        res += d;
    }

    return res;
}

void solve(int index, int cnt) {
    if (cnt == M) {
        ans = min(ans, calc());

        return;
    }

    for (int i = index; i < chickenCnt; i++) {
        if (visit[i]) {
            continue;
        }

        visit[i] = true;
        vc.push_back(chicken[i]);
        solve(i, cnt + 1);
        visit[i] = false;
        vc.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) {
                house.push_back({ i, j });
            }
            if (arr[i][j] == 2) {
                chicken.push_back({ i, j });
            }
        }
    }
    chickenCnt = chicken.size();

    solve(0, 0);

    cout << ans;

    return 0;
}
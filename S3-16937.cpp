#include <iostream>
#include <vector>
using namespace std;

int H, W, N, ans;
bool mp[100][100];
bool sel[100];
bool sel2[100];
vector<pair<pair<int, int>, int>> vc;
vector<pair<int, int>> sticker;

int bigger(int a, int b) {
    return a > b ? a : b;
}

void dfs(int index, int cnt) {
    if (cnt == 2) {
        int x = sticker[0].first;
        int y = sticker[0].second;
        int xx = sticker[1].first;
        int yy = sticker[1].second;
        int res = (x * y) + (xx * yy);

        if (x + xx <= H) {
            int yyy = bigger(y, yy);

            if (yyy <= W) {
                ans = bigger(ans, res);
            }
        }

        if (y + yy <= W) {
            int xxx = bigger(x, xx);

            if (xxx <= H) {
                ans = bigger(ans, res);
            }
        }

        return;
    }

    for (int i = index; i < vc.size(); i++) {
        if (sel[i] || sel2[vc[i].second]) {
            continue;
        }

        sel[i] = true;
        sel2[vc[i].second] = true;
        sticker.push_back({ vc[i].first.first, vc[i].first.second });

        dfs(i, cnt + 1);

        sticker.pop_back();
        sel2[vc[i].second] = false;
        sel[i] = false;
    }
}

int main() {
    cin >> H >> W >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if (a * b >= H * W) {
            continue;
        }

        if (a != b) {
            vc.push_back({{ a, b }, i });
            vc.push_back({{ b, a }, i });
        }
        else {
            vc.push_back({{ a, b }, i });
        }
    }

    if (vc.size() > 1) {
        dfs(0, 0);
    }

    cout << ans;

    return 0;
}
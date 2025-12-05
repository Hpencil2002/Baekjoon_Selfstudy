#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, w, L;
int Time = 0;
int curL = 0;
vector<int> vc;
queue<pair<int, int>> qu;

void solve() {
    int i = 0;

    while (true) {
        if (i < n && curL + vc[i] <= L) {
            qu.push({ w, vc[i] });
            curL += vc[i];
            i += 1;
        }

        int s = qu.size();

        for (int j = 0; j < s; j++) {
            if (!qu.empty()) {
                int curTime = qu.front().first;
                int weight = qu.front().second;
                qu.pop();

                if (curTime - 1 != 0) {
                    qu.push({ curTime - 1, weight });
                }
                else {
                    curL -= weight;
                }
            }
        }

        Time += 1;

        if (i == n && qu.empty()) {
            break;
        }
    }

    cout << Time + 1;
}

int main() {
    cin >> n >> w >> L;

    vc.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    solve();

    return 0;
}
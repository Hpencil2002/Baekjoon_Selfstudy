#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int room, from, to;
int ans = 1;
vector<pair<int, int>> vc;
priority_queue<int, vector<int>, greater<int>> qu;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> room >> from >> to;
        vc.push_back({ from, to });
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < vc.size(); i++) {
        int start = vc[i].first;
        int end = vc[i].second;

        if (qu.empty()) {
            qu.push(end);
        }
        else {
            if (qu.top() > start) {
                ans += 1;
            }
            else {
                qu.pop();
            }

            qu.push(end);
        }
    }

    cout << ans;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int ans = 1;
vector<pair<int, int>> vc;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;

        vc.push_back({ s, e });
    }

    sort(vc.begin(), vc.end());

    pq.push(vc[0].second);
    for (int i = 1; i < N; i++) {
        while (!pq.empty() && pq.top() <= vc[i].first) {
            pq.pop();
        }

        pq.push(vc[i].second);
        ans = max(ans, (int)pq.size());
    }

    cout << ans;

    return 0;
}
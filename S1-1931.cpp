#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<pair<int, int>> vc;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> end >> start;
        vc.push_back(make_pair(start, end));
    }
    sort(vc.begin(), vc.end());

    int time = vc[0].first;
    int ans = 1;
    int j = 0;
    for (int i = 1; i <= N; i++) {
        if (vc[i].second >= time) {
            ans += 1;
            time = vc[i].first;
        }
    }

    cout << ans;

    return 0;
}
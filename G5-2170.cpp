#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> line[1000010];
int ans;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> line[i].first >> line[i].second;
    }

    sort(line + 1, line + N + 1, comp);

    int left = -1000000010;
    int right = -1000000010;
    for (int i = 1; i <= N; i++) {
        if (line[i].first <= right) {
            right = max(right, line[i].second);
        }
        else {
            ans += right - left;

            left = line[i].first;
            right = line[i].second;
        }
    }
    ans += right - left;

    cout << ans;

    return 0;
}
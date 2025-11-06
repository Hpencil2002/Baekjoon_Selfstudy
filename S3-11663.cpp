#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> point = vector<int>(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> point[i];
    }
    point[N] = 1000000001;

    sort(point.begin(), point.end());

    while (M--) {
        int start, end;
        cin >> start >> end;

        int left = lower_bound(point.begin(), point.end(), start) - point.begin();
        int right = upper_bound(point.begin(), point.end(), end) - point.begin();

        cout << right - left << "\n";
    }

    return 0;
}
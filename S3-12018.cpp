#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> point;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;

        vector<int> vc = vector<int>(p);
        for (int j = 0; j < p; j++) {
            cin >> vc[j];
        }

        if (p < l) {
            point.push_back(1);
        }
        else {
            sort(vc.begin(), vc.end());
            point.push_back(vc[p - l]);
        }
    }

    sort(point.begin(), point.end());

    int ans = 0;
    for (int i = 0; i < point.size(); i++) {
        if (m >= point[i]) {
            ans += 1;
            m -= point[i];
        }
    }

    cout << ans;

    return 0;
}
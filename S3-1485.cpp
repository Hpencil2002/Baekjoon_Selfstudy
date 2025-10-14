#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<pair<int, int>> vc;
        vector<int> res;

        for (int i = 0; i < 4; i++) {
            int x, y;
            cin >> x >> y;
            vc.push_back({x, y});
        }

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                res.push_back(pow(vc[i].first - vc[j].first, 2) + pow(vc[i].second - vc[j].second, 2));
            }
        }

        sort(res.begin(), res.end());

        if (res[0] == res[1] && res[1] == res[2] && res[2] == res[3] && res[4] == res[5]) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
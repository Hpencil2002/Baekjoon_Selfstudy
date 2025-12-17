#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int calcDist(string a, string b, string c) {
    int diff = 4;

    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i] && b[i] == c[i]) {
            diff -= 1;
        }
    }

    return 2 * diff;
}

int solve(vector<string>& mbtis) {
    int res = 8;
    int n = (int)mbtis.size();

    if (n > 32) {
        res = 0;
    }
    else {
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int dist = calcDist(mbtis[i], mbtis[j], mbtis[k]);
                    res = min(res, dist);
                }
            }
        }
    }

    return res;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        vector<string> vc = vector<string>(N);
        for (int i = 0; i < N; i++) {
            cin >> vc[i];
        }

        cout << solve(vc) << "\n";
    }

    return 0;
}
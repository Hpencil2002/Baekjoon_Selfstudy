#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> vc;
int ans = 987654321;

int main() {
    cin >> N;
    vc.resize(N, vector<int>(N));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> vc[y][x];
        }
    }

    for (unsigned int bitmask = 0; bitmask < (1 << N); bitmask++) {
        vector<int> teamStart;
        vector<int> teamLink;

        for (int i = 0; i < N; i++) {
            if (bitmask & (1 << i)) {
                teamStart.push_back(i);
            }
            else {
                teamLink.push_back(i);
            }
        }

        int sumStart = 0;
        int sumLink = 0;

        for (int i = 0; i < teamStart.size(); i++) {
            for (int j = 0; j < teamStart.size(); j++) {
                sumStart += vc[teamStart[i]][teamStart[j]];
            }
        }
        for (int i = 0; i < teamLink.size(); i++) {
            for (int j = 0; j < teamLink.size(); j++) {
                sumLink += vc[teamLink[i]][teamLink[j]];
            }
        }

        ans = min(ans, abs(sumStart - sumLink));
    }

    cout << ans;

    return 0;
}
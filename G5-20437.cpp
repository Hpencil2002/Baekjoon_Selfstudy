#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int T, K;
string W;
vector<int> vc[26];

int main() {
    cin >> T;

    while (T--) {
        cin >> W >> K;
        for (int i = 0; i < 26; i++) {
            vc[i].clear();
        }

        for (int i = 0; i < W.length(); i++) {
            int num = W[i] - 97;
            vc[num].push_back(i);
        }

        int minI = 100000;
        int maxI = 0;
        for (int i = 0; i < 26; i++) {
            int size = (int)vc[i].size();

            if (size >= K) {
                for (int j = 0; j <= size - K; j++) {
                    minI = min(minI, vc[i][j + K - 1] - vc[i][j] + 1);
                    maxI = max(maxI, vc[i][j + K - 1] - vc[i][j] + 1);
                }
            }
        }

        if (minI == 100000 || maxI == 0) {
            cout << "-1\n";
        }
        else {
            cout << minI << ' ' << maxI << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int N, M;

int main() {
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            return 0;
        }

        vector<int> secondRank;
        vector<int> ans;
        map<int, int> mp;

        for (int i = 0; i < N * M; i++) {
            int num;
            cin >> num;

            mp[num] += 1;
        }

        int first = 0;
        int second = 0;
        for (auto e : mp) {
            first = max(first, e.second);
        }
        for (auto e : mp) {
            if (e.second == first) {
                continue;
            }

            second = max(second, e.second);
        }

        for (auto e : mp) {
            if (e.second == second) {
                cout << e.first << ' ';
            }
        }
        cout << "\n";
    }
}
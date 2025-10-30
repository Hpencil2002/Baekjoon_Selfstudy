#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> vc = vector<pair<int, int>>(26);
    for (int i = 0; i < 52; i++) {
        char c;
        cin >> c;

        int now = c - 'A';
        if (vc[now].first == 0) {
            vc[now].first = i + 1;
        }
        else {
            vc[now].second = i + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (vc[i].first < vc[j].first && vc[j].first < vc[i].second && vc[i].second < vc[j].second) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}
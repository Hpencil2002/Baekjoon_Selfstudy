#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int p, m, l;
string n;
vector<pair<string, int>> vc[310];

int main() {
    cin >> p >> m;
    for (int i = 0; i < p; i++) {
        cin >> l >> n;

        int flag = 0;
        for (int j = 0; j <= i; j++) {
            if (vc[j].size() < m && vc[j].size() > 0) {
                if (abs(vc[j][0].second - l) <= 10) {
                    flag = 1;
                    vc[j].push_back({ n, l });
                    break;
                }
            }
        }

        if (flag == 0) {
            vc[i].push_back({ n, l });
        }
    }

    for (int i = 0; i < 300; i++) {
        if (vc[i].size() == 0) {
            continue;
        }
        else if (vc[i].size() >= m) {
            cout << "Started!\n";
        }
        else if (vc[i].size() > 0 && vc[i].size() < m) {
            cout << "Waiting!\n";
        }

        sort(vc[i].begin(), vc[i].end());

        for (int j = 0; j < vc[i].size(); j++) {
            cout << vc[i][j].second << ' ' << vc[i][j].first << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, D;

int main() {
    cin >> N >> D;

    vector<int> vc = vector<int>(D + 1, 987654321);
    vector<pair<int, int>> sc[10001];

    for (int i = 0; i < N; i++) {
        int start, end, len;
        cin >> start >> end >> len;

        sc[end].push_back({ start, len });
    }

    vc[0] = 0;
    for (int i = 1; i <= D; i++) {
        if (sc[i].size() == 0) {
            vc[i] = vc[i - 1] + 1;
        }
        else {
            for (auto v : sc[i]) {
                vc[i] = min(vc[i], min(vc[i - 1] + 1, vc[v.first] + v.second));
            }
        }
    }

    cout << vc[D];

    return 0;
}
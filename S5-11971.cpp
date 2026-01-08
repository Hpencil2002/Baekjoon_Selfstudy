#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans;
vector<int> limit;
vector<int> speed;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int l, s;
        cin >> l >> s;

        for (int j = 0; j < l; j++) {
            limit.push_back(s);
        }
    }
    for (int i = 0; i < M; i++) {
        int l, s;
        cin >> l >> s;

        for (int j = 0; j < l; j++) {
            speed.push_back(s);
        }
    }

    for (int i = 0; i < 100; i++) {
        ans = max(ans, speed[i] - limit[i]);
    }

    cout << ans;

    return 0;
}
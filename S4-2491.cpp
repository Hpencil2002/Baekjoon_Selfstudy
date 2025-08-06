#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    int ans = 1;
    int cnt = 1;
    for (int i = 0; i < N - 1; i++) {
        if (vc[i] <= vc[i + 1]) {
            cnt += 1;
        }
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cnt = 1;

    for (int i = 0; i < N - 1; i++) {
        if (vc[i] >= vc[i + 1]) {
            cnt += 1;
        }
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);

    cout << ans;

    return 0;
}
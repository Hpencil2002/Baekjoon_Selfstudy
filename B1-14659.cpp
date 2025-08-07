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
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (vc[i] > vc[j]) {
                cnt += 1;
            }
            else {
                break;
            }
        }

        ans = max(cnt, ans);
        cnt = 0;
    }

    cout << ans;

    return 0;
}
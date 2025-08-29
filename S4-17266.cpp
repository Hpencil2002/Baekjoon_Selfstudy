#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> vc(M);
    for (int i = 0; i < M; i++) {
        cin >> vc[i];
    }

    int ans = max(vc[0], N - vc[vc.size() - 1]);
    for (int i = 0; i < M - 1; i++) {
        int h = vc[i + 1] - vc[i];

        if (h % 2 == 1) {
            h = h / 2 + 1;
            if (ans < h) {
                ans = h;
            }
        }
        else {
            h /= 2;
            if (ans < h) {
                ans = h;
            }
        }
    }

    cout << ans;

    return 0;
}
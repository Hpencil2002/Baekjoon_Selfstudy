#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, index;
int ans = 0;

int main() {
    cin >> N >> M;

    vector<int> vc = vector<int>(M);
    for (int i = 0; i < M; i++) {
        cin >> vc[i];
    }

    sort (vc.begin(), vc.end(), greater<int>());

    for (int i = 0; i < M; i++) {
        if (i < N) {
            if (vc[i] * (i + 1) > ans) {
                ans = vc[i] * (i + 1);
                index = i;
            }
        }
        else {
            break;
        }
    }

    cout << vc[index] << ' ' << ans;

    return 0;
}
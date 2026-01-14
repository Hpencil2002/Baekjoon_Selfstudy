#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vc;
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int snow;
        cin >> snow;

        vc.push_back(snow);
    }

    if (N == 1) {
        if (vc[0] > 1440) {
            cout << -1;
        }
        else {
            cout << vc[0];
        }

        return 0;
    }

    while (true) {
        sort(vc.begin(), vc.end());

        if (vc[N - 1] == 0) {
            break;
        }

        vc[N - 1] -= 1;
        if (vc[N - 2] != 0) {
            vc[N - 2] -= 1;
        }
        ans += 1;

        if (ans > 1440) {
            cout << -1;

            return 0;
        }
    }

    cout << ans;

    return 0;
}
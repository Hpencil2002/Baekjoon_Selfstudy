#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int P, N;
int ans;
vector<int> vc;

int main() {
    cin >> P >> N;

    vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < N; i++) {
        if (P < 200) {
            ans += 1;
            P += vc[i];
        }
        else {
            break;
        }
    }

    cout << ans;

    return 0;
}
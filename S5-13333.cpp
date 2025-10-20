#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vc = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    int ans = 0;
    for (int i = 0; i < vc.size(); i++) {
        if (vc[i] >= ans && n - i >= ans) {
            ans += 1;
            i -= 1;
        }
        else if (vc[i] < ans && n - i < ans) {
            ans -= 1;
            break;
        }
        else if (vc[i] < ans) {
            if (i == vc.size() - 1) {
                ans -= 1;
            }

            continue;
        }
        else if (n - i < ans) {
            ans -= 1;
            break;
        }
    }

    cout << ans;

    return 0;
}
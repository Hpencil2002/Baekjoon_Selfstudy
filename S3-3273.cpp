#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    int x;
    cin >> x;

    int ans = 0;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int tmp = vc[left] + vc[right];

        if (tmp < x) {
            left += 1;
        }
        else if (tmp > x) {
            right -= 1;
        }
        else if (tmp == x) {
            ans += 1;
            left += 1;
            right -= 1;
        }
    }

    cout << ans;

    return 0;
}
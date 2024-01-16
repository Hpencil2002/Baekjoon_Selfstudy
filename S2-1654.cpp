#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned int n, k, maxi = 0;
    unsigned int *lan;
    cin >> k >> n;
    lan = new unsigned int[k];
    for (int i = 0; i < k; i++) {
        cin >> lan[i];
        maxi = max(maxi, lan[i]);
    }

    sort(lan, lan + k);
    
    unsigned int ans = 0, left = 1, right = maxi, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        unsigned int now = 0;
        
        for (int i = 0; i < k; i++) {
            now += lan[i] / mid;
        }

        if (now >= n) {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
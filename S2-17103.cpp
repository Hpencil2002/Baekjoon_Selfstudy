#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 1000000;
vector<bool> isPrime;

void SetPrime() {
    isPrime = vector<bool>(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) {
            continue;
        }

        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;

    SetPrime();
    while (T--) {
        int num;
        cin >> num;

        vector<int> vc;
        for (int i = 2; i < num; i++) {
            if (isPrime[i]) {
                vc.push_back(i);
            }
        }

        int ans = 0;
        for (auto it = vc.begin(); it != vc.end(); it++) {
            int other = num - *it;
            if (other < *it) {
                break;
            }

            if (binary_search(it, vc.end(), other)) {
                ans += 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int A, B;
int ans;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> A >> B;

    vector<int> vc = vector<int>(100001, 1);
    vector<int> prime;
    for (int i = 2; i <= 100000; i++) {
        if (vc[i]) {
            prime.push_back(i);

            for (int j = i * 2; j <= 100000; j += i) {
                vc[j] = 0;
            }
        }
    }

    for (int i = A; i <= B; i++) {
        vector<int> check;
        int x = i;

        for (int j : prime) {
            while (x % j == 0) {
                check.push_back(j);
                x /= j;
            }

            if (x < 2) {
                break;
            }
        }

        if (isPrime(check.size())) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}
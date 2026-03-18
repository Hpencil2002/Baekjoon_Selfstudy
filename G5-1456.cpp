#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long A, B;
long long limit;
long long ans;
vector<bool> isPrime;
vector<long long> prime;

int main() {
    cin >> A >> B;

    limit = sqrt(B) + 1;
    isPrime = vector<bool>(limit + 1, true);

    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            prime.push_back(i);

            for (long long j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (long long i : prime) {
        long long tmp = i * i;

        while (tmp <= B) {
            if (tmp >= A) {
                ans += 1;
            }

            if (tmp > B / i) {
                break;
            }
            tmp *= i;
        }
    }

    cout << ans;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<long long> vc = vector<long long>(1000002, 1);
vector<long long> prime;
long long ans = 1;

void getPrime() {
    for (int i = 2; i <= sqrt(1000001); i++) {
        for (int j = i * i; j <= 1000001; j += i) {
            vc[j] = 0;
        }
    }

    for (int i = 2; i < 1000001; i++) {
        if (vc[i] == 1) {
            prime.push_back(i);
        }
    }
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    getPrime();

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        for (int j = 0; j < prime.size(); j++) {
            if (num == prime[j]) {
                ans = lcm(ans, num);
            }
        }
    }

    if (ans == 1) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
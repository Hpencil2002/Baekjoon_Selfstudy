#include <iostream>
#include <unordered_map>
using namespace std;

long long N, P, Q;
unordered_map<long long, long long> mp;

long long solve(long long num) {
    long long res;

    if (mp.find(num) != mp.end()) {
        return mp[num];
    }

    res = solve(num / P) + solve(num / Q);
    mp[num] = res;

    return res;
}

int main() {
    cin >> N >> P >> Q;

    mp[0] = 1;
    if (N == 0) {
        cout << 1;
    }
    else {
        cout << solve(N / P) + solve(N / Q);
    }

    return 0;
}
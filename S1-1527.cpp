#include <iostream>
using namespace std;

long long A, B;
long long ans;

void solve(long long num) {
    if (num > B) {
        return;
    }

    if (A <= num && num <= B) {
        ans += 1;
    }

    solve(num * 10 + 4);
    solve(num * 10 + 7);
}

int main() {
    cin >> A >> B;

    solve(4);
    solve(7);

    cout << ans;

    return 0;
}
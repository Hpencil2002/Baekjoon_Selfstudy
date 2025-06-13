#include <iostream>
#include <queue>
using namespace std;

long long A, B;
int ans = -1;
queue<pair<long long, int>> qu;

int main() {
    cin >> A >> B;

    qu.push({A, 1});

    while (!qu.empty()) {
        long long k = qu.front().first;
        int n = qu.front().second;
        qu.pop();

        if (k == B) {
            ans = n;
            break;
        }

        if (k * 2 <= B) {
            qu.push({k * 2, n + 1});
        }
        if (k * 10 + 1 <= B) {
            qu.push({k * 10 + 1, n + 1});
        }
    }

    cout << ans;

    return 0;
}
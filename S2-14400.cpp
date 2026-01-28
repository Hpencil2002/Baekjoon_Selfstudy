#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x[100001];
int y[100001];
long long ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x, x + n);
    sort(y, y + n);

    int midIndex = n / 2;
    int midX = x[midIndex];
    int midY = y[midIndex];

    for (int i = 0; i < n; i++) {
        ans += abs(midX - x[i]);
        ans += abs(midY - y[i]);
    }

    cout << ans;

    return 0;
}
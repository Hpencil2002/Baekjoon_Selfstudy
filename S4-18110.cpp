#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0;

    cin >> n;
    if (n == 0) {
        cout << res;
        return 0;
    }

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    int index = round(n * 0.15);
    double sum = 0;

    for (int i = index; i < n - index; i++) {
        sum += num[i];
    }

    res = round(sum / (n - index * 2));

    cout << res;

    return 0;
}
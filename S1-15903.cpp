#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> qu;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        qu.push(num);
    }

    while (m--) {
        long long a, b;

        a = qu.top();
        qu.pop();
        b = qu.top();
        qu.pop();

        qu.push(a + b);
        qu.push(a + b);
    }

    long long sum = 0;
    while (!qu.empty()) {
        sum += qu.top();
        qu.pop();
    }

    cout << sum;

    return 0;
}
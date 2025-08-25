#include <iostream>
#include <algorithm>
using namespace std;

int Euc(int a, int b) {
    int r = a % b;

    if (r == 0) {
        return b;
    }
    else {
        return Euc(b, r);
    }
}

int main() {
    int N;
    cin >> N;

    int trees[100001];
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    int ans = 0;
    int gcd = 0;
    int distance[100001];

    sort(trees, trees + N);

    for (int i = 0; i < N - 1; i++) {
        distance[i] = trees[i + 1] - trees[i];
    }

    gcd = distance[0];
    for (int i = 1; i < N - 1; i++) {
        gcd = Euc(gcd, distance[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        ans += (distance[i] / gcd) - 1;
    }

    cout << ans;

    return 0;
}
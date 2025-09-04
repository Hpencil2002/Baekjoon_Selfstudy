#include <iostream>
#include <climits>
using namespace std;

int road[100001];
int cost[100001];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> road[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    int minCost = INT_MAX;
    long long ans = 0;
    for (int i = 1; i < N; i++) {
        if (cost[i] < minCost) {
            minCost = cost[i];
        }

        ans += (long long)minCost * (long long)road[i];
    }

    cout << ans;

    return 0;
}
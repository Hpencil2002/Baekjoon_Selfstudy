#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[21];
bool check[2000001];

void solve(int x, int sum) {
    check[sum] = true;

    if (x == N) {
        return;
    }

    solve(x + 1, sum);
    solve(x + 1, sum + arr[x]);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve(0, 0);

    int i = 1;
    while (check[i]) {
        i += 1;
    }

    cout << i;

    return 0;
}
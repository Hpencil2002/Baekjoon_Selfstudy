#include <iostream>
#include <set>
using namespace std;

int N, M;
int ans;
int arr[21];
set<int> s;

void solve(int index, int sum) {
    s.insert(sum);
    if (index == N) {
        return;
    }

    solve(index + 1, sum + arr[index]);
    solve(index + 1, sum);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        M += arr[i];
    }

    solve(0, 0);

    ans = M - s.size() + 1;
    cout << ans;

    return 0;
}
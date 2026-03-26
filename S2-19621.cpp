#include <iostream>
#include <cmath>
using namespace std;

int N;
int s[26];
int e[26];
int people[26];
int ans;

void solve(int index, int sum) {
    if (index >= N) {
        ans = max(ans, sum);

        return;
    }

    solve(index + 1, sum);
    solve(index + 2, sum + people[index]);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> people[i];
    }

    solve(0, 0);

    cout << ans;

    return 0;
}
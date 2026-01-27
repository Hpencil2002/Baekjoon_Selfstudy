#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int N, M;
int arr[10];
bool check[9000];
set<int> s;

void solve(int cnt, int index, int sum) {
    if (cnt == M) {
        if (check[sum]) {
            s.insert(sum);
        }

        return;
    }

    for (int i = index; i < N; i++) {
        solve(cnt + 1, i + 1, sum + arr[i]);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    memset(check, true, sizeof(check));
    check[0] = check[1] = false;
    for (int i = 2; i * i <= 9000; i++) {
        for (int j = i * 2; j <= 9000; j += i) {
            check[j] = false;
        }
    }

    solve(0, 0, 0);

    if (s.empty()) {
        cout << -1;
    }
    else {
        for (auto i : s) {
            cout << i << ' ';
        }
    }

    return 0;
}
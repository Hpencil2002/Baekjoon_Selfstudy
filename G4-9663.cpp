#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[16];
int ans;

void solve(int x) {
    if (x == N) {
        ans += 1;
    }
    else {
        for (int i = 0; i < N; i++) {
            arr[x] = i;
            bool flag = true;

            for (int j = 0; j < x; j++) {
                if (arr[x] == arr[j] || abs(arr[x] - arr[j]) == x - j) {
                    flag = false;

                    break;
                }
            }

            if (flag) {
                solve(x + 1);
            }
        }
    }
}

int main() {
    cin >> N;

    solve(0);

    cout << ans;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    string seat;
    cin >> seat;

    int ans = 1;
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (seat[i] == 'S') {
            ans += 1;
        }
        else {
            tmp += 1;

            if (tmp == 2) {
                tmp = 0;
                ans += 1;
            }
        }
    }

    if (ans > N) {
        cout << N;
    }
    else {
        cout << ans;
    }

    return 0;
}
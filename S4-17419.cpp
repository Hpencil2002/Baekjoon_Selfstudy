#include <iostream>
using namespace std;

int N;
char K;
int ans;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> K;
        if (K == '1') {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}
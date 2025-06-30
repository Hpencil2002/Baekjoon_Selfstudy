#include <iostream>
using namespace std;

int main() {
    int N;
    int ans = 0;

    cin >> N;
    for (int start = 1; start <= N; start++) {
        int total = start;
        for (int end = start + 1; end <= N; end++) {
            total += end;

            if (total == N) {
                ans += 1;
                break;
            }
            else if (total > N) {
                break;
            }
        }
    }

    cout << ans + 1;

    return 0;
}
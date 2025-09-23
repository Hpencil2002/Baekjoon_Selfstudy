#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] != 'P') {
            continue;
        }

        for (int j = i - K; j <= i + K; j++) {
            if (j >= 0 && j < N && str[j] == 'H') {
                str[j] = '-';
                ans += 1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
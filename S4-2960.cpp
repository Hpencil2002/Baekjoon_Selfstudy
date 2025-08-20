#include <iostream>
using namespace std;

int num[1000];
int cnt, erase;

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            cnt = 0;

            for (int x = 0; num[x] != 0; x++) {
                if (num[x] == j) {
                    cnt += 1;
                }
            }

            if (cnt == 0) {
                num[erase++] = j;
            }
        }
    }

    cout << num[K - 1];

    return 0;
}
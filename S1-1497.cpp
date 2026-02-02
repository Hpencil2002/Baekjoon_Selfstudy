#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<long long> vc;
int ans = -1;
int maxCnt;

int countBit(long long num) {
    if (num == 0) {
        return 0;
    }

    return num % 2 + countBit(num / 2);
}

void solve(int index, long long bit, int num) {
    int bitCnt = countBit(bit);

    if (bitCnt > maxCnt) {
        maxCnt = bitCnt;
        ans = num;
    }
    else if (bitCnt == maxCnt) {
        ans = min(ans, num);
    }

    if (index == N) {
        return;
    }

    solve(index + 1, bit | vc[index], num + 1);
    solve(index + 1, bit, num);
}

int main() {
    cin >> N >> M;

    vc = vector<long long>(N);
    for (int i = 0; i < N; i++) {
        string str, list;
        cin >> str >> list;

        for (int j = 0; j < M; j++) {
            int bit = 0;
            if (list[j] == 'Y') {
                bit = 1;
            }
            else {
                bit = 0;
            }

            vc[i] = vc[i] | ((long long)bit << j);
        }
    }

    solve(0, 0, 0);

    cout << ans;

    return 0;
}
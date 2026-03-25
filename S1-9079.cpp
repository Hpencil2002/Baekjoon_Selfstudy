#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int ans = -1;
int mask[] = { 7, 56, 448, 73, 146, 292, 273, 84 };
bool visit[512];

int makeBit(string s) {
    int bit = 0;

    for (int i = 8; i >= 0; i--) {
        bit <<= 1;

        if (s[i] == 'H') {
            bit |= 1;
        }
    }

    return bit;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        memset(visit, false, sizeof(visit));
        ans = -1;

        string str;
        char c;
        for (int i = 0; i < 9; i++) {
            cin >> c;
            str += c;
        }
        int bit = makeBit(str);

        queue<int> qu;
        qu.push(bit);
        visit[bit] = true;

        bool flag = false;
        while (!qu.empty() && !flag) {
            ans += 1;
            int n = qu.size();

            while (n--) {
                int cur = qu.front();
                qu.pop();

                if (cur == 0 || cur == (1 << 9) - 1) {
                    flag = true;

                    break;
                }

                for (int i = 0; i < 8; i++) {
                    int next = cur ^ mask[i];

                    if (visit[next]) {
                        continue;
                    }

                    visit[next] = true;
                    qu.push(next);
                }
            }
        }

        if (flag) {
            cout << ans << "\n";
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}
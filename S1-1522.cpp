#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int aCnt, bCnt;
int ans = 987654321;

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'a') {
            aCnt += 1;
        }
    }

    for (int i = 0; i < str.size(); i++) {
        int cnt = aCnt;
        bCnt = 0;
        int j = i;

        while (true) {
            if (cnt == 0) {
                break;
            }

            if (str[j % str.size()] == 'b') {
                bCnt += 1;
            }

            cnt -= 1;
            j += 1;
        }

        ans = min(ans, bCnt);
    }

    cout << ans;

    return 0;
}
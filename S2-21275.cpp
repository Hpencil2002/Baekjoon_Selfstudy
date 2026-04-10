#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string A, B;
int cnt;
long long ans, ansA, ansB;

int calMax(string str) {
    int res = 0;

    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            int cmp = str[i] - 'a';
            cmp += 11;

            res = max(res, cmp);
        }
        else {
            int cmp = str[i] - '0';
            cmp += 1;

            res = max(res, cmp);
        }
    }

    return res;
}

long long calc(int num, string str) {
    long long res = 0;
    int tmp = 0;

    for (int i = str.size() - 1; i >= 0; i--) {
        int rem;
        if (isalpha(str[i])) {
            rem = str[i] - 'a';
            rem += 10;
        }
        else {
            rem = str[i] - '0';
        }

        res += pow(num, tmp) * rem;
        tmp += 1;
    }

    return res;
}

int main() {
    cin >> A >> B;

    int maxA = calMax(A);
    int maxB = calMax(B);

    for (int i = maxA; i <= 36; i++) {
        for (int j = maxB; j <= 36; j++) {
            long long tmpA = calc(i, A);
            long long tmpB = calc(j, B);

            if (i == j) {
                continue;
            }

            if (tmpA == tmpB && tmpA >= 0) {
                cnt += 1;

                ans = tmpA;
                ansA = i;
                ansB = j;
            }
        }
    }

    if (cnt >= 2) {
        cout << "Multiple";
    }
    else if (cnt == 0) {
        cout << "Impossible";
    }
    else {
        cout << ans << ' ' << ansA << ' ' << ansB;
    }

    return 0;
}
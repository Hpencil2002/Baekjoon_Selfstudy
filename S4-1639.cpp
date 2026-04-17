#include <iostream>
using namespace std;

char S[51];

bool check(int start, int end) {
    int sum1 = 0, sum2 = 0;
    int mid = (start + end) / 2;

    for (int i = start; i < mid; i++) {
        sum1 += S[i] - '0';
    }
    for (int i = mid; i < end; i++) {
        sum2 += S[i] - '0';
    }

    if (sum1 == sum2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cin >> S;

    int len = 0;
    while (S[len++] != NULL);

    for (int i = len - 1; i >= 0; i--) {
        if (i & 1) {
            continue;
        }

        for (int j = 0; j < len - i; j++) {
            if (check(j, j + i)) {
                cout << i;

                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}
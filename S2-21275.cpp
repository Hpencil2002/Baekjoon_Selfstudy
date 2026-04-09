#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long X;
int A, B;
string first, second;

int findMinDigit(string str) {
    int res = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = max(res, str[i] - '0');
        }
        else {
            res = max(res, str[i] - 'a' + 11);
        }
    }

    return res;
}

long long changeDecimalNumber(string str, int digit) {
    long long res = 0;

    for (int i = 0; i < str.length(); i++) {
        int num;

        if (str[i] > '0' && str[i] <= '9') {
            num = str[i] - '0';
        }
        else {
            num = str[i] - 'a' + 10;
        }

        res += num * pow(digit, str.length() - i - 1);
    }

    return res;
}

int main() {
    cin >> first >> second;

    int digitA = findMinDigit(first);
    int digitB = findMinDigit(second);

    int cnt = 0;
    for (int i = digitA; i <= 36; i++) {
        for (int j = digitB; j <= 36; j++) {
            long long changeA = changeDecimalNumber(first, i);
            long long changeB = changeDecimalNumber(second, j);

            if (i != j && changeA >= 0 && changeA == changeB) {
                cnt += 1;

                X = changeA;
                A = i;
                B = j;
            }
        }
    }

    if (cnt == 0) {
        cout << "Impossible";
    }
    else if (cnt == 1) {
        cout << X << ' ' << A << ' ' << B;
    }
    else {
        cout << "Multiple";
    }

    return 0;
}
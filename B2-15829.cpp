#include <iostream>
#include <string>
using namespace std;

int main() {
    int L;
    string str;

    cin >> L >> str;

    long long result = 0;
    long long tmp = 1;

    for (int i = 0; i < L; i++) {
        result += ((str[i] - 'a' + 1) * tmp) % 1234567891;
        tmp *= 31;
        tmp %= 1234567891;
    }

    cout << result % 1234567891;

    return 0;
}
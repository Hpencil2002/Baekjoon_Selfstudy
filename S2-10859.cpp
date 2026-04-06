#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string N;

bool check(long long n) {
    if (n == 1) {
        return false;
    }

    int cnt = 0;
    for (long long i = 2; i * i < n + 1; i++) {
        if (n % i == 0) {
            cnt += 1;
        }
    }

    if (cnt == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cin >> N;
    if (!check(stoll(N))) {
        cout << "no";

        return 0;
    }

    reverse(N.begin(), N.end());

    bool flag = true;
    string tmp = "";
    for (int i = 0; i < N.length(); i++) {
        char c = N[i];

        if (c == '3' || c == '4' || c == '7') {
            flag = false;

            break;
        }
        else if (c == '6') {
            tmp += '9';
        }
        else if (c == '9') {
            tmp += '6';
        }
        else {
            tmp += c;
        }
    }

    if (!flag) {
        cout << "no";
    }
    else if (check(stoll(tmp))) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

    return 0;
}
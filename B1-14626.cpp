#include <iostream>
#include <string>
using namespace std;

int main() {
    string ISBN;
    int ans;
    int tmp = 0;

    cin >> ISBN;
    for (int i = 0; i < ISBN.length(); i++) {
        if (ISBN[i] >= '0' && ISBN[i] <= '9') {
            if (i % 2 == 0) {
                tmp += ISBN[i] - '0';
            }
            else {
                tmp += (ISBN[i] - '0') * 3;
            }
        }
    }

    if (tmp % 10 == 0) {
        ans = 0;
    }
    else {
        ans = 10 - tmp % 10;
    }

    cout << ans;

    return 0;
}
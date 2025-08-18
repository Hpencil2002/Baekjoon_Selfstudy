#include <iostream>
#include <string>
using namespace std;

string password;

bool check() {
    int cnt1 = 0, cnt2 = 0;
    bool isFind = false;

    for (int i = 0; i < password.size(); i++) {
        if (!(password[i] == 'e' || password[i] == 'o')) {
            if (i + 1 < password.size() && password[i] == password[i + 1]) {
                return false;
            }
        }

        if (password[i] == 'a' || password[i] == 'i' || password[i] == 'u' || password[i] == 'e' || password[i] == 'o') {
            isFind = true;
            cnt1 += 1;
            cnt2 = 0;

            if (cnt1 == 3) {
                return false;
            }
        }
        else {
            cnt2 += 1;
            cnt1 = 0;

            if (cnt2 == 3) {
                return false;
            }
        }
    }

    return isFind;
}

int main() {
    while (true) {
        cin >> password;
        if (password == "end") {
            return 0;
        }

        cout << "<" << password << "> is " << (check() ? "acceptable.\n" : "not acceptable.\n");
    }
}
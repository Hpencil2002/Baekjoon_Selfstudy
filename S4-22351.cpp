#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S;
int A;

int main() {
    cin >> S;

    int range = min(3, (int)S.length());
    for (int i = 0; i < range; i++) {
        A = A * 10 + S[i] - '0';
        string str;

        for (int B = A; ; B++) {
            str += to_string(B);

            if (str == S) {
                cout << A << ' ' << B;

                return 0;
            }

            if (str.size() > S.size()) {
                break;
            }
        }
    }
}
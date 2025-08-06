#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int quarter = 0;
        int dime = 0;
        int nickel = 0;
        int penny = 0;

        int C;
        cin >> C;

        while (C) {
            if (C >= 25) {
                quarter += 1;
                C -= 25;
            }
            else if (C >= 10) {
                dime += 1;
                C -= 10;
            }
            else if (C >= 5) {
                nickel += 1;
                C -= 5;
            }
            else {
                penny += 1;
                C -= 1;
            }
        }

        cout << quarter << ' ' << dime << ' ' << nickel << ' ' << penny << "\n";
    }

    return 0;
}
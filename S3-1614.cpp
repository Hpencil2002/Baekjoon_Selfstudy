#include <iostream>
using namespace std;

long long index, limit;

int main() {
    cin >> index >> limit;

    if (index == 1) {
        cout << limit * 8;
    }
    else if (index == 2) {
        if (limit % 2 == 0) {
            cout << limit * 4 + 1;
        }
        else {
            cout << limit * 4 + 3;
        }
    }
    else if (index == 3) {
        cout << limit * 4 + 2;
    }
    else if (index == 4) {
        if (limit % 2 == 0) {
            cout << limit * 4 + 3;
        }
        else {
            cout << limit * 4 + 1;
        }
    }
    else if (index == 5) {
        cout << limit * 8 + 4;
    }

    return 0;
}
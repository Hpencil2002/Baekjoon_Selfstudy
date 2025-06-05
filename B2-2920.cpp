#include <iostream>
using namespace std;

int main() {
    int num[8];
    for (int i = 0; i < 8; i++) {
        cin >> num[i];
    }

    switch (num[0]) {
        case 1:
            for (int i = 0; i < 7; i++) {
                if (num[i + 1] - num[i] != 1) {
                    cout << "mixed";
                    return 0;
                }
            }
            cout << "ascending";
            break;
        case 8:
            for (int i = 0; i < 7; i++) {
                if (num[i] - num[i + 1] != 1) {
                    cout << "mixed";
                    return 0;
                }
            }
            cout << "descending";
            break;
        default:
            cout << "mixed";
            break;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> getNotation(int num, int b) {
    int tmp = num;
    vector<int> notation;

    while (tmp) {
        notation.push_back(tmp % b);
        tmp /= b;
    }

    return notation;
}

bool canMakePalindrome(vector<int> notationB) {
    for (int i = 0; i < notationB.size() / 2; i++) {
        if (notationB[i] != notationB[notationB.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int num;
        cin >> num;

        int isValid = 0;
        for (int b = 2; b <= 64; b++) {
            vector<int> vc = getNotation(num, b);
            if (canMakePalindrome(vc)) {
                isValid = 1;
                break;
            }
        }

        cout << isValid << "\n";
    }


    return 0;
}
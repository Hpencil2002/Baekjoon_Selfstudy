#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    int index_A = 0, index_B = 0;
    bool flag = false;

    cin >> A >> B;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (A[i] == B[j]) {
                index_A = i;
                index_B = j;
                flag = true;

                break;
            }
        }

        if (flag) {
            break;
        }
    }

    for (int i = 0; i < B.size(); i++) {
        if (i == index_B) {
            cout << A << "\n";
            continue;
        }

        for (int j = 0; j < A.size(); j++) {
            if (j == index_A) {
                cout << B[i];
            }
            else {
                cout << '.';
            }
        }

        cout << '\n';
    }

    return 0;
}
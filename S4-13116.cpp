#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        while (A != B) {
            if (A > B) {
                A >>= 1;
            }
            else {
                B >>= 1;
            }
        }

        cout << A << "0\n";
    }

    return 0;
}
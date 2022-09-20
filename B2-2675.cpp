#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, R;
    string S, P = "";
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> R >> S;

        for (int j = 0; j < S.size(); j++) {
            for (int k = 0; k < R; k++) {
                P += S[j];
            }
        }

        cout << P << "\n";
        P = "";
    }

    return 0;
}
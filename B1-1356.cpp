#include <iostream>
#include <string>
using namespace std;

int main() {
    string N;
    int res_a, res_b;

    cin >> N;
    for (int i = 1; i < N.size(); i++) {
        res_a = int(N[0] - '0');
        for (int j = 1; j < i; j++) {
            res_a *= int(N[j] - '0');
        }

        res_b = int(N[i] - '0');
        if (i != N.size()) {
            for (int j = i + 1; j < N.size(); j++) {
                res_b *= int(N[j] - '0');
            }
        }

        if (res_a == res_b) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}
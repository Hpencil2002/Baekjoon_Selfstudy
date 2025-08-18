#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int m;
    cin >> m;

    int num[26];
    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }

    int index = 0;
    int tmp = 0;
    for (int i = m - 1; i >= 0; i--) {
        tmp += num[index] * pow(A, i);
        index += 1;
    }

    vector<int> vc;
    while (tmp >= B) {
        vc.push_back(tmp % B);
        tmp /= B;

        if (tmp < B) {
            vc.push_back(tmp);
        }
    }

    for (int i = vc.size() - 1; i >= 0; i--) {
        cout << vc[i] << ' ';
    }

    return 0;
}
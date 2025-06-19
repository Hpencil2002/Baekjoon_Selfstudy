#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, n;

int main() {
    cin >> L;
    vector<int> vc(L);
    for (int i = 0; i < L; i++) {
        cin >> vc[i];
    }
    vc.push_back(0);
    cin >> n;

    int s, e;
    bool b = true;

    sort(vc.begin(), vc.end());

    for (int i = 1; i < L + 1; i++) {
        if (n == vc[i]) {
            b = false;
        }
        else if (n < vc[i]) {
            s = vc[i - 1] + 1;
            e = vc[i] - 1;
            break;
        }
    }

    if (b) {
        cout << (n - s) * (e - n + 1) + (e - n);
    }
    else {
        cout << 0;
    }

    return 0;
}
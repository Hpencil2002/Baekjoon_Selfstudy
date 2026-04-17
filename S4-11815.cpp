#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        long long x;
        cin >> x;

        long long sq = sqrt(x);
        if (sq * sq == x) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }

    return 0;
}
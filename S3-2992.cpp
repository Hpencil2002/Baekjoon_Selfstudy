#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string X;
    cin >> X;

    if (next_permutation(X.begin(), X.end())) {
        cout << X;
    }
    else {
        cout << 0;
    }

    return 0;
}
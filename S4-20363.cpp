#include <iostream>
#include <cmath>
using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    cout << max(X, Y) + min(X, Y) + min(X, Y) / 10;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, W;
    cin >> n >> W;

    vector<int> vc = vector<int>(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    long long coin = 0;
    for (int i = 0; i < n; i++) {
        if (vc[i] < vc[i + 1]) {
            coin += W / vc[i];
            W %= vc[i];
        }
        else {
            W += vc[i] * coin;
            coin = 0;
        }
    }

    cout << W;

    return 0;
}
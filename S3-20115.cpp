#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> vc;
    for (int i = 0; i < N; i++) {
        double drink;
        cin >> drink;
        vc.push_back(drink);
    }

    sort(vc.begin(), vc.end());

    double ans = vc[N - 1];
    for (int i = 0; i < N - 1; i++) {
        ans += vc[i] / 2;
    }

    cout << ans;

    return 0;
}
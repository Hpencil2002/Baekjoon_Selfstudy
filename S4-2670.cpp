#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> vc = vector<double>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    double ans = vc[0];
    double tmp;
    vector<double> result;

    result.push_back(vc[0]);
    for (int i = 1; i < N; i++) {
        if (vc[i] * result[i - 1] >= vc[i]) {
            tmp = vc[i] * result[i - 1];
        }
        else {
            tmp = vc[i];
        }

        result.push_back(tmp);
        if (ans < tmp) {
            ans = tmp;
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << ans;

    return 0;
}